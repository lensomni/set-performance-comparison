#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class SetOnUnorderedMultiMap {
private:
    unordered_multimap<int, bool> set;

public:
    SetOnUnorderedMultiMap();
    bool isEmpty();
    bool isElementInSet(int);
    void addFrontElementToSet(int);
    int getSetCapacity();
    string printSet(char);
    ~SetOnUnorderedMultiMap();
    bool isSubset(SetOnUnorderedMultiMap&);
    bool isEqual(SetOnUnorderedMultiMap&);
    SetOnUnorderedMultiMap unionSet(SetOnUnorderedMultiMap&);
    SetOnUnorderedMultiMap intersectionSet(SetOnUnorderedMultiMap&);
    SetOnUnorderedMultiMap differenceSet(SetOnUnorderedMultiMap&);
    SetOnUnorderedMultiMap symmetricDifference(SetOnUnorderedMultiMap&);
    void fillSet(const vector<int>&);
};