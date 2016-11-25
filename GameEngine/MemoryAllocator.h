#pragma once
#include"HeapAllocator.h"

class MemoryAllocator {
public:
	MemoryAllocator();
	~MemoryAllocator();

	/*Total Memory Allocated*/
	size_t mTotalMemorySize;

	/*Current Memory size of the Heap*/
	size_t mCurrentMemoryHeapSize;

	/*Current Memory size of the FreeHeapDescriptor */
	size_t mCurrentMemoryFreeHeapDescriptorSize;

	/*Current Memory size of the UsedHeapDescriptor */
	size_t mCurrentMemoryUsedHeapDescriptorSize;

	/*Current Free Memory Address */
	char* mCurrentMemoryAddress;

	/*current FreeHeapDescriptor Address*/
	char* mCurrentFreeHeapDescriptorAddress;

	/*current FreeUsedDescriptor Address*/
	char* mCurrentUsedHeapDescriptorAddress;

	/*needs to be called once, or gets automatically called*/
	void MemoryAllocated();
	
	/*Request Memory for Heap*/
	void* MemoryRequest(size_t memorySizeRequested);

	/*Request Memory for HeapDescriptor*/
	void* MemoryRequest_HeapDescriptor(size_t heapDescriptorMemorySize);

	/*Print Total Memory size*/
	void PrintMemorySize();

	/*Memory delete*/
	void* MemoryDeallocate(size_t memorySizeRequested);

	/*get the Total Memory Size*/
	int GetMemorySize();

private:
	bool mIsMemoryAllocated;
	
	char* mAllocatedAddress;
	const char* mStartHeapAddress;
	const char* mStartFreeHeapDescriptorListAddress;
	const char* mStartUsedHeapDescriptorListAdress;

	void SeperateMemory();
	void WriteMemory_Free();
	void UpdateHeapSize_Allocate(size_t memorySizeRequested);
	void UpdateHeapSize_Deallocate(size_t memorySizeRequested);	
};

