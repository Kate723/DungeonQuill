#include "CombatMap.h"

CombatMap::CombatMap(int id, std::string& name, std::string& remark, 
	GridTag mapGrid[MAX_SIZE][MAX_SIZE], int num, std::vector<CombatPiece*> picecs) :

	mapInfo(id, name, remark), piecesNum(num),piecesList(picecs) 
{
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			grid[i][j] = mapGrid[i][j];
		}
	}
	

}