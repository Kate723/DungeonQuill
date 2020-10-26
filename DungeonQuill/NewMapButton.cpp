#include "NewMapButton.h"
#include <qdebug.h>

NewMapButton::NewMapButton()
{
	ui.setupUi(this);
	qDebug() << "button set up";
	connect(this, SIGNAL(clicked()), this, SLOT(newMapEditor()));
}

NewMapButton::~NewMapButton()
{
}

void NewMapButton::newMapEditor() {
	qDebug() << "button clicked";
	auto mapEditor = new MapEditor();
	mapEditor->setWindowModality(Qt::ApplicationModal);
	mapEditor->show();
}
