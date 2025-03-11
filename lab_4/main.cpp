#include "Node.h"
#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = build_link_list(arr, 5);

    std::cout << "Original list: ";
    print_linked_list(head);

    Node* new_head = std::move(head);
    std::cout << "After move constructor: ";
    print_linked_list(new_head);

    Node* another_head = build_link_list(arr, 5);
    new_head = std::move(another_head);
    std::cout << "After move assignment operator: ";
    print_linked_list(new_head);

    delete_entire_linked_list(new_head);

    return 0;
}