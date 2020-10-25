#include "DungeonQuill.h"

DungeonQuill::DungeonQuill(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initSpellTab();
}

/// <summary>
/// 初始化法术标签页
/// </summary>
void DungeonQuill::initSpellTab() {
    QGridLayout* grid = new QGridLayout();
    
    int spellNum = Spell::spellNum + DamageSpell::damageSpellNum + HealSpell::healSpellNum;
    for (int i = 1; i <= spellNum; i++) {
        auto pSpell = findNextSpell(i == spellNum);
        auto newButton = new SpellBotton(pSpell);
        grid->addWidget(newButton);
    }
    
    //grid->setColumnStretch(1, 1);   // 在第 n 列增加一个弹簧，比例为 1   
    //grid->setRowStretch(1, 1);      // 在第 n 行增加一个弹簧，比例为 1
    ui.SpellArea->setLayout(grid);
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
    if (pDamage > DamageSpell::damageSpellNum && DamageSpell::DamageSpellList[pDamage]->getID() < lowestID) {
        nextSpell = DamageSpell::DamageSpellList[pDamage];
        lowestID = nextSpell->getID();
    }
    if (pHeal > HealSpell::healSpellNum && HealSpell::HealSpellList[pHeal]->getID() < lowestID) {
        nextSpell = HealSpell::HealSpellList[pHeal++];
        lowestID = nextSpell->getID();
    }
    else if (nextSpell == DamageSpell::DamageSpellList[pDamage]) {
        pDamage++;
    }
    else if (nextSpell == Spell::spellList[p]) {
        p++;
    }

    if (resetFlag) {
        p = pDamage = pHeal = 0;
    }

    return nextSpell;
}