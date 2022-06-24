#include "Projectile.h"

Projectile::Projectile(int PositionX, int PositionY, int FlightDirection)
{
	PosX = PositionX;
	PosY = PositionY;
	Direction = FlightDirection;
}

int Projectile::GetPosX() const
{
	return PosX;
}
int Projectile::GetPosY() const
{
	return PosY;
}
int Projectile::GetDirection()
{
	return Direction;
}

char Projectile::GetProjectileCharacter() const
{
	return ProjectileCharacter;
}

void Projectile::Tick()
{
	PosY += Direction;
	if (PosY < 0 || PosY >19)
	{
		delete(this);
	}
}