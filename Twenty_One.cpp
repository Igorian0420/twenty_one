#include <iostream>
#include <time.h>

int cardsForPlayer(int summ);
int cardsForBot(int summ);
int summCard(int summ, int* card);
bool botDesigion(int summ);


int main()
{
	int summ = 0;

	int pointsPlayer = cardsForPlayer(summ);
	int pointsBot = cardsForBot(summ);

	if (pointsPlayer > 21 || (pointsBot > pointsPlayer && pointsBot <= 21))
	{
		std::cout << "You're looser!!! Bot defeated you:)" << std::endl;
	}
	else if ((pointsPlayer <= 21 && pointsPlayer > pointsBot) || pointsBot > 21)
	{
		std::cout << "Congratulations!!! You're winner." << std::endl;
	}
	else
	{
		std::cout << "Dead heat." << std::endl;
	}

	return 0;
}

int cardsForPlayer(int summ)
{
	int card = 0;
	char choose;
	do
	{
		summ = summCard(summ, &card);
		std::cout << card << " - your poinsts " << std::endl;
		std::cout << "You have: " << summ << " points!" << std::endl;
		std::cout << "Do you want one more card?" << std::endl;
		std::cin >> choose;
	} while (choose == 'y' || choose == 'Y');
	return summ;
}

int cardsForBot(int summ)
{
	int card = 0;
	while (botDesigion(summ))
	{
		summ = summCard(summ, &card);
	}
	std::cout << "Bot have: " << summ << " points!" << std::endl;

	return summ;
}

int summCard(int summ, int* card)
{
	srand(time(NULL));
	*card = 2 + rand() % 10;
	return summ += *card;
}

bool botDesigion(int summ)
{
	srand(time(NULL));
	int rnd = rand() % 2;
	int nrand = 21 - summ;
	if ((nrand + rnd) < 4)
	{
		return false;
	}
	else
	{
		return true;
	}
}