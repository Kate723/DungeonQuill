#include "DungeonQuill.h"

DungeonQuill* DungeonQuill::instance = nullptr;

DungeonQuill::DungeonQuill()
{
    if (instance) {
        delete this;
        return;
    }
    instance = this;

    ui.setupUi(this);

    connect(ui.comboBox_level, SIGNAL(currentIndexChanged(int)), this, SLOT(spellInquiry(int)));
    connect(ui.comboBox_school, SIGNAL(currentIndexChanged(int)), this, SLOT(spellInquiry(int)));

    initCharacterTab();
    initCombatTab();
    initSpellTab();
}

void DungeonQuill::initCharacterTab() {
    QGridLayout* grid = new QGridLayout();

    int characterNum = Adventurer::adventurerList.size();
    qDebug() << characterNum;

    int row = 0;
    int col = 0;
    for (int i = 0; i < characterNum; i++) {
        qDebug() << i;
        auto newButton = new CharacterButton(Adventurer::adventurerList[i]);
        grid->addWidget(newButton, row, col + 1);

        row += ++col / 4;
        col %= 4;
    }
    grid->setColumnStretch(0, 0);
    grid->setColumnStretch(5, 0);
    grid->setRowStretch(row + 1, 1);
    grid->setSpacing(20);
    ui.characterArea->setLayout(grid);
}

void DungeonQuill::initCombatTab() {
    QGridLayout* grid = new QGridLayout();
    auto newMapButton = new NewMapButton();
    grid->addWidget(newMapButton, 0, 0);

    int row = 0;
    int col = 1;
    for (auto i = CombatMap::mapList.begin(); i != CombatMap::mapList.end(); i++) {
        auto curMap = (CombatMap*)*i;
        auto newButton = new MapButton(curMap);
        grid->addWidget(newButton, row, col++);

        row += col / 4;
        col %= 4;
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
        auto pSpell = findNextSpell(i == spellNum);
        auto newButton = new SpellBotton(pSpell);
        grid->addWidget(newButton, row, col + 1);

        row += ++col / 4;
        col %= 4;
    }
    grid->setColumnStretch(0, 0);
    grid->setColumnStretch(5, 0);
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
    deleteLayout(ui.spellListContents->layout());

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

        row += col / 4;
        col %= 4;
    }

    grid->setColumnStretch(0, 0);
    grid->setColumnStretch(5, 0);
    grid->setRowStretch(row + 1, 1);
    grid->setSpacing(20);
    ui.spellListContents->setLayout(grid);
}

void DungeonQuill::renewMapList() {
    instance->deleteLayout(instance->ui.mapArea->layout());

    instance->initCombatTab();
}

void DungeonQuill::deleteLayout(QLayout* layout) {
    int itemCount = layout->count();
    for (int i = (itemCount - 1); i >= 0; --i)
    {
        QLayoutItem* item = layout->takeAt(i);
        if (item != 0)
        {
            layout->removeWidget(item->widget());
            delete item->widget();
        }
    }
    delete layout;
}

void DungeonQuill::combatStart(CombatMap* _map) {
    auto combatWin = new MapEditor(_map);
    instance->deleteLayout(combatWin->ui.editorLayout);

    CombatManager::combatStart(_map, combatWin);
}

QTableWidget* DungeonQuill::showMap(CombatMap* map)
{
    QColor barrierColor = QColor(138, 105, 19);
    QColor flatColor = QColor(249, 241, 219);
    QColor piecesColor = QColor(130, 107, 72);

    auto mapTable = new QTableWidget();
    mapTable->setRowCount(300);
    mapTable->setColumnCount(300);

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            QTableWidgetItem* gridItem = NULL;
            switch (map->grid[i][j])
            {
            case CombatMap::GridTag::Barrier:
                gridItem = tableItem(barrierColor, QString());
                mapTable->setItem(i, j, gridItem);
                break;
            case CombatMap::GridTag::Flat:
                gridItem = tableItem(flatColor, QString());
                mapTable->setItem(i, j, gridItem);
                break;
            default:
                break;
            }
        }
    }

    mapTable->verticalHeader()->setMinimumWidth(40);							//行表头宽度

    mapTable->horizontalHeader()->setDefaultSectionSize(50);
    mapTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    mapTable->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);		//表头内容居中

    mapTable->verticalHeader()->setDefaultSectionSize(50);
    mapTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    mapTable->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);		//表头内容居中

    mapTable->setStyleSheet("QTableWidget::item:selected { background-color: rgb(166, 27, 41) }");

    return mapTable;
}

QTableWidgetItem* DungeonQuill::tableItem(QColor gridColor, QString& str)
{
    auto item = new QTableWidgetItem(str);
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    item->setBackgroundColor(gridColor);

    return item;
}