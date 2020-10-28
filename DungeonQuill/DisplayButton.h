#pragma once

#include <QToolButton>
#include <qtextbrowser.h>
#include <qlayout.h>

class DisplayButton : public QToolButton
{
	Q_OBJECT
	virtual void setDisplayText();

protected:
	QTextBrowser* displayText;

public:
	DisplayButton();
	~DisplayButton();	
};
