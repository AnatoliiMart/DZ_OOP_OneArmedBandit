#include"ReelClassLib.h"
#include<iostream>
Quewe::Quewe() : reelLenCurr(reelLenMax = 0), reel(new int[reelLenMax]) {}

Quewe::Quewe(int maxLen) : reelLenMax(maxLen), reel(new int[reelLenMax]), reelLenCurr(0) {}
bool Quewe::Empty()
{
	return reelLenCurr == 0;
}

bool Quewe::Full()
{
	return reelLenCurr == reelLenMax;
}

void Quewe::AddElem(int reelObj = 0)
{
	if (!Full())
	{
		reel[reelLenCurr++] = reelObj;
	}
	else
	{
		std::cout << "The reel is full of values" << std::endl;
	}
}

void Quewe::ShowReel() noexcept
{
	if (!Empty())
	{
		for (size_t i = 0; i < reelLenCurr; i++)
		{
			std::cout << reel[i] << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Reel is empty! Nothing to print(" << std::endl;
	}
}

int  Quewe::Extract()
{

	if (!Empty())
	{
		int tmp = *reel;
		for (size_t i = 0; i < reelLenCurr; i++)
		{
			reel[i - 1] = reel[i];
		}
		reel[reelLenCurr - 1] = tmp;
		return tmp;
	}
	else
	{
		std::cout << "Reel is empty! Nothing to extruct(" << std::endl;
		return -1;
	}
}

int Quewe::RandExtract(int& reelObj)
{
	int randIndex = rand() % 9;
	for (size_t i = 0; i <= randIndex; i++)
	{
		reelObj = Extract();


	}
	return reelObj;
}

Quewe::~Quewe()
{
	delete[] reel;
}