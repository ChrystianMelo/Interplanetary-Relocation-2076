#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

Node::Node() {
        this->content = "";
        this->next = nullptr;
    }

Node::Node(string content, Node* node) {
        this->content = content;
        this->next = node;
    }

string Node::getContent() {
        return content;
    }

Node* Node::getNext() {
        return next;
    }

    void Node::setNext(Node* next) {
        this->next = next;
    }

    void Node::edit(string content, Node* next) {
        this->content = content;
        this->next = next;
    }

    bool Node::hasNext() {
        return this->next != nullptr;
    }

    int Node::connections() {
        int times = 1;
        for (Node node = *this; node.hasNext(); node = *node.next)
            times++;
        return times;
    }

    bool Node::isEmpty() {
        return next == nullptr && content == "";
    }