#include "State.h"
State::State()
{
	for (int i = 0; i < this->Size; i++)
	{
		this->list[i] = 0;
	}
}

bool State::operator==(State rhs)
{
	if (this->Size != rhs.Size)
	{
		return false;
	}
	for (int i = 0; i < this->Size; i++)
	{
		if (this->list[i] != rhs.list[i])
		{
			return false;
		}
	}

	return true;
}

bool State::operator!=(State rhs)
{
	return !(*this == rhs);
}