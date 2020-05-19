#include "Game.h"
#include <cstdlib>
#include <memory>
#include <iostream>
#include "interfaces.h"

Game::Game()
{

}
Game::~Game()
{

}

//старт гри розпочинається з розстановки полів 2 гравців
void Game::Start()
{
	m_player_data_1.m_player->GenerateField();
	m_player_data_2.m_player->GenerateField();
}

//при закінченні виводить статистичну інформацію
void Game::Finish()
{
	std::cout << "Game over!" << std::endl;
	std::cout << "Score: " << 20-m_player_data_1.m_left_decks << " : " << 20 - m_player_data_2.m_left_decks << std::endl;
	std::cout << "Shots: " <<  m_player_data_1.m_num_shots << " : " << m_player_data_2.m_num_shots << std::endl;
	std::cout << (m_player_data_1.m_is_winner?"Winner":"Looser") << " : " << (m_player_data_2.m_is_winner ? "Winner" : "Looser") << std::endl;
}

//
void Game::PlayRound()
{
	PlayerData* p_attacker;
	PlayerData* p_defender;
	//в залежності від змінної temp, визначається хто ходить першим
	int temp = rand() % 2;
	if (temp == 0)
	{
		p_attacker = &m_player_data_1;
		p_defender = &m_player_data_2;
	}
	else
	{
		p_attacker = &m_player_data_2;
		p_defender = &m_player_data_1;
	}
	ShowFields();
	//головний цикл гри
	while (p_attacker->m_left_decks > 0 && p_defender->m_left_decks > 0)
	{
		int ver, hor;
		p_attacker->m_player->Shot(&ver, &hor);
		p_attacker->m_num_shots++;
		AttackStatus status = p_defender->m_player->GetStatus(ver, hor);
		p_attacker->m_player->ShotStatus(ver, hor, status);
		if (status == AttackStatus::Miss)
		{
			std::swap(p_attacker, p_defender);
			std::cout << "Miss" << std::endl;
		}
		else if (status == AttackStatus::Killed)
		{
			p_defender->m_left_decks--;
			std::cout << "Killed" << std::endl;
		}
		else 
		{
			p_defender->m_left_decks--;
			std::cout << "Injured" << std::endl;
		}
		ShowFields();
	}
	p_attacker->m_is_winner = true;
	p_attacker->m_player->FinishGame(true);
	p_defender->m_player->FinishGame(false);
}


//функція яка передає дані про гравця 1 та 2
void Game::SetPlayers(IPlayer* player1, IPlayer* player2)
{
	m_player_data_1.m_player = player1;
	m_player_data_2.m_player = player2;
}

void Game::ShowFields()
{
	system("CLS");
	std::cout << m_player_data_1.m_player->ShowMyField();
	std::cout << m_player_data_2.m_player->ShowMyField();
}
