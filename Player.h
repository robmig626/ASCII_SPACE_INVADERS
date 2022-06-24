#pragma once
#include "Projectile.h"
class Player
{
public:
	Player();
	Player(int PosX, int PosY);

	char GetPlayerCharacter() const;

	int GetPlayerPositionX() const;
	int GetPlayerPositionY() const;

	Projectile* FireProjectile();
	void MoveLeft();
	void MoveRight();
protected:
private:
	char PlayerCharacter = 'A';
	int PlayerPositionX = 9;
	int PlayerPositionY = 18;//This doesn't change

};