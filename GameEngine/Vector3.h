#pragma once
class Vector3 {

public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	bool operator==(const Vector3& v);
	bool operator!=(const Vector3& v);
	Vector3 operator+(const Vector3& v);
	Vector3 operator-(const Vector3& v);
	Vector3 operator*(const float f);
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(const float f);
	Vector3 inverse();

	//static variables
	static Vector3 zero;
	static Vector3 one;
	static Vector3 right;
	static Vector3 left;
	static Vector3 up;
	static Vector3 down;

	void printInFloat() const;
	void printInInt() const;
	void input();

	//getters
	float GetPositionX() const;
	float GetPositionY() const;
	float GetPositionZ() const;

	//setters
	void SetPositionX(float f);
	void SetPositionY(float f);
	void SetPositionZ(float f);

private:
	float mX;
	float mY;
	float mZ;
};