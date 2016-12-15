#pragma once
#include<cstring>
#include"GameObject.h"
#include"Vector3.h"
#include"IGameObjectController.h"

class CPlayer : IGameObjectController {
public:
	CPlayer();	
	~CPlayer();
	void SetGameObject(GameObject* gameObject) override { gameObjectPlayer = gameObject; }
	void UpdateGameObject() override;
	void InitializePlayer();
	inline void DecideToMoveORQuit(const char choice);
	inline void Move(const char choice);
	void GetMovementDirectionFromUserInput();
	const char Input();

private:
	GameObject* gameObjectPlayer;
	char mName[10];
};