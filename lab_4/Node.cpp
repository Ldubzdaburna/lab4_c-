#include "Node.h"
#include <stdexcept>

Node::Node(const Node& other) : data(other.data), next(nullptr) {
    if (other.next != nullptr) {
        next = new Node(*other.next);
    }
}

Node::Node(Node&& other) noexcept : data(other.data), next(other.next) {
    other.data = 0; // Optional: Reset the data of the moved-from object
    other.next = nullptr;
}

Node& Node::operator=(const Node& other) {
    if (this != &other) {
        delete next;
        next = nullptr;
        
        data = other.data;
        if (other.next != nullptr) {
            next = new Node(*other.next);
        }
    }
    return *this;
}

Node& Node::operator=(Node&& other) noexcept {
    if (this != &other) {
        delete next;
        data = other.data;
        next = other.next;
        other.data = 0; // Optional: Reset the data of the moved-from object
        other.next = nullptr;
    }
    return *this;
}

Node::~Node() {
    delete next;
}

Node* build_link_list(const int arr[], int size) {
    if (size == 0) {
        return nullptr;
    }
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void print_linked_list(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void delete_entire_linked_list(Node*& head) {
    delete head;
    head = nullptr;
}

int get_linked_list_data_item_value(Node* root, int node_number) {
    Node* current = root;
    int count = 0;
    while (current) {
        if (count == node_number) return current->data;
        count++;
        current = current->next;
    }
    throw std::out_of_range("Node number out of range");
}

void delete_list_element(Node*& head, int node_number) {
    if (!head) return;
    
    if (node_number == 0) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; current && i < node_number - 1; i++) {
        current = current->next;
    }

    if (!current || !current->next) return;

    Node* temp = current->next;
    current->next = current->next->next;
    temp->next = nullptr;
    delete temp;
}