#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size, capacity;
    int* arr;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->front = this->rear = -1;
        this->size = 0;
        this->arr = new int[capacity];
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }

        if (isEmpty()) {
            rear = front = 0;
            arr[rear] = item;
        } else {
            rear = (rear + 1) % capacity;
            arr[rear] = item;
        }

        size++;
        cout << item << " enqueued to queue" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int item = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        cout << item << " dequeued from queue" << endl;
        return item;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int getSize() {
        return size;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
    cout<<"Queue size: "<<q.getSize()<<endl;
    

    return 0;
}
