#pragma once
class EnemyBase
{
public:
	EnemyBase(int InitHealth, int InitSpeed, int InitPosX, int InitPosY);
	EnemyBase(int InitHealth, int InitSpeed, int InitPosX, int InitPosY, char InitCharacter);
	void Tick();
	int GetHealth() const;
	int GetSpeed() const;
	char GetCharacter() const;
	int GetPosX() const;
	int GetPosY() const;
	int GetDirection() const;
	void SetHealth(int NewHealth);
	void SetSpeed(int NewSpeed);
	void SetDirection(int NewDirection);
	
	bool MarkedForDestruction = false;
protected:
private:
	char Character = 'O';
	int Health = 1;
	int Speed = 0;
	int PosX = 0;
	int PosY = 0;
	int Direction = 1;
};