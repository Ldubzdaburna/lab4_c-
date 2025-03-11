
Lab 4: Implementing Move Constructor and Move Assignment Operator
Overview
In this lab, we extend the linked list implementation from the previous lab by adding a move constructor and a move assignment operator to the Node class. We also provide unit tests to verify the correctness of these implementations.

Files
Node.h: Header file containing the definition of the Node class and function declarations.
Node.cpp: Implementation file for the Node class and related functions.
main.cpp: Main program to demonstrate the usage of the move constructor and move assignment operator.
testlab4.cpp: Unit tests for the move constructor and move assignment operator using the Doctest framework.
Node Class
The Node class represents a node in a singly linked list. It includes the following members:

int data: The data stored in the node.
Node* next: Pointer to the next node in the list.
Constructors and Destructor
Node(int value): Constructor to initialize a node with a given value.
Node(const Node& other): Copy constructor.
Node(Node&& other) noexcept: Move constructor.
Node& operator=(const Node& other): Copy assignment operator.
Node& operator=(Node&& other) noexcept: Move assignment operator.
~Node(): Destructor.
Functions
Node* build_link_list(const int arr[], int size): Builds a linked list from an array.
void print_linked_list(Node* head): Prints the linked list.
void delete_entire_linked_list(Node*& head): Deletes the entire linked list.
int get_linked_list_data_item_value(Node* root, int node_number): Gets the data value of a node at a specific position.
void delete_list_element(Node*& head, int node_number): Deletes a node at a specific position.
Unit Tests
The unit tests are written using the Doctest framework and are located in testlab4.cpp. The tests cover the following scenarios:

Move Constructor: Verifies that the move constructor correctly transfers ownership of the linked list and nullifies the original pointer.
Move Assignment Operator: Verifies that the move assignment operator correctly transfers ownership of the linked list and nullifies the original pointer.
How to Compile and Run
Compile the Main Program
To compile the main program, use the following command:
g++ -std=c++11 -o main Node.cpp main.cpp

Run the Main Program
To run the main program, use the following command:
./main

Compile the Unit Tests
To compile the unit tests, use the following command:
g++ -std=c++11 -o testlab4 Node.cpp testlab4.cpp

Run the Unit Tests
To run the unit tests, use the following command:
./testlab4

Dependencies
C++11 or later
Doctest framework for unit testing
Conclusion
This lab demonstrates the implementation of move semantics in C++ by adding a move constructor and a move assignment operator to the Node class. The provided unit tests ensure the correctness of these implementations.
