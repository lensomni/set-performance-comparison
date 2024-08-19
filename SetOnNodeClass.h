#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class SetOnNode {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    SetOnNode();
    bool isEmpty();
    bool isElementInSet(int);
    Node* addFrontElementToSet(int);
    int getSetCapacity();
    string printSet(char);
    ~SetOnNode();
    bool isSubset(SetOnNode&);
    bool isEqual(SetOnNode&);
    SetOnNode unionSet(SetOnNode&);
    SetOnNode intersectionSet(SetOnNode&);
    SetOnNode differenceSet(SetOnNode&);
    SetOnNode symmetricDifference(SetOnNode&);
    void fillSet(const vector<int>&);
};    