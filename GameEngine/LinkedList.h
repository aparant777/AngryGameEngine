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
	bool DeleteNode(T data);
	bool DeleteNode(Node<T>* node);
	void DeleteLastNode();
	void DeleteFirstNode();
	void PrintLinkedList();
	
	int GetLength();
	bool IsEmpty();

	Node<T>* GetFirst();
	Node<T>* GetLast();
	Node<T>* GetElement(int number);
	Node<T>* DetailElements(int iterator);
	char* GetNodeAddress(int iterator);

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
inline bool LinkedList<T>::DeleteNode(T dataToBeDeleted) {
	Node<T>* node = nullptr;
	if (IsEmpty()) {
		printf("Linked List is empty.\n Returning \n");
		return false;
	}
	else {
		//now we need to get that data from the linked list using DetailElements()
		for (int i = 1;i <= GetLength();i++) {
			node = GetElement(i);
			if (node->data == dataToBeDeleted) {
				/*we found the node*/
				break;
			}
		}
		/*if the node to be deleted is the first one*/
		if (node == mHead) {
			if (node->next != nullptr) {
				mHead = node->next;
			}
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
					//printf("node deleted successfully.\n");
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
			//printf("node deleted successfully.\n");
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
					//printf("node deleted successfully.\n");
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
		//printf("List is empty. \n");
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
		//printf("Node deleted successfully.\n");
	}
}


template<typename T>
inline void LinkedList<T>::PrintLinkedList() {
	if (IsEmpty()) {
		//printf("List is empty. \n");
		return;
	} else {
		int count = mCount;
		Node<T>* currentNode = mHead;
		//printf("Printing all elements of the list..\n");
		while (count >= 1) {
			//printf("currentNode->data->mID = %d ", currentNode->data->mID);
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
	if (IsEmpty()) {
		//printf("List is empty.\n");	
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
	if (IsEmpty()) {
		//printf("List is empty.\n");
		return nullptr;
	}
	return mHead;
}

template<typename T>
inline Node<T>* LinkedList<T>::GetLast() {
	if (IsEmpty()) {
		//printf("List is empty.\n");
		return nullptr;
	}
	return mTail;
}

#pragma warning(push)
#pragma warning(disable:4715)
template<typename T>
inline Node<T>* LinkedList<T>::GetElement(int number) {
	if (IsEmpty()) {
		//printf("List is empty.\n");
		return nullptr;
	} else {
		int listLength = mCount;
		Node<T>* currentNode = mHead;
		for (int i = 1;i <= listLength;i++){

			if (number == i) {
				//printf("Element found in list. Returned. \n");
				return currentNode;
				currentNode = currentNode->next;
			}
			//printf("Requested element not found. \n");
			//return nullptr;	
			//i think currentnode->currentnode=>next
		}
	}
}
#pragma warning(pop)

/*this is an iterator function. Run this in a for loop*/
template<typename T>
inline Node<T>* LinkedList<T>::DetailElements(int iterator) {
	if (IsEmpty()) {
		//printf("List is empty. In LinkedList::DetailElements().\n");
		return nullptr;
	}
	else {
		int currentNodeNumber = 1;
		int length = GetLength();
		Node<T>* currentNode = mHead;
		while (currentNodeNumber <= length) {
			if (iterator == currentNodeNumber) {
				//printf("Node requested found in Node<T>* LinkedList::DetailElements(iterator).\n");
				return currentNode;
			}
			currentNodeNumber++;
			currentNode = currentNode->next;
		}
		//printf("Node requested not found in Node<T>* LinkedList::DetailElements(iterator).\n");
		return nullptr;
	}
}

/*this is an iterator function. Run this in a for loop*/
template<typename T>
inline char * LinkedList<T>::GetNodeAddress(int iterator) {
	if (IsEmpty()) {
	//	printf("List is empty. In LinkedList::DetailElements().\n");
		return nullptr;
	}
	else {
		if (iterator == 0) {
			//printf("First element of list starts from iterator 1.\n");
			return nullptr;
		}
		else if (iterator < 0) {
		//	printf("enter an iterator equal to or greater than 1.\n");
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
			//printf("element not found of the specific iterator.\n");
			return nullptr;
		}
	}
}
