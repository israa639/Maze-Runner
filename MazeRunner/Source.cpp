#include<iostream>
#include "Maze.h"
#include"graph.h"
using namespace std;
int main()
{


	int check=0;
	
	do {
		Maze  m;
		graph g;
		g.graphBuilder(m.maze);
		m.MazeGenerator(g);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		m.mazeSolver(g);
		m.mazeSolution();
		cout << "do you want to solve another maze ?press 1 if yes 2 if else" << endl;
		
		cin >> check;
	} while (check == 1);
	
	






	system("pause");
	return 0;
}