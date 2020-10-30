#include "InitiativeRoll.h"

InitiativeRoll::InitiativeRoll(std::vector<Adventurer*> characterList)
{
	ui.setupUi(this);

	CharacterDisplay::initTableFormat(ui.initTable);
	ui.initTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

	int row = 0;
	for (auto i = characterList.begin(); i != characterList.end(); i++) {
		DiceMaid::initiativeRoll(*i);

		ui.initTable->insertRow(row);
		ui.initTable->setItem(row, 0, CharacterDisplay::tableItem((*i)->getName()));
		ui.initTable->setItem(row++, 1, CharacterDisplay::tableItem((*i)->getInitiativeString()));
	}

	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(close()));
}

InitiativeRoll::~InitiativeRoll()
{
}
