#include "Amour.h"

Amour::Amour(int ID, std::string name, std::string remark, AmourType type, int tbasicAC, int strength) :
	Equipment(ID, name, remark, EquipemntType::AMOUR), type(type), basicAC(tbasicAC),strengthLimit(strength) {}