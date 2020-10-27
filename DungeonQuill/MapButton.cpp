#include "MapButton.h"

MapButton::MapButton(CombatMap* _map) :
	map(_map)
{
	connect(this, SIGNAL(clicked()), this, SLOT(selectMap()));

	this->setMinimumSize(QSize(180, 120));

	setMaptext();

	QGridLayout* gLayout = new QGridLayout();
	gLayout->addWidget(mapText);

	this->setLayout(gLayout);
}

MapButton::~MapButton()
{
}

void MapButton::setMaptext() 
{
	//设置格式
	mapText = new QTextBrowser();
	mapText->setStyleSheet("background-color:transparent");			//背景色透明
	mapText->setAttribute(Qt::WA_TransparentForMouseEvents, true);	//不接受鼠标事件

	//设置内容
	QString mapInfo = map->mapInfo.getName();
	mapText->setText(
		tr("<h3><font color = brown>%1<br>")
		.arg(mapInfo) );
	mapText->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

void MapButton::selectMap() {
	auto editWindow = new MapEditor(map);
	editWindow->setWindowModality(Qt::ApplicationModal);
	editWindow->show();
}
