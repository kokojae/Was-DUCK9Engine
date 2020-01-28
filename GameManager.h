#pragma once


class ScoreIt
{
public:
	string name;
	int score;
};

class GameManager
{
public:
	GameManager();
	~GameManager();

	static list<ScoreIt*> score_list;

	static int score1;
	static int score2;
	static int hp;
	static int hack;
	static int homing;

	static bool player_alive;

	static D3DXVECTOR2 check;

	static bool speedup;
	static bool doublejump;
	static bool rangeup;
	static bool tripple;
	static int buff_count;
	static int player_level;

	static int cheat_dontdie;

	static void Reset();
	static void GameOver();
	static void GameWin();
	static void ReStart();
	static void HardReset();

	static void InputScore(string name, int s)
	{
		ScoreIt* it = new ScoreIt;
		it->name = name;
		it->score = s;
		score_list.push_back(it);
		score_list.sort(ScoreSort);

	}

	static bool ScoreSort(const ScoreIt* a, const ScoreIt* b);


};

