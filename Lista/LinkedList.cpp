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
	Node* currentNode = head;
	int nodeCount = 0;
	while (currentNode != nullptr) {
		std::cout << "Node: " << nodeCount << ": " << currentNode->data << std::endl;
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
}

void LinkedList::InsertNode(Node* node, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->nextNode = node->nextNode;
	node->nextNode = newNode;
}

void LinkedList::DeleteNode(Node* node) {
	Node* currentNode = head;
	while (currentNode->nextNode != node) {
		currentNode = currentNode->nextNode;
	}
	node = currentNode;
}