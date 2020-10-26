#include "DungeonQuill.h"

DungeonQuill::DungeonQuill()
{
    ui.setupUi(this);

    connect(ui.comboBox_level, SIGNAL(currentIndexChanged(int)), this, SLOT(spellInquiry(int)));
    connect(ui.comboBox_school, SIGNAL(currentIndexChanged(int)), this, SLOT(spellInquiry(int)));

    initCombatTab();
    initSpellTab();
}

void DungeonQuill::initCombatTab() {
    QGridLayout* grid = new QGridLayout();
    auto newMapButton = new NewMapButton();
    grid->addWidget(newMapButton, 0, 0);

    CombatMap::mapList.push_back(new CombatMap());

    int row = 0;
    int col = 1;
    for (auto i = CombatMap::mapList.begin(); i != CombatMap::mapList.end(); i++) {
        auto curMap = (CombatMap*)*i;
        auto newButton = new MapButton(curMap);
        grid->addWidget(newButton, row, col++);

        row += col / 5;
        col %= 5;
    }

    ui.mapArea->setLayout(grid);
}

/// <summary>
/// 初始化法术标签页
/// </summary>
void DungeonQuill::initSpellTab() {
    QGridLayout* grid = new QGridLayout();

    int spellNum = Spell::spellNum + DamageSpell::damageSpellNum + HealSpell::healSpellNum;
    qDebug() << spellNum;

    int row = 0;
    int col = 0;
    for (int i = 1; i <= spellNum; i++) {
        qDebug() << i;
        auto pSpell = findNextSpell(i == spellNum);
        auto newButton = new SpellBotton(pSpell);
        grid->addWidget(newButton, row, col + 1);

        row += ++col / 5;
        col %= 5;
    }
    grid->setColumnStretch(0, 0);
    grid->setColumnStretch(6, 1);
    grid->setRowStretch(row + 1, 1);
    grid->setSpacing(20);
    ui.spellListContents->setLayout(grid);
}

Spell* DungeonQuill::findNextSpell(bool resetFlag) {
    static int p = 0;
    static int pDamage = 0;
    static int pHeal = 0;

    int lowestID = 100000;
    Spell* nextSpell = NULL;
    if (p > Spell::spellNum) {
        nextSpell = Spell::spellList[p];
        lowestID = nextSpell->getID();
    }
    if (pDamage < DamageSpell::damageSpellNum && DamageSpell::DamageSpellList[pDamage]->getID() < lowestID) {
        nextSpell = DamageSpell::DamageSpellList[pDamage];
        lowestID = nextSpell->getID();
    }
    if (pHeal < HealSpell::healSpellNum && HealSpell::HealSpellList[pHeal]->getID() < lowestID) {
        nextSpell = HealSpell::HealSpellList[pHeal++];
        lowestID = nextSpell->getID();
    }
    else if (pDamage < DamageSpell::damageSpellNum && nextSpell == DamageSpell::DamageSpellList[pDamage]) {
        pDamage++;
    }
    else if (p < Spell::spellNum && nextSpell == Spell::spellList[p]) {
        p++;
    }

    if (resetFlag) {
        p = pDamage = pHeal = 0;
    }

    return nextSpell;
}

void DungeonQuill::spellInquiry(int x)
{
    //清除当前layout及其内容
    int itemCount = ui.spellListContents->layout()->count(); 
    for (int i = (itemCount - 1); i >= 0; --i) 
    {
        QLayoutItem* item = ui.spellListContents->layout()->takeAt(i);
        if (item != 0)
        {
            ui.spellListContents->layout()->removeWidget(item->widget());
            delete item->widget(); 
        }
    }
    delete ui.spellListContents->layout();

    int selectedLV = ui.comboBox_level->currentIndex();
    int selectedSchool = ui.comboBox_school->currentIndex();
    
    //重新筛选建立
    QGridLayout* grid = new QGridLayout();
    int spellNum = Spell::spellNum + DamageSpell::damageSpellNum + HealSpell::healSpellNum;
    qDebug() << spellNum;

    int row = 0;
    int col = 0;
    for (int i = 1; i <= spellNum; i++) {
        auto pSpell = findNextSpell(i == spellNum);
        if (selectedLV && pSpell->getLevel() != selectedLV - 1) continue;
        if (selectedSchool && pSpell->getSchoolID() != selectedSchool - 1) continue;

        qDebug() << i;
        auto newButton = new SpellBotton(pSpell);
        grid->addWidget(newButton, row, col++);

        row += col / 5;
        col %= 5;
    }

    grid->setColumnStretch(0, 0);
    grid->setColumnStretch(6, 1);
    grid->setRowStretch(row + 1, 1);
    grid->setSpacing(20);
    ui.spellListContents->setLayout(grid);
}