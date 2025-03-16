/*622. Design Circular Queue

Design your implementation of the circular queue. The circular queue is a linear data structure in
which the operations are performed based on FIFO (First In First Out) principle, and the last position is
 connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.
In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space
in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. */

#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue
{
private:
    vector<int> queue;
    int head, tail, size;

public:
    MyCircularQueue(int k)
    {
        queue.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            head = 0;
        }
        tail = (tail + 1) % size;
        queue[tail] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        if (head == tail)
        {
            head = -1;
            tail = -1;
        }
        else
        {
            head = (head + 1) % size;
        }
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return queue[head];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return queue[tail];
    }

    bool isEmpty()
    {
        return head == -1;
    }

    bool isFull()
    {
        return (tail + 1) % size == head;
    }
};
