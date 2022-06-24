#include "Player.h"
#include "Projectile.h"
Player::Player()
{

}
Player::Player(int PosX, int PosY)
{
	PlayerPositionX = PosX;
	PlayerPositionY = PosY;
}
Projectile* Player::FireProjectile()
{
	return new Projectile(PlayerPositionX, PlayerPositionY-1, -1);
}

void Player::MoveLeft()
{
	if (PlayerPositionX < 19)
	{
		PlayerPositionX++;
	}
}

void Player::MoveRight()
{
	if (PlayerPositionX > 0)
	{
		PlayerPositionX--;
	}
}

char Player::GetPlayerCharacter() const
{
	return PlayerCharacter;
}

int Player::GetPlayerPositionX() const
{
	return PlayerPositionX;
}

int Player::GetPlayerPositionY() const
{
	return PlayerPositionY;
}