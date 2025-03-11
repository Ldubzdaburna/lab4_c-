#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
    Node(const Node& other);
    Node(Node&& other) noexcept;
    Node& operator=(const Node& other); // Copy assignment operator
    Node& operator=(Node&& other) noexcept; // Move assignment operator
    ~Node();
};

Node* build_link_list(const int arr[], int size);
void print_linked_list(Node* head);
void delete_entire_linked_list(Node*& head);
int get_linked_list_data_item_value(Node* root, int node_number);
void delete_list_element(Node*& head, int node_number);

#endif