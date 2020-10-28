#include "CharacterDetails.h"

QString CharacterDetails::getGender() {
	if (sex)
		return QString::fromLocal8Bit("男");
	return QString::fromLocal8Bit("女");
}

QString CharacterDetails::getAge() {
	return QString::number(age) + QString::fromLocal8Bit("岁");
}

QString CharacterDetails::getAlignment() {
	switch (alignment)
	{
	case Aligment::LG:
		return QString::fromLocal8Bit("守序善良");
		break;
	case Aligment::NG:
		return QString::fromLocal8Bit("中立善良");
		break;
	case Aligment::CG:
		return QString::fromLocal8Bit("混乱善良");
		break;
	case Aligment::LN:
		return QString::fromLocal8Bit("守序中立");
		break;
	case Aligment::TN:
		return QString::fromLocal8Bit("绝对中立");
		break;
	case Aligment::CN:
		return QString::fromLocal8Bit("混乱中立");
		break;
	case Aligment::LE:
		return QString::fromLocal8Bit("守序邪恶");
		break;
	case Aligment::NE:
		return QString::fromLocal8Bit("中立邪恶");
		break;
	case Aligment::CE:
		return QString::fromLocal8Bit("混乱邪恶");
		break;
	default:
		break;
	}
	return NULL;
}