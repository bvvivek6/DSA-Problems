/*
706. Design HashMap
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap.
If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1
if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.*/

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    int key;
    node *next;

    node(int key, int value)
    {
        this->value = value;
        this->key = key;
        this->next = nullptr;
    }
};
class MyHashMap
{
public:
    node *head = nullptr;
    MyHashMap()
    {
        head = new node(-1, -1);
    }

    void put(int key, int value)
    {
        node *temp = head;
        while (temp->next != nullptr && temp->key != key)
        {
            temp = temp->next;
        }
        if (temp->key == key)
        {
            temp->value = value;
        }
        else
        {
            temp->next = new node(key, value);
        }
    }

    int get(int key)
    {
        node *temp = head;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    void remove(int key)
    {
        node *prev = head;
        node *curr = head->next;
        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */