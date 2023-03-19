//
// Created by Tanmay Vemuri_L on 18-03-2023.
//

#ifndef DSA_PRACTICE_DOUBLYLINKEDLIST_H
#define DSA_PRACTICE_DOUBLYLINKEDLIST_H

#include <iostream>

template<class T>
class DLNode {
public:
    T data;
    DLNode<T> *next;
    DLNode<T> *prev;

    DLNode() = default;
    DLNode(DLNode<T>* inPrevious, T inData, DLNode<T> *inNext) : prev(inPrevious), data(inData), next(inNext){};
};

template<class T>
void DLInsertAt(DLNode<T> *nodeIn, T inData) {
    DLNode<T>* ptrToNext = nullptr;
    if (nodeIn->next) {
        ptrToNext = nodeIn->next;
    }

    auto targetNode = new DLNode<T>(nodeIn, inData, ptrToNext);

    /*
     * Things to do:
     *      i) Change the targetNode's previous to nodeIn
     *      (Of course set its data as well)
     *      ii) Change the targetNode's next to nodeIn's next (if it exists)

     *      iii) Change the nodeIn's next to the target node.
     *      iv)Change the node after targetNode's previous to the targetNode.
     */


    nodeIn->next = targetNode;
    if (ptrToNext){
        targetNode->next->prev = targetNode;
    }


}

template<class T>
void DLDeleteAfter(DLNode<T> &nodeIn){
    auto ptrToDeletionNode = nodeIn.next;
    nodeIn.next = nodeIn.next->next;
    delete ptrToDeletionNode;
    nodeIn.next->prev = &nodeIn;
}


template<class T>
void DebugDLList(DLNode<T> head) {
    auto currentNode = head;
    std::cout << "\n";

    while (currentNode.next != nullptr) {
        std::cout << currentNode.data << "<->";
        currentNode = *(currentNode.next);
    }
    std::cout << currentNode.data << "\n";

}

//NOTE: The displacement can be negative wrt to a given node. So either direction needs to be implemented
template<class T>
DLNode<T>* DLTraverseTo(DLNode<T> &nodeIn, int displacement) {
    auto currentNode = &nodeIn;
    if (displacement >= 0) {
        while (displacement--) {
            currentNode = currentNode->next;
        }
    } else {
        while (displacement++){
            currentNode = currentNode->prev;
        }
    }

    return currentNode;


}

#endif //DSA_PRACTICE_DOUBLYLINKEDLIST_H
