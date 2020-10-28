#include "AdventurerRace.h"

QString AdventurerRace::getRaceName() {
	return QString::fromStdString(name);
}

QString AdventurerRace::getSubRaceName() {
	return QString::fromStdString(subName);
}