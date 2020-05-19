#pragma once

#include <string>

enum class AttackStatus
{
	Miss,
	Injured,
	Killed
};


class IPlayer
{
public:
	virtual ~IPlayer() {};
	virtual void GenerateField() = 0;
	virtual void Shot(int* p_ver, int* p_hor) = 0;
	virtual AttackStatus GetStatus(int ver, int hor) = 0;
	virtual void ShotStatus(int ver, int hor, AttackStatus status) = 0;
	virtual void FinishGame(bool are_you_winner) = 0;
	virtual std::string ShowMyField() = 0;
	virtual std::string ShowEnemyField() = 0;
};
