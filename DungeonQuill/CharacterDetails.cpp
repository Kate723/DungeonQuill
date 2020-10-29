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

QString CharacterDetails::getHeight() {
	return QString::number(height.feet) + "\'" + QString::number(height.inch) +"\'\'";
}

QString CharacterDetails::getWeight() {
	return QString::number(weight);
}

QString* CharacterDetails::getCharacteristics() {
	QString characteristicsList[] = { QString::fromStdString(characteristics.trait[0]),
		QString::fromStdString(characteristics.trait[1]), QString::fromStdString(characteristics.ideal),
		QString::fromStdString(characteristics.bond), QString::fromStdString(characteristics.flaw) };

	return characteristicsList;
}

QString CharacterDetails::getAppearance() {
	return QString::fromStdString(apperance);
}

QString CharacterDetails::getBGStory() {
	return QString::fromStdString(bgStory);
}

std::vector<std::string> CharacterDetails::getLanguageList() {
	return languageList;
}

bool CharacterDetails::isMale() {
	return sex;
}

int CharacterDetails::getAlignmentID() {
	return alignment;
}