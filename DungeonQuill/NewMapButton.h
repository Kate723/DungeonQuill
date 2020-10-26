#pragma once

#include <qtoolbutton.h>
#include "MapEditor.h"
#include "ui_NewMapButton.h"

class NewMapButton : public QToolButton
{
	Q_OBJECT

public slots:
	void newMapEditor();

public:
	NewMapButton();
	~NewMapButton();

private:
	Ui::NewMapButton ui;
};
