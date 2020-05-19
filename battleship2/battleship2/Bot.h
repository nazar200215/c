#pragma once
#include "interfaces.h"
#include "Field.h"
class Bot :
	public IPlayer
{
public:
	// Inherited via IPlayer
	virtual void GenerateField() override;
	virtual void Shot(int* p_ver, int* p_hor) override;
	virtual AttackStatus GetStatus(int ver, int hor) override;
	virtual void ShotStatus(int ver, int hor, AttackStatus status) override;
	virtual void FinishGame(bool are_you_winner) override;
	virtual std::string ShowMyField() override;
	virtual std::string ShowEnemyField() override;

protected:
	Field m_field;
};

struct RandomCoord
{
	int m_hor;
	int m_ver;
	bool m_is_in_used;
};


class Bot2 : public Bot
{
public:
	Bot2();
	virtual void Shot(int* p_ver, int* p_hor) override;
protected:
	RandomCoord m_rnd[100];
};


class Human : public Bot
{
public:
	virtual void Shot(int* p_ver, int* p_hor) override;
};