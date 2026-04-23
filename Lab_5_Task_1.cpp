#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int rear, front;
    int arr[SIZE];

public:
    Queue() {
        rear = -1;
        front = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return; 
        }

        if (front == -1)
            front = 0;

        arr[++rear] = value;
        cout << "Inserted: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return; 
        }

        cout << "Dequeued: " << arr[front] << endl;
        front++;

        
        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue values: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    cout << endl;
    q1.dequeue();

    q1.display();

    return 0;
}
