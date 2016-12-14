#pragma once
#include "MemoryAllocator.h"
#include"LinkedList.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


MemoryAllocator::MemoryAllocator() {
	mIsMemoryAllocated = false;
	mAllocatedAddress = nullptr;
	mTotalMemorySize = SAMPLE_MEMORY_SIZE_TOTAL;
	mCurrentMemoryHeapSize = mTotalMemorySize;
	mCurrentMemoryFreeHeapDescriptorSize = SAMPLE_MEMORY_SIZE_FREEHEAPDESCRIPTOR_LIST;
	mCurrentMemoryUsedHeapDescriptorSize = SAMPLE_MEMORY_SIZE_USEDHEAPDESCRIPTOR_LIST;
	mCurrentMemoryAddress = nullptr;
	mCurrentFreeHeapDescriptorAddress = nullptr;
	mCurrentUsedHeapDescriptorAddress = nullptr;

	MemoryAllocated();
}

MemoryAllocator::~MemoryAllocator() {

}

/*generate some default memory, if not called, this function gets automatically called when memory is requested*/
inline void MemoryAllocator::MemoryAllocated() {
	mIsMemoryAllocated = true;
	mAllocatedAddress = static_cast<char*>(malloc(SAMPLE_MEMORY_SIZE_TOTAL));
	/*give the current memory address as the newly generated address*/
	mCurrentMemoryAddress = mAllocatedAddress;
	printf("mAllocatedAddress = %p.\n", (void*)&mAllocatedAddress);
	SeperateMemory();
}

/*seperate addresses will be given for the Heap, Free and Used Lists*/
inline void MemoryAllocator::SeperateMemory() {
	/*poiners bumped to their respective positions*/
	mStartHeapAddress = mAllocatedAddress;
	mStartFreeHeapDescriptorListAddress = mStartHeapAddress + SAMPLE_MEMORY_SIZE_FREEHEAPDESCRIPTOR_LIST;
	mCurrentFreeHeapDescriptorAddress = mAllocatedAddress + SAMPLE_MEMORY_SIZE_FREEHEAPDESCRIPTOR_LIST;

	mStartUsedHeapDescriptorListAdress = mStartFreeHeapDescriptorListAddress + SAMPLE_MEMORY_SIZE_USEDHEAPDESCRIPTOR_LIST;
	mCurrentUsedHeapDescriptorAddress = mCurrentFreeHeapDescriptorAddress + SAMPLE_MEMORY_SIZE_USEDHEAPDESCRIPTOR_LIST;

	WriteMemory_Free();
}

/*Writing 'F' to memory indicating its Free*/
inline void MemoryAllocator::WriteMemory_Free() {
	/*convert from char* to void*/
	void* tempAllocatedAddress = mAllocatedAddress;	
	memset(tempAllocatedAddress, static_cast<int>(FREE_MEMORY), SAMPLE_MEMORY_SIZE_TOTAL);
}

/*when user requests for memory*/
void* MemoryAllocator::MemoryRequest(size_t memorySizeRequested) {

	static int memoryCalledCount = 0;

	/*check if memory has been allocated, if no then allocate*/
	if (mIsMemoryAllocated) {
		printf("mIsMemoryAllcoated = %d\n", mIsMemoryAllocated);
		/*check if the first memory block is free*/
		if ((size_t)memchr(mCurrentMemoryAddress, static_cast<int>(FREE_MEMORY), 1) != USED_MEMORY ) {			
			/*check if the entire block requested by user is free*/ 
			if ((size_t)memchr(mCurrentMemoryAddress, static_cast<int>(FREE_MEMORY), memorySizeRequested) != USED_MEMORY) {
				/*check if the heap can be allocated */
				if (memorySizeRequested < mCurrentMemoryHeapSize) {
					char* tempAddresss = mCurrentMemoryAddress;
					/*cast to a void*/
					void* tempMCurrentMemoryAddress = mCurrentMemoryAddress;
					/*write to the memory that is now being used*/
					memset(tempMCurrentMemoryAddress, static_cast<int>(USED_MEMORY), memorySizeRequested);
					/*bump the currentMemoryAddress pointer to the next free memory*/
					mCurrentMemoryAddress += memorySizeRequested;
					/*update the current heap size*/
					UpdateHeapSize_Allocate(memorySizeRequested);
					/*update the totalMemorySize now*/
					mTotalMemorySize -= memorySizeRequested;

					memoryCalledCount++;
					printf("\n Memory Allocator called %d times\n", memoryCalledCount);

					/*finally, send it to user*/
					return tempAddresss;
				}else{
					printf("not enough memory to allocate (first). \n");
					return nullptr;
				}
			} else {
				printf("not enough memory to allocate (second). \n");
				return nullptr;
			}
		} else {
			printf("No memory left to allocate. \n");
			return nullptr;
		}
	} else {
		printf("Memory not yet allocated. Allocating memory from the system to you. \n");
		MemoryAllocated();
		printf("Done. Memory allocated. \n");
		/*then call the Request function for the user again*/
		printf("Recalling the MemoryRequest function again for you. \n");
		return MemoryRequest(memorySizeRequested);
	}
}

void* MemoryAllocator::MemoryRequest_HeapDescriptor(size_t heapDescriptorMemorySize) {
	if (mIsMemoryAllocated) {
		/*no need to check whether memory requested > size, since sizeof() will be used*/
		char* tempAddresss = mCurrentFreeHeapDescriptorAddress;
		//bump the pointer
		mCurrentFreeHeapDescriptorAddress += heapDescriptorMemorySize;
		//update the size of the heapDescriptor 
		mCurrentMemoryFreeHeapDescriptorSize -= heapDescriptorMemorySize;

		return tempAddresss;
	}else{
		printf("Memory not yet allocated. \n");
		return nullptr;
	}
}

void MemoryAllocator::PrintMemorySize() const {
	printf("Total Memory availabe is %zu. \n", mCurrentMemoryHeapSize);
}

void* MemoryAllocator::MemoryDeallocate(size_t memorySizeRequested, char* memoryAddress) {
	if (mIsMemoryAllocated) {
		//printf("char* memoryAddress = %d. \n", memoryAddress);
		/*only perform this operation if the memory set be deleted is a used memory*/
		if ((size_t)memchr(memoryAddress, static_cast<int>(USED_MEMORY), sizeof(char)) != FREE_MEMORY) {
			//char* tempAddresss = mCurrentMemoryAddress;
			void* tempMCurrentMemoryAddress = mCurrentMemoryAddress;
			/*write to the memory that is now being used*/
			memset(tempMCurrentMemoryAddress, static_cast<int>(FREE_MEMORY), memorySizeRequested);
			/*bump the currentMemoryAddress pointer to the next free memory*/
			mCurrentMemoryAddress -= memorySizeRequested;
			/*update the current heap size*/
			UpdateHeapSize_Deallocate(memorySizeRequested);
			/*finally, send it to user*/
			printf("Memory freed.\n");
			return nullptr;
		}
		else {
			printf("Memory is already free. No need to delete");
			return nullptr;
		}
	} else {
		printf("No memory allocated to delete. \n");
		return nullptr;
	}
}

inline size_t MemoryAllocator::GetMemorySize() const {
	return mTotalMemorySize;
}

inline void MemoryAllocator::UpdateHeapSize_Allocate(const size_t memorySizeRequested) {
	mCurrentMemoryHeapSize -= memorySizeRequested;
}

inline void MemoryAllocator::UpdateHeapSize_Deallocate(const size_t memorySizeRequested) {
	mCurrentMemoryHeapSize += memorySizeRequested;
//	printf("mCurrentMemoryHeapSize = %d. \n", mCurrentMemoryHeapSize);
	mTotalMemorySize += memorySizeRequested;
	//printf("mTotalMemorySize = %d. \n", mTotalMemorySize);
}