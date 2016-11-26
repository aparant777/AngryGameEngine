#pragma once

void Input();
void Generate();
void InitializePlayer();
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
#include "Main.h"

HeapAllocator heapallocator = HeapAllocator();
CMonster* listOfMonsters;
CMonster monster;
CPlayer* player;
CPlayer* player1;
CPlayer* player2;
int numberOfMonsters;
char choice = 'a';

int main() {

	srand((unsigned int)time(0));	//set the seed rolling with time
	
	//heapallocator.PrintMemorySize();
	
	player = static_cast<CPlayer*>(heapallocator.AllocateMemory(sizeof(CPlayer)));
	//heapallocator.PrintMemorySize();
	
	player1 = static_cast<CPlayer*>(heapallocator.AllocateMemory(sizeof(CPlayer)));

	player2 = static_cast<CPlayer*>(heapallocator.AllocateMemory(sizeof(CPlayer)));

	heapallocator.PrintMemorySize();
	
	//heapallocator.PrintMemorySize();
	//int length = heapallocator.heapUsedDescriptorList.GetLength();
	//printf("Length of linked list is %d.\n", length);
	//heapallocator.heapUsedDescriptorList.DeleteLastNode();
	//HeapDescriptor* heapDescriptor1 = (HeapDescriptor*)heapallocator.heapUsedDescriptorList.GetElement(1);
	printf("Size of player class is %zu", sizeof(player));
	heapallocator.DeallocateMemory(player);

	if (player != nullptr) {
		Input();
		Generate();
		InitializePlayer();
		Update();
		CleanMemory();
	}
	
	//system("pause");
	return 0;
}

void Input() {
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

void InitializePlayer() {
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
	//delete player;
	listOfMonsters = 0;
	player = 0;
}