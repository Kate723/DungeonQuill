﻿#include "SpellBotton.h"
#include <qdebug.h>

SpellBotton::SpellBotton(Spell* _spell) : spell(_spell)
{
	connect(this, SIGNAL(clicked()), this, SLOT(displaySpell()));
	
	this->setMinimumSize(QSize(180,120));

	setSpellText();

	//将文本显示器插入按钮中
	QHBoxLayout* hLayout = new QHBoxLayout();
	hLayout->addWidget(spellText);
	this->setLayout(hLayout);
}

SpellBotton::~SpellBotton()
{

}

void SpellBotton::setSpellText() {
	//设置格式
	spellText = new QTextBrowser();
	spellText->setStyleSheet("background-color:transparent");			//背景色透明
	spellText->setAttribute(Qt::WA_TransparentForMouseEvents, true);	//不接受鼠标事件

	//设置内容
	std::string spellInfo = spell->getLevelString() + ' ' + spell->getSchoolName();
	spellText->setText( 
		tr("<h3><font color = brown>%1<br>%2</font>"
		"<h4>%3")
		.arg(QString::fromLocal8Bit(spell->getNameCH().c_str()))
		.arg(QString::fromLocal8Bit(spell->getNameEN().c_str()))
		.arg(QString::fromLocal8Bit(spellInfo.c_str())) );
}

//槽函数，弹出法术信息窗口
void SpellBotton::displaySpell() {
	auto displayWindow = new SpellDisplay(spell);
	displayWindow->setWindowModality(Qt::ApplicationModal);
	displayWindow->show();
}