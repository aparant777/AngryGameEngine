#pragma once
#include"Vector3.h"

class GameObject {
public:
	GameObject(const Vector3& position, char* name);
	inline Vector3 GetPosition() const { return mPosition; }
	void SetPosition(Vector3& newPosition) ;
	inline bool IsActive() const { return mIsActive; }
	void SetActive(bool isItActive);
	//void SetName(char newName[5]);

private:
	char* mName;
	Vector3 mPosition;
};