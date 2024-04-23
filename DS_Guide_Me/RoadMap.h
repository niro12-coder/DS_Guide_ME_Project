#pragma once
#include<string>
#include<list>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include <sstream>
using namespace std;

struct Tranporation 
{
	// data members
	string destination="";
	string vechile="";
	double price=0.0;
};


class RoadMap
{

private:
	// datamembers
	
	//      key=> name of source & value=> vector (transporation(source,destination,cost))  
	unordered_map<string, vector <Tranporation> > map;

public:
	// constructors
		
	RoadMap();  // read map

	// methods


	// WRITE YOUR METHODS HERE, THEN IMPLEMENT THEM IN .CPP FILE 

	bool isComplete();

};

