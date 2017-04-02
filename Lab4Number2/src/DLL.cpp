#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
using namespace std;
DLL::DLL() {
	first = NULL;
	last = NULL;
	size = 0;
}
DLL::DLL(int x) {
	size = 0;
	srand(time(NULL));
	cout << x << endl;
	cout << endl;
	for (int g = 0; g < x; g++) {
		if (g == 0) {
			addFirst(rand() % 101);
			cout << size << endl;
		} else {
			insertInOrder(rand() % 101);
			cout << size << endl;
		}
	}
}
DLL::~DLL() {
	DNode* tmp = first;
	DNode* next;
	while (tmp != NULL) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	first = NULL;
}
void DLL::printDLL() {
	DNode *tmp = first;
	while(tmp != NULL){
		cout << tmp->data << ", ";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printReverse() {
	DNode *tmp = last;
	while(tmp != NULL){
		cout << tmp->data << ", ";
		tmp = tmp->prev;
	}
	cout << endl;
}
void DLL::addFirst(int x) {
	DNode *tmp = new DNode(x);
	tmp->next = NULL;
	tmp->prev = NULL;
	first = tmp;
	last = first;
	size += 1;
}
void DLL::addAtFront(int x) {
	DNode *tmp = new DNode(x);
	tmp->prev = NULL;
	tmp->next = first;
	first->prev = tmp;
	first = tmp;
	size += 1;
}
void DLL::push(int x) {
	DNode *tmp = new DNode(x);
	tmp->prev = last;
	tmp->next = NULL;
	last->next = tmp;
	last = tmp;
	size += 1;
}
void DLL::insertInOrder(int x) {
	if (x < first->data) {
		addAtFront(x);
	}
	else if(x > last->data){
		push(x);
	}else {
		DNode *tmp = new DNode(x);
		DNode *comp = first;
		DNode *prevy = comp;
		while ((comp != NULL) & (tmp->data > comp->data)) {
			prevy = comp;
			comp = comp->next;
		}
		prevy->next = tmp;
		comp->prev = tmp;
		tmp->next = comp;
		tmp->prev = prevy;
		if(comp->next == NULL){
			last = comp;
		}
		size += 1;
	}
}
