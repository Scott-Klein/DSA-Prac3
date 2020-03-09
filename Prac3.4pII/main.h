#pragma once

#define nine 9
void Setup();
void GenerateRandomPositions(vector<int>& randomPositions);
int GetNewRandom();
void WriteToArray(State& arr, vector<int>& randomPositions);
void PrintArray(vector<vector<int>> results);
void PrintVector(vector<int> result);
void LinearSearch(unorderedLinkedList<State> subject);
