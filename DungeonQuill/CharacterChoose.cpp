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
}

CharacterChoose::~CharacterChoose()
{
}
