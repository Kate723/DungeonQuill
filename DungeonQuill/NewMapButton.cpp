#include "NewMapButton.h"

NewMapButton::NewMapButton()
{
	connect(this, SIGNAL(clicked()), this, SLOT(newMapEditor()));

	setDisplayText();
}

NewMapButton::~NewMapButton()
{
}

void NewMapButton::setDisplayText() {
	//设置内容
	displayText->setText(
		tr("<font style = 'font-family:SimHei; font-size:72pt;'>+</font>")
		);
	displayText->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

void NewMapButton::newMapEditor() {
	auto mapEditor = new MapEditor();
	mapEditor->setWindowModality(Qt::ApplicationModal);
	mapEditor->show();
}
