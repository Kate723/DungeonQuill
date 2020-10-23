/*创建日期：2020/9/18
* 类名称：区域
* 类用途：存储法术影响/角色占据区域
* 作者：吴彤
*/

#pragma once
class Area
{
	int shapeID;	//形状编号，0锥状，1立方，2柱状，3线状，4球状
	int size;		//区域大小，以尺为单位
public:
	Area(int sI, int s):
		shapeID(sI),size(s){}
};

