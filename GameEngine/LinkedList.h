#pragma once
/*Linked List implementation*/
/*This is a template class hence all the function implementations will reside in this class*/
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
	/*if list is empty, then make the added node as head and tail*/
	if (IsEmpty()) {
		mHead = node;
		mTail = mHead;
	}
	else {
		/*Node<T>* currentNode = mHead;
		mHead = node;
		mHead->next = currentNode;
		currentNode->previous = mHead;
		currentNode->next = nullptr;*/
		
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
	} else {
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

/*this is an iterator function. Run this in a for loop*/
template<typename T>
inline Node<T>* LinkedList<T>::DetailElement(int iterator) {
	if (IsEmpty()) {
		return nullptr;
	} else {
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
