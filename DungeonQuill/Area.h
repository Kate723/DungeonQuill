/*创建日期：2020/9/18
* 类名称：区域
* 类用途：存储法术影响/角色占据区域
* 作者：吴彤
*/

#pragma once
class Area
{
	enum AreaShape {
		CONE,		//锥状
		CUBE,		//立方
		CYLINDER,	//柱状
		LINE,		//线状
		SPHERE		//球状
	}shape;
	int size;		//区域大小，以尺为单位
public:
	Area(int sI, int s):
		shape((AreaShape)sI),size(s){}
};

