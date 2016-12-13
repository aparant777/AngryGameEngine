#include<stdio.h>
#include"Random.h"
#include "Monster.h"
#include"Vector3.h"


CMonster::CMonster() { }

/*initializes the Monster class and gives them a random position and lifetime*/
void CMonster::InitializeMonster(int numberOfMonsters, CMonster* listOfMonsters) {
	for (int i = 0;i < numberOfMonsters;i++) {
		printf("Enter the name of the monster: ");
		scanf_s("%s", &mName, 100);
		listOfMonsters[i].SetGameObject( new GameObject(Vector3(0, 0, 0), mName));
		listOfMonsters[i].gameObjectMonster->PrintPosition();
		listOfMonsters[i].gameObjectMonster->SetPosition(Vector3(Random(0, 100), Random(0, 100), 0));
		listOfMonsters[i].mLifetime = Random(10, 15);
	}
}

/*Checks whether monster is dead or not*/
bool CMonster::IsDead() {
	if (mLifetime <= 0) {
		return true;
	}
	else {
		return false;
	}
}

/*Moves the monster randomly, either + or - in X or Y*/
void CMonster::Move(int numberOfMonsters, CMonster* listOfMonsters) {

	for (int i = 0;i < numberOfMonsters;i++) {
		int choice = Random(1, 2);
		float newPositionX, newPositionY;
		if (choice == 1) {
			newPositionX = listOfMonsters[i].gameObjectMonster->mPosition.GetPositionX() + Random(-1, 1);

		} else {
			newPositionY = listOfMonsters[i].gameObjectMonster->mPosition.GetPositionY() + Random(-1, 1);
		}
		Vector3 newPosition = gameObjectMonster->GetPosition() + Vector3(newPositionX, newPositionY, 0.0f);
		listOfMonsters[i].mLifetime--;	//decrease the life of the monster by one
	}	
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

/*Delete the memory generated and set its pointer to 0*/
void CMonster::FreeMemory(CMonster* monster) {
	delete monster;
	monster = 0;
}

CMonster::~CMonster() {
}