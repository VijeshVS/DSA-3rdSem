#include <iostream>
#include <string>
using namespace std;

// Circular Queue for Message Queue
class MessageQueue {
private:
    int front, rear, size;
    string* queue; // Array to store messages
    int capacity;

public:
    // Constructor
    MessageQueue(int capacity) {
        this->capacity = capacity;
        queue = new string[capacity];
        front = rear = -1; // Queue is empty
    }

    ~MessageQueue() {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Enqueue operation: Add a message to the queue
    void enqueue(const string& message) {
        if (isFull()) {
            cout << "Message queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0; // First element
        } else {
            rear = (rear + 1) % capacity; // Circular increment
        }
        queue[rear] = message;
        cout << "Message enqueued: " << message << "\n";
    }

    // Dequeue operation: Remove a message from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Message queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << "Message dequeued: " << queue[front] << "\n";

        if (front == rear) { // Last element
            front = rear = -1; // Reset the queue
        } else {
            front = (front + 1) % capacity; // Circular increment
        }
    }

    // Display all messages in the queue
    void display() {
        if (isEmpty()) {
            cout << "Message queue is empty.\n";
            return;
        }

        cout << "Messages in the queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break; // Stop when we reach the last element
            i = (i + 1) % capacity; // Circular increment
        }
        cout << "\n";
    }
};

// Main function
int main() {
    int capacity;
    cout << "Enter the capacity of the message queue: ";
    cin >> capacity;

    MessageQueue mq(capacity);

    // Example operations
    mq.enqueue("Message 1");
    mq.enqueue("Message 2");
    mq.enqueue("Message 3");
    mq.display();
    mq.dequeue();
    mq.display();
    mq.enqueue("Message 4");
    mq.enqueue("Message 5"); // Attempt to enqueue beyond capacity
    mq.display();
    mq.dequeue();
    mq.dequeue();
    mq.dequeue();
    mq.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}




/*
OUTPUT:
Message enqueued: Message 1
Message enqueued: Message 2
Message enqueued: Message 3
Messages in the queue: Message 1 Message 2 Message 3 
Message dequeued: Message 1
Messages in the queue: Message 2 Message 3 
Message enqueued: Message 4
Message queue is full. Cannot enqueue.
Messages in the queue: Message 2 Message 3 Message 4 
Message dequeued: Message 2
Message dequeued: Message 3
Message dequeued: Message 4
Message queue is empty. Cannot dequeue.
*/