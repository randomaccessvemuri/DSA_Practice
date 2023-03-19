//
// Created by Tanmay Vemuri_L on 17-03-2023.
//

#ifndef DSA_PRACTICE_SINGLYLINKEDLIST_H
#define DSA_PRACTICE_SINGLYLINKEDLIST_H


template<class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T inData, Node<T>* newNext) : data(inData), next(newNext) {};

    explicit Node(T inData) : data(inData), next(nullptr) {};

};

template<class T>
void insertAfter(Node<T>* node, T data) {
    auto newNode = new Node<T>(data,node->next);
    node->next = newNode;
}



template<class T>
Node<T>* traverseTo(Node<T> &head, int index) {
    auto temp = &head;
    while (index--){
        temp = temp->next;
    }
    return temp;
}

template<class T>
Node<T> convertVectorToLinkedList(std::vector<T> a){
    auto head = Node<T>(a[0]);
    for (int num: std::vector<T>(a.rbegin(), a.rend()-1)){
        insertAfter(&head, num);
    }

    return head;
}

template<class T>
void deleteAfter(Node<T>* node) {
    if (node->next == nullptr) {
        throw std::runtime_error("Cannot delete after last node");
    }
    auto temp = node->next;
    node->next = node->next->next;
    delete temp;
}

template<class T>
void debugSLList(Node<T> head) {
    auto currentNode = head;
    std::cout<<"\n";
    while (currentNode.next != nullptr) {
        std::cout << currentNode.data << " -> ";
        currentNode = *(currentNode.next);
    }
    std::cout<<"\n";
}




#endif //DSA_PRACTICE_SINGLYLINKEDLIST_H
