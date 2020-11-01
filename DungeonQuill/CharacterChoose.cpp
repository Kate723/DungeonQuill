#include "CharacterChoose.h"

CharacterChoose::CharacterChoose()
{
	ui.setupUi(this);
	auto vLayout = new QVBoxLayout();

	for (auto i = Adventurer::adventurerList.begin(); i != Adventurer::adventurerList.end(); i++) {
		auto checkBox = new QCheckBox();
		checkBox->setText((*i)->getName());

		checkBoxList.push_back(checkBox);
		vLayout->addWidget(checkBox);
	}

	vLayout->addStretch();
	ui.chooseArea->setLayout(vLayout);

	connect(ui.selectButton, SIGNAL(clicked()), this, SLOT(characterSelected()));
}

CharacterChoose::~CharacterChoose()
{
}

void CharacterChoose::characterSelected() {
	std::vector<Adventurer*> selectList;
	auto character = Adventurer::adventurerList.begin();
	for (auto i = checkBoxList.begin(); i != checkBoxList.end(); i++,character++) {
		if (!(*i)->isChecked()) continue;
		selectList.push_back(*character);
	}

	CombatManager::characterSelected(selectList);

	close();
}
