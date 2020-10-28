#include "Adventurer.h"

QString Adventurer::getRaceName() {
	if (!race.getSubRaceName().isEmpty())
		return race.getSubRaceName();
	return race.getRaceName();
}

QString Adventurer::getClassName() {
	return _class._classInfo.getName();
}