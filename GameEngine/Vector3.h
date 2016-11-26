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

	inline void printInFloat() const;
	void printInInt() const;
	inline void input();

	//getters
	inline float GetPositionX() const { return mX; }
	inline float GetPositionY() const { return mY; }
	inline float GetPositionZ() const { return mZ; }

	//setters
	void SetPositionX(const float f);
	void SetPositionY(const float f);
	void SetPositionZ(const float f);

private:
	float mX;
	float mY;
	float mZ;
};