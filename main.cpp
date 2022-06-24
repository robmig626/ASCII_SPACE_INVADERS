#include <iostream>
#include <Windows.h>
#include "Game.h"


int main(void)
{
	Game GameInstance = Game();
	if (GameInstance.GetWon())
	{
		std::cout << "You WIN !!!" << std::endl;
	}
	else
	{
		std::cout << "You Lost!" << std::endl;
	}
	Sleep(1000);
	return 0;
}