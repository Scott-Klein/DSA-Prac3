
#include <iostream>
#include <time.h>
#include <vector>
#include "unorderedLinkedList.h"
#include "State.h"
#include "main.h"

using namespace std;

static int randomCalls;
static vector<int> occuredNumbers;

int main()
{
	unorderedLinkedList<State> linkedListResults;
	Setup();
	int vectorSize = 50000;

	for (int i = 0; i < vectorSize; i++)
	{
		randomCalls = 0;
		occuredNumbers = { 0,1,2,3,4,5,6,7,8 };
		State arr;
		vector<int> randomPositions = { 0,0,0,0,0,0 };
		GenerateRandomPositions(randomPositions);
		WriteToArray(arr, randomPositions);
		arr.list[9] = randomCalls;
		linkedListResults.insertLast(arr);
	}
	LinearSearch(linkedListResults);
	//PrintArray(allResults);
}

bool IsMatch(vector<int> candidate)
{
	vector<int> test = { 2,1,5,4,0,0,6,0,3 };
	for (int i = 0; i < test.size(); i++)
	{
		if (candidate[i] != test[i])
		{
			return false;
		}
	}

	return true;
}

void FoundMatch(vector<int> match, int index)
{
	cout << "Found the vector at index: " << index;
}

void LinearSearch(unorderedLinkedList<State> subject)
{
	State searchItem;
	int insertion[10] = { 2,1,5,4,0,0,6,0,3,0 };
	for (int i = 0; i < 10; i++)
	{
		searchItem.list[i] = insertion[i];
	}

	if (subject.search(searchItem))
	{
		cout << "Found the match";
	}
	else
	{
		cout << "Did not find anything";
	}
}

void GenerateRandomPositions(vector<int>& positions)
{
	for (int i = 0; i < 6; i++)
	{
		positions[i] = GetNewRandom();
	}
}

int GetNewRandom()
{
	int randomNum;

	randomNum = rand() % occuredNumbers.size();

	int result = occuredNumbers[randomNum];
	occuredNumbers.erase(occuredNumbers.begin() + randomNum);

	randomCalls++;

	return result;
}


void WriteToArray(State& arr, vector<int>& randomPositions)
{
	for (int i = 0; i < 6; i++)
	{
		arr.list[randomPositions[i]] = i + 1;
	}
}

void PrintArray(vector<vector<int>> results)
{
	for (int i = 0; i < results.size(); i++)
	{
		PrintVector(results[i]);
		cout << "Random calls: " << results[i][9] << endl;
	}

}

void PrintVector(vector<int> result)
{
	for (int i = 0; i < result.size() - 1; i++)
	{
		cout << result[i] << " ";
	}
}



void Setup()
{
	srand(time(NULL));
}
