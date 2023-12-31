#include "linked_list.h"

int Linked_List::get_length() {
	int length = 0;
	Node* current = head;
	while (current != NULL){
		length++;
		current = current->next;
	}
	return length;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:
	string temp = " ";
	Node* current = head;
	while (current != NULL){
		temp += to_string(current->val);
		temp += " ";
		current = current->next;
	}
	cout << temp << endl;
	delete current;
}

void Linked_List::push_front(int val){
	Node* new_node = new Node();

	new_node->val = val;
	new_node->next = head;
	head = new_node;
	this->length++;

	return;
}

void Linked_List::pop_front(){
	if (this->length == 0) {
		return;
	}

	Node* current = head;
	head = head->next;
	delete current;

	this->length--;

	return;
}

void Linked_List::push_back(int val){
	Node* new_node = new Node();
	new_node->val = val;
	new_node->next = nullptr;
	this->length++;

	if (head == NULL) {
		head = new_node;
		return;
	}

	Node* current = head;
	while (current->next != nullptr){
		 current = current->next;
	}
	current->next = new_node;
	return;
}

void Linked_List::pop_back(){
	if (this->length == 0){
		return;
	}

	if (this->length == 1){
		delete head;
		head = nullptr;
		return;
		this->length--;
	}

	Node* current = head;
	while(current->next->next != nullptr){
		current = current->next;
	}
	delete current->next;
	current->next = nullptr;
	this->length--;

	return;
}

void Linked_List::insert(int val, int index){
	Node* current = head;
	Node* previous = NULL;
	Node* new_node = new Node();
	new_node->val = val;
	new_node->next = nullptr;
	this->length++;

	if (index > this->length){
		delete new_node;
		return;
	}

	if(head == NULL) {
		head = new_node;	
		return;
	}
	else if (index == 0) {
		new_node->next = head;
		head = new_node;
		return;
	}
	else {
		for (int i = 0; i < index; i++) {
			previous = current;
			current = current->next;
			if (current == nullptr){
				break;
			}
		}	
		new_node->next = current;
		previous->next = new_node;
		return;
	}
}

void Linked_List::remove(int index){
	if (index < 0 || index >= this->length) {
		return;
	}

	if (index == 0) {
		pop_front();
		return;
	}

	Node* current = head;
	for (int i = 1; i < index; i++) {
		current = current->next;
	}
	Node* temp = current->next;
	current->next = current->next->next;
	delete temp;
	this->length--;

	return;
}

Node* Linked_List::split(Node* start) {
	Node* slow = start;
	Node* fast = start->next;

	while (fast != nullptr) {
		fast = fast->next;
		if (fast != nullptr) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	Node* middle = slow->next;
	slow->next = nullptr;

	return middle;
}

void Linked_List::sort_ascending(){
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* middle = split(head);

	Node* left = sort_list_ascending(head);
	Node* right = sort_list_ascending(middle);

	head = merge_ascending(left, right);
	return;
}

Node* Linked_List::sort_list_ascending(Node* start) {
	if (start == nullptr || start->next == nullptr) {
		return start;
	}

	Node* middle = split(start);

	Node* left = sort_list_ascending(start);
	Node* right = sort_list_ascending(middle);

	return merge_ascending(left, right);
}

Node* Linked_List::merge_ascending(Node* left, Node* right) {
	Node* result = nullptr;

	if (left == nullptr) {
		return right;
	} else if (right == nullptr) {
		return left;
	}

	if (left->val <= right->val) {
		result = left;
		result->next = merge_ascending(left->next, right);
	} else {
		result = right;
		result->next = merge_ascending(left, right->next);
	}

	return result;
}

void Linked_List::sort_descending(){
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* middle = split(head);

	Node* left = sort_list_descending(head);
	Node* right = sort_list_descending(middle);

	head = merge_descending(left, right);
	return;
}

Node* Linked_List::sort_list_descending(Node* start) {
	if (start == nullptr || start->next == nullptr) {
		return start;
	}

	Node* middle = split(start);

	Node* left = sort_list_descending(start);
	Node* right = sort_list_descending(middle);

	return merge_descending(left, right);
}

Node* Linked_List::merge_descending(Node* left, Node* right) {
	Node* result = nullptr;

	if (left == nullptr) {
		return right;
	} else if (right == nullptr) {
		return left;
	}

	if (left->val >= right->val) {
		result = left;
		result->next = merge_descending(left->next, right);
	} else {
		result = right;
		result->next = merge_descending(left, right->next);
	}

	return result;
}

void Linked_List::clear(){
	Node* current = head;

	while (current != nullptr) {
		Node* new_node = current->next;
		delete current;
		current = new_node;
		this->length--;
	}
	head = nullptr;
	return;

	return;
}