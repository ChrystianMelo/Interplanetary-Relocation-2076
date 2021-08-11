#include <iostream>
#include <string>

#include "Node.h"
#include "Queue.h"

using namespace std;

Queue::Queue() {
        firstNode = new Node();
    }

Queue::Queue(Node* head) {
        this->firstNode = head;
    }

    Node* Queue::getNode() {
        return firstNode;
    }

    void Queue::push(Node head) {
        if (firstNode->isEmpty())
            firstNode->edit(head.getContent(), nullptr);
        else {
            Queue last = *this;
            while (last.firstNode->hasNext() && !last.firstNode->isEmpty())
                last.firstNode = last.firstNode->getNext();
            last.firstNode->setNext(new Node(head.getContent(), nullptr));
        }
    }

    Node Queue::pop() {
        Queue nextNode = Queue(firstNode->getNext());
        Node atualNode = *firstNode;

        if (nextNode.firstNode != nullptr) {
            Queue node = new Node(nextNode.firstNode->getContent(), nextNode.firstNode->getNext());
            firstNode = node.firstNode;
        }
        else {
            firstNode = new Node();
        }

        return atualNode;
    }

    void Queue::setOnTop(int infoPosition) {
        Queue firstDiv = new Node();
        for (int i = 0; i < infoPosition; i++)
            firstDiv.push(pop());

        Queue finalServer = new Node();
        finalServer.push(pop());

        while (!firstDiv.firstNode->isEmpty())
            finalServer.push(firstDiv.pop());

        while (!firstNode->isEmpty())
            finalServer.push(pop());

        firstNode = finalServer.firstNode;
    }

    void Queue::print() {
        Node atual = *firstNode;
        if (!atual.isEmpty()) {
            cout << atual.getContent();
            while (atual.hasNext()) {
                atual = *atual.getNext();
                cout << endl << atual.getContent();
            }
            cout << endl;
        }
    }