#include "CharacterButton.h"

CharacterButton::CharacterButton(CombatCharacter* _chatacter)
{
	connect(this, SIGNAL(clicked()), this, SLOT(displayCharacter()));

	this->setMinimumSize(QSize(180, 120));

	setCharacterText();

	QHBoxLayout* hLayout = new QHBoxLayout();
	hLayout->addWidget(characterText);

	this->setLayout(hLayout);
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