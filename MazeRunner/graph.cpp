#include "graph.h"
#include<unordered_map>
#include<unordered_set>

graph::graph()
{
}
void graph::graphBuilder(char maze[11][15])
{
	
	int x;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (maze[i][j] == ' ')
			{
				x = 10 * i + j;
				if (i == 1 && j == 1)
				{
					
					mazeGraph[x].insert(x + 2);
					edges.push_back(make_pair( x,x + 2));
					mazeGraph[x].insert(x + 20);
					edges.push_back(make_pair(x, x + 20));

				}
				else if (i == 9 && j == 1)
				{
					mazeGraph[x].insert(x + 2);
					edges.push_back(make_pair(x, x + 2));
					mazeGraph[x].insert(x - 20);
					
				}
				else if (j == 13 && i == 1)
				{
					mazeGraph[x].insert(x - 2);
					
					mazeGraph[x].insert(x + 20);
					edges.push_back(make_pair(x, x + 20));
				}
				else if (j == 13 && i == 9)
				{
					mazeGraph[x].insert(x - 2);
				
					mazeGraph[x].insert(x -20);
					
				}
				else if (i == 1)
				{
					mazeGraph[x].insert(x + 2);
					edges.push_back(make_pair(x, x + 2));
					mazeGraph[x].insert(x + 20);
					edges.push_back(make_pair(x, x + 20));
					mazeGraph[x].insert(x -2);
					
					
				}
				else if (i == 9)
				{
					mazeGraph[x].insert(x + 2);
					edges.push_back(make_pair(x, x + 2));
					mazeGraph[x].insert(x - 20);
				
					mazeGraph[x].insert(x - 2);
					

				}
				else if (j == 1)
				{
					mazeGraph[x].insert(x + 2);
					edges.push_back(make_pair(x, x + 2));
					mazeGraph[x].insert(x + 20);
					edges.push_back(make_pair(x, x + 20));
					mazeGraph[x].insert(x - 20);
					
				}
				else if (j == 13)
				{
					mazeGraph[x].insert(x - 2);
					
					mazeGraph[x].insert(x + 20);
					edges.push_back(make_pair(x, x + 20));
					mazeGraph[x].insert(x - 20);
					

				}
				else
				{
					mazeGraph[x].insert(x + 2);
					edges.push_back(make_pair(x, x + 2));
					mazeGraph[x].insert(x - 2);
					
					mazeGraph[x].insert(x + 20);
					edges.push_back(make_pair(x, x + 20));
					mazeGraph[x].insert(x - 20);
					
				}
				
			}
		}
	}
}


graph::~graph()
{
}
