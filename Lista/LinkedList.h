#pragma once
#include "Node.h"


class LinkedList {
private:
	Node* head;
public:
	LinkedList();
	void AddNode(int value);
	void PrintNodes();
	Node* FindNode(int value);
	void InsertNode(Node* node, int value);
	int DeleteNode(Node* node);
	Node* GetLast();
	void ClearList();
};