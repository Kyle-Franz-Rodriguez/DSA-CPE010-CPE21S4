#include <iostream>
#include "nodes.h"
#include "searching.h"

int main() {
	//Make nodes
	Node<char> *name1 = new_node('K');
	Node<char> *name2 = new_node('Y');
	Node<char> *name3 = new_node('L');
	Node<char> *name4 = new_node('E');
	
	name1 ->next = name2;
	name2 ->next = name3;
	name3 ->next = name4;
	name4 ->next = nullptr;
	
	linearLS(name1, 'E');

}
