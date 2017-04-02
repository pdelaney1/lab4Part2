//============================================================================
// Name        : DLLMain.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	srand(time(NULL));
	int n = (rand()%11) + 10; // random number between 10 and 20
	DLL *test = new DLL(n);
	test->printDLL();
	cout << endl;
	test->printReverse();
	cout << endl;
	cout << "If this prints out in order, then reverse order then this problem is done" << endl;
	test->~DLL();
	delete[] test;
	return 0;
}
