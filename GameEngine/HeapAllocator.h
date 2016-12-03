#pragma once
#include"LinkedList.h"
#include"MemoryAllocator.h"
#include<stdio.h>


struct Heap {
	void* mAddress_Self;
	size_t mSize;
};

struct HeapDescriptor {
	int mID;
	void* mAddress_Self;
	Heap* mHeap;

	inline void Print() {
		printf("HeapDecriptor %d is. \n", mID);
	}

	inline void GetHeapSize() {
		//printf("Its Block Size is %Iu. \n", mHeap->mSize);
	}
};




class HeapAllocator {
public:
	
	LinkedList<HeapDescriptor*> heapUsedDescriptorList;
	LinkedList<HeapDescriptor*> heapFreeDescriptorList;

	/*Allocate Memory*/
	void* AllocateMemory(size_t memorySize);

	/*Deallocate Memory*/
	void DeallocateMemory(char* memoryAddress);

	/*overloaded 'new' operator: DO NOT USE*/
	void* operator new(size_t memorySize);	
	
	/*Print Total Memory size*/
	void PrintMemorySize();

	/*Print Used HeapDescriptor List*/
	inline void PrintUsedHeapDescriptorList();
};


//first allocate some memory

//divide the memory into heap, freeHeapdescriptors list, usedHeapdescriptors list
//...DONE DUDE

//user asks for memory
//...DONE DONE

//divide the memory by breaking the heap which is of full size
//...DONE DONE

//create a heap descriptor for the heap genereated, since it was divided
//...DONE DONE

//put the heap descriptor into the usedHeapAllocators list
//...DONE DONE

//user asks to delete memory

//clear the heap which user was using

//move the heap descriptor back to freeHeapdescriptors list

//-------------------


/*player address is present

player address  == heap address

match the heap address with each address of the heap in heap descriptor which is in the used list

once the address is matched, get the heapSize from the heap in the deap descriptor. 

delete the memory elements from the start of address upto its size
*/
