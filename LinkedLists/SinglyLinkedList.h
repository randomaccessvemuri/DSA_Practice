//
// Created by Tanmay Vemuri_L on 17-03-2023.
//

#ifndef DSA_PRACTICE_SINGLYLINKEDLIST_H
#define DSA_PRACTICE_SINGLYLINKEDLIST_H

/*
 * TODO: It must be able to
 *          i) Add elements (at any index)
 *          ii) Remove elements (consider edge cases as well)
 */

//Contains data at a node and pointer to the next
template <class T>
class Node {
public:
    T data;
    Node* next;

    Node<T>(T inData, Node* newNext): data(inData), next(newNext) {};

};

template <class T>
class SinglyLinkedList{
public:
    Node<T>* head;

    Node<T>* at(int index){
        auto currentNode = head;
        while (index--){
            currentNode = currentNode->next;
        }

        return currentNode;
    }

    void insertAt(int index, T data){
        if (index!=0)
        {
            auto prev = this->at(index-1);
            auto newNode = Node<T>(data, prev->next);
            prev->next = &newNode;
        } else {
            Node<T> newHead = Node<T>(data, this->head);
            head = &newHead;
        }
    }

};



#endif //DSA_PRACTICE_SINGLYLINKEDLIST_H
