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

	void* AllocateMemoryForLinkedList(size_t memorySize);

	/*Deallocate Memory*/
	void DeallocateMemory(void* memoryAddress);

	/*class specific -> overloaded 'new' operator*/
	void* operator new(size_t memorySize);	

	/*class specific -> overloaded 'delete' operator*/
	void operator delete(void *ptr);
	
	/*Print Total Memory size*/
	void PrintMemorySize();

	/*Print Used HeapDescriptor List*/
	inline void PrintUsedHeapDescriptorList();
};