#include "Amour.h"

Amour::Amour(int ID, std::string name, std::string remark, AmourType type, int strength) :
	Equipment(ID, name, remark, EquipemntType::AMOUR), type(type), strengthLimit(strength) {}