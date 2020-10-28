#include "CharacterButton.h"

CharacterButton::CharacterButton(Adventurer* _character) :
	adventurer(_character)
{
	connect(this, SIGNAL(clicked()), this, SLOT(displayCharacter()));

	setDisplayText();
}

CharacterButton::~CharacterButton()
{
}

void CharacterButton::setDisplayText()
{
	displayText->setText(
		tr("<h3><font color = brown>%1<br>")
		.arg(adventurer->getName()) 
	);	
}

void CharacterButton::displayCharacter()
{
	auto characterWindow = CharacterDisplay(adventurer);
	characterWindow.setWindowModality(Qt::ApplicationModal);
	characterWindow.show();
}