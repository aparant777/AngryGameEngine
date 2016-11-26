#pragma once
#include<cstring>
#include"Vector3.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	void InitializePlayer();
	inline void DecideToMoveORQuit(const char choice);
	inline void Move(const char choice);

	const char Input();

private:
	char mName[5];
	Vector3 mPosition;
};
