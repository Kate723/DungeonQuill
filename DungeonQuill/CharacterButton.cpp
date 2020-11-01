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
		tr("<h4><font color = brown>%1<h2><font color = green>LV.%2</font>"
		   "<h5><font color = black>%3%4  %5  %6"
			"<h5>%7")
		.arg(adventurer->getName())
		.arg(adventurer->_class.getLV())
		.arg(adventurer->getRaceName())
		.arg(adventurer->getClassName())
		.arg(adventurer->details.getGender())
		.arg(adventurer->details.getAge())
		.arg(adventurer->details.getAlignment())
	);	
}

void CharacterButton::displayCharacter()
{
	auto characterWindow = new CharacterDisplay(adventurer);
	characterWindow->setWindowModality(Qt::ApplicationModal);
	characterWindow->show();
}