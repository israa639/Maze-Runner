#include "Maze.h"
#include"disjointSet.h"
#include<iostream>
Maze::Maze()
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < 11; i++)
	{
		x = 0; y = 0;
		if (i % 2 == 0)
		{
			x = 1;

		}
		else
		{
			y = 1;
		}
		for (int j = 0; j < 15; j++)
		{
			if (x == 1)
			{
				if (j % 2 == 0)
				{
					maze[i][j] = '+';
				}
				else
				{
					maze[i][j] = '-';
				}
			}
			else if (y == 1)
			{
				if (j % 2 == 0)
				{
					maze[i][j] = '|';
				}
				else
				{
					maze[i][j] = ' ';
				}
			}
			
		}
		
		
	}
	
}

void Maze::mazeSolver(graph g) {

	unordered_set<int>inBfs; //to check if the cell already in the queue or not;
	unordered_map<int, int>backtrack; //will be used when backtracking to get the path
	bfs.push(startId);
	inBfs.insert(startId);
	int cell; int id, row, col;
	while (!bfs.empty())
	{
		cell = bfs.front();
		bfs.pop();
		visited.insert(cell);
		if (cell != endId)
		{
		for (auto m : g.mazeGraph[cell])
		{
			unordered_set<int>::iterator it = visited.find(m);
			if (it == visited.end()) {
				id = cell;
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
				if (m == cell + 2)
				{
					if (maze[row ][col+1] == ' ')
					{
						if (inBfs.find(m) == inBfs.end())
						{
							bfs.push(m);
							inBfs.insert(m);
							backtrack[m] = cell;
						}
					}
				}
				else if (m == cell - 2)
				{
					if (maze[row ][col-1] == ' ')
					{
						if (inBfs.find(m) == inBfs.end())
						{
							bfs.push(m);
							inBfs.insert(m);
							backtrack[m] = cell;
						}
					}
				}
				else if (m == cell - 20)
				{
					if (maze[row -1][col] == ' ')
					{
						if (inBfs.find(m) == inBfs.end())
						{
							bfs.push(m);
							inBfs.insert(m);
							backtrack[m] = cell;
						}
					}
				}
				else
				{
					if (maze[row + 1][col] == ' ')
					{
						if (inBfs.find(m) == inBfs.end())
						{
							bfs.push(m);
							inBfs.insert(m);
							backtrack[m] = cell;
						}
					}
				}
			}
		}
		}
		
	}
	unordered_map<int, int>::iterator iteratr = backtrack.find(endId);
	while (iteratr!= backtrack.find(startId))
	{
		id = iteratr->second;
		iteratr = backtrack.find(id);
		if (id != startId) {
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
			maze[row][col] = '#';
		}
		
	}



}
void  Maze::mazeSolution() {

	

	for (int i = 0; i < 11; i++)
	{

		for (int j = 0; j < 15; j++)
		{


			cout << maze[i][j];
		}cout << endl;
	}






}
void Maze::MazeGenerator(graph g)
{
	disjointSet ds(maze,g);
	srand(time(0));
	srand(time(0));
	startCell = 2*(rand() % 4)+1;
	
	endCell= 2*(rand() % 4)+1;

	maze[1][startCell] = '*';
	maze[9][endCell] = 'o';
	startId = 10 + startCell;
	endId = 90 + endCell;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << maze[i][j];


		}
		cout << endl;
	}








}




Maze::~Maze() {}
