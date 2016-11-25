#pragma once
#include<cstring>
#include"Vector3.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	void InitializePlayer();
	void DecideToMoveORQuit(const char choice);
	void Move(const char choice);

	char Input();

private:
	char mName[5];
	Vector3 mPosition;
};
