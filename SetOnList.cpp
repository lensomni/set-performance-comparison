#include "SetOnList.h"

SetOnList::SetOnList() {}

bool SetOnList::isEmpty() {
    return list.empty();
}

bool SetOnList::isElementInSet(int value) {
    return find(list.begin(), list.end(), value) != list.end();
}

void SetOnList::addFrontElementToSet(int value) {
    if (!isElementInSet(value)) {
        list.push_front(value);
    }
}

void SetOnList::fillSet(const vector<int>& arr) {
    for (int value : arr) {
        list.push_front(value);
    }
}

int SetOnList::getSetCapacity() {
    return list.size();
}

string SetOnList::printSet(char splitter) {
    string result;
    if (isEmpty()) return result;
    for (int& element : list) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}

SetOnList::~SetOnList() {
    list.clear();
}

bool SetOnList::isSubset(SetOnList& setB) {
    for (int& element : setB.list) {
        if (!isElementInSet(element)) {
            return false;
        }
    }
    return true;
}

bool SetOnList::isEqual(SetOnList& setB) {
    return isSubset(setB) && setB.isSubset(*this);
}

SetOnList SetOnList::unionSet(SetOnList& setB) {
    SetOnList unionResult;

    for (int& element : list) {
        unionResult.addFrontElementToSet(element);
    }
    for (int& element : setB.list) {
        unionResult.addFrontElementToSet(element);
    }
    return unionResult;
}

SetOnList SetOnList::intersectionSet(SetOnList& setB) {
    SetOnList intersectionResult;

    for (int& element : setB.list) {
        if (isElementInSet(element)) {
            intersectionResult.addFrontElementToSet(element);
        }
    }
    return intersectionResult;
}

SetOnList SetOnList::differenceSet(SetOnList& setB) {
    SetOnList differenceResult;

    for (int& element : list) {
        if (!setB.isElementInSet(element)) {
            differenceResult.addFrontElementToSet(element);
        }
    }
    return differenceResult;
}

SetOnList SetOnList::symmetricDifference(SetOnList& setB) {
    SetOnList unionS = unionSet(setB);
    SetOnList intersectionS = intersectionSet(setB);
    SetOnList symmetricDifferenceResult = unionS.differenceSet(intersectionS);

    return symmetricDifferenceResult;
}