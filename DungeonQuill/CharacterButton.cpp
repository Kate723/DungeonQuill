#include "CharacterButton.h"

CharacterButton::CharacterButton(CombatCharacter* _character) :
	character(_character)
{
	connect(this, SIGNAL(clicked()), this, SLOT(displayCharacter()));

	this->setMinimumSize(QSize(180, 120));

	setCharacterText();

	QGridLayout* gLayout = new QGridLayout();
	gLayout->addWidget(characterText);

	this->setLayout(gLayout);
}

CharacterButton::~CharacterButton()
{
}

void CharacterButton::setCharacterText() 
{
	characterText = new QTextBrowser();
	characterText->setStyleSheet("background-color:transparent");
	characterText->setAttribute(Qt::WA_TransparentForMouseEvents, true);

	//characterText->setText(
		//tr());	
}

void CharacterButton::displayCharacter()
{
	
}