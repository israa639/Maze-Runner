#include"unordered_map"
#include"unordered_set"
#include<vector>
using namespace std;
#pragma once

class graph
{
	
public:
	
	
	unordered_map< int, unordered_set<int>> mazeGraph;
	vector<pair<int, int>>edges;
	graph();
	void graphBuilder(char maze[11][15]);
	~graph();
};

