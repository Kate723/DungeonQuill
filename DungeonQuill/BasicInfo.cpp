#include "BasicInfo.h"

BasicInfo::BasicInfo(int tid,std::string tname, std::string tremarks):
	id(tid), name(tname), remarks(tremarks) {}

QString BasicInfo::getName() {
	return QString::fromLocal8Bit(name.c_str());
}