#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

Queue factory() {
    Queue q = Queue({ "elo", "r", "value", "rzadzi" },10);
    return q;
}

int main() {
    Queue* queue = new Queue(5);
    
    string command;
    while (true) {
        try {
            cin >> command;
            if (command == "exit") {
                break;
            }
            else if (command == "write") {
                cout << "Queue contains: ";
                for (auto& e : *queue) {
                    cout << e << " ";
                }
                cout << "\n";
            }
            else if (command == "size") {
                cout << "Size: " << queue->size() << "\n";
            }

            else if (command == "push") {
                Queue::Type x; cin >> x;
                queue->push(x);
            }

            else if (command == "front") {
                cout << "Front: " << queue->front() << "\n";
            }

            else if (command == "pop") {
                cout << "Pop: " << queue->pop() << "\n";
            }
            else {
                cout << "Command: " << command << " unknown :(\n";
            }
        }
        catch (string error) {
            cout << "Error: " << error << "\n";
        }
    }
    return 0;
}