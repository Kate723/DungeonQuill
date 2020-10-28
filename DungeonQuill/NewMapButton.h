#pragma once

#include "DisplayButton.h"
#include "MapEditor.h"

class NewMapButton : public DisplayButton
{
	Q_OBJECT
	virtual void setDisplayText();

public slots:
	void newMapEditor();

public:
	NewMapButton();
	~NewMapButton();
};
