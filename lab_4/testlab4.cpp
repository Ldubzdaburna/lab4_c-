#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "Node.h"

// Test for the move constructor
TEST_CASE("Test Move Constructor") {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = build_link_list(arr, 5);
    Node* new_head = std::move(head);
    head = nullptr; // Manually nullify the old pointer

    REQUIRE(new_head != nullptr);
    REQUIRE(head == nullptr);
    REQUIRE(new_head->data == 1);
    REQUIRE(new_head->next->data == 2);

    delete_entire_linked_list(new_head);
}

// Test for the move assignment operator
TEST_CASE("Test Move Assignment Operator") {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = build_link_list(arr, 5);
    Node* new_head = build_link_list(arr, 5);
    new_head = std::move(head);
    head = nullptr; // Explicitly set head to nullptr after the move

    REQUIRE(new_head != nullptr);
    REQUIRE(head == nullptr);
    REQUIRE(new_head->data == 1);
    REQUIRE(new_head->next->data == 2);

    delete_entire_linked_list(new_head);
}