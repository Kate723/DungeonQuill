#include "MapButton.h"

MapButton::MapButton(CombatMap* _map) :
	map(_map)
{
	connect(this, SIGNAL(clicked()), this, SLOT(selectMap()));

	setDisplayText();
}

MapButton::~MapButton()
{
}

void MapButton::setDisplayText()
{
	//设置内容
	QString mapInfo = map->mapInfo.getName();
	displayText->setText(
		tr("<h3><font color = brown>%1<br>")
		.arg(mapInfo) );
	displayText->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

void MapButton::selectMap() {
	auto option = QMessageBox::question(NULL, 
		map->mapInfo.getName(), QString::fromLocal8Bit("开始战斗？"), 
		QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

	if (option == QMessageBox::Yes) {
		DungeonQuill::combatStart(map);
	}
}
