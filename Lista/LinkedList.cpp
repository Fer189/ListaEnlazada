#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
	LinkedList::head = nullptr;
}

void LinkedList::AddNode(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->nextNode = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* currentNode = head;
		while (currentNode->nextNode != nullptr) {
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = newNode;
	}
}

void LinkedList::PrintNodes() {
	if (head == nullptr) {
		std::cout << "La lista esta vacia!" << std::endl;
		return;
	}
	Node* currentNode = head;
	int nodeCount = 0;
	while (currentNode != nullptr) {
		std::cout << "Nodo: " << nodeCount << ": " << currentNode->data << std::endl;
		nodeCount++;
		currentNode = currentNode->nextNode;
	}
}

Node* LinkedList::FindNode(int value) {
	Node* currentNode = head;
	while (currentNode != nullptr) {
		if (currentNode->data == value) {
			return currentNode;
		}
		currentNode = currentNode->nextNode;
	}
	return nullptr;
}

void LinkedList::InsertNode(Node* node, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->nextNode = node->nextNode;
	node->nextNode = newNode;
}

int LinkedList::DeleteNode(Node* node) {
	if (head == nullptr || node == nullptr) {
		return 0;
	}
	if (node == head) {
		Node* temp = head;
		head = head->nextNode;
		delete temp;
		return 1;
	}
	Node* currentNode = head;
	while (currentNode->nextNode != node) {
		currentNode = currentNode->nextNode;
	}
	Node* temp = currentNode->nextNode;
	currentNode->nextNode = temp->nextNode;
	delete temp;
	return 2;
}

Node* LinkedList::GetLast() {
	if (head == nullptr) {
		return nullptr;
	}
	Node* currentNode = head;
	while (currentNode->nextNode != nullptr) {
		currentNode = currentNode->nextNode;
	}
	return currentNode;
}

void LinkedList::ClearList() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->nextNode;
		delete temp;
	}
}
