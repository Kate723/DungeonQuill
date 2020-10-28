#include "CharacterDisplay.h"

CharacterDisplay::CharacterDisplay(Adventurer* _character) : 
	character(_character)
{
	ui.setupUi(this);

	initFormat();
}

CharacterDisplay::~CharacterDisplay()
{
}

void CharacterDisplay::initFormat() 
{
	initBasicInfo();
	initBgTab();
	initMainTab();
}

void CharacterDisplay::initBasicInfo() 
{
	QComboBox* raceBox = new QComboBox();
	raceBox->addItem(QString::fromLocal8Bit("矮人"));
	raceBox->addItem(QString::fromLocal8Bit("精灵"));
	raceBox->addItem(QString::fromLocal8Bit("半身人"));
	raceBox->addItem(QString::fromLocal8Bit("人类"));
	raceBox->addItem(QString::fromLocal8Bit("龙裔"));
	raceBox->addItem(QString::fromLocal8Bit("侏儒"));
	raceBox->addItem(QString::fromLocal8Bit("半精灵"));
	raceBox->addItem(QString::fromLocal8Bit("半兽人"));
	raceBox->addItem(QString::fromLocal8Bit("提夫林"));
	ui.raceTable->setCellWidget(0, 0, raceBox);

	QComboBox* genderBox = new QComboBox();
	genderBox->addItem(QString::fromLocal8Bit("男"));
	genderBox->addItem(QString::fromLocal8Bit("女"));
	ui.ageTable->setCellWidget(0, 0, genderBox);

	QComboBox* aligBox = new QComboBox();
	aligBox->addItem(QString::fromLocal8Bit("守序善良"));
	aligBox->addItem(QString::fromLocal8Bit("中立善良"));
	aligBox->addItem(QString::fromLocal8Bit("混乱善良"));
	aligBox->addItem(QString::fromLocal8Bit("守序中立"));
	aligBox->addItem(QString::fromLocal8Bit("绝对中立"));
	aligBox->addItem(QString::fromLocal8Bit("混乱中立"));
	aligBox->addItem(QString::fromLocal8Bit("守序邪恶"));
	aligBox->addItem(QString::fromLocal8Bit("中立邪恶"));
	aligBox->addItem(QString::fromLocal8Bit("混乱邪恶"));
	ui.alignmentTable->setCellWidget(1, 0, aligBox);

	initTableFormat(ui.nameTable);
	initTableFormat(ui.classTable);
	initTableFormat(ui.levelTable);
	initTableFormat(ui.raceTable,40);
	initTableFormat(ui.ageTable,40);
	initTableFormat(ui.sizeTable,40);
	initTableFormat(ui.alignmentTable,40);
}

void CharacterDisplay::initMainTab() {
	auto item = tableItem("体型");
	ui.hpTable->setItem(0, 0, item);
	item = tableItem("速度");
	ui.hpTable->setItem(0, 2, item);
	item = tableItem("特殊");
	ui.hpTable->setItem(1, 0, item);
	item = tableItem("临时HP");
	ui.hpTable->setItem(1, 2, item);
	item = tableItem("HP");
	ui.hpTable->setItem(2, 0, item);
	item = tableItem("HD");
	ui.hpTable->setItem(3, 0, item);
	ui.hpTable->setSpan(2, 1, 1, 3);
	ui.hpTable->setSpan(3, 1, 1, 3);

	//插入属性名称
	item = tableItem("力量");
	ui.abilityTable->setItem(0, 1, item);
	item = tableItem("敏捷");
	ui.abilityTable->setItem(1, 1, item);
	item = tableItem("体质");
	ui.abilityTable->setItem(2, 1, item);
	item = tableItem("智力");
	ui.abilityTable->setItem(3, 1, item);
	item = tableItem("感知");
	ui.abilityTable->setItem(4, 1, item);
	item = tableItem("魅力");
	ui.abilityTable->setItem(5, 1, item);

	for (int i = 0; i <= 5; i++) {
		ui.abilityTable->setCellWidget(i, 0, newProBox());
	}

	initSkillTable();

	//表格整体格式初始化
	initTableFormat(ui.abilityTable);
	initTableFormat(ui.combatTable,100);
	initTableFormat(ui.hpTable);
	initTableFormat(ui.skillTable);
	initTableFormat(ui.skillTable);
}

void CharacterDisplay::initSkillTable() {
	//合并技能类型名单元格
	ui.skillTable->setSpan(1, 0, 1, 3);
	ui.skillTable->setSpan(5, 0, 1, 3);
	ui.skillTable->setSpan(11, 0, 1, 3);
	ui.skillTable->setSpan(17, 0, 1, 3);

	//设置内容与格式
	auto item = tableItem("敏捷系");
	ui.skillTable->setItem(1, 0, item);
	item = tableItem("智力系");
	ui.skillTable->setItem(5, 0, item);
	item = tableItem("感知系");
	ui.skillTable->setItem(11, 0, item);
	item = tableItem("魅力系");
	ui.skillTable->setItem(17, 0, item);

	item = tableItem("运动");
	ui.skillTable->setItem(0, 1, item);
	item = tableItem("特技");
	ui.skillTable->setItem(2, 1, item);
	item = tableItem("巧手");
	ui.skillTable->setItem(3, 1, item);
	item = tableItem("隐匿");
	ui.skillTable->setItem(4, 1, item);
	item = tableItem("调查");
	ui.skillTable->setItem(6, 1, item);
	item = tableItem("奥秘");
	ui.skillTable->setItem(7, 1, item);
	item = tableItem("历史");
	ui.skillTable->setItem(8, 1, item);
	item = tableItem("自然");
	ui.skillTable->setItem(9, 1, item);
	item = tableItem("宗教");
	ui.skillTable->setItem(10, 1, item);
	item = tableItem("察觉");
	ui.skillTable->setItem(12, 1, item);
	item = tableItem("洞悉");
	ui.skillTable->setItem(13, 1, item);
	item = tableItem("驯养");
	ui.skillTable->setItem(14, 1, item);
	item = tableItem("医疗");
	ui.skillTable->setItem(15, 1, item);
	item = tableItem("生存");
	ui.skillTable->setItem(16, 1, item);
	item = tableItem("说服");
	ui.skillTable->setItem(18, 1, item);
	item = tableItem("欺诈");
	ui.skillTable->setItem(19, 1, item);
	item = tableItem("威吓");
	ui.skillTable->setItem(20, 1, item);
	item = tableItem("表演");
	ui.skillTable->setItem(21, 1, item);

	ui.skillTable->setCellWidget(0, 0, newProBox());
	ui.skillTable->setCellWidget(2, 0, newProBox());
	ui.skillTable->setCellWidget(3, 0, newProBox());
	ui.skillTable->setCellWidget(4, 0, newProBox());
	ui.skillTable->setCellWidget(6, 0, newProBox());
	ui.skillTable->setCellWidget(7, 0, newProBox());
	ui.skillTable->setCellWidget(8, 0, newProBox());
	ui.skillTable->setCellWidget(9, 0, newProBox());
	ui.skillTable->setCellWidget(10, 0, newProBox());
	ui.skillTable->setCellWidget(12, 0, newProBox());
	ui.skillTable->setCellWidget(13, 0, newProBox());
	ui.skillTable->setCellWidget(14, 0, newProBox());
	ui.skillTable->setCellWidget(15, 0, newProBox());
	ui.skillTable->setCellWidget(16, 0, newProBox());
	ui.skillTable->setCellWidget(18, 0, newProBox());
	ui.skillTable->setCellWidget(19, 0, newProBox());
	ui.skillTable->setCellWidget(20, 0, newProBox());
	ui.skillTable->setCellWidget(21, 0, newProBox());
}

void CharacterDisplay::initBgTab()
{
	ui.characterDetailsTable->setSpan(0, 0, 2, 1);
	ui.characterDetailsTable->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("个性")));
	ui.characterDetailsTable->setItem(2, 0, new QTableWidgetItem(QString::fromLocal8Bit("理念")));
	ui.characterDetailsTable->setItem(3, 0, new QTableWidgetItem(QString::fromLocal8Bit("羁绊")));
	ui.characterDetailsTable->setItem(4, 0, new QTableWidgetItem(QString::fromLocal8Bit("缺点")));

	for (int i = 0; i <= 4; i++) {
		auto item = ui.characterDetailsTable->item(i, 0);
		item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	}
	
	initTableFormat(ui.characterDetailsTable);

	ui.characterDetailsTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
}

QTableWidgetItem* CharacterDisplay::tableItem(const char* str) {
	auto item = new QTableWidgetItem(QString::fromLocal8Bit(str));
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	return item;
}

QComboBox* CharacterDisplay::newProBox() {
	auto proBox = new QComboBox();
	proBox->addItem(QString::fromLocal8Bit("-"));
	proBox->addItem(QString::fromLocal8Bit("O"));

	return proBox;
}

void CharacterDisplay::initTableFormat(const QTableWidget* table, const int HeaderWidth)
{
	table->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);		//表头内容居中

	table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);		//列头铺满
	table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);		//行头铺满
	table->verticalHeader()->setMinimumWidth(HeaderWidth);		//行表头宽度

	((QAbstractItemView*)table)->setSelectionMode(QAbstractItemView::NoSelection);		//取消选择功能
}