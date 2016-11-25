#include<stdio.h>
#include"Random.h"
#include "Monster.h"
#include"Vector3.h"


CMonster::CMonster() { }

/*initializes the Monster class*/
void CMonster::InitializeMonster(CMonster* monster) {
	printf("Enter the name of the monster: ");
	scanf_s("%s", &monster->mName, 100);
	
	monster->mPosition.SetPositionX(monster->mPosition.GetPositionX() + Random(0, 100));
	monster->mPosition.SetPositionY((monster->mPosition.GetPositionY() + Random(0, 100)));
	monster->mlifetime = Random(10, 15);
}

/*Checks whether monster is dead or not*/
bool CMonster::IsDead() {
	if (mlifetime <= 0) {
		return true;
	}
	else {
		return false;
	}
}

/*Moves the monster randomly, either + or - in X or Y*/
void CMonster::Move(CMonster* monster) {
	int choice = Random(1, 2);
	if (choice == 1) {
		monster->mPosition.SetPositionX((monster->mPosition.GetPositionX() + Random(-1, 1)));
	}
	else {
		monster->mPosition.SetPositionY(monster->mPosition.GetPositionY() + Random(-1, 1));
	}
	mlifetime--;	//decrease the life of the monster by one
}

/*Displays monster data*/
void CMonster::DisplayMonsterData(CMonster* monster) {
	printf("Monster %s is ", monster->mName);
	monster->mPosition.printInInt();
	//std::cout << "Monster " << monster->GetName() << " at (" << monster->GetPositionX() << ", " << monster->GetPositionY() << ")." << std::endl;
}

/*Checks whether a monster encounters another one at same position*/
void CMonster::EncounterAnotherMonster(CMonster* anotherMonster) {
	if (anotherMonster->mPosition == mPosition) {
		//generate a new monster
		CMonster* newMonster = new CMonster;
	}
}

/*Getter Functions*/
char* CMonster::GetName() {
	return mName;
}

float CMonster::GetPositionX() {
	return mPosition.GetPositionX();
}

float CMonster::GetPositionY() {
	return mPosition.GetPositionY();
}

/*Delete the memory generated and set its pointer to 0*/
void CMonster::FreeMemory(CMonster* monster) {
	delete monster;
	monster = 0;
}

CMonster::~CMonster() {
}