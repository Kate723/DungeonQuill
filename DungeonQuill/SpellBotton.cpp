#include "SpellBotton.h"

SpellBotton::SpellBotton(Spell* _spell) : spell(_spell)
{
	if (!spell) {
		delete this;
		return;
	}
	connect(this, SIGNAL(clicked()), this, SLOT(displaySpell()));

	setDisplayText();
}

SpellBotton::~SpellBotton()
{

}

void SpellBotton::setDisplayText() {
	//设置内容
	QString spellInfo = spell->getLevelString() + ' ' + spell->getSchoolName();
	displayText->setText( 
		tr("<h3><font color = brown>%1<br>%2</font>"
		"<h4>%3")
		.arg(spell->getNameCH())
		.arg(spell->getNameEN())
		.arg(spellInfo));
	displayText->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

//槽函数，弹出法术信息窗口
void SpellBotton::displaySpell() {
	auto displayWindow = new SpellDisplay(spell);
	displayWindow->setWindowModality(Qt::ApplicationModal);
	displayWindow->show();
}