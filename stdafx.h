// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <d3d9.h>
#include <d3dx9.h>
#include <mmsystem.h>

#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")
#pragma comment (lib, "winmm.lib")

using namespace std;
#include <string>
#include <vector>
#include <list>
#include <map>

#include "TextureInfo.h"
#include "GameObject.h"
#include "GrapicManager.h"
#include "ObjectManager.h"
#include "TextureManager.h"
#include "Player.h"
#include "Camera.h"
#include "SceneManager.h"
#include "BoxCollider.h"
#include "MonsterParent.h"
#include "SoundManager.h"
#include "GameManager.h"
#include "Layer.h"
//#include "ItemParent.h"
#include "Effect.h"
//#include "DieEffect.h"
#include "PhanClose.h"
#include "PhanOpen.h"

//콘솔창 띄우기
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
//#define FULLSCREEN false;
#define FULLSCREEN true;