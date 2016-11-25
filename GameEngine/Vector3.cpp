#include "Vector3.h"
#include<stdio.h>

/*static variables*/
Vector3 Vector3::zero = Vector3(0, 0, 0);
Vector3 Vector3::right = Vector3(1, 0, 0);
Vector3 Vector3::left = Vector3(-1, 0, 0);
Vector3 Vector3::up = Vector3(0, 1, 0);
Vector3 Vector3::down = Vector3(0, -1, 0);

/*default vector of <0,0,0>*/
Vector3::Vector3() {
	mX = 0;
	mY = 0;
	mZ = 0;
}

/*vector which takes in parameters*/
Vector3::Vector3(const float x, const float y,const float z) {
	mX = x;
	mY = y;
	mZ = z;
}

/*getter functions*/
float Vector3::GetPositionX() const {
	return mX;
}

float Vector3::GetPositionY() const{
	return mY;
}

float Vector3::GetPositionZ() const {
	return mZ;
}

/*setter functions*/
void Vector3::SetPositionX(float x) {
	mX = x;
}

void Vector3::SetPositionY(float y) {
	mY = y;
}

void Vector3::SetPositionZ(float z) {
	mZ = z;
}

/*Check if 2 vectors are equal or not*/
bool Vector3::operator==(const Vector3& v) {
	if (mX == v.mX && mY == v.mY && mZ == v.mZ) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector3::operator!=(const Vector3& v) {
	if (mX != v.mX || mY != v.mY || mZ != v.mZ) {
		return true;
	}
	else {
		return false;
	}
}

/*addition of 2 vectors (+ operator)*/
Vector3 Vector3::operator+(const Vector3& v) {
	Vector3 sum;
	sum.mX = mX + v.mX;
	sum.mY = mY + v.mY;
	sum.mZ = mZ + v.mZ;
	return sum;
}

/*addition of 2 vectors (+= operator)*/
Vector3& Vector3::operator+=(const Vector3& v) {
	this->mX = this->mX + v.mX;
	this->mY = this->mY + v.mY;
	this->mZ = this->mZ + v.mZ;
	return *this;
}

/*subtraction of 2 vectors (- operator)*/
Vector3 Vector3::operator-(const Vector3& v) {
	Vector3 sub;
	sub.mX = mX - v.mX;
	sub.mY = mY - v.mY;
	sub.mZ = mZ - v.mZ;
	return sub;
}

/*addition of 2 vectors (-= operator)*/
Vector3& Vector3::operator-=(const Vector3& v) {
	this->mX = this->mX - v.mX;
	this->mY = this->mY - v.mY;
	this->mZ = this->mZ - v.mZ;
	return *this;
}

/*multiplication of vectors (* operator)*/
Vector3 Vector3::operator*(const float f) {
	Vector3 mul;
	mul.mX = f * mX;
	mul.mY = f * mY;
	mul.mZ = f * mZ;
	return mul;
}

/*multiplication of vectors (*= operator)*/
Vector3& Vector3::operator*=(const float f) {
	this->mX = this->mX * f;
	this->mY = this->mY * f;
	this->mZ = this->mZ * f;
	return *this;
}

/*inverse of the current vector*/
Vector3 Vector3::inverse() {
	Vector3 v;
	v.mX = -mX;
	v.mY = -mY;
	v.mZ = -mZ;
	return v;
}

/*print the vector*/
void Vector3::printInFloat() {
	printf("< %f, %f, %f > \n", mX, mY, mZ);
}

void Vector3::printInInt() {
	int mXInt = static_cast<int>(mX);
	int mYInt = static_cast<int>(mY);
	int mZInt = static_cast<int>(mZ);

	printf("< %d, %d, %d > \n", mXInt, mYInt, mZInt);
}

/*input the vector*/
void Vector3::input() {
	printf("Enter x: ");
	scanf_s("%f", &mX);
	printf("Enter y: ");
	scanf_s("%f", &mY);
	printf("Enter Z: ");
	scanf_s("%f", &mZ);
}

Vector3::~Vector3() {}