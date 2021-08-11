#include <iostream>
#include <string>
#include <fstream>

#include "Queue.h"

using namespace std;

void transferData(Queue* node1, Queue* node2) {
    while (!node1->getNode()->isEmpty())
        node2->push(node1->pop());
}

void processCommand(Queue* servers, int serversSize, Queue* serversHistory, string line) {
    int separation = line.find(" ");
    string command = line.substr(0, separation);

    if (command.compare("INFO") == 0) {
        string line2 = line.substr(separation + 1);

        separation = line2.find(" ");
        string server = line2.substr(0, separation);
        int serverNumber = stoi(server);

        string data = line2.substr(separation + 1);

        servers[serverNumber].push(Node(data, nullptr));
    }
    else if (command == "WARN") {
        string line2 = line.substr(separation + 1);

        separation = line2.find(" ");
        string server = line2.substr(0, separation);
        int serverNumber = stoi(server);

        string data = line2.substr(separation + 1);
        int dataNumber = stoi(data);

        servers[serverNumber].setOnTop(dataNumber);
    }
    else if (command == "TRAN") {
        string line2 = line.substr(separation + 1);

        separation = line2.find(" ");
        string server1 = line2.substr(0, separation);
        int origem = stoi(server1);

        string server2 = line2.substr(separation + 1);
        int destino = stoi(server2);

        transferData(&servers[origem], &servers[destino]);
    }
    else if (command == "ERRO") {
        string line2 = line.substr(separation + 1);

        separation = line2.find(" ");
        string server = line2.substr(0, separation);
        int serverNumber = stoi(server);

        cout << command << " " << server << endl;
        servers[serverNumber].print();

        while (!servers[serverNumber].getNode()->isEmpty()) {
            servers[serverNumber].pop();
        }
    }
    else if (command == "SEND") {
        for (int i = 0; i < serversSize; i++) {
            Node node = servers[i].pop();
            if (!node.isEmpty())
                serversHistory->push(node);
        }
    }
    else if (command == "FLUSH") {
        serversHistory->print();

        for (int i = 0; i < serversSize; i++)
            servers[i].print();
    }
}

int main() {
    string filename;
    cin >> filename;
    ifstream input_stream(filename);

    string line;
    getline(input_stream, line);
    int server_qtt = stoi(line);

    Queue* servers = (Queue*)malloc((server_qtt + 1) * sizeof(Queue));

    for (int i = 0; i < server_qtt + 1; i++) {
        Queue serverNodes = Queue();
        servers[i] = serverNodes;
    }

    while (getline(input_stream, line))
        processCommand(servers, server_qtt, &servers[server_qtt], line);

    return 0;
}