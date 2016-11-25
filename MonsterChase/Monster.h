#pragma once
#include<cstring>
#include"Vector3.h"

class CMonster {
	
public:
	CMonster();
	~CMonster();

	void InitializeMonster(CMonster* monster);
	void Move(CMonster* monster);
	void EncounterAnotherMonster(CMonster* monster);	
	void CMonster::DisplayMonsterData(CMonster* monster);
	void FreeMemory(CMonster* monster);
	bool IsDead();
	char* GetName();
	float GetPositionX();
	float GetPositionY();

private:
	char mName[100];
	Vector3 mPosition;
	int mlifetime;
};

