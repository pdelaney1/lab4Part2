/*
 * DNode.hpp
 *
 *  Created on: Mar 30, 2017
 *      Author: Peter
 */

#ifndef DNODE_HPP_
#define DNODE_HPP_
#include <string>
using namespace std;
class DNode {
	friend class DLL;
	int data;
	DNode *next;
	DNode *prev;
public:
	DNode(int x);
	~DNode();
};
#endif /* DNODE_HPP_ */
