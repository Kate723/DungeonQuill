#include "SpellDisplay.h"

SpellDisplay::SpellDisplay(Spell* displaySpell, QWidget *parent)
	: QWidget(parent)
{
	if (!displaySpell) {
		QMessageBox::critical(NULL, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无法找到对应法术"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	ui.setupUi(this);
	spell = displaySpell;

	initFormat();
}

SpellDisplay::~SpellDisplay()
{

}

void SpellDisplay::initFormat() {
	//生成所需格式
	QFont emphasize("黑体", 12, QFont::Bold);
	QFont default("宋体", 10);
	QFont bold("宋体", 10, QFont::Bold);
	QColor brown(124, 60, 33);

	//合并单元格
	ui.basicTable->setSpan(0, 0, 1, 2);
	ui.basicTable->setSpan(1, 0, 1, 2);

	//显示法术名称
	std::string spellName = spell->getNameCH() + ' ' + spell->getNameEN();
	auto nameItem = tableItem(spellName.c_str(), emphasize, brown);
	ui.basicTable->setItem(0, 0, nameItem);

	//显示法术环阶学派


	//显示法术属性

	initTableFormat(ui.basicTable);
	ui.basicTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

QTableWidgetItem* SpellDisplay::tableItem(const char* str,QFont font, QColor color) {
	auto item = new QTableWidgetItem(QString::fromLocal8Bit(str));
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	item->setTextAlignment(Qt::AlignVCenter);
	item->setFont(font);
	item->setTextColor(color);

	return item;
}


void SpellDisplay::initTableFormat(const QTableWidget* table)
{
	table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);		//列头铺满
	table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);		//行头铺满

	((QAbstractItemView*)table)->setSelectionMode(QAbstractItemView::NoSelection);		//取消选择功能
	((QAbstractItemView*)table)->setEditTriggers(QAbstractItemView::NoEditTriggers);		//取消编辑功能
}