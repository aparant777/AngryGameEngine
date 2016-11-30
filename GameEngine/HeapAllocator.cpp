#include "HeapAllocator.h"

MemoryAllocator memoryAllocator = MemoryAllocator();
static Heap* heap = nullptr;
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

void HeapAllocator::DeallocateMemory(void* type) {
	/*get the size of the type (special case: HeapDescriptor)*/
	size_t sizeToBeDeleted = sizeof(type);
	printf("Size of type is %zu.\n", sizeToBeDeleted);
	/*get the specific heapDestricptor*/

	/*get the heap memory address respective to that heapdescriptor*/	

	/*reset the data of heap by writing FREE_MEMORY*/

	/*reset the data of heap descriptor*/	

	/*add the descriptor to the free descriptor list*/
	//heapFreeDescriptorList.AddNode((void*));
}

void * HeapAllocator::operator new(size_t memorySize) {
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

			heapDescriptor->mAddress_Self = (void*)heapDescriptor;

			heapDescriptor->mHeap = heap;
			heapDescriptor->mID = tempID;
			heapDescriptor->Print();
			heapDescriptor->GetHeapSize();

			//Node<HeapDescriptor*>* node = (void*)(memoryAllocator.mCurrentMemoryUsedHeapDescriptorSize);
			//node->data = heapDescriptor;

			/*put heapDescriptor in the usedHeapDescritpors list*/
			
			//heapUsedDescriptorList.AddNode((Node<HeapDescriptor*>* )(node));

			/*increment the tempID*/
			printf("TempID value is %d.\n", tempID);
			tempID++;

			printf("\n\n\n");
			return heap->mAddress_Self;

		}
		else {
			if (heap == nullptr) {
				printf("Failed to generate Heap. \n");
				return nullptr;
			}
			else if (heapDescriptor == nullptr) {
				printf("Failed to generate Heap Descriptor. \n");
				return nullptr;
			}
			else {
				printf("Failed to generate Heap and Heap Descriptor. \n");
				return nullptr;
			}
		}
	}
	else {
		printf("Requested memory is more than allocated memory. \n");
		return nullptr;
	}
}

void HeapAllocator::PrintMemorySize() {
	memoryAllocator.PrintMemorySize();
}

inline void HeapAllocator::PrintUsedHeapDescriptorList() {
	int length = heapUsedDescriptorList.mCount;
	for (int i = 0;i <= length;i++) {
		HeapDescriptor* heapDescriptor = (HeapDescriptor*) heapUsedDescriptorList.GetElement(i);
		printf("Heapdescriptor with ID is %d and size %zu.\n", heapDescriptor->mID, heapDescriptor->mHeap->mSize);
	}
	printf("length is ------> %d.\n", length);
}