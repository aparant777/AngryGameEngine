#pragma once
#include"IGameObjectController.h"

class MonsterController : public IGameObjectController
{
public:
	MonsterController(const char* monsterName, const Vector3 monsterPosition);
	~MonsterController();
	
	void InitializeMonster();
	inline void DisplayPosition() const;
	inline void SetPosition();

	void SetGameObject(GameObject* gameObject) override {
		monster = gameObject;
	}

	void UpdateGame() override {

	}

private:
	char name[10];
	Vector3 monsterPosition;
	GameObject* monster;
};

