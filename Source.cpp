#include<iostream>
#include<ctime>
#include"ReelClassLib.h"
#include"Variables.h"

void PrintRules();
void PauseAndClear();
void ReelsNumSet();
int main()
{
	srand(static_cast<int>(time(0)));
	
	PrintRules();
	PauseAndClear();
	ReelsNumSet();
	
	do
	{
		reel1->RandExtract(res1);
		reel2->RandExtract(res2);
		reel3->RandExtract(res3);
		std::cout << "----------------Menu----------------\n"
			<< "Credits current: " << creditCurr << "\n"
			<< "1.Spin\n"
			<< "2.End game\n"
			<< "Choose the action: ";
		std::cin >> choose;
		
		switch (choose)
		{
		case 1:
			std::cout << "Current combo: " << res1 << res2 << res3 << std::endl;
			creditCurr -= lessCredits;
			if (res1 == 0 && res2 == 0 && res3 == 0 ||
				res1 == 1 && res2 == 1 && res3 == 1 ||
				res1 == 2 && res2 == 2 && res3 == 2 ||
				res1 == 3 && res2 == 3 && res3 == 3 ||
				res1 == 4 && res2 == 4 && res3 == 4 ||
				res1 == 5 && res2 == 5 && res3 == 5 ||
				res1 == 6 && res2 == 6 && res3 == 6)

			{
				creditCurr += creditsForWinStuck;
				std::cout << " Win combo!!!\nYou won 15 credits." << std::endl;
			}
			else if (res2 == 0 && res3 == 0 && res1 != 0 || res1 == 0 && res2 == 0 && res3 != 0 || res1 == 0 && res3 == 0 && res2 != 0 ||
				     res2 == 1 && res3 == 1 && res1 != 1 || res1 == 1 && res2 == 1 && res3 != 1 || res1 == 1 && res3 == 1 && res2 != 1 ||
				     res2 == 2 && res3 == 2 && res1 != 2 || res1 == 2 && res2 == 2 && res3 != 2 || res1 == 2 && res3 == 2 && res2 != 2 ||
				     res2 == 3 && res3 == 3 && res1 != 3 || res1 == 3 && res2 == 3 && res3 != 3 || res1 == 3 && res3 == 3 && res2 != 3 ||
				     res2 == 4 && res3 == 4 && res1 != 4 || res1 == 4 && res2 == 4 && res3 != 4 || res1 == 4 && res3 == 4 && res2 != 4 ||
				     res2 == 5 && res3 == 5 && res1 != 5 || res1 == 5 && res2 == 5 && res3 != 5 || res1 == 5 && res3 == 5 && res2 != 5 ||
				     res2 == 6 && res3 == 6 && res1 != 6 || res1 == 6 && res2 == 6 && res3 != 6 || res1 == 6 && res3 == 6 && res2 != 6)
			{
				creditCurr += creditsToWin;
				std::cout << " Win combo!!!\nYou won 10 credits." << std::endl;
			}
			else if (res1 == 7 && res2 == 7 && res3 == 7)
			{
				creditCurr += jackpotCredits;
				std::cout << "JACKPOOOOOOOT!!!!!\n YOU WON 1000 CREDITS!!!!!!!!" << std::endl;
			}
			break;
		case 2:
			creditCurr = 0;
			std::cout << "You decide to exit game( Good luck!" << std::endl;
		}
	} while (creditCurr > 0);
	
	if (creditCurr == 0)
	{
		std::cout << "There are not enough credits in your wallet(((" << std::endl;
	}
}

void PrintRules()
{
	std::cout << "------------------------Rules------------------------\n"
		<< "At the beginning of the game you have 100 coins.\n"
		<< "For every non - winning scroll you lose 5 coins.\n"
		<< "For every winning spin you get 10 coins\n"
		<< "The winning combinations are: NxN, NNx, xNN\n"
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

void ReelsNumSet()
{
	for (int i = 0; i < 9; i++)
	{
		reel1->AddElem(rand() % 8);
		reel2->AddElem(rand() % 8);
		reel3->AddElem(rand() % 8);
	}
}
