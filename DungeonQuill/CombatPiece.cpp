#include "CombatPiece.h"

CombatPiece::CombatPiece(Adventurer* _character) :
	pieceInfo(_character->getID(),_character->getName().toStdString()), character(_character)
{

}