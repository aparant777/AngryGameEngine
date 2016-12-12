#pragma once
#include"Vector3.h"

class GameObject {
public:
	GameObject(const Vector3& position, char* name);
	inline Vector3 GetPosition() const { return mPosition; }
	void SetPosition(Vector3& newPosition) ;

private:
	char* mName;
	Vector3 mPosition;
};