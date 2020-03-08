/*
 * task3_2.cpp
 *
 *  Created on: 29/02/2020
 *      Author: dongmo
 */

#include<iostream>
#include<random>
#include<ctime>
#include<stack>

using namespace std;

#include"state.h"

int main() {
	srand(time(0));

	State state;
	state.printBoard();

	state.pushDown();
	state.printBoard();

	return 0;
}

