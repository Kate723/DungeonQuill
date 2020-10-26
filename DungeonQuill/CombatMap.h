/*创建日期：2020/9/18
* 类名称：战斗地图
* 类用途：存储战斗所需地形图
* 作者：吴彤
*/

#pragma once
#include <string>
#include <vector>
#include "BasicInfo.h"
#include "CombatPiece.h"

constexpr auto MAX_SIZE = 300;

class MapEditor;

class CombatMap
{
	

	enum GridTag {
		Barrier,
		Flat,
		Difficult,
		Piece,
		Tag
	}grid[MAX_SIZE][MAX_SIZE];			//格子标记

	int piecesNum;							//棋子数目
	std::vector<CombatPiece*> piecesList;	//棋子列表

public:
	BasicInfo mapInfo;					//地图基本信息
	static int mapNum;					//存储地图数量
	static std::vector<CombatMap*> mapList;	//存储地图列表

	CombatMap();
	CombatMap(int id, std::string& name, std::string& remark,						//构造函数
		GridTag mapGrid[MAX_SIZE][MAX_SIZE], int num, std::vector<int> picecs);	

	friend MapEditor;
};

