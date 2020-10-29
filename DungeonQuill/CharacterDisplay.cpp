#include "CharacterDisplay.h"

CharacterDisplay::CharacterDisplay(Adventurer* _character) : 
	character(_character)
{
	ui.setupUi(this);

	initFormat();
	initContent();
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
	initTableFormat(ui.nameTable);
	initTableFormat(ui.classTable);
	initTableFormat(ui.levelTable);
	initTableFormat(ui.raceTable,40);
	initTableFormat(ui.ageTable,40);
	initTableFormat(ui.sizeTable,40);
	initTableFormat(ui.alignmentTable,40);
}

void CharacterDisplay::initMainTab() {
	ui.hpTable->setSpan(2, 1, 1, 3);
	ui.hpTable->setSpan(3, 1, 1, 3);
	initSkillTable();

	//表格整体格式初始化
	initTableFormat(ui.abilityTable);
	initTableFormat(ui.hpTable);
	initTableFormat(ui.skillTable);
}

void CharacterDisplay::initSkillTable() {
	int skillFamilyNameRow[] = { 0,1,5,11,17 };
	std::string skillFamilyName[] = { "","敏捷系","智力系","感知系","魅力系" };

	//合并技能类型名单元格
	for (int i = 1; i < 5; i++) {
		ui.skillTable->setSpan(skillFamilyNameRow[i], 0, 1, 3);
		//设置内容与格式
		auto item = tableItem(skillFamilyName[i]);
		ui.skillTable->setItem(skillFamilyNameRow[i], 0, item);
	}

	int skillIndex = 0;

	auto item = tableItem("运动");
	ui.skillTable->setItem(0, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(0, 2, item);

	item = tableItem("特技");
	ui.skillTable->setItem(2, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(2, 2, item);

	item = tableItem("巧手");
	ui.skillTable->setItem(3, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(3, 2, item);

	item = tableItem("隐匿");
	ui.skillTable->setItem(4, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(4, 2, item);

	item = tableItem("调查");
	ui.skillTable->setItem(6, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(6, 2, item);

	item = tableItem("奥秘");
	ui.skillTable->setItem(7, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(7, 2, item);

	item = tableItem("历史");
	ui.skillTable->setItem(8, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(8, 2, item);

	item = tableItem("自然");
	ui.skillTable->setItem(9, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(9, 2, item);

	item = tableItem("宗教");
	ui.skillTable->setItem(10, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(10, 2, item);

	item = tableItem("察觉");
	ui.skillTable->setItem(12, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(12, 2, item);

	item = tableItem("洞悉");
	ui.skillTable->setItem(13, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(13, 2, item);

	item = tableItem("驯养");
	ui.skillTable->setItem(14, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(14, 2, item);

	item = tableItem("医疗");
	ui.skillTable->setItem(15, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(15, 2, item);

	item = tableItem("生存");
	ui.skillTable->setItem(16, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(16, 2, item);

	item = tableItem("说服");
	ui.skillTable->setItem(18, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(18, 2, item);

	item = tableItem("欺诈");
	ui.skillTable->setItem(19, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(19, 2, item);

	item = tableItem("威吓");
	ui.skillTable->setItem(20, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(20, 2, item);

	item = tableItem("表演");
	ui.skillTable->setItem(21, 1, item);
	item = tableItem(character->getSkillProBonus(skillIndex++));
	ui.skillTable->setItem(21, 2, item);

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
	ui.characterDetailsTable->setItem(0, 0, tableItem("个性"));
	ui.characterDetailsTable->setItem(2, 0, tableItem("理念"));
	ui.characterDetailsTable->setItem(3, 0, tableItem("羁绊"));
	ui.characterDetailsTable->setItem(4, 0, tableItem("缺点"));

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

QTableWidgetItem* CharacterDisplay::tableItem(QString str) {
	auto item = new QTableWidgetItem(str);
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	return item;
}

QTableWidgetItem* CharacterDisplay::tableItem(std::string str) {
	auto item = new QTableWidgetItem(QString::fromStdString(str));
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	return item;
}

QTableWidgetItem* CharacterDisplay::tableItem(int num) {
	auto item = new QTableWidgetItem(QString::number(num));
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	return item;
}

QComboBox* CharacterDisplay::newProBox() {
	auto proBox = new QComboBox();
	proBox->addItem(QString::fromLocal8Bit("-"));
	proBox->addItem(QString::fromLocal8Bit("O"));

	proBoxList.push_back(proBox);
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

/// <summary>
/// 初始化内容函数
/// </summary>

void CharacterDisplay::initContent() {
	initRaceBox(character->race.getRaceID());
	initGenderBox(character->details.isMale());
	initAligBox(character->details.getAlignmentID());
	setProBox();
	initHPContent();
	initAbilityContent();
}

void CharacterDisplay::initBasicContent() {
	ui.nameTable->setItem(0, 0, new QTableWidgetItem(character->getName()));
	ui.nameTable->setItem(1, 0, new QTableWidgetItem(character->getPlayerName()));

	ui.classTable->setItem(0, 0, tableItem(character->getClassName()));
	ui.classTable->setItem(0, 0, new QTableWidgetItem(QString::number(character->getEXP())));

	ui.levelTable->setItem(0, 0, tableItem(character->_class.getLV()));

	ui.raceTable->setItem(0, 0, tableItem(character->getRaceName()));
	ui.raceTable->setItem(1, 0, tableItem(character->getSubRaceName()));

	ui.ageTable->setItem(1, 0, new QTableWidgetItem(character->details.getAge()));

	ui.sizeTable->setItem(0, 0, new QTableWidgetItem(character->details.getHeight()));
	ui.sizeTable->setItem(1, 0, new QTableWidgetItem(character->details.getWeight()));
}

void CharacterDisplay::initRaceBox(int index) {
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

	raceBox->setCurrentIndex(index);

	ui.raceTable->setCellWidget(0, 0, raceBox);
}

void CharacterDisplay::initGenderBox(int index) {
	QComboBox* genderBox = new QComboBox();
	genderBox->addItem(QString::fromLocal8Bit("男"));
	genderBox->addItem(QString::fromLocal8Bit("女"));

	genderBox->setCurrentIndex(index);

	ui.ageTable->setCellWidget(0, 0, genderBox);
}

void CharacterDisplay::initAligBox(int index) {
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

	aligBox->setCurrentIndex(index);

	ui.alignmentTable->setCellWidget(1, 0, aligBox);
}

void CharacterDisplay::setProBox() {
	auto proList = character->Ability()->getProList();
	auto i = proBoxList.begin();
	int abilityIndex = 0;
	for (; abilityIndex < 6; abilityIndex++) {
		(*i)->setCurrentIndex(proList[abilityIndex]);
	}

	proList = character->getSkillProList();
	int skillIndex = 0;
	for (; i != proBoxList.end(); i++) {
		(*i)->setCurrentIndex(proList[skillIndex++]);
	}
}

void CharacterDisplay::initHPContent() {
	auto item = tableItem("体型");
	ui.hpTable->setItem(0, 0, item);
	item = tableItem(character->getSizeString());
	ui.hpTable->setItem(0, 1, item);

	item = tableItem("速度");
	ui.hpTable->setItem(0, 2, item);
	item = tableItem(character->getSpeedString());
	ui.hpTable->setItem(0, 3, item);

	item = tableItem(character->_class.getspecialAbilityName());
	ui.hpTable->setItem(1, 0, item);
	item = tableItem(character->_class.getspecialAbilityString());
	ui.hpTable->setItem(1, 1, item);

	item = tableItem("临时HP");
	ui.hpTable->setItem(1, 2, item);
	item = tableItem(*(character->getHPdata() + 2));
	ui.hpTable->setItem(1, 3, item);

	item = tableItem("HP");
	ui.hpTable->setItem(2, 0, item);
	item = tableItem(character->getHPString());
	ui.hpTable->setItem(2, 1, item);

	item = tableItem("HD");
	ui.hpTable->setItem(3, 0, item);
}

void CharacterDisplay::initAbilityContent() {
	auto proList = character->Ability()->getProList();
	for (int i = 0; i < 6; i++) {
		ui.abilityTable->setCellWidget(i, 0, newProBox());
		auto item = tableItem(AbilityScore::abilityNameCh[i]);
		ui.abilityTable->setItem(i, 1, item);
		item = tableItem(character->Ability()->getAbilityScore(i));
		ui.abilityTable->setItem(i, 2, item);
		item = tableItem(character->Ability()->getAbilityModifier(i));
		ui.abilityTable->setItem(i, 3, item);
		if (proList[i]) {
			item = tableItem(character->Ability()->getAbilityModifier(i) + character->_class.getProBonus());
		}
		else
			item = tableItem(character->Ability()->getAbilityModifier(i));
		ui.abilityTable->setItem(i, 4, item);
	}
}

void CharacterDisplay::initBGContent() {
	auto list = character->details.getCharacteristics();
	for (int i = 0; i < 5; i++) {
		ui.characterDetailsTable->setItem(i, 1, tableItem(list[i]));
	}
	
	auto languageList = character->details.getLanguageList();
	int row = 0;
	for (auto i = languageList.begin(); i != languageList.end(); i++) {
		ui.languageTable->insertRow(row);
		ui.languageTable->setItem(row++, 0, tableItem(*i));
	}

	ui.appearanceText->setPlainText(character->details.getAppearance());
	ui.bgText->setPlainText(character->details.getBGStory());
}

void CharacterDisplay::initWealthTable() {
	auto wealth = character->characterWealth.getWealth();

	for (int i = 0; i < 5; i++) {
		ui.wealthTable->setItem(i, 0, new QTableWidgetItem(QString::number(wealth[i])));
	}
}