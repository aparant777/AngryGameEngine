#include"GameObject.h"
#include"Vector3.h"
#include<stdint.h>

void GameObject::SetPosition(Vector3 & newPosition) {
	mPosition = newPosition;
}

void GameObject::SetActive(bool isItActive) {
	mIsActive = isItActive;
}
