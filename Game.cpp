#include <iostream>
#include <Windows.h>
#include <Vector>
#include "Game.h"

#define STATIONARY_ENEMY(x, y) EnemyBase(5, 0, x, y)
#define MOVING_ENEMY(x, y) EnemyBase(1, 1, x, y, 'X')


Game::Game()
{
	PlayerInstance = Player();
	SetupLevelEnemies(0);
	InitializeGameBoard();
	PrintGameBoard();
	GameLoop();
}

void Game::GameTick()
{
	if (GetKeyState('A') & 0x8000)
	{
		PlayerInstance.MoveRight();
	}
	if (GetKeyState('D') & 0x8000)
	{
		PlayerInstance.MoveLeft();
	}
	if (GetKeyState(' ') & 0x8000)
	{
		int i = 0;
		while (PlayerProjectiles[i] != NULL)
		{
			i++;
		}
		PlayerProjectiles[i]=PlayerInstance.FireProjectile();
	}

	for (int i = 0; i < MAX_SHOTS; i++)
	{
		if (PlayerProjectiles[i])
		{
			PlayerProjectiles[i]->Tick();
		}
	}

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (LevelEnemies[i])
		{
			LevelEnemies[i]->Tick();

			if (LevelEnemies[i]->GetPosY() >= ENEMY_POS_GAME_OVER_THRESHOLD)//Game Over condition
			{
				bGameOver = true;
			}

			if (LevelEnemies[i]->MarkedForDestruction)
			{
				delete(LevelEnemies[i]);
				LevelEnemies[i] = nullptr;
				TotalEnemies--;
			}
		}
	}

	//Enemy Collision with Player Projectile
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (LevelEnemies[i])
		{
			for (int j = 0; j < MAX_SHOTS; j++)
			{
				if (PlayerProjectiles[j])
				{
					if (LevelEnemies[i]->GetPosX() == PlayerProjectiles[j]->GetPosX())
					{
						if (LevelEnemies[i]->GetPosY() == PlayerProjectiles[j]->GetPosY())
						{
							LevelEnemies[i]->SetHealth(LevelEnemies[i]->GetHealth() - 1);
						}
					}
				}
			}
		}
	}

	UpdateGameBoard();
	GoBeginningGameBoard();
	PrintGameBoard();

	if (TotalEnemies <= 0)
	{
		bWinConditionMet = true;
		bGameOver = true;
	}

	Sleep(100);
}

char** Game::GetGameBoard() const
{
	return GameBoard;
}

void Game::InitializeGameBoard()
{
	GameBoard = new char* [BOARD_BOUNDS];
	for (int i=0;i<20;i++)
	{
		GameBoard[i] = new char[BOARD_BOUNDS];
	}
	for (int j = 0; j < 20; j++)
	{
		for (int k = 0; k < 20; k++)
		{
#if 0
			GameBoard[j][k] = (j+k+'0');
#else
			GameBoard[j][k] = (' ');
#endif
		}
	}

	GameBoard[PlayerInstance.GetPlayerPositionY()][PlayerInstance.GetPlayerPositionX()] = PlayerInstance.GetPlayerCharacter();

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (LevelEnemies[i])
		{
			GameBoard[LevelEnemies[i]->GetPosY()][LevelEnemies[i]->GetPosX()] = LevelEnemies[i]->GetCharacter();
		}
	}
}

void Game::PrintGameBoard()
{
	for (int i = 0; i < BOARD_BOUNDS; i++)
	{
		for (int j = 0; j < BOARD_BOUNDS; j++)
		{
			std::cout << GameBoard[i][j];
			std::cout << ' ';

		}
		std::cout << '\n';
	}
}

void Game::GameLoop()
{
	while (!bGameOver)
	{
		GameTick();
	}
}

void Game::GoBeginningGameBoard()
{
	for (int i = 0; i < 20; i++)
	{
		std::cout << "\x1b[A";
	}
	std::cout << '\r';
}

void Game::UpdateGameBoard()
{
	for (int j = 0; j < BOARD_BOUNDS; j++)
	{
		for (int k = 0; k < BOARD_BOUNDS; k++)
		{
			GameBoard[j][k] = (' ');
		}
	}
	GameBoard[PlayerInstance.GetPlayerPositionY()][PlayerInstance.GetPlayerPositionX()] = PlayerInstance.GetPlayerCharacter();
	for (int i =0; i < 20; i++)
	{
		if (PlayerProjectiles[i])
		{
			if ((PlayerProjectiles[i]->GetPosY() < 0) || PlayerProjectiles[i]->GetPosY() > (BOARD_BOUNDS - 1))
			{
				PlayerProjectiles[i] = nullptr;
				continue;
			}
			GameBoard[PlayerProjectiles[i]->GetPosY()][PlayerProjectiles[i]->GetPosX()] = PlayerProjectiles[i]->GetProjectileCharacter();
		}
	}

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (LevelEnemies[i])
		{
 			GameBoard[LevelEnemies[i]->GetPosY()][LevelEnemies[i]->GetPosX()] = LevelEnemies[i]->GetCharacter();
		}
	}
}

void Game::SetupLevelEnemies(int Level)
{
	LevelEnemies[0] = new STATIONARY_ENEMY(4,  5);
	LevelEnemies[1] = new STATIONARY_ENEMY(9,  5);
	LevelEnemies[2] = new STATIONARY_ENEMY(14, 5);

	LevelEnemies[3] = new MOVING_ENEMY(4, 6);
	LevelEnemies[4] = new MOVING_ENEMY(9, 6);
	LevelEnemies[5] = new MOVING_ENEMY(14, 6);

	TotalEnemies = 6;
}

bool Game::GetWon() const
{
	return bWinConditionMet;
}