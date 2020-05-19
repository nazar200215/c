#pragma once
#include "interfaces.h"

//��������� ��� ������� �� �������������� �������(������� ����� �� ������� ����� �����)
struct Ship
{
	Ship()
	{
		m_decks = -1;
		m_alive_decks = -1;
	}
	Ship(int decks)
	{
		m_decks = decks;
		m_alive_decks = decks;
	}
	//��� ����� ������� ���� ��������� 1 ������
	void Attack()
	{
		if (m_alive_decks > 0)
			m_alive_decks--;
	}
	int m_decks;
	int m_alive_decks;
};

//��������� � �������� ������
struct Cell
{
	Cell()
	{
		m_is_ship = false;	//�� � ��������
		m_is_attacked = false; //�� ��������
		m_ship_index = -1;	//����� ������� �� 0 �� 9
	};
	bool m_is_ship;
	bool m_is_attacked;
	int m_ship_index;
};

class Field
{
public:
	void Create();
	AttackStatus Attacked(int ver, int hor);
	std::string ToString(bool as_for_me);

protected:
	bool SetShip(int num_decks, int cur_ship_index);
	bool IsCellAvailable(int ver, int hor);
	void FindPlaceForDeck(int* p_ver, int* p_hor);

protected:
	Cell m_cells[10][10];
	Ship m_ships[10];
};

