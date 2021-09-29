#include "disjointSet.h"
#include<unordered_map>
#include<unordered_set>
#include"graph.h"
using namespace std;
#include<iostream>
disjointSet::disjointSet(char maze[11][15],graph g)
{
	
	makeSet(g);
	int x,edgsSize=g.edges.size();
	int first, second;
	while (!g.edges.empty())
	{
		edgsSize = g.edges.size();
		x= (rand() % edgsSize) ;
		first=g.edges[x].first;
       second = g.edges[x].second;
	   unionSet(first, second,maze);
	   g.edges.erase(g.edges.begin()+x);
	   

	}
	
}
void disjointSet::makeSet(graph g)
{
	int i = 0;
	for(auto m : g.mazeGraph)
	{
		
		
		Node n ;
		n.val = m.first;
		n.rank = 0;
		
		sets[n.val]=n;
		tree[n.val].insert(n.val);
		
		i++;
	}
}

unordered_map<int, Node>::iterator disjointSet::findSet(int v)
{
	Node n;
	n.val = v;
	unordered_map<int, Node>::iterator it = sets.find(v);
	
	if (it->first != it->second.val)
	{
		
		
		it->second = findSet(it->second.val)->second;
	}
	
		return it;
}

void disjointSet::unionSet(int x, int y, char maze[11][15])
{
	unordered_map<int, Node>::iterator it = findSet(x);
	unordered_map<int, Node>::iterator it1 =findSet(y);
	if (it->second.val != it1->second.val)
	{
		int id;          //to get the id of the cell 

		int row, col;             //to get the position of the edge to be removed
		if (it->first == it1->first+2)
		{
			id = it1->first;
			col = id % 10;
			if (id >= 100)
			{
				row = 10;
			}
			else {
				id /= 10;

				row = id % 10;
			}
			if (row % 2 == 0)
			{
				col = 10 + col;
				row = row - 1;

			}
			maze[row][col+1] = ' '; // remove edge between the 2 cells;
			

		}
		else if (it->first == it1->first - 2)
		{
			id = it->first;
			col = id % 10;
			if (id >= 100)
			{
				row = 10;
			}
			else {
				id /= 10;

				row = id % 10;
			}
			if (row % 2 == 0)
			{
				col = 10 + col;
				row = row - 1;

			}
			maze[row][col+1] = ' ';
			
		}
		else if (it->first == it1->first+20)
		{
			id = it1->first;
			col = id % 10;
			if (id >= 100)
			{
				row = 10;
			}
			else {
				id /= 10;

				row = id % 10;
			}
			if (row % 2 == 0)
			{
				col = 10 + col;
				row = row - 1;

			}
			maze[row+1][col ] = ' ';
			
		}
		else
		{
	
		id = it->first;
		col = id % 10;
		if (id >= 100)
		{
			row = 10;
		}
		else {
			id /= 10;

			row = id % 10;
		}
		if (row % 2 == 0)
		{
			col = 10 + col;
			row = row - 1;

		}
		maze[row + 1][col] = ' ';
		
		}

		int parent, child,oldParent,rank;
		if (it->second.rank > it1->second.rank)
		{
			oldParent = it1->second.val;
			parent = it->second.val;
			rank = it->second.rank;
			child = it1->first;
			it1->second.val = it->second.val;
			it1->second.rank = it->second.rank;
		}
		else if(it->second.rank < it1->second.rank)
		{
			oldParent = it->second.val;
			parent = it1->second.val;
			rank = it1->second.rank;
			child = it->first;
			it->second.val = it1->second.val;
			it->second.rank = it1->second.rank;
		}
		else
		{
			oldParent = it->second.val;
			parent = it1->second.val;
			child = it->first;
			rank = it1->second.rank;
			it->second.val = it1->second.val;
			it->second.rank = it1->second.rank;
			it1->second.rank++; 
			
		}Node n;
		n.val = parent;
		n.rank = rank;
		//tree[parent].insert(child);
		
		for  (auto m : tree[oldParent])
		{
			tree[parent].insert(m);
			sets[m] = n;

		}
		//tree[parent].insert(oldParent);
		sets[oldParent] = n;
		tree.erase(oldParent);

	}


}
disjointSet::~disjointSet()
{
}
