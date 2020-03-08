
#include <iostream>
#include <time.h>
#include <vector>
#include <list>
#include "State.h"
#include "unorderedLinkedList.h"
using namespace std;

#define nine 9
void Setup();
void GenerateRandomPositions(vector<int>& randomPositions);
int GetNewRandom();
void WriteToArray(State& arr, vector<int>& randomPositions);
void PrintArray(unorderedLinkedList<State> results);
void PrintVector(State result);
int OccurancesOf(int numChecked, vector<int> arr);

static int randomCalls;
static vector<int> occuredNumbers;
static int occuredNumberIndex;

int main()
{
	unorderedLinkedList<State> linkedListResults;
	Setup();
	for (int i = 0; i < 10; i++)
	{
		randomCalls = 0;
		occuredNumbers = { -1,-1,-1,-1,-1,-1 };
		occuredNumberIndex = 0;
		State arr = State();
		vector<int> randomPositions = { 0,0,0,0,0,0 };
		GenerateRandomPositions(randomPositions);
		WriteToArray(arr, randomPositions);
		arr.list[9] = randomCalls;
		linkedListResults.insertLast(arr);
	}

	PrintArray(linkedListResults);
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
	do
	{
		randomNum = rand() % 9;
		randomCalls++;
	} while (OccurancesOf(randomNum, occuredNumbers) > 0);

	occuredNumbers[occuredNumberIndex++] = randomNum;

	return randomNum;
}


void WriteToArray(State& arr, vector<int>& randomPositions)
{
	for (int i = 0; i < 6; i++)
	{
		arr.list[randomPositions[i]] = i + 1;
	}
}

void PrintArray(unorderedLinkedList<State> results)
{
	for (int i = 0; i < results.length(); i++)
	{
		auto result = results.getKThElement(i);
		PrintVector(result);

		cout << "Random calls: " << result.list[9] << endl;
	}

}

void PrintVector(State result)
{
	for (int i = 0; i < result.Size; i++)
	{
		cout << result.list[i] << " ";
	}
}


int OccurancesOf(int numChecked, vector<int> arr)
{
	int occurances = 0;
	for (int i = 0; i < 6; i++)
	{
		if (numChecked == arr[i])
		{
			occurances++;
		}
	}
	return occurances;
}

void Setup()
{
	srand(time(NULL));
}
