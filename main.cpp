#pragma once

#include <optional>
#include <iostream>

template <typename DataType>
class LinkedList {
    struct Node {
        Node* next;
        DataType data;
        
        Node(const DataType& value)
            : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    LinkedList(LinkedList&& tList)
        : head(tList.head) {
        tList.head = nullptr;
    }

    ~LinkedList() {
        Node* curNode = head;
        while (curNode != nullptr) {
            Node* nextNode = curNode->next;
            delete curNode;
            curNode = nextNode;
        }
    }

    void addNode(const DataType& newData, int position) {
        Node* newNode = new Node(newData);
        Node* curNode = head;

        if (curNode != nullptr) {
            if (position == 0) {
                newNode->next = curNode;
                head = newNode;
            } else {
                size_t curPosition = 0;
                while (curNode != nullptr) {
                    if (curPosition == position - 1) {
                        newNode->next = curNode->next;
                        curNode->next = newNode;
                        break;
                    }
                    curPosition++;
                    curNode = curNode->next;
                }
            }
        } else {
            head = newNode;
        }
    }

    void deleteNode(int position) {
        Node* curNode = head;
        Node* nextNode;

        if (position == 0) {
            head = curNode->next;
            delete curNode;
        } else {
            int curPosition = 0;
            while (curNode != nullptr) {
                nextNode = curNode->next;
                if (curPosition == position - 1) {
                    curNode->next = nextNode->next;
                    delete nextNode;
                    break;
                }
                curPosition++;
                curNode = curNode->next;
            }
        }
    }

    std::optional<DataType> getElement(size_t position) {
        Node* curNode = head;
        size_t curPosition = 0;

        while (curNode != nullptr) {
            if (curPosition == position) {
                return curNode->data;
            }
            curPosition++;
            curNode = curNode->next;
        }
        return std::nullopt;
    }

    void setElement(const DataType& data, size_t position) {
        addNode(data, position);
    }

    void showList() {
        Node* curNode = head;
        while (curNode != nullptr) {
            std::cout << curNode->data << " ";
            curNode = curNode->next;
        }
        std::cout << "\n";
    }
};

