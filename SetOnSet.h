#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;

class SetOnSet {
private:
    set<int> set;

public:
    SetOnSet();
    bool isEmpty();
    bool isElementInSet(int);
    bool addFrontElementToSet(int);
    int getSetCapacity();
    string printSet(char);
    ~SetOnSet();
    bool isSubset(SetOnSet&);
    bool isEqual(SetOnSet&);
    SetOnSet unionSet(SetOnSet&);
    SetOnSet intersectionSet(SetOnSet&);
    SetOnSet differenceSet(SetOnSet&);
    SetOnSet symmetricDifference(SetOnSet&);
    void fillSet(const vector<int>&);
};
