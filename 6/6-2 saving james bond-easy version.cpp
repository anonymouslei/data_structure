#include <iostream>
#include <vector>
// 不用建图，直接把点存起来就可以。反正每次都要和所有的点算距离
// 每次还要算是否到边界
// the center island is a disk centered at 
// (0.0) with the diameter of 15

class savingJamesBondEasy
{
public:
	savingJamesBondEasy();
	~savingJamesBondEasy();
	void DFS();

private:
	std::vector<std::vector<int>> vertex;
	
};