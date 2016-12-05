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


void HeapAllocator::DeallocateMemory(void* memoryAddress) {
	//printf("memoryAddress received at the Heap Allocator is %d.\n", memoryAddress);

	/*get the size of the type (special case: HeapDescriptor)*/
	//if(memoryAddress == )
	size_t sizeToBeDeleted = 0;
	//printf("Size of type is %zu.\n", sizeToBeDeleted);

	printf("memory address incoming is %d.\n", memoryAddress);
	printf("------------FOR LOOP ITERATIONS------------\n");
	for (int i = 1;i <= heapUsedDescriptorList.GetLength();i++) {
		printf("length is %d.\n", heapUsedDescriptorList.GetLength());
		printf("memory address is %d. ", memoryAddress);
		printf(" memory address during %d iteration is %d . \n",i, (char*)(heapUsedDescriptorList.DetailElements(i)->data->mHeap->mAddress_Self));

		/*Find the respective address of the heap who's address mactches the 'memoryAddress' variable*/
		if ((char*)(heapUsedDescriptorList.DetailElements(i)->data->mHeap->mAddress_Self) == memoryAddress) {
			printf("Length of the UsedHeapDescriptor list is %d. \n", heapUsedDescriptorList.GetLength());

			/*we found, the Node, now get its data i.e. the HeapDescriptor*/
			HeapDescriptor* heapDescriptor = heapUsedDescriptorList.DetailElements(i)->data;
			/*get the size to be deleted*/
			sizeToBeDeleted  = heapDescriptor->mHeap->mSize;
			/*add the respective heapDescriptor to the FreeHeapDescriptor List*/
			heapFreeDescriptorList.AddNode(heapDescriptor);
			/*pass the address and the size to the deallocator*/
			printf("Length of the UsedHeapDescriptor list is %d. \n", heapUsedDescriptorList.GetLength());
			if (heapUsedDescriptorList.DeleteNode(heapDescriptor) == true) {

			}

			memoryAllocator.MemoryDeallocate(sizeToBeDeleted, (char*)memoryAddress);
			break;
		}
		else {
			printf("The respective address could not be matched from the linked list to the address received to HeapAllocator::DeallocateMemory(). \n");
			//return;
		}
	}
	printf("------------FOR LOOP ITERATIONS------------\n");
		//heapFreeDescriptorList.AddNode()
	//}

	//printf("memory address received through linked list is %d.\n", heapUsedDescriptorList.GetNodeAddress(4));
	
	//printf("values coming are %d. \n", heapUsedDescriptorList.DetailElements(2));

	/*get the specific heapDestricptor*/
		/*traverse the specific list to obtain the same address as that of the 'memoryAddress'*/
		//heapUsedDescriptorList
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

			//heapDescriptor->mHeap = heap;
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
		//printf("Heapdescriptor with ID is %d and size %zu.\n", heapDescriptor->mID, heapDescriptor->mHeap->mSize);
	}
	printf("length is ------> %d.\n", length);
}