#include "Bot.h"
#include <stdlib.h>
#include <iostream>

void Bot::GenerateField()
{
	m_field.Create();
}

void Bot::Shot(int* p_ver, int* p_hor)
{
	*p_ver = rand() % 10;
	*p_hor = rand() % 10;
}

AttackStatus Bot::GetStatus(int ver, int hor)
{
	return m_field.Attacked(ver, hor);
}

void Bot::ShotStatus(int ver, int hor, AttackStatus status)
{
	//You are so lazy
}

void Bot::FinishGame(bool are_you_winner)
{
	//ignore
}
std::string Bot::ShowMyField()
{
	return m_field.ToString(true);
}

std::string Bot::ShowEnemyField()
{
	return m_field.ToString(false);
}



Bot2::Bot2()
{
	for (int i = 0; i < 100; ++i)
	{
		m_rnd[i].m_hor = i / 10;
		m_rnd[i].m_ver = i % 10;
		m_rnd[i].m_is_in_used = false;
	}
}
void Bot2::Shot(int* p_ver, int* p_hor)
{
	while (true)
	{
		int index = rand() % 100;
		RandomCoord& c = m_rnd[index];
		if (c.m_is_in_used)
			continue;
		c.m_is_in_used = true;
		*p_ver = c.m_ver;
		*p_hor = c.m_hor;
		break;
	}
}


void Human::Shot(int* p_ver, int* p_hor)
{
	char ver, hor;
	std::cout << "My shot (a-j, 0-9) is:\n>";
	do
	{
		std::cin >> ver >> hor;
	} while (strchr("abcdefghij", ver) == nullptr || strchr("0123456789", hor) == nullptr);
	*p_ver = ver - 'a';
	*p_hor = hor - '0';
	std::cout << "\n";

}

