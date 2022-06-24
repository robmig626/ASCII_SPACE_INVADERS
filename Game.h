#pragma once
#include "Player.h"
#include "Projectile.h"
#include "EnemyBase.h"

#define BOARD_BOUNDS 20
#define MAX_SHOTS 20
#define MAX_ENEMIES 10
#define ENEMY_POS_GAME_OVER_THRESHOLD 18
class Game
{
public:
	Game();
	char** GetGameBoard() const;
	bool GetWon() const;
protected:
private:
	void InitializeGameBoard();
	void SetupLevelEnemies(int Level);
	void PrintGameBoard();
	void GoBeginningGameBoard();
	void UpdateGameBoard();
	void GameTick();
	void GameLoop();


	bool bGameOver = false;
	bool bWinConditionMet = false;

	int TotalEnemies = 0;

	char** GameBoard;
	class Player PlayerInstance;
	Projectile* PlayerProjectiles[MAX_SHOTS];
	EnemyBase* LevelEnemies[MAX_ENEMIES] = { nullptr };

};