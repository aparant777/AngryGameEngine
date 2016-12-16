#include "FixedSizeAllocator.h"
#include"HeapAllocator.h"

MemoryAllocator memoryAllocator = MemoryAllocator();
FixedSizeAllocator::FixedSizeAllocator() {
	printf("we are in the FSA  Construtor. \n");
	mBlockSize = 5;
	memoryAllocator.InitializeMemoryAllocator();
	mStartingAddressFSA = memoryAllocator.mCurrentMemoryAddress;
	
}

void * FixedSizeAllocator::alloc(size_t sizeRequested) {
	if (sizeRequested < mBlockSize) {
		printf("the requested size is less than the block size.\n");
		return mStartingAddressFSA;
	} else {
		printf("the requested size is bigger than the block size.\n");
		return nullptr;
	}
}

void FixedSizeAllocator::GetTheStartingAddress(void * mStartingAddressFSA) {
	printf("the address receiveived is mAllocatedAddress = %p.\n", mStartingAddressFSA);
}

void FixedSizeAllocator::SegregateBlocks() {

}

FixedSizeAllocator::~FixedSizeAllocator() {

}