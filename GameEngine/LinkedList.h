#pragma once
/*Linked List implementation*/
/*This is a template class hence all the function implementations will reside in this class*/
template<class T>
struct Node {
	Node<T>* next;
	Node<T>* previous;
	T data;
};

template <typename T>
class LinkedList {
public:
	
	LinkedList();
	~LinkedList();

	Node<T>* mHead;
	Node<T>* mTail;
	bool mIsListEmpty;
	int mCount;

	void AddNode(T data);
	void DeleteNode(T data);
	bool DeleteNode(Node<T>* node);
	void DeleteLastNode();
	void DeleteFirstNode();
	void PrintLinkedList();
	
	int GetLength();
	bool IsEmpty();

	Node<T>* GetFirst();
	Node<T>* GetLast();
	Node<T>* GetElement(int number);
	size_t DetailElements(int iterator);
	char* GetNodeAddress(int iterator);
	//Node<T>* DetailElement(int number);
	//T* GetElements(int number);

private:
	
};

template<typename T>
inline LinkedList<T>::LinkedList() { 
	mHead = nullptr;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{ }

template<typename T>
inline void LinkedList<T>::AddNode(T nodeToBeAdded) {
	Node<T>* newNode = new Node<T>;
	newNode->data = nodeToBeAdded;
	/*if the linked list is empty*/
	if (mHead == nullptr) {
		mHead = newNode;
		printf("Element added to the list successfully.\n");
	} else {
		newNode->next = mHead;
		mHead = newNode;
		printf("Element added to the list successfully.\n");
	}
	/*increment the counter*/
	mCount++;
}

template<typename T>
inline void LinkedList<T>::DeleteNode(T nodeToBeDeleted) {
	if (IsEmpty()) {
		printf("Linked List is empty.\n Returning \n");
		return;
	}
	else {
		Node<T>* currentNode = mHead;
		while (currentNode->next != nullptr) {
			if (currentNode == node) {
				Node<T>* nextOfCurrentNode = currentNode->next;
				Node<T>* previousOfCurrentNode = currentNode->previous;

				previousOfCurrentNode->next = nextOfCurrentNode;
				nextOfCurrentNode->previous = previousOfCurrentNode;
				
				currentNode = nullptr;
				mCount--;
			}
			else {
				currentNode = currentNode->next;
			}
		}
	}
}

template<typename T>
inline bool LinkedList<T>::DeleteNode(Node<T>* node) {
	if (IsEmpty()) {
		printf("Linked List is empty.\n Returning \n");
		return false;
	} else {
		/*if the node to be deleted is the first one*/
		if (node == mHead) {
			mHead = node->next;
			delete(node);
			node = 0;
			printf("node deleted successfully.\n");
			mCount--;
			return true;
		}
		else {
			Node<T>* currentNode = mHead;
			Node<T>* previousNode = currentNode;

			while (currentNode->next != nullptr) {
				if (currentNode->next == node) {
					//if the node to be deleted is not the last node, then reconnect the connection
					if (node->next != nullptr) {
						previousNode = currentNode;
						currentNode = node->next;
					}
					//else just delete
					delete(node);
					node = 0;
					printf("node deleted successfully.\n");
					mCount--;
					return true;
				}
				else {
					previousNode = currentNode;
					currentNode = previousNode->next;
				}
			}
			return false;
		}
	}
}

template<typename T>
inline void LinkedList<T>::DeleteLastNode() {
	if (IsEmpty()) {
		return;
	}
	else {
		mTail = mTail->previous;
		mTail->next = nullptr;
		mCount--;
	}
}

template<typename T>
inline void LinkedList<T>::DeleteFirstNode() {
	if (IsEmpty()) {
		printf("List is empty. \n");
		return;
	} else {
		Node<T>* nodeToBeDeleted;
		/*take the reference of the first node*/	
		nodeToBeDeleted = mHead;
		/*the first node's next element is the new first node*/
		mHead = mHead->next;
		/*delete the node*/
		delete(nodeToBeDeleted);
		mCount--;
		printf("Node deleted successfully.\n");
	}
}


template<typename T>
inline void LinkedList<T>::PrintLinkedList() {
	if (IsEmpty()) {
		printf("List is empty. \n");
		return;
	} else {
		int count = mCount;
		Node<T>* currentNode = mHead;
		printf("Printing all elements of the list..\n");
		while (count >= 1) {
			printf("currentNode->data->mID = %d ", currentNode->data->mID);
			//printf("address is %d. \n", currentNode->data->mA);

			if (currentNode->next != nullptr) {
				currentNode = currentNode->next;
				count--;
			}
		}
	}
}

template<typename T>
inline int LinkedList<T>::GetLength() {
	int length = 0;
	if (IsEmpty()) {
		printf("List is empty.\n");	
	} 
	return mCount;
}

template<typename T>
inline bool LinkedList<T>::IsEmpty() {
	if (mHead == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline Node<T>* LinkedList<T>::GetFirst() {
	return mHead;
}

template<typename T>
inline Node<T>* LinkedList<T>::GetLast() {
	return mTail;
}

#pragma warning(push)
#pragma warning(disable:4715)
template<typename T>
inline Node<T>* LinkedList<T>::GetElement(int number) {
	if (IsEmpty()) {
		printf("List is empty.\n");
		return nullptr;
	} else {
		int listLength = mCount;
		Node<T>* currentNode = mHead;
		for (int i = 0;i < listLength;i++){

			if (number == i) {
				printf("Element found in list. Returned. \n");
				return currentNode;
				currentNode = currentNode->next;
			}
			//printf("Requested element not found. \n");
			//return nullptr;	
		}
	}
}
#pragma warning(pop)

/*this is an iterator function. Run this in a for loop*/
template<typename T>
inline size_t LinkedList<T>::DetailElements(int iterator) {
	if (IsEmpty()) {
		printf("List is empty. In LinkedList::DetailElements().\n");
		return 0;
	}
	else {
		int length = GetLength();
		Node<T>* currentNode = mHead;
		printf("Nodes->HeapDescriptor's ID is %d \n", currentNode->data->mHeap->mSize);
		//return currentNode->data->mID;
		return currentNode->data->mHeap->mSize;
	}
}

template<typename T>
inline char * LinkedList<T>::GetNodeAddress(int iterator) {
	if (IsEmpty()) {
		printf("List is empty. In LinkedList::DetailElements().\n");
		return nullptr;
	}
	else {
		int length = GetLength();
		Node<T>* currentNode = mHead;
		int currentNodeNumber = 1;
		length = GetLength();
		while (currentNodeNumber <= length) {
			if (iterator == currentNodeNumber) {
				return (char*)currentNode->data->mHeap->mAddress_Self;
				break;
			}
			currentNodeNumber++;
			currentNode = currentNode->next;
		}
		printf("element not found of the specific iterator.\n");
		return nullptr;
		//printf("Length of the linked list is %d. \n\n",length);
		//printf("Nodes->HeapDescriptor's ID is %d \n", currentNode->data->mHeap->mSize);
		//return currentNode->data->mID;
		
	}
}


/*	
#pragma once

/*Linked List implementation
/*This is a template class hence all the function implementations will reside in this class
template<typename T>
struct Node {
	//T data;
	Node<T>* next;
	Node<T>* previous;
	T data;
};

template <typename T>
class LinkedList {
public:

	LinkedList();
	~LinkedList();

	Node<T>* mHead;
	Node<T>* mTail;
	bool mIsListEmpty;
	int mCount;

	void AddNode(Node<T>* node);
	void DeleteNode(Node<T>* node);
	void DeleteLastNode();
	void PrintLinkedList();

	int GetLength();
	bool IsEmpty();

	Node<T>* GetFirst();
	Node<T>* GetLast();
	Node<T>* GetElement(int number);
	Node<T>* DetailElement(int number);

private:

};

template<typename T>
inline LinkedList<T>::LinkedList() { }

template<typename T>
inline LinkedList<T>::~LinkedList()
{ }

template<typename T>
inline void LinkedList<T>::AddNode(Node<T>* node) {
	/*if list is empty, then make the added node as head and tail
	if (IsEmpty()) {
		mHead = node;
		mTail = mHead;
	}
	else {
		/*Node<T>* currentNode = mHead;
		mHead = node;
		mHead->next = currentNode;
		currentNode->previous = mHead;
		currentNode->next = nullptr;

		mTail->next = node;
		mTail = mTail->next;
	}
	mCount++;
}

template<typename T>
inline void LinkedList<T>::DeleteNode(Node<T>* node) {
	if (IsEmpty()) {
		return;
	}
	else {
		Node<T>* currentNode = mHead;
		while (currentNode->next != nullptr) {
			if (currentNode == node) {
				Node<T>* nextOfCurrentNode = currentNode->next;
				Node<T>* previousOfCurrentNode = currentNode->previous;

				previousOfCurrentNode->next = nextOfCurrentNode;
				nextOfCurrentNode->previous = previousOfCurrentNode;

				currentNode = nullptr;
				mCount--;
			}
			else {
				currentNode = currentNode->next;
			}
		}
	}
}

template<typename T>
inline void LinkedList<T>::DeleteLastNode() {
	if (IsEmpty()) {
		return;
	}
	else {
		mTail = mTail->previous;
		mTail->next = nullptr;
		mCount--;
	}
}

template<typename T>
inline void LinkedList<T>::PrintLinkedList() {
	if (IsEmpty()) {
		printf("List is empty. \n");
	}
	else {
		int count = mCount;
		Node<T>* currentNode = mHead;
		while (count > 1) {
			printf("Executing..\n");
			if (currentNode->next != nullptr) {
				currentNode = currentNode->next;
				count--;
			}
		}
	}
}

template<typename T>
inline int LinkedList<T>::GetLength() {
	int length = 0;
	if (IsEmpty()) {
		return length;
	}
	else {
		Node<T>* currentNode = mHead;
		while (currentNode->next != nullptr) {
			currentNode = currentNode->next;
			length++;
		}
		return length;
	}
}

template<typename T>
inline bool LinkedList<T>::IsEmpty() {
	if (mHead == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline Node<T>* LinkedList<T>::GetFirst() {
	return mHead;
}

template<typename T>
inline Node<T>* LinkedList<T>::GetLast() {
	return mTail;
}

#pragma warning(push)
#pragma warning(disable:4715)
template<typename T>
inline Node<T>* LinkedList<T>::GetElement(int number) {
	if (IsEmpty()) {
		printf("List is empty.\n");
		return nullptr;
	}
	else {
		int listLength = mCount;
		Node<T>* currentNode = mHead;
		for (int i = 0;i < listLength;i++) {

			if (number == i) {
				printf("Element found in list. Returned. \n");
				return currentNode;
				currentNode = currentNode->next;
			}

			//printf("Requested element not found. \n");
			//return nullptr;

		}
	}
}
#pragma warning(pop)



/*this is an iterator function. Run this in a for loop
template<typename T>
inline Node<T>* LinkedList<T>::DetailElement(int iterator) {
	if (IsEmpty()) {
		return nullptr;
	}
	else {
		int length = GetLength();
		Node<T>* currentNode = mHead;
		while (length < 1) {
			if (length == iterator) {
				return currentNode;
			}
			currentNode = currentNode->next;
			length--;
		}
	}
}
*/