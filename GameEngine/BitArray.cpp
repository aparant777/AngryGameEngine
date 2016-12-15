#include "BitArray.h"
#include<assert.h>
#include<string.h>

BitArray::BitArray(size_t numberOfBits, bool isInitializedToZero) {
	const size_t bitsPerByte = 8;
	mBytes = new uint8_t[numberOfBits / bitsPerByte];
	assert(mBytes);

	memset(mBytes, isInitializedToZero ? 0 : 1, numberOfBits / bitsPerByte);
	FindFirstSetBit();
}

bool BitArray::FindFirstSetBit() {
	size_t index = 0;
	while ((mBytes[index] == 0xFF) && (index < mNumberOfBytes)) {
		index++;
	}
}

void BitArray::ClearAll() {
	memset(mBytes, 0, mNumberOfBits / mNumberOfBytes);
}

void BitArray::SetAll(bool isSetAll) {
	memset(mBytes, isSetAll ? 0 : 1, mNumberOfBits / mNumberOfBytes);
}

BitArray::~BitArray()
{
}
