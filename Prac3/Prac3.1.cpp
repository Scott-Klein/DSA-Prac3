
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

#define nine 9
void Setup();
void GenerateRandomPositions(vector<int>& randomPositions);
int GetNewRandom();
void WriteToArray(vector<int>& arr, vector<int>& randomPositions);
void PrintArray(vector<vector<int>> results);
void PrintVector(vector<int> result);
int OccurancesOf(int numChecked, vector<int> arr);

static int randomCalls;
static vector<int> occuredNumbers;
static int occuredNumberIndex;

int main()
{
	vector<vector<int>> allResults;
	Setup();
	for (int i = 0; i < 10; i++)
	{
		randomCalls = 0;
		occuredNumbers = { -1,-1,-1,-1,-1,-1 };
		occuredNumberIndex = 0;
		vector<int> arr = { 0,0,0,0,0,0,0,0,0,0 };
		vector<int> randomPositions = { 0,0,0,0,0,0 };
		GenerateRandomPositions(randomPositions);
		WriteToArray(arr, randomPositions);
		arr[9] = randomCalls;
		allResults.push_back(arr);
	}

	PrintArray(allResults);
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


void WriteToArray(vector<int>& arr, vector<int>& randomPositions)
{
	for (int i = 0; i < 6; i++)
	{
		arr[randomPositions[i]] = i + 1;
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
