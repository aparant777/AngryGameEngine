#pragma once
#include"GameObject.h"
class IGameObjectController
{
public:
	virtual void SetGameObject(GameObject* gameObject) = 0;
	virtual void UpdateGameObject() = 0;
};

