#include "HeapAllocator.h"

static MemoryAllocator memoryAllocator = MemoryAllocator();
static Heap* heap = nullptr;
static HeapAllocator heapAllocator = HeapAllocator();
 void* HeapAllocator::AllocateMemory(size_t memorySize) {

	printf("Inside AllocateMemory() in HeapAllocator.\n");
	printf("The requested memory size is %Iu and TotalMemorySize is %Iu. \n", memorySize, memoryAllocator.mTotalMemorySize);

	/*check the memory requested is less than the total allocated memory size*/
	if (memorySize < memoryAllocator.mTotalMemorySize) {

		printf("Requested memory size is less than the total allocated memory.\n");

		static int tempID = 1;
		/*create a heap and heap descriptor*/

		heap = (Heap*)memoryAllocator.MemoryRequest(memorySize);
		HeapDescriptor* heapDescriptor = (HeapDescriptor*)memoryAllocator.MemoryRequest_HeapDescriptor(sizeof(HeapDescriptor));
		heapDescriptor->mID = tempID;

		/*check if heap and heapDescriptor is not null*/
		if (heap != nullptr && heapDescriptor != nullptr) {

			printf("Heap and Heap descriptor created successfully.\n");

			heap->mSize = memorySize;
			heap->mAddress_Self = (void*)heap;
			//heap->mHeapDescriptor = heapDescriptor;
			heapDescriptor->mAddress_Self = (void*)heapDescriptor;

			heapDescriptor->mHeap = heap;
			heapDescriptor->mID = tempID;
			heapDescriptor->Print();
			heapDescriptor->GetHeapSize();
		

			/*put heapDescriptor in the usedHeapDescritpors list*/
			heapUsedDescriptorList.AddNode(heapDescriptor);

			/*increment the tempID*/
			printf("TempID value is %d.\n", tempID);
			tempID++;
			printf("mTotalMemorySize is %d. \n", memoryAllocator.mTotalMemorySize);
			printf("\n\n\n");
			return heap->mAddress_Self;

		}else{
			if (heap == nullptr) {
				printf("Failed to generate Heap. \n");
				return nullptr;
			}
			else if (heapDescriptor == nullptr) {
				printf("Failed to generate Heap Descriptor. \n");
				return nullptr;
			} else {
				printf("Failed to generate Heap and Heap Descriptor. \n");
				return nullptr;
			}
		}
	}else{
		printf("Requested memory is more than allocated memory. \n");
		return nullptr;
	}
}

 void * HeapAllocator::AllocateMemoryForLinkedList(size_t memorySize) {
	 return memoryAllocator.MemoryRequest(memorySize);
 }


void HeapAllocator::DeallocateMemory(void* memoryAddress) {
	printf("In DeallocateMemory()\n");
	size_t sizeToBeDeleted = 0;
	int count = heapUsedDescriptorList.mCount;
	printf("HeapUsedDescriptorList count is %d. \n", count);
		for (int i = 1;i <= heapUsedDescriptorList.GetLength();i++) {
			/*Find the respective address of the heap who's address mactches the 'memoryAddress' variable*/
			LinkedList<HeapDescriptor*> heapTEMPDescriptorList = heapUsedDescriptorList; 
			void* memoryAddressRetrieved = (heapUsedDescriptorList.GetElement(i)->data->mHeap);
			void* charMemoryAddress = memoryAddress;
			HeapDescriptor* heapDescriptor = heapUsedDescriptorList.GetElement(i)->data;
			printf("memoryAddress is %d", memoryAddress);
			printf("memoryAddressReceived is %d", memoryAddressRetrieved);
			if (memoryAddressRetrieved == charMemoryAddress) {
				/*we found, the Node, now get its data i.e. the HeapDescriptor*/
				HeapDescriptor* heapDescriptor = heapUsedDescriptorList.DetailElements(i)->data;
				/*get the size to be deleted*/
				printf("printing HeapDescriptors in this list: %d. \n", heapDescriptor->mID);
				sizeToBeDeleted  = heapDescriptor->mHeap->mSize;
				/*add the respective heapDescriptor to the FreeHeapDescriptor List*/
				heapFreeDescriptorList.AddNode(heapDescriptor);
				/*pass the address and the size to the deallocator*/
				if (heapUsedDescriptorList.DeleteNode(heapDescriptor) == true) {
					printf("node deleted successfully");
				}
				memoryAllocator.MemoryDeallocate(sizeToBeDeleted, (char*)memoryAddress);
				break;
		}
		else {
			printf("The respective address could not be matched from the linked list to the address received to HeapAllocator::DeallocateMemory(). \n");
		}
	}	
}

//void * HeapAllocator::operator new(size_t memorySize) {
//	return heapAllocator.AllocateMemory(memorySize);
//}

void  HeapAllocator::operator delete(void* memoryAddress) {
	//heapAllocator.DeallocateMemory(memoryAddress);
}


void * operator new(size_t memorySize) {
	return heapAllocator.AllocateMemory(memorySize);
}

void * operator new[](size_t memorySize) {
	return heapAllocator.AllocateMemory(memorySize);
}

void * operator new(size_t memorySize, bool isTrue) {
	return heapAllocator.AllocateMemoryForLinkedList(memorySize);
}

void HeapAllocator::PrintMemorySize() {
	memoryAllocator.PrintMemorySize();
}

inline void HeapAllocator::PrintUsedHeapDescriptorList() {
	int length = heapUsedDescriptorList.mCount;
	for (int i = 0;i <= length;i++) {
		HeapDescriptor* heapDescriptor = (HeapDescriptor*) heapUsedDescriptorList.GetElement(i);
		//printf("Heapdescriptor with ID is %d and size %zu.\n", heapDescriptor->mID, heapDescriptor->mHeap->mSize);
	}
}