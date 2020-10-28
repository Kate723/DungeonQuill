#include "BasicInfo.h"

BasicInfo::BasicInfo(int tid,std::string tname, std::string tremarks):
	id(tid), name(tname), remarks(tremarks) {}

QString BasicInfo::getName() {
	return QString::fromUtf8(name.c_str());
}