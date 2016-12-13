#pragma once

inline void Input();
void Generate();
inline void InitializePlayer();
void Update();
void CleanMemory();

#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<conio.h>
#include"HeapAllocator.h"
#include"Monster.h"
#include"Player.h"
#include"Main.h"
#include"GameObject.h"

HeapAllocator heapallocator = HeapAllocator();
CMonster* listOfMonsters;
CMonster monster;
CPlayer* player;
int numberOfMonsters;
char choice = 'a';

int main() {

	srand((unsigned int)time(0));	//set the seed rolling with time
	/*
		NEW and DELETE have not been globally overloaded. Since this will mess up usage of STL in later versions of the engine.
		Since all custom memory allocations go through the HeapAllocator class, the operators overloaded are class specific.
	*/
	
	//heapallocator.DeallocateMemory(player1);
	printf("\n\n\n");
	//player = (CPlayer*)heapallocator.operator new (sizeof(CPlayer));
	player = new CPlayer();

	if (player != nullptr) {
		Input();
		Generate();
		InitializePlayer();
		Update();
		CleanMemory();
	}

	return 0;
}

inline void Input() {
	printf("Enter the number of Monsters\n");
	scanf_s("%d", &numberOfMonsters);

	if (numberOfMonsters == 0 || numberOfMonsters < 0) {
		Input();
	}
}

void Generate() {
	listOfMonsters = new CMonster[numberOfMonsters];
	for (int i = 0;i < numberOfMonsters;i++) {
		monster.InitializeMonster(&listOfMonsters[i]);
	}
}

inline void InitializePlayer() {
	player->InitializePlayer();
}

void Update() {
	do {
		for (int i = 0;i < numberOfMonsters;i++) {
			if (listOfMonsters[i].IsDead() == false) {
				monster.Move(&listOfMonsters[i]);
				monster.DisplayMonsterData(&listOfMonsters[i]);
				monster.EncounterAnotherMonster(&listOfMonsters[i]);
			}
			else {
				monster.FreeMemory(&listOfMonsters[i]);
			}
		}
		choice = player->Input();

	} while (choice != 'q') ;
}

void CleanMemory() {
	/*clean up memory*/
	delete[] listOfMonsters;
	heapallocator.DeallocateMemory(player);
	listOfMonsters = 0;
	player = 0;
}