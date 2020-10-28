#include "CombatManager.h"

CombatManager* CombatManager::instance = NULL;

CombatManager::CombatManager() :
	map(nullptr), combatWin(nullptr), actionQueue(std::queue < CombatPiece*>()), conditionFlag(CombatCondition::IDIE)
{
	if (instance) {
		delete this;
		return;
	}
}

CombatManager::~CombatManager()
{
}

void CombatManager::combatStart(CombatMap* _map, MapEditor* _combatWin) {
	instance->map = _map;
	instance->combatWin = _combatWin;

	auto combatQueueArea = new QScrollArea();
	combatQueueArea->setFrameStyle(0);
	instance->combatWin->ui.groupBox->layout()->addWidget(combatQueueArea);

	auto combatEndButton = new QPushButton();
	combatEndButton->setText(QString::fromLocal8Bit("结束战斗"));
	combatEndButton->setMinimumHeight(40);
	instance->combatWin->ui.groupBox->layout()->addWidget(combatEndButton);
	connect(combatEndButton, SIGNAL(clicked()), instance, SLOT(combatEnd()));

	instance->combatWin->show();
	instance->conditionFlag = CHARACTER_CHOOSE;
}

void CombatManager::combatEnd() {
	instance->combatWin->close();
	delete instance->combatWin;
	instance->conditionFlag = CombatCondition::IDIE;
}