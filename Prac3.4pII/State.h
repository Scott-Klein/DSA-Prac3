#pragma once
class State
{
private:
public:
	int list[10];
	int Size = 9;

	State();

	bool operator==(State rhs);
	bool operator!=(State rhs);
};

