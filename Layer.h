#pragma once
class Layer
{
public:
	Layer();
	~Layer();

	const static int DEFAULT = 1 << 1;
	const static int BLOCK = 1 << 2;
	const static int BLOCKUP = 1 << 3;
	const static int MONSTER = 1 << 4;
	const static int BULLET = 1 << 5;
	const static int MONSTERBULLET = 1 << 6;
	const static int PLAYER = 1 << 7;
	const static int ITEM = 1 << 8;
	const static int BOX = 1 << 9;

};

