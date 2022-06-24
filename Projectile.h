#pragma once
class Projectile
{
public:
	Projectile(int PositionX, int PositionY, int FlightDirection);
	int GetPosX() const;
	int GetPosY() const;
	int GetDirection();
	char GetProjectileCharacter() const;
	void Tick();
protected:
private:
	char ProjectileCharacter = '|';
	int PosX = 0;
	int PosY = 0;
	int Direction;
};