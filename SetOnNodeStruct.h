#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct SetOnNodeStruct {
    int data; //поле данных
    SetOnNodeStruct* next; //указатель на след узел
};

SetOnNodeStruct* createEmptySet();
bool isEmpty(SetOnNodeStruct*);
bool isElementInSet(int, SetOnNodeStruct*);
SetOnNodeStruct* addFrontElementToSet(int, SetOnNodeStruct*&);
int getSetCapacity(SetOnNodeStruct*);
string printSet(SetOnNodeStruct*, char);
SetOnNodeStruct* deleteSet(SetOnNodeStruct*&);
bool isSubset(SetOnNodeStruct*, SetOnNodeStruct*);
bool isEqual(SetOnNodeStruct*, SetOnNodeStruct*);
SetOnNodeStruct* unionSet(SetOnNodeStruct*, SetOnNodeStruct*);
SetOnNodeStruct* intersectionSet(SetOnNodeStruct*, SetOnNodeStruct*);
SetOnNodeStruct* differenceSet(SetOnNodeStruct*, SetOnNodeStruct*);
SetOnNodeStruct* symmetricDifference(SetOnNodeStruct*, SetOnNodeStruct*);
SetOnNodeStruct* fillSet(const vector<int>&);
