#pragma once
#include"BitArray.h"

struct FixedSizedBlock {
	size_t mBlockSize;
	void* mAddress;
};

class FixedSizeAllocator {
public:
	FixedSizeAllocator();
	~FixedSizeAllocator();

	void * alloc(size_t i_size);
	static void GetTheStartingAddress(void* mStartingAddressFSA);
	void SegregateBlocks();
private:
	BitArray* mAvailableBits;
	size_t mBlockSize;
	unsigned int mNumberOfBlocks;
	char* mStartingAddressFSA;
	char* mEndingAddressFSA;
	const size_t mTotalFSASize = 100;
};

