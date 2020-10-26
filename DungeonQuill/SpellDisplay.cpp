#include "SpellDisplay.h"
#include <qdebug.h>

SpellDisplay::SpellDisplay(Spell* displaySpell) : spell(displaySpell)
{
	if (!displaySpell) {
		QMessageBox::critical(NULL, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无法找到对应法术"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	ui.setupUi(this);

	initFormat();

	this->setWindowTitle(spell->getNameCH());
}

SpellDisplay::~SpellDisplay()
{

}

void SpellDisplay::initFormat() {
	//生成所需格式
	QFont emphasize("SimHei", 12, QFont::Bold);
	QFont default("Times New Roman", 10);
	QFont bold("Times New Roman", 10, QFont::Bold);
	QFont italicBold("Times New Roman", 8, QFont::Bold, true);
	QColor brown(124, 60, 33);

	//显示法术名称
	auto nameItem = tableItem(spell->getNameCH(), emphasize, brown, 1);
	ui.basicTable->setItem(0, 0, nameItem);
	nameItem = tableItem(spell->getNameEN(), emphasize, brown);
	ui.basicTable->setItem(0, 1, nameItem);

	//显示法术环阶学派
	QString spellInfo = spell->getLevelString() + ' ' + spell->getSchoolName();
	if (spell->spellIsRitual()) {
		spellInfo += QString::fromLocal8Bit("（仪式）");
	}
	auto infoItem = tableItem(spellInfo, italicBold);
	ui.basicTable->setItem(1, 0, infoItem);

	//显示法术属性
	auto headerItem = tableItem(QString::fromLocal8Bit("施法时间："), bold);
	ui.basicTable->setItem(2, 0, headerItem);
	auto contentItem = tableItem(spell->getCastingTimeRemarks(), default);
	ui.basicTable->setItem(2, 1, contentItem);

	headerItem = tableItem(QString::fromLocal8Bit("施法距离："), bold);
	ui.basicTable->setItem(3, 0, headerItem);
	contentItem = tableItem(spell->getRangeString(), default);
	ui.basicTable->setItem(3, 1, contentItem);

	headerItem = tableItem(QString::fromLocal8Bit("法术成分："), bold);
	ui.basicTable->setItem(4, 0, headerItem);
	contentItem = tableItem(spell->getComponentString(), default);
	ui.basicTable->setItem(4, 1, contentItem);

	headerItem = tableItem(QString::fromLocal8Bit("持续时间："), bold);
	ui.basicTable->setItem(5, 0, headerItem);
	contentItem = tableItem(spell->getDurationString(), default);
	ui.basicTable->setItem(5, 1, contentItem);

	ui.detailText->setText(spell->getRemarks());
	ui.detailText->setFont(default);
	
	initTableFormat(ui.basicTable);
	ui.basicTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	ui.basicTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	ui.basicTable->setSpan(1, 0, 1, 2);

	ui.basicTable->setStyleSheet("background-color:transparent");
	ui.detailText->setStyleSheet("background-color:transparent");
}

QTableWidgetItem* SpellDisplay::tableItem(QString str,QFont font, QColor color, int codeType) {
	auto item = new QTableWidgetItem(str);
	item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
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