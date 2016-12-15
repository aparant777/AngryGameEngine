#pragma once

inline void Input();
void Generate();

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
#include"BitArray.h"

inline void InitializePlayer();
HeapAllocator heapallocator = HeapAllocator();
CMonster* listOfMonsters;
CMonster monster;
CPlayer* player;
int numberOfMonsters;
char choice = 'a';
char* a;
int main() {

	srand((unsigned int)time(0));	//set the seed rolling with time
	/*
		NEW and DELETE have not been globally overloaded. Since this will mess up usage of STL in later versions of the engine.
		Since all custom memory allocations go through the HeapAllocator class, the operators overloaded are class specific.
	*/
	//void* addressReceived = heapallocator.AllocateMemory(sizeof(CPlayer));
	
	//player = (CPlayer*)addressReceived;
	//heapallocator.DeallocateMemory(player1);
	//player = (CPlayer*)heapallocator.AllocateMemory(sizeof(CPlayer));
	printf("\n\n\n");

	//player = (CPlayer*)heapallocator.operator new (sizeof(CPlayer));
	player = new CPlayer();
	printf("size of player is %d. \n", sizeof(CPlayer));

	//BitArray* bitArray = new BitArray(8, heapallocator, true);

	if (player != nullptr) {
		Input();
		Generate();
		InitializePlayer();
		Update();
		CleanMemory();
	}

	system("pause");
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
	printf("size of monster is %d. \n", sizeof(CMonster));
	listOfMonsters = new CMonster[numberOfMonsters];

	monster.InitializeMonster(numberOfMonsters, listOfMonsters);
}

inline void InitializePlayer() {
	player->InitializePlayer();
}

void Update() {
	do {
		monster.Move(numberOfMonsters, listOfMonsters);
		monster.DisplayMonsterData(numberOfMonsters, listOfMonsters);
		choice = player->Input();
	} while (choice != 'q') ;
}

void CleanMemory() {
	/*clean up memory*/
	void* playerAddress = (void*)player;
	heapallocator.DeallocateMemory(player);
	delete[] listOfMonsters;
	
	listOfMonsters = 0;
	player = 0;
}