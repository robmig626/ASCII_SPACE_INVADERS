#include "EnemyBase.h"

#define BOARD_BOUNDS 20

EnemyBase::EnemyBase(int InitHealth, int InitSpeed, int InitPosX, int InitPosY)
{
	Health = InitHealth;
	Speed = InitSpeed;
	PosX = InitPosX;
	PosY = InitPosY;
}

EnemyBase::EnemyBase(int InitHealth, int InitSpeed, int InitPosX, int InitPosY, char InitCharacter)
{
	Health = InitHealth;
	Speed = InitSpeed;
	PosX = InitPosX;
	PosY = InitPosY;
	Character = InitCharacter;
}

void EnemyBase::Tick()
{
	PosX+=Direction*Speed;
	if ((PosX > BOARD_BOUNDS - 1) || (PosX <= 0))
	{
		if (Direction > 0) // Moving Right
		{
			PosX = BOARD_BOUNDS - 1;
		}
		else if (Direction < 0) // Moving Left
		{
			PosX = 0;
		}
		Direction *= -1;
		PosY++;
	}

	if (Health <= 0)
	{
		MarkedForDestruction = true;
	}
}

void EnemyBase::SetHealth(int NewHealth)
{
	Health = NewHealth;
}

void EnemyBase::SetSpeed(int NewSpeed)
{
	Speed = NewSpeed;
}

void EnemyBase::SetDirection(int NewDirection)
{
	Direction = NewDirection;
}

int EnemyBase::GetHealth() const
{
	return Health;
}

int EnemyBase::GetSpeed() const
{
	return Speed;
}

char EnemyBase::GetCharacter() const
{
	return Character;
}

int EnemyBase::GetPosX() const
{
	return PosX;
}

int EnemyBase::GetPosY() const
{
	return PosY;
}

int EnemyBase::GetDirection() const
{
	return Direction;
}