#include "DisplayButton.h"

DisplayButton::DisplayButton()
{
	this->setMinimumSize(QSize(210, 140));

	//设置格式
	displayText = new QTextBrowser();
	displayText->setStyleSheet("background-color:transparent");			//背景色透明
	displayText->setAttribute(Qt::WA_TransparentForMouseEvents, true);	//不接受鼠标事件
	displayText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	displayText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);	//关闭滚动条

	//将文本显示器插入按钮中
	QGridLayout* gLayout = new QGridLayout();
	gLayout->addWidget(displayText);

	this->setLayout(gLayout);
}

DisplayButton::~DisplayButton()
{
}

void DisplayButton::setDisplayText() {

}
