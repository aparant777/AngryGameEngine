#include<stdio.h>
#include<conio.h>
#include"HeapAllocator.h"
#include "Player.h"
#include"Vector3.h"

CPlayer::CPlayer() { }

/*initializes the Player class*/
void CPlayer::InitializePlayer() {
	printf("Enter the name of the player: ");
	scanf_s("%s", mName, 100);
	printf("player name is %s. \n\n", mName);
	printf("all oke re..");
	GameObject* temp = new GameObject(Vector3(0, 0, 0), mName);
	printf("\n\n till herer we got");
	SetGameObject(temp);
	//player->gameObjectPlayer->SetPosition(Vector3::zero);
	
	printf("\n");
	printf("%s spawned at ", mName);
	printf("location");
	gameObjectPlayer->PrintPosition();
}

/* will spill out a character to Move or Exit*/
const char CPlayer::Input() {
	char choice = 'a';
	printf("Press 'A' to move Left, 'D' for Right, 'W' for Forward and 'S' for Down. Press 'Q' to Quit.\n");
	choice = _getch();
	DecideToMoveORQuit(choice);
	return choice;
}

inline void CPlayer::DecideToMoveORQuit(const char choice) {
	if (choice == 'A' || choice == 'a' || choice == 'W' || choice == 'w' || choice == 'S' || choice == 's' || choice == 'D' || choice == 'd') {
		Move(choice);
	}
	else {
	}
}

/*Moves the Player, either + or - in X or Y*/
inline void CPlayer::Move(const char choice) {
	if (choice == 'A' || choice == 'a') {
		Vector3 newPosition = gameObjectPlayer->GetPosition() + Vector3::left;
		printf("%s moved left.\n",mName);
		gameObjectPlayer->SetPosition(newPosition);
		//gameObjectPlayer->PrintPosition();
	}
	else if (choice == 'W' || choice == 'w') {
		Vector3 newPosition = gameObjectPlayer->GetPosition() + Vector3::up;
		printf("%s moved up.\n", mName);
		gameObjectPlayer->SetPosition(newPosition);
		//gameObjectPlayer->PrintPosition();

	}
	else if (choice == 'S' || choice == 's') {
		Vector3 newPosition = gameObjectPlayer->GetPosition() + Vector3::down;
		printf("%s moved down.\n", mName);
		gameObjectPlayer->SetPosition(newPosition);
		//gameObjectPlayer->PrintPosition();
	}
	else if (choice == 'D' || choice == 'd') {
		Vector3 newPosition = gameObjectPlayer->GetPosition() + Vector3::right;
		printf("%s moved right.\n", mName);
		gameObjectPlayer->SetPosition(newPosition);
		//gameObjectPlayer->PrintPosition();
	}
	gameObjectPlayer->PrintPosition();
}

void CPlayer::GetMovementDirectionFromUserInput() {
	
}

void CPlayer::UpdateGameObject() {

}

CPlayer::~CPlayer() { }
