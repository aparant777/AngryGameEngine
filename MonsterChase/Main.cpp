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
CPlayer* player1;
CPlayer* player2;
CPlayer* player3;
int numberOfMonsters;
char choice = 'a';

int main() {

	srand((unsigned int)time(0));	//set the seed rolling with time
	
	//heapallocator.PrintMemorySize();

	char* a = (char*)heapallocator.AllocateMemory(20);
	heapallocator.DeallocateMemory(a);
	char* c = (char*)heapallocator.AllocateMemory(20);
	heapallocator.DeallocateMemory(a);

	printf("------------------------------------------------------------------------\n");


	player = static_cast<CPlayer*>(heapallocator.AllocateMemory(sizeof(CPlayer)));
	/*player1 = static_cast<CPlayer*>(heapallocator.AllocateMemory(sizeof(CPlayer)));
	player2 = static_cast<CPlayer*>(heapallocator.AllocateMemory(sizeof(CPlayer))); 
	player3 = static_cast<CPlayer*>(heapallocator.AllocateMemory(sizeof(CPlayer)));*/

	//heapallocator.PrintMemorySize();

	/*
	player->
	*/

	//heapallocator.PrintMemorySize();
	//int length = heapallocator.heapUsedDescriptorList.GetLength();
	//printf("Length of linked list is %d.\n", length);
	//heapallocator.heapUsedDescriptorList.DeleteLastNode();
	//HeapDescriptor* heapDescriptor1 = (HeapDescriptor*)heapallocator.heapUsedDescriptorList.GetElement(1);
	
	//send the address to the heapallocator for 

	//heapallocator.DeallocateMemory(player);
	
	//heapallocator.heapUsedDescriptorList.PrintLinkedList();
	//printf("Length of linked list is %d.\n", heapallocator.heapUsedDescriptorList.GetLength());
	//heapallocator.heapUsedDescriptorList.DeleteFirstNode();
	//heapallocator.heapUsedDescriptorList.PrintLinkedList();
	//heapallocator.heapUsedDescriptorList.DeleteFirstNode();
	
	//heapallocator.GetHeapSize();
	//heapallocator.heapUsedDescriptorList.PrintLinkedList();

	printf("&player = %u. \n", &player);
	heapallocator.DeallocateMemory(player);

	//printf("Length of linked list is %d.\n", heapallocator.heapUsedDescriptorList.GetLength());

	printf("\n\n\n");

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
	//delete player;
	listOfMonsters = 0;
	player = 0;
}