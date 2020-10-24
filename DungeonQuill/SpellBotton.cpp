#include "SpellBotton.h"
#include <qdebug.h>

SpellBotton::SpellBotton(Spell* _spell) : spell(_spell)
{
	connect(this, SIGNAL(clicked()), this, SLOT(displaySpell()));
	qDebug() << "init";
	this->setMinimumSize(QSize(200,140));
	this->setText(QString::fromLocal8Bit("酸液飞溅 Acid Splash\n咒法 戏法"));
}

SpellBotton::~SpellBotton()
{

}

void SpellBotton::displaySpell() {
	auto displayWindow = new SpellDisplay(spell);
	displayWindow->setWindowModality(Qt::ApplicationModal);
	displayWindow->show();

}