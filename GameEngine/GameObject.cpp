#include"GameObject.h"
#include"Vector3.h"
#include<stdio.h>

void GameObject::PrintPosition() {
	printf("Position is: (%f, %f, %f). \n", mPosition.GetPositionX(), mPosition.GetPositionY(), mPosition.GetPositionZ());
}
