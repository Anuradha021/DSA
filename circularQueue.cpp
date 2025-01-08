#include <iostream>
using namespace std;

class Circularqueue {
    int* arr;
    int size;
    int front;
    int rear;

public:
    Circularqueue() {
        this->front = -1;
        this->rear = -1;
        this->size = 5; // For testing, use a smaller size like 5
        arr = new int[size];
    }

    void enqueue(int data) {
        // Case 1: Queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % size)) {
            cout << "Queue is full!" << endl;
            return;
        }

        // Case 2: First element being enqueued
        if (front == -1) {
            front = rear = 0;
            arr[rear] = data;
            return;
        }

        // Case 3: Rear wraps around to the beginning
        if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = data;
            return;
        }

        // Case 4: Normal case, increment rear
        rear++;
        arr[rear] = data;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // Case 1: Queue becomes empty
        if (front == rear) {
            front = rear = -1;
        }
        // Case 2: Front wraps around
        else if (front == size - 1) {
            front = 0;
        }
        // Case 3: Normal case
        else {
            front++;
        }

        return ans;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Elements of the queue are: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) { // Stop when we reach the rear index
                break;
            }
            i = (i + 1) % size; // Move to the next index (wrap around if needed)
        }
        cout << endl;
    }
};

int main() {
    Circularqueue q;
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(9);

    q.display();

    return 0;
}
