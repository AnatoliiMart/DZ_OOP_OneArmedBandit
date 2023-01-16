#include<iostream>
#include<string.h>
#include<ctime>

class Quewe
{
public:
	Quewe();
	Quewe(int);
	bool Empty();
	bool Full();
	void AddElem(int);
	void ShowReel() noexcept;
	int Extract();
	int RandExtract(int&);
	void ClearReel()   { reelLenCurr = 0; }
	size_t GetCurrLen() {return reelLenCurr;}
	~Quewe();

private:
	int* reel;
	size_t reelLenMax;
	size_t reelLenCurr;
};

Quewe::Quewe() : reelLenCurr(reelLenMax = 0), reel ( new int[reelLenMax]){}

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
	int randIndex = 1 + rand() % 7;
	for (size_t i = 0; i <= randIndex; i++)
	{
		if (i == randIndex/2)
		{
			reelObj = Extract();
		}
		
	}
	return reelObj;
}

Quewe::~Quewe()
{
	delete[] reel;
}


void PrintRules();
void PauseAndClear();
int main()
{
	srand(static_cast<int>(time(0)));
	Quewe* r1 = new Quewe(9);
	Quewe* r2 = new Quewe(9);
	Quewe* r3 = new Quewe(9);
	const int creditBegin        = 100;
	const int lessCredits        = 5;
	const int creditsToWin       = 10;
	const int creditsForWinStuck = 15;
	const int jackpotCredits     = 1000;
	PrintRules();
	PauseAndClear();
	std::cout << "----------------Menu----------------\n"
		<< "1." << std::endl;

	for (int i = 0; i < 9; i++)
	{
		r1->AddElem(rand() % 8);
		r2->AddElem(rand() % 8);
		r3->AddElem(rand() % 8);
	}
	r1->ShowReel();
	r2->ShowReel();
	r3->ShowReel();		


	delete r1;
	delete r2;
	delete r3;
	return 0;
}

void PrintRules()
{
	std::cout << "------------------------Rules------------------------\n"
		<< "At the beginning of the game you have 100 coins.\n"
		<< "For every non - winning scroll you lose 5 coins.\n"
		<< "For every winning spin you get 10 coins\n"
		<< "The winning combinations are: Nxx, NNx, xNx, xNN, xxN, NxN\n"
		<< "Where x - some digit, you earned 10 credits.\n"
		<< "For 111, 222, 333, 444, 555, 666 you earned 15 credits \n"
		<< "For 777 you get the jackpot of 1000 coins\n"
		<< "If you exit the game you will lose all reward and progress\n"
		<< "Good luck, and have fun)))\n"
		<< "-----------------------------------------------------" << std::endl;
}

void PauseAndClear()
{
	system("pause");
	system("cls");
}
