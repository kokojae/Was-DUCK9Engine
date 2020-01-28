#include "stdafx.h"
#include "GameManager.h"
//#include "DieEffect.h"
#include "YouDie.h"
#include "YouWin.h"

int GameManager::score1 = 0;
int GameManager::score2 = 0;
int GameManager::hp = 3;
bool GameManager::speedup = false;
bool GameManager::doublejump = false;
bool GameManager::rangeup = false;
bool GameManager::tripple = false;
int GameManager::buff_count = 0;
int GameManager::player_level = 0;
int GameManager::hack = 2;
int GameManager::homing = 3;
int GameManager::cheat_dontdie = false;
D3DXVECTOR2 GameManager::check = D3DXVECTOR2(0, 0);
bool GameManager::player_alive = true;
list<ScoreIt*> GameManager::score_list;

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::Reset()
{
	player_level = 0;
	buff_count = 0;
	speedup = false;
	doublejump = false;
	rangeup = false;
	homing = 2;
	tripple = false;
	hack = 2;
}

void GameManager::GameOver()
{
	if (GameManager::cheat_dontdie)
		return;
	if (SceneManager::current_scene == SceneManager::Stage1)
		score1 = 0;
	if (SceneManager::current_scene == SceneManager::Stage2)
		score2 = 0;
	//hp -= 1;
	player_alive = false;
	//ObjectManager::Instantiate<DieEffect>(Player::me->position)->Set(Player::me->texture.texture, Player::me->texture.size, 0);
	ObjectManager::Instantiate<YouDie>();
	SoundManager::PlayBGM(L"resorce/sound/scene/gameover.mp3");
	Player::me->destroy = true;
	//GameManager::Reset();
	//SceneManager::LoadScene(SceneManager::current_scene);
}

void GameManager::GameWin()
{
	player_alive = false;
	ObjectManager::Instantiate<YouWin>();
	SoundManager::PlayBGM(L"resorce/sound/scene/gameover.mp3");
	Player::me->destroy = true;
}

void GameManager::ReStart()
{
	GameManager::Reset();

	if (SceneManager::current_scene == SceneManager::Stage1)
		score1 = 0;
	if (SceneManager::current_scene == SceneManager::Stage2)
		score2 = 0;

	if (hp <= 0)
	{
		HardReset();
		ObjectManager::Instantiate<PhanClose>()->scene = SceneManager::Main;
	}
	else
	{
		ObjectManager::Instantiate<PhanClose>()->scene = SceneManager::current_scene;
	}
}

void GameManager::HardReset()
{
	hp = 3;
	check = D3DXVECTOR2(0, 0);
}

bool GameManager::ScoreSort(const ScoreIt* a, const ScoreIt* b)
{
	return a->score > b->score;
}
