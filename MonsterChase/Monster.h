#pragma once
#include<cstring>
#include"Vector3.h"
#include"GameObject.h"
#include"IGameObjectController.h"

class CMonster : IGameObjectController {
public:
	CMonster();
	~CMonster();
	void SetGameObject(GameObject* gameObject) override { gameObjectMonster = gameObject; }
	void UpdateGameObject() override {	}
	void InitializeMonster(int numberOfMonsters, CMonster** listOfMonsters);
	//void Move(int numberOfMonsters, CMonster &listOfMonsters);
	void EncounterAnotherMonster(int numberOfMonsters, CMonster* listOfMonsters);
	void CMonster::DisplayMonsterData(int numberOfMonsters, CMonster* listOfMonsters);
	void FreeMemory(CMonster* monster);
	bool IsDead();
	void Move(int numberOfMonsters, CMonster ** listOfMonsters);
	inline char* GetName() { return mName; }
	//inline float GetPositionX() { return mPosition.GetPositionX(); }
	//inline float GetPositionY() { return mPosition.GetPositionY(); }

private:
	GameObject* gameObjectMonster;
	char mName[10];
	int mLifetime;
	CMonster* tempListArray;
};

