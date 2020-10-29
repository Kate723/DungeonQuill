#include "DiceMaid.h"

DiceMaid* DiceMaid::instance = nullptr;

DiceMaid::DiceMaid(DungeonQuill* mainWindow) :
	ui(&mainWindow->ui)
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

	ui->diceNumSpinBox->setValue(1);
	ui->diceSideSpinBox->setValue(20);
}

void DiceMaid::diceRollButtonClicked() {
	int diceNum = ui->diceNumSpinBox->value();
	int diceSide = ui->diceSideSpinBox->value();
	if (diceNum <= 0 ||diceSide <= 0) return;

	QString resString = QString();
	int resSum = 0;
	for (int i = 0; i < diceNum; i++) {
		auto dice = new DiceRollType(10, 0, diceSide);
		auto rollResult = diceRoll(dice);
		
		for (int j = 0; j < 10; j++) {
			ui->diceRollText->setText(resString + QString::number(rollResult[j]));
			ui->diceRollText->setAlignment(Qt::AlignCenter);
			sleep(50);
		}
		resSum += rollResult[9];
		resString += QString::number(rollResult[9]);
		if(i != (diceNum - 1))
			resString += QString::fromLocal8Bit("+");
	}
	if (diceNum > 1) {
		resString += QString::fromLocal8Bit("=");
		sleep(100);
		ui->diceRollText->setText(resString);
		ui->diceRollText->setAlignment(Qt::AlignCenter);

		resString += QString::number(resSum);
		sleep(100);
		ui->diceRollText->setText(resString);
		ui->diceRollText->setAlignment(Qt::AlignCenter);
	}
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
