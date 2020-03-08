/*
 * state.h
 *
 *  Created on: 29/02/2020
 *      Author: dongmo
 */
#include <stack>
#ifndef BOARD_H_
#define BOARD_H_

const int BOARDSIZE = 3;
const int NUMBER_OF_BLOCKS = 6;

class State {
private:
	int grid[BOARDSIZE][BOARDSIZE];
public:
	State() {
		for (int i = 0; i < BOARDSIZE; i++)
			for (int j = 0; j < BOARDSIZE; j++)
				grid[i][j] = rand() % 7;
	}

	//For Task 3.4
	bool operator==(State s) {
		for (int i = 0; i < BOARDSIZE; i++)
			for (int j = 0; j < BOARDSIZE; j++)
				if (s.grid[i][j] != grid[i][j])
					return false;
		return true;
	}

	//For Task 3.4
	bool operator!=(State s) {
		for (int i = 0; i < BOARDSIZE; i++)
			for (int j = 0; j < BOARDSIZE; j++)
				if (s.grid[i][j] != grid[i][j])
					return true;
		return false;
	}

	void printBoard();
	void pushDown();
};

void State::printBoard() {
	cout << endl;

	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			cout << " " << grid[BOARDSIZE - i - 1][j] << " ";
		}
		cout << endl;
	}
}

void State::pushDown() {

//Add your code here!
	stack<int> toPush;

	for (int j = 0; j < 3; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (grid[i-1][j] > 0)
			{
				toPush.push(grid[i-1][j]);
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (toPush.size() > 0)
			{
				grid[i][j] = toPush.top();
				toPush.pop();
			}
			else
			{
				grid[i][j] = 0;
			}
		}
	}

	
}

#endif /* BOARD_H_ */
