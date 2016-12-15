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
		listOfMonsters[i].gameObjectMonster->SetPosition(Vector3(static_cast<float>(Random(0, 100)), static_cast<float>(Random(0, 100)), 0));
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
		float newPositionX = 0; 
		float newPositionY = 0;
		if (choice == 1) {
			newPositionX = static_cast<float>( Random(-1, 1));
		} else {
			newPositionY = static_cast<float>(Random(-1, 1));
		}
		Vector3 receivedPosition = listOfMonsters[i].gameObjectMonster->GetPosition();
		Vector3 newPosition = receivedPosition + Vector3(newPositionX, newPositionY, 0.0f);
		listOfMonsters[i].gameObjectMonster->SetPosition(newPosition);
		listOfMonsters[i].mLifetime--;	//decrease the life of the monster by one
	}	
}

/*Displays monster data*/
void CMonster::DisplayMonsterData(int numberOfMonsters, CMonster* listOfMonsters) {
	for (int i = 0;i < numberOfMonsters;i++) {
		printf("Monster position at ");
		listOfMonsters[i].gameObjectMonster->PrintPosition();
		printf("/n");
	}
}

/*Checks whether a monster encounters another one at same position*/
void CMonster::EncounterAnotherMonster(int numberOfMonsters, CMonster* listOfMonsters) {
	for (int i = 0;i < numberOfMonsters;i++) {
		if (listOfMonsters[i].gameObjectMonster->GetPosition() ==  gameObjectMonster->GetPosition()) {
			//generate a new monster
			CMonster* newMonster = new CMonster;
		}
	}
}

/*Delete the memory generated and set its pointer to 0*/
void CMonster::FreeMemory(CMonster* listOfMonsters) {
	delete[] listOfMonsters;
	listOfMonsters = 0;
}

CMonster::~CMonster() {
}