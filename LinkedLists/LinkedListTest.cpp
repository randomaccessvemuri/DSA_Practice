#include <gtest/gtest.h>
#include <SinglyLinkedList.h>
#include <DoublyLinkedList.h>
#include <vector>


TEST(CheckConstruction, SinglyLinkedList) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    auto head = convertVectorToLinkedList<int>(a);

    for (int i = 0; i < a.size(); i++) {
        EXPECT_EQ(traverseTo(head, i)->data, a[i]);
    }

}

TEST(CheckInsertionDeletion, SinglyLinkedList) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    auto head = convertVectorToLinkedList<int>(a);

    //Insertion
    insertAfter(&head, 6);
    EXPECT_EQ(traverseTo(head, 1)->data, 6);

    deleteAfter(head.next);
    EXPECT_EQ(traverseTo(head, 2)->data, 3);

}


TEST(CheckConstruction, DoublyLinkedList) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    auto head = DLNode<int>(nullptr, a[0], nullptr);

    for (int num : std::vector(a.rbegin(), a.rend()-1)){
        DLInsertAt(&head, num);
    }

    EXPECT_EQ(DLTraverseTo(head, 3)->data, 4);

}

TEST(CheckInsertionDeletion, DoublyLinkedList){
    std::vector<int> a = {1,2,3,4,5};

    auto head = DLNode<int>(nullptr, a[0], nullptr);

    for (int num : std::vector(a.rbegin(), a.rend()-1)){
        DLInsertAt(&head, num);
    }

    //INSERTION:
    auto nodeInList = DLTraverseTo(head, 2);
    DLInsertAt(nodeInList, 544);
    EXPECT_EQ(DLTraverseTo(head,3)->data, 544);

    //DELETION:
    DLDeleteAfter(head);
    EXPECT_EQ(DLTraverseTo(head,3)->data, 4);
}