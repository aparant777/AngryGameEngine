#pragma once
#include"HeapAllocator.h"]


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
	void PrintMemorySize() const;

	/*Memory delete*/
	void* MemoryDeallocate(size_t memorySizeRequested);

	/*get the Total Memory Size*/
	int GetMemorySize() const;

private:

	/*const varaibles replaced from #define*/
	const unsigned long SAMPLE_MEMORY_SIZE_TOTAL = 1024;
	const unsigned long SAMPLE_MEMORY_SIZE_HEAP = 512;
	const unsigned long SAMPLE_MEMORY_SIZE_FREEHEAPDESCRIPTOR_LIST = 256;
	const unsigned long SAMPLE_MEMORY_SIZE_USEDHEAPDESCRIPTOR_LIST = 256;
	const unsigned short FREE_MEMORY = 70;	//its F (Free)
	const unsigned short USED_MEMORY = 85;	//its U (Used)

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

