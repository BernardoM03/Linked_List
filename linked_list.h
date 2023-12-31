/*********************************************************************
** Program Filename: linked_list
** Author: Bernardo Mendes
** Date: 12/11/2023
** Description: A program that goes through many general functions of a linked list
** Input: none
** Output: A series of test that test the programs of the functions
*********************************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include <iostream>

using namespace std;

class Linked_List {
private:
	int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list
	// anything else you need...
public:
	//constructor
	Linked_List() : length(0), head(NULL) {}

	/*********************************************************************
	** Function: get_length
	** Description: Iterates through the linked_list and returns the number of nodes
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: returns an int equal to number of nodes
	*********************************************************************/
	int get_length();
   
   	/*********************************************************************
	** Function: print
	** Description: Iterates through linked list and prints out the value of each node
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: linked list is printed out
	*********************************************************************/
	void print(); // output a list of all integers contained within the 
   
   	/*********************************************************************
	** Function: push_front
	** Description: Inserts a new node at the front of the linked list
	** Parameters: An int with a value
	** Pre-Conditions: none
	** Post-Conditions: A new node with passed in value is added to the front of the list
	*********************************************************************/
	void push_front(int); 

	/*********************************************************************
	** Function: push_back
	** Description: insert a new node at the back of the linked list 
	** Parameters: An int with a value
	** Pre-Conditions: none
	** Post-Conditions: A new node with passed in value is added to the back of the list
	*********************************************************************/
	void push_back(int);

	/*********************************************************************
	** Function: insert
	** Description: insert a new node in the list at the specified index 
	** Parameters: An int with value and an int as an index
	** Pre-Conditions: none
	** Post-Conditions: A new node at specified index is created
	*********************************************************************/
	void insert(int val, int index); 

	/*********************************************************************
	** Function: pop_back
	** Description: remove the node at the back of the list
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: A node at the back of the list is removed
	*********************************************************************/
	void pop_back(); 

	/*********************************************************************
	** Function: pop_front
	** Description: remove the node at the front of the list
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: A node at the front of the list is removed
	*********************************************************************/
	void pop_front(); 

	/*********************************************************************
	** Function: remove
	** Description: remove the node at index of the list
	** Parameters: An int with value and an int as an index
	** Pre-Conditions: none
	** Post-Conditions: A node at a specified is removed
	*********************************************************************/
	void remove(int index); 

	/*********************************************************************
	** Function: split
	** Description: Uses a fast and slow node to iterate through the linked list and find the center node
	** Parameters: A head node
	** Pre-Conditions: none
	** Post-Conditions: Returns the node at the center of the linked list
	*********************************************************************/
	Node* split(Node* start);

	/*********************************************************************
	** Function: sort_ascending
	** Description: Sorts the linked_list in an ascending order
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: The linked list is sorted
	*********************************************************************/
	void sort_ascending(); 

	/*********************************************************************
	** Function: sort_list_ascending
	** Description: Recursively splits the linked_list and uses merge sort to sort the linked_list in an ascending order
	** Parameters:  A head node
	** Pre-Conditions: none
	** Post-Conditions: returns the new head for sorted_list
	*********************************************************************/
	Node* sort_list_ascending(Node* start);

	/*********************************************************************
	** Function: merge_ascending
	** Description: compares the values of two nodes in the list, and swap them in ascending order
	** Parameters: Two nodes to compare with.
	** Pre-Conditions: none
	** Post-Conditions: Returns the node of the lesser value
	*********************************************************************/
	Node* merge_ascending(Node* left, Node* right);
	
	/*********************************************************************
	** Function: sort_descending
	** Description: Sorts the linked_list in an descending order
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: The linked list is sorted
	*********************************************************************/
	void sort_descending();

	/*********************************************************************
	** Function: sort_list_ascending
	** Description: Recursively splits the linked_list and uses merge sort to sort the linked_list in an ascending order
	** Parameters: a head node
	** Pre-Conditions: none
	** Post-Conditions: returns the new head for sorted_list
	*********************************************************************/
	Node* sort_list_descending(Node* start);

	/*********************************************************************
	** Function: merge_ascending
	** Description: compares the values of two nodes in the list, and swap them in ascending order
	** Parameters: Two nodes to compare with.
	** Pre-Conditions: none
	** Post-Conditions: Returns the node of the greater value
	*********************************************************************/
	Node* merge_descending(Node* left, Node* right);
	// you can add extra member variables or functions as desired

	/*********************************************************************
	** Function: clear
	** Description: deletes all the Node pointers within the linked list and clears from the heap
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: linked list is deleted and cleared from the heap
	*********************************************************************/
	void clear(); // delete the entire list (remove all nodes and reset length to 0)

};




#endif
