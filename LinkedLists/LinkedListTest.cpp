#include <gtest/gtest.h>
#include <SinglyLinkedList.h>
#include <vector>
#include <iostream>


TEST(CheckPushBack, Node) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    SinglyLinkedList<int> list;


    for (int i = 0; i < 5; i++) {
        list.insertAt(i, a[i]);
    }

    //TODO: Fix incorrect result. Potential problem may be that you're messing up somewhere with the pointers.
    EXPECT_EQ(list.at(0)->data,1);
}

