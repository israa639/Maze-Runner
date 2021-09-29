#pragma once
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;
#include<queue>
#include<unordered_set>
#include"graph.h"
class Maze
{

public:
	char maze[11][15];
	int startCell;
	int endCell;
	int startId, endId;
	queue<int>bfs;
	unordered_set<int>visited;

	Maze();
	~Maze();
	void MazeGenerator(graph g);
	void mazeSolver(graph g);
	void mazeSolution();
	

};