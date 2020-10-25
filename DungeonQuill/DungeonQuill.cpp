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
    for (int i = 0; i < spellNum; i++) {

    }
    auto p = new Spell(1000, std::string("酸液飞溅"), std::string("Acid Splash"), 1, 0, 0, 1, std::string("1动作"), 60, 0, 1, 1, 0, std::string(""), 0, 0, std::string("立即"), 1, 1, 0, 0,
        std::string("111"));
    auto test = new SpellBotton(p);
    grid->addWidget(test);
    //grid->setColumnStretch(1, 1);   // 在第 n 列增加一个弹簧，比例为 1   
    //grid->setRowStretch(1, 1);      // 在第 n 行增加一个弹簧，比例为 1
    ui.SpellArea->setLayout(grid);
}