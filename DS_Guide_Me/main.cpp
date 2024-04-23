#include<iostream>
#include"RoadMap.h"
using namespace std;

int main()
{

	RoadMap* road = new RoadMap();

	cout << road->isComplete() << endl;

	return 0;
}