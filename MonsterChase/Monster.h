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
	void InitializeMonster(CMonster* monster);
	void Move(CMonster* monster);
	void EncounterAnotherMonster(CMonster* monster);	
	void CMonster::DisplayMonsterData(CMonster* monster);
	void FreeMemory(CMonster* monster);
	bool IsDead();
	inline char* GetName() { return mName; }
	inline float GetPositionX() { return mPosition.GetPositionX(); }
	inline float GetPositionY() { return mPosition.GetPositionY(); }

private:
	GameObject* gameObjectMonster;
	char mName[10];

};

