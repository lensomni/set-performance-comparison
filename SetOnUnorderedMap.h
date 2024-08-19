#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class SetOnUnorderedMap {
private:
    unordered_map<int, bool> set;

public:
    SetOnUnorderedMap();
    bool isEmpty();
    bool isElementInSet(int);
    bool addFrontElementToSet(int);
    int getSetCapacity();
    string printSet(char);
    ~SetOnUnorderedMap();
    bool isSubset(SetOnUnorderedMap&);
    bool isEqual(SetOnUnorderedMap&);
    SetOnUnorderedMap unionSet(SetOnUnorderedMap&);
    SetOnUnorderedMap intersectionSet(SetOnUnorderedMap&);
    SetOnUnorderedMap differenceSet(SetOnUnorderedMap&);
    SetOnUnorderedMap symmetricDifference(SetOnUnorderedMap&);
    void fillSet(const vector<int>&);
};