#pragma once
#include"Vector3.h"

class GameObject {
public:
	
	inline Vector3 GetPosition() const { return mPosition; }
	void SetPosition(Vector3& newPosition) { mPosition = newPosition; }

private:
	Vector3 mPosition;
};