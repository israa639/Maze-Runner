#pragma once
#include<unordered_map>
#include<unordered_set>
#include "graph.h"
using namespace std;
struct Node {

	int val;
	int rank;

};
class disjointSet
{

public:
	unordered_map<int, Node>sets;         //unordered map to store the value of node  as a key and its parent Node as a value

	unordered_map<int, unordered_set<int>>tree;//to store the children for each node

	
	disjointSet(char maze[11][15],graph g);
	
	void makeSet(graph g);
	unordered_map<int, Node>::iterator findSet(int);
	void unionSet(int, int, char maze[11][15]);
	~disjointSet();
};

