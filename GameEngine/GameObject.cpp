#include"GameObject.h"
#include"Vector3.h"
#include<stdint.h>

GameObject::GameObject(const Vector3 & position, char * name) : 
	mPosition (position),
	mName(name) 
{	
}

void GameObject::SetPosition(Vector3 & newPosition) {
	mPosition = newPosition;
}

