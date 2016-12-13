#pragma once
#include"Vector3.h"

class GameObject {
public:
	Vector3 mPosition;
	GameObject(const Vector3& position, char* name) :
		mName(name),
		mPosition(position)
	{
	}
		GameObject(const Vector3& position) :
			mName("default"),
			mPosition(position)
	{
	}

	inline Vector3 GetPosition() const { return mPosition; }
	void SetPosition(Vector3 newPosition) { mPosition = newPosition; }
	void PrintPosition();
	void SetName(char* name) { mName = name; }
private:
	char* mName;
	
};