#include "CombatManager.h"

CombatManager* CombatManager::instance = nullptr;

CombatManager::CombatManager() :
	map(nullptr), combatWin(nullptr), combatQueueArea(nullptr),
	actionQueue(std::queue < CombatPiece*>()), conditionFlag(CombatCondition::IDIE)
{
	if (instance) {
		delete this;
		return;
	}

	instance = this;
}

CombatManager::~CombatManager()
{
}

void CombatManager::combatStart(CombatMap* _map, MapEditor* _combatWin) {
	instance->map = _map;
	instance->combatWin = _combatWin;

	instance->combatQueueArea = new QScrollArea();
	instance->combatQueueArea->setFrameStyle(0);
	instance->combatQueueArea->setMinimumWidth(220);
	instance->combatWin->ui.groupBox->layout()->addWidget(instance->combatQueueArea);

	auto combatEndButton = new QPushButton();
	combatEndButton->setText(QString::fromLocal8Bit("结束战斗"));
	combatEndButton->setMinimumHeight(40);
	instance->combatWin->ui.groupBox->layout()->addWidget(combatEndButton);
	connect(combatEndButton, SIGNAL(clicked()), instance, SLOT(combatEnd()));

	instance->combatWin->show();
	instance->conditionFlag = CHARACTER_CHOOSE;

	auto chooseWin = new CharacterChoose();
	chooseWin->setWindowModality(Qt::ApplicationModal);
	chooseWin->show();
}

void CombatManager::characterSelected(std::vector<Adventurer*> characterList) {
	auto initiativeWindow = new InitiativeRoll(characterList);
	initiativeWindow->setWindowModality(Qt::ApplicationModal);
	initiativeWindow->show();

	instance->characterSort(characterList);
}

void CombatManager::characterSort(std::vector<Adventurer*> characterList) {
	initQuickSort(characterList, 0, characterList.size() - 1);

	initQueue(characterList);
}

void CombatManager::initQuickSort(std::vector<Adventurer*> &characterList, int begin, int end) {
	if (begin >= end) 
		return;
	auto key = characterList[begin];
	int i = begin;
	int j = end;
	while (i < j) {
		while (i < j && key->compareInitiative(characterList[j])) {
			j--;
		}
		if (i < j) {
			characterList[i] = characterList[j];
			i++;
		}
		while (i < j && characterList[i]->compareInitiative(key)) {
			i++;
		}
		if (i < j) {
			characterList[j] = characterList[i];
			j--;
		}
	}

	characterList[i] = key;
	initQuickSort(characterList, begin, i - 1);
	initQuickSort(characterList, i + 1, end);
}

void CombatManager::initQueue(std::vector<Adventurer*> characterList) {
	auto scrollWidget = new QWidget();
	auto vLayout = new QVBoxLayout();

	for (auto i = characterList.begin(); i != characterList.end(); i++) {
		actionQueue.push(new CombatPiece(*i));

		vLayout->addWidget(new CharacterButton(*i));
	}

	scrollWidget->setLayout(vLayout);
	instance->combatQueueArea->setWidget(scrollWidget);
}


void CombatManager::combatEnd() {
	instance->combatWin->close();
	delete instance->combatWin;
	instance->conditionFlag = CombatCondition::IDIE;
}

CombatCondition CombatManager::getCombatCondition() {
	return instance->conditionFlag;
}

void CombatManager::setCombatCondition(CombatCondition condition) {
	instance->conditionFlag = condition;
}