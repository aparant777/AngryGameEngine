#pragma once
#include<stdint.h>
class BitArray {
public:

	BitArray(size_t numberOfBits, bool isInitializedToZero);
	/*get the bit having value 1*/
	bool FindFirstSetBit();

	/*set all bits to 0*/
	void ClearAll();

	/*Sets all bits to a specific value*/
	void SetAll(bool isSetAll);

	~BitArray();

private:
	uint8_t* mBytes;
	size_t mNumberOfBytes;
	size_t mNumberOfBits;
};

