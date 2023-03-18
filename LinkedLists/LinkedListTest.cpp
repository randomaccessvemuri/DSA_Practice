#include <gtest/gtest.h>
#include <SinglyLinkedList.h>
#include <vector>


TEST(CheckIfWorked, SinglyLinkedList) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    auto head = convertVectorToLinkedList<int>(a);

    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(traverseTo(head, i).data, a[i]);
    }

}

TEST(CheckInsertionDeletion, SinglyLinkedList) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    auto head = convertVectorToLinkedList<int>(a);

    //Insertion
    insertAfter(&head, 6);
    EXPECT_EQ(traverseTo(head, 1).data, 6);

    deleteAfter(head.next);
    EXPECT_EQ(traverseTo(head, 2).data, 3);

}

