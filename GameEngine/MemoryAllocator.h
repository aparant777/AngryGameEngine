#pragma once
#include"HeapAllocator.h"
#include<stdint.h>


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
	inline void MemoryAllocated();
	
	/*Request Memory for Heap*/
	void* MemoryRequest(size_t memorySizeRequested);

	/*Request Memory for HeapDescriptor*/
	void* MemoryRequest_HeapDescriptor(size_t heapDescriptorMemorySize);

	/*Print Total Memory size*/
	void PrintMemorySize() const;

	/*Memory delete*/
	void* MemoryDeallocate(size_t memorySizeRequested, char* memoryAddress);

	/*get the Total Memory Size*/
	inline size_t GetMemorySize() const;

private:

	/*const varaibles replaced from #define*/
	const size_t SAMPLE_MEMORY_SIZE_TOTAL = 1024;
	const size_t SAMPLE_MEMORY_SIZE_HEAP = 512;
	const size_t SAMPLE_MEMORY_SIZE_FREEHEAPDESCRIPTOR_LIST = 256;
	const size_t SAMPLE_MEMORY_SIZE_USEDHEAPDESCRIPTOR_LIST = 256;
	const size_t FREE_MEMORY = 70;	//its F (Free)
	const size_t USED_MEMORY = 85;	//its U (Used)
	const size_t FREELIST_MEMORY = 71;	//its U (Used)
	const size_t USEDLIST_MEMORY = 72;	//its U (Used)

	bool mIsMemoryAllocated;
	
	char* mAllocatedAddress;
	const char* mStartHeapAddress;
	const char* mStartFreeHeapDescriptorListAddress;
	const char* mStartUsedHeapDescriptorListAdress;

	inline void SeperateMemory();
	inline void WriteMemory_Free();
	inline void UpdateHeapSize_Allocate(const size_t memorySizeRequested);
	inline void UpdateHeapSize_Deallocate(const size_t memorySizeRequested);
};

