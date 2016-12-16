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
#include"FixedSizeAllocator.h"

inline void InitializePlayer();
HeapAllocator heapallocator = HeapAllocator();
CMonster* listOfMonsters;
CMonster monster;
CPlayer* player;
int numberOfMonsters;
char choice = 'a';

int main() {

	//FixedSizeAllocator FSA = FixedSizeAllocator();
	srand((unsigned int)time(0));	//set the seed rolling with time
	
	//player = (CPlayer*)heapallocator.AllocateMemory(sizeof(CPlayer));
	//player = (CPlayer*)heapallocator.operator new (sizeof(CPlayer));
	player = new CPlayer();

	if (player != nullptr) {
		Input();
		InitializePlayer();
		Generate();
		Update();
		CleanMemory();
	}

	system("pause");
	return 0;
}


///*----------------------------------------------------------WILL NOT BE EXECUTED-------------------------------------------------------------*/
inline void Input() {
	printf("Enter the number of Monsters\n");

	scanf_s("%d", &numberOfMonsters);

	if (numberOfMonsters == 0 || numberOfMonsters < 0) {
		Input();
	}
}

void Generate() {
	listOfMonsters = new CMonster[numberOfMonsters];
	monster.InitializeMonster(numberOfMonsters, &listOfMonsters);
}

inline void InitializePlayer() {
	player->InitializePlayer();
}

void Update() {
	do {
		monster.Move(numberOfMonsters, &listOfMonsters);
		//monster.DisplayMonsterData(numberOfMonsters, listOfMonsters);
		choice = player->Input();
	} while (choice != 'q') ;
}

void CleanMemory() {
	/*clean up memory*/
	void* playerAddress = (void*)player;
	//heapallocator.DeallocateMemory(player);
	delete[] listOfMonsters;
	
	listOfMonsters = 0;
	player = 0;
}
///*----------------------------------------------------------WILL NOT BE EXECUTED-------------------------------------------------------------*/