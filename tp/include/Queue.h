#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
    private:
        Node* firstNode;

    public:
        Queue();

        Queue(Node* head);

        Node* getNode();

        void push(Node head);

        Node pop();

        void setOnTop(int infoPosition);

        void print();
};
#endif
