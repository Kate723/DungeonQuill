#include "CharacterButton.h"

CharacterButton::CharacterButton(CombatCharacter* _character) :
	character(_character)
{
	connect(this, SIGNAL(clicked()), this, SLOT(displayCharacter()));

	this->setMinimumSize(QSize(210, 140));

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

	characterText->setText(
		tr("<h3><font color = brown>%1<br>")
		.arg(character->getName()) 
	);	
}

void CharacterButton::displayCharacter()
{
	
}