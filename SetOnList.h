#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
using namespace std;

class SetOnList {
private:
    list<int> list;

public:
    SetOnList();
    bool isEmpty();
    bool isElementInSet(int);
    void addFrontElementToSet(int);
    int getSetCapacity();
    string printSet(char);
    ~SetOnList();
    bool isSubset(SetOnList&);
    bool isEqual(SetOnList&);
    SetOnList unionSet(SetOnList&);
    SetOnList intersectionSet(SetOnList&);
    SetOnList differenceSet(SetOnList&);
    SetOnList symmetricDifference(SetOnList&);
    void fillSet(const vector<int>&);
};