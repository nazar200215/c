#include "Field.h"
#include <stdlib.h>
#include <sstream>
#include <iomanip>

//функція сворення поля
void Field::Create()
{
	SetShip(4, 0);
	SetShip(3, 1);
	SetShip(3, 2);
	SetShip(2, 3);
	SetShip(2, 4);
	SetShip(2, 5);
	SetShip(1, 6);
	SetShip(1, 7);
	SetShip(1, 8);
	SetShip(1, 9);
}


//
AttackStatus Field::Attacked(int ver, int hor)
{
	Cell& c = m_cells[hor][ver];
	
	if (c.m_is_attacked)
		return AttackStatus::Miss;

	c.m_is_attacked = true;
	if (!c.m_is_ship)
		return AttackStatus::Miss;
	else
	{
		Ship& sh = m_ships[c.m_ship_index];
		sh.Attack();
		if (sh.m_alive_decks == 0)
			return AttackStatus::Killed;
		else
			return AttackStatus::Injured;
	}
}


//функція шо перевіря чи можна поставити палубу в дану точку
bool Field::IsCellAvailable(int ver, int hor)
{
	if (ver < 0 || ver > 9 || hor < 0 || hor > 9)
		return false;
	for (int v = -1; v < 2; ++v)
	{
		int check_v = ver + v;
		if (check_v < 0 || check_v > 9)
			continue;
		for (int h = -1; h < 2; ++h)
		{
			int check_h = hor + h;
			if (check_h < 0 || check_h > 9)
				continue;
			if (m_cells[check_h][check_v].m_is_ship)
				return false;
		}
	}
	return true;
}

//функція пошуку доступної клітини для постановки палуби
void Field::FindPlaceForDeck(int* p_ver, int* p_hor)
{
	int ver, hor;
	do
	{
		ver = rand() % 10;
		hor = rand() % 10;
	} while (!IsCellAvailable(ver, hor));
	*p_ver = ver;
	*p_hor = hor;
}


//функція розстановки кораблів
bool Field::SetShip(int num_decks, int cur_ship_index)
{
	//однопалубний корабель
	if (num_decks == 1)
	{
		int ver, hor;
		FindPlaceForDeck(&ver, &hor);
		m_ships[cur_ship_index] = Ship(1);
		m_cells[hor][ver].m_is_ship = true;
		m_cells[hor][ver].m_ship_index = cur_ship_index;
	}
	//двопалубний корабель
	else if (num_decks == 2)
	{
		bool is_found = false;
		while (!is_found)
		{
			int ver, hor;
			FindPlaceForDeck(&ver, &hor);
			bool is_ver = (rand() % 2 == 0);
			if (is_ver)
			{
				if (IsCellAvailable(ver, hor - 1))
				{
					m_ships[cur_ship_index] = Ship(2);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor - 1][ver].m_is_ship = true;
					m_cells[hor - 1][ver].m_ship_index = cur_ship_index;
					is_found = true;
				}
				else if (IsCellAvailable(ver, hor + 1))
				{
					m_ships[cur_ship_index] = Ship(2);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor + 1][ver].m_is_ship = true;
					m_cells[hor + 1][ver].m_ship_index = cur_ship_index;
					is_found = true;
				}
			}
			else
			{
				if (IsCellAvailable(ver - 1, hor))
				{
					m_ships[cur_ship_index] = Ship(2);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor][ver - 1].m_is_ship = true;
					m_cells[hor][ver - 1].m_ship_index = cur_ship_index;
					is_found = true;
				}
				else if (IsCellAvailable(ver + 1, hor))
				{
					m_ships[cur_ship_index] = Ship(2);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor][ver + 1].m_is_ship = true;
					m_cells[hor][ver + 1].m_ship_index = cur_ship_index;
					is_found = true;
				}
			}
		}
	}
	//трипалубний корабель
	else if (num_decks == 3)
	{
		bool is_found = false;
		while (!is_found)
		{
			int ver, hor;
			FindPlaceForDeck(&ver, &hor);
			bool is_ver = (rand() % 2 == 0);
			if (is_ver)
			{
				if (IsCellAvailable(ver, hor - 1) && IsCellAvailable(ver, hor - 2))
				{
					m_ships[cur_ship_index] = Ship(3);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor - 1][ver].m_is_ship = true;
					m_cells[hor - 1][ver].m_ship_index = cur_ship_index;
					m_cells[hor - 2][ver].m_is_ship = true;
					m_cells[hor - 2][ver].m_ship_index = cur_ship_index;
					is_found = true;
				}
				else if (IsCellAvailable(ver, hor + 1) && IsCellAvailable(ver, hor + 2))
				{
					m_ships[cur_ship_index] = Ship(3);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor + 1][ver].m_is_ship = true;
					m_cells[hor + 1][ver].m_ship_index = cur_ship_index;
					m_cells[hor + 2][ver].m_is_ship = true;
					m_cells[hor + 2][ver].m_ship_index = cur_ship_index;
					is_found = true;
				}
			}
			else
			{
				if (IsCellAvailable(ver - 1, hor) && IsCellAvailable(ver - 2, hor))
				{
					m_ships[cur_ship_index] = Ship(3);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor][ver - 1].m_is_ship = true;
					m_cells[hor][ver - 1].m_ship_index = cur_ship_index;
					m_cells[hor][ver - 2].m_is_ship = true;
					m_cells[hor][ver - 2].m_ship_index = cur_ship_index;
					is_found = true;
				}
				else if (IsCellAvailable(ver + 1, hor) && IsCellAvailable(ver + 2, hor))
				{
					m_ships[cur_ship_index] = Ship(3);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor][ver + 1].m_is_ship = true;
					m_cells[hor][ver + 1].m_ship_index = cur_ship_index;
					m_cells[hor][ver + 2].m_is_ship = true;
					m_cells[hor][ver + 2].m_ship_index = cur_ship_index;
					is_found = true;
				}
			}
		}
	}

	//чотирипалубний корабель
	else if (num_decks == 4)
	{
		bool is_found = false;
		while (!is_found)
		{
			int ver, hor;
			FindPlaceForDeck(&ver, &hor);
			bool is_ver = (rand() % 2 == 0);
			if (is_ver)
			{
				if (IsCellAvailable(ver, hor - 1) && IsCellAvailable(ver, hor - 2) && IsCellAvailable(ver, hor - 3))
				{
					m_ships[cur_ship_index] = Ship(4);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor - 1][ver].m_is_ship = true;
					m_cells[hor - 1][ver].m_ship_index = cur_ship_index;
					m_cells[hor - 2][ver].m_is_ship = true;
					m_cells[hor - 2][ver].m_ship_index = cur_ship_index;
					m_cells[hor - 3][ver].m_is_ship = true;
					m_cells[hor - 3][ver].m_ship_index = cur_ship_index;
					is_found = true;
				}
				else if (IsCellAvailable(ver, hor + 1) && IsCellAvailable(ver, hor + 2) && IsCellAvailable(ver, hor + 3))
				{
					m_ships[cur_ship_index] = Ship(4);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor + 1][ver].m_is_ship = true;
					m_cells[hor + 1][ver].m_ship_index = cur_ship_index;
					m_cells[hor + 2][ver].m_is_ship = true;
					m_cells[hor + 2][ver].m_ship_index = cur_ship_index;
					m_cells[hor + 3][ver].m_is_ship = true;
					m_cells[hor + 3][ver].m_ship_index = cur_ship_index;
					is_found = true;
				}
			}
			else
			{
				if (IsCellAvailable(ver - 1, hor) && IsCellAvailable(ver - 2, hor) && IsCellAvailable(ver - 3, hor))
				{
					m_ships[cur_ship_index] = Ship(4);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor][ver - 1].m_is_ship = true;
					m_cells[hor][ver - 1].m_ship_index = cur_ship_index;
					m_cells[hor][ver - 2].m_is_ship = true;
					m_cells[hor][ver - 2].m_ship_index = cur_ship_index;
					m_cells[hor][ver - 3].m_is_ship = true;
					m_cells[hor][ver - 3].m_ship_index = cur_ship_index;
					is_found = true;
				}
				else if (IsCellAvailable(ver + 1, hor) && IsCellAvailable(ver + 2, hor) && IsCellAvailable(ver + 3, hor))
				{
					m_ships[cur_ship_index] = Ship(4);
					m_cells[hor][ver].m_is_ship = true;
					m_cells[hor][ver].m_ship_index = cur_ship_index;
					m_cells[hor][ver + 1].m_is_ship = true;
					m_cells[hor][ver + 1].m_ship_index = cur_ship_index;
					m_cells[hor][ver + 2].m_is_ship = true;
					m_cells[hor][ver + 2].m_ship_index = cur_ship_index;
					m_cells[hor][ver + 3].m_is_ship = true;
					m_cells[hor][ver + 3].m_ship_index = cur_ship_index;
					is_found = true;
				}
			}
		}
	}
	return true;
}

std::string Field::ToString(bool as_for_me)
{
	std::ostringstream s;
	s << "  |ABCDEFGHIJ|" << std::endl;
	s << "--|----------|" << std::endl;
	for (int h = 0; h < 10; ++h)
	{
		s << std::setw(2) << h << "|";
		for (int v = 0; v < 10; ++v)
		{
			Cell c = m_cells[v][h];
			if (c.m_is_attacked)
			{
				if (!c.m_is_ship)
					s << "*";
				else
					s << "X";
			}
			else if (c.m_is_ship && as_for_me)
				s << "#";
			else
				s << " ";
		}
		s << "|" << std::endl;
	}
	s << "--------------" << std::endl;
	return s.str();
}
