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

	
	mPosition = mPosition.zero;
	


	printf("\n");
	printf("%s spawned at ", mName);
	printf("location");
	mPosition.printInInt();
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
		mPosition += mPosition.left;
		printf("%s moved left.\n",mName);
		Vector3 position = Vector3::left;
	}
	else if (choice == 'W' || choice == 'w') {
		mPosition += mPosition.up;
		printf("%s moved up.\n",mName);
		Vector3 position = Vector3::up;
	}
	else if (choice == 'S' || choice == 's') {
		mPosition += mPosition.down;
		printf("%s moved down.\n",mName);
		Vector3 position = Vector3::down;
	}
	else if (choice == 'D' || choice == 'd') {
		mPosition += mPosition.right;
		printf("%s moved right.\n",mName);
		Vector3 position = Vector3::right;
	}
	mPosition.printInInt();
}

void CPlayer::GetMovementDirectionFromUserInput() {
	
}



CPlayer::~CPlayer() { }
