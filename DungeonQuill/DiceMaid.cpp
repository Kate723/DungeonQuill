#include "DiceMaid.h"


DiceMaid* DiceMaid::instance = nullptr;

DiceMaid::DiceMaid() :
	ui(&DungeonQuill::instance->ui)
{
	if (instance) {
		delete this;
		return;
	}

	instance = this;
	connect(ui->diceRollButton, SIGNAL(clicked()), instance, SLOT(diceRollButtonClicked()));

	initDiceTab();
}

DiceMaid::~DiceMaid()
{
}

void DiceMaid::initDiceTab() {
	ui->diceMaidText->setAlignment(Qt::AlignCenter);
	ui->diceRollText->setAlignment(Qt::AlignCenter);
}

void DiceMaid::diceRollButtonClicked() {
	int diceNum = ui->diceNumSpinBox->value();
	int diceSide = ui->diceSideSpinBox->value();
	if (diceNum <= 0 ||diceSide <= 0) return;

	auto dice = new DiceRollType(diceNum, 0, diceSide);
	auto rollResult = diceRoll(dice);

	QString resString = QString::number(*rollResult);
	for (int i = 1; i < diceNum; i++) {
		resString += QString::fromLocal8Bit("+") + QString::number(rollResult[i]);
	}
	if (diceNum > 1) {
		resString += QString::fromLocal8Bit("=") + QString::number(rollResult[diceNum]);
	}

	ui->diceRollText->setText(resString);
	ui->diceRollText->setAlignment(Qt::AlignCenter);
}

int* DiceMaid::diceRoll(DiceRollType* dice) {
	if (dice->diceNum <= 0 || dice->diceSideNum <= 0) return nullptr;

	std::random_device rd;			//真随机数生成器生成种子
	std::mt19937 eng(rd());			// 使用梅森旋转法作为伪随机数生成器
	std::uniform_int_distribution<int> dis(1, dice->diceSideNum); //整数均匀分布

	auto diceList = (int *)malloc(sizeof(int) * ((size_t)dice->diceNum + (size_t)1));
	if(!diceList) return nullptr;

	int res = 0;
	for (auto i = diceList; i < diceList + dice->diceNum; i++) {
		*i = dis(eng);
		res += *i;
	}
	diceList[dice->diceNum] = res;

	return diceList;
}

void DiceMaid::sleep(int msec) {
	QTime reachTime = QTime::currentTime().addMSecs(msec);

	while (QTime::currentTime() < reachTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents);
}
