#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node {
    private:
        string content;
        Node* next;

    public:
        Node();

        Node(string content, Node* node);

        string getContent();

        Node* getNext();

        void setNext(Node* next);

        void edit(string content, Node* next);

        bool hasNext();

        int connections();

        bool isEmpty();
};

#endif
