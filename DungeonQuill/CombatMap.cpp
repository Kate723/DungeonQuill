#include "CombatMap.h"

int CombatMap::mapNum = 0;
std::vector<CombatMap*> CombatMap::mapList = std::vector<CombatMap*>();

CombatMap::CombatMap() :
	mapInfo(0, "New Map", std::string()), piecesNum(0), piecesList(NULL)
{
	if (!mapList.empty())
		mapInfo.id = mapList.back()->mapInfo.id++;
	else
		mapInfo.id = 100;

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			grid[i][j] = GridTag::Flat;
		}
	}
}

CombatMap::CombatMap(int id, std::string& name, std::string& remark, 
	GridTag mapGrid[MAX_SIZE][MAX_SIZE], int num, std::vector<int> picecs) :
	mapInfo(id, name, remark), piecesNum(num) 
{
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			grid[i][j] = mapGrid[i][j];
		}
	}
	

}