#include "Equipment.h"

Equipment::Equipment(int ID, std::string name, std::string remark, EquipemntType type):
	equipmentInfo(ID,name,remark), equipmentType(type){}

int Equipment::getID() {
	return this->equipmentInfo.id;
}

std::string Equipment::getName() {
	return this->equipmentInfo.name;
}

std::string Equipment::getRemarks() {
	return this->equipmentInfo.remarks;
}