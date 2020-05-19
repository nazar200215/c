#pragma once
#include "interfaces.h"

//≤нформац≥€ про гравц€(людина чи робот)
struct PlayerData
{
	PlayerData() 
	{
		m_player = nullptr;	//людина чи робот
		m_left_decks = 20;	//к≥льк≥сть залишених палуб
		m_num_shots = 0;	//к≥льк≥сть вистр≥л≥в за гру
		m_is_winner = false; //чи перем≥г даний гравець/бот
	}
	IPlayer* m_player;
	int m_left_decks;
	int m_num_shots;
	bool m_is_winner;
};

class Game
{
public:
	Game();	//конструктору
	virtual ~Game(); //деструктор
	void Start();
	void Finish();
	void PlayRound();
	void SetPlayers(IPlayer* player1, IPlayer* player2);
protected:
	void ShowFields();

protected:
	PlayerData m_player_data_1;
	PlayerData m_player_data_2;
};

