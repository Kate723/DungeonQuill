#include "DungeonQuill.h"
#include "qtablewidget.h"
#include "DataManager.h"

DungeonQuill::DungeonQuill(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //表格首行水平铺满
    ui.spellTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    
}

