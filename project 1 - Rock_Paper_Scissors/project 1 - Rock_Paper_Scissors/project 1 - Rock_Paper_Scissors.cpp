#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;



enum enChoiceGameType{ rock = 1, paper = 2, scissors = 3 };

enum enresult { computer = 1, player = 2, draw = 3 };

struct stResults { int howmanyplayerwin, howmanycomputerwin, howmanydraw, howmanyround; };

int ReadHowManyRound()
{
	int number;
	do
	{
		cout << "Pls enter how many round do you want to play(1 to 10)?" << endl;
		cin >> number;
	} while (number <= 0 || number >10);

	return number;
}

enChoiceGameType ChoicePaperorRockorScissers()
{
	int choice = 0;
	do
	{
		cout << "pls enter your choice (rock = 1,paper =2,scissers=3)?";
		cin >> choice;
	} while (choice < 1 || choice >3);
	return (enChoiceGameType)choice;
}

int RandomNumber(int from,int to)
{
	int randomnumber;

	randomnumber = rand() % (to - from + 1) + from;

	return randomnumber;
}

enresult CheckWinner(enChoiceGameType ComputerChoice,enChoiceGameType PlayerChoice)
{
	if (ComputerChoice == PlayerChoice)
	{
		return enresult::draw;
	}

	if (PlayerChoice == enChoiceGameType::scissors && ComputerChoice == enChoiceGameType::paper)
	{
		return enresult::player;
	}
	else if (PlayerChoice == enChoiceGameType::rock && ComputerChoice == enChoiceGameType::scissors)
	{
		return enresult::player;
	}
	else if (PlayerChoice == enChoiceGameType::paper && ComputerChoice == enChoiceGameType::rock)
	{
		return enresult::player;
	}
	else
	{
		return enresult::computer;
	}
}

string ChoicetoText(enChoiceGameType choice) 
{
	switch (choice)
	{
	case enChoiceGameType::paper:
		return "paper";
	case enChoiceGameType::rock:
		return "Rock";
	case enChoiceGameType::scissors:
		return "sissors";
	default:
		return "Unknown";
	}
}

string WinnertosText(enresult winner)
{
	switch (winner)
	{
	case enresult::computer:
		return "Computer";
	case enresult::player:
		return "player";
	case enresult::draw:
		return "draw";
	default:
		return "there is no winner";
	}
}

void PrintRoundWinnerColor(enresult RoundWinner)
{
	if (RoundWinner == enresult::computer)
	{
		cout << "\a";
		system("color 4F");
	}
	else if (RoundWinner == enresult::player)
	{
		system("color 2F");
	}
	else
	{
		system("color 6F");
	}
}

void PrintRoundInformation(int number, enChoiceGameType ComputerChoice, enChoiceGameType PlayerChoice, enresult RoundWinner)
{
		cout << "________________round(" << number << ")________________" << endl;
		cout << "Player choice is : " << ChoicetoText(PlayerChoice) << endl;
		cout << "computer choice is : " << ChoicetoText(ComputerChoice) << endl;
		cout << "the winner in the round is : " << WinnertosText(RoundWinner) << endl;
}

void PrintAllRoundsInformation(stResults GameResults)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "____________________________________________________________";
	cout << endl;
	cout << "               + + + G A M E  O V E R + + +                 ";
	cout << endl;
	cout << "____________________________________________________________";
	cout << endl;
	cout << "____________________[ Game Results ] _______________________" << endl;

	cout << "game Rounds : " << GameResults.howmanyround << endl;
	cout << "player won times : " << GameResults.howmanyplayerwin << endl;
	cout << "computer won times : " << GameResults.howmanycomputerwin << endl;
	cout << "draw times : " << GameResults.howmanydraw << endl;


	if (GameResults.howmanyplayerwin > GameResults.howmanycomputerwin)
	{
		system("color 2F");
		cout << "final winner : " << "player" << endl;
	}
	else if (GameResults.howmanycomputerwin == GameResults.howmanyplayerwin)
	{
		system("color 6F");
		cout << "final winner : " << "Draw" << endl;
	}
	else
	{
		cout << "\a";
		system("color 4F");
		cout << "final winner : " << "computer" << endl;
	}

	cout << "__________________________________________________" << endl;
}

void PlayGame()  
{
	int computerChoice = 0;
	stResults GameResults = { 0,0,0,0 };

	int NumberLength = ReadHowManyRound();

	for (int i = 0; i < NumberLength; i++)
	{
		enChoiceGameType PlayerChoice = ChoicePaperorRockorScissers();
		enChoiceGameType computerChoice = (enChoiceGameType)RandomNumber(1, 3);

		enresult RoundWinner = CheckWinner(computerChoice, PlayerChoice);

		GameResults.howmanyround = NumberLength;

		if (RoundWinner == player)
		{
			++GameResults.howmanyplayerwin;
		}
		else if (RoundWinner == computer)
		{
			++GameResults.howmanycomputerwin;
		}
		else if (RoundWinner == draw)
		{
			++GameResults.howmanydraw;
		}

		
		PrintRoundWinnerColor(RoundWinner);
		PrintRoundInformation(i + 1, computerChoice, PlayerChoice, RoundWinner);
	}


	PrintAllRoundsInformation(GameResults);

}

void StartGameApplication()
{
	char more = 'y';

	do
	{
		system("color 0F");
		system("cls");

		PlayGame();

		cout << "do you want to play again ? Y/N?";
		cin >> more;
	} while (more == 'y' || more == 'Y');
}

 
int main()
{
	srand((unsigned)time(NULL));


	StartGameApplication();

	return 0;
}