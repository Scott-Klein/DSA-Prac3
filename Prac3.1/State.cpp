#include "State.h"
State::State()
{
	for (int i = 0; i < this->Size; i++)
	{
		this->list[i] = 0;
	}
}