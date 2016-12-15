#pragma once
#include "HeapAllocator.h"
#include <stdio.h>
#include <string.h>

class BitArray
{
public:
	BitArray();
	BitArray(size_t i_numBits, HeapAllocator  i_pManager, bool i_startClear = true);
	
	BitArray * Create(size_t i_numBytes, HeapAllocator  i_pManager, bool i_startClear = true);
	void ClearAll();
	void SetAll(bool isSetTrue);

	bool AreAllClear() const;
	bool AreAllSet() const;

	bool IsBitSet(size_t bitNumber) const;
	bool IsBitClear(size_t bitNumber) const;

	void SetBit(size_t bitNumber);
	void ClearBit(size_t bitNumber);

	size_t GetFirstClearBit() const;
	size_t GetFirstSetBit() const;

private:
	
	uint8_t *m_pBits;

	/*number of bits per byte*/
	const static size_t bitsPerBytes = 8;
	
	/*the number of bits*/
	size_t m_numBits;
};

