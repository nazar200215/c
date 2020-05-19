#pragma once
#include "interfaces.h"

//���������� ��� ������(������ �� �����)
struct PlayerData
{
	PlayerData() 
	{
		m_player = nullptr;	//������ �� �����
		m_left_decks = 20;	//������� ��������� �����
		m_num_shots = 0;	//������� ������� �� ���
		m_is_winner = false; //�� ������ ����� �������/���
	}
	IPlayer* m_player;
	int m_left_decks;
	int m_num_shots;
	bool m_is_winner;
};

class Game
{
public:
	Game();	//������������
	virtual ~Game(); //����������
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

