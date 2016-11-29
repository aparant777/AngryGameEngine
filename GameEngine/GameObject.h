#pragma once
#include"Vector3.h"

class GameObject {
public:
	
	inline Vector3 GetPosition() const { return mPosition; }
	void SetPosition(Vector3& newPosition) ;
	inline bool IsActive() const { return mIsActive; }
	void SetActive(bool isItActive);
	//void SetName(char newName[5]);

private:
	Vector3 mPosition;
	char mName[5];
	static const int mID;
	bool mIsActive;
};