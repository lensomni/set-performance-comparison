#include "SetOnSet.h"

SetOnSet::SetOnSet() {}

bool SetOnSet::isEmpty() {
    return set.empty();
}

bool SetOnSet::isElementInSet(int value) {
    return find(set.begin(), set.end(), value) != set.end();
}

bool SetOnSet::addFrontElementToSet(int value) {
    return set.insert(value).second;
}

void SetOnSet::fillSet(const vector<int>& arr) {
    for (int value : arr) {
        set.insert(value);
    }
}

int SetOnSet::getSetCapacity() {
    return set.size();
}

string SetOnSet::printSet(char splitter) {
    string result;
    if (isEmpty()) return result;
    for (const int& element : set) {
        result += to_string(element) + splitter;
    }
    result.pop_back();
    return result;
}

SetOnSet::~SetOnSet() {
    set.clear();
}

bool SetOnSet::isSubset(SetOnSet& setB) {
    for (const int& element : setB.set) {
        if (!isElementInSet(element)) {
            return false;
        }
    }
    return true;
}

bool SetOnSet::isEqual(SetOnSet& setB) {
    return isSubset(setB) && setB.isSubset(*this);
}

SetOnSet SetOnSet::unionSet(SetOnSet& setB) {
    SetOnSet unionResult;

    for (const int& element : set) {
        unionResult.addFrontElementToSet(element);
    }
    for (const int& element : setB.set) {
        unionResult.addFrontElementToSet(element);
    }
    return unionResult;
}

SetOnSet SetOnSet::intersectionSet(SetOnSet& setB) {
    SetOnSet intersectionResult;

    for (const int& element : setB.set) {
        if (isElementInSet(element)) {
            intersectionResult.addFrontElementToSet(element);
        }
    }
    return intersectionResult;
}

SetOnSet SetOnSet::differenceSet(SetOnSet& setB) {
    SetOnSet differenceResult;

    for (const int& element : set) {
        if (!setB.isElementInSet(element)) {
            differenceResult.addFrontElementToSet(element);
        }
    }
    return differenceResult;
}

SetOnSet SetOnSet::symmetricDifference(SetOnSet& setB) {
    SetOnSet unionS = unionSet(setB);
    SetOnSet intersectionS = intersectionSet(setB);
    SetOnSet symmetricDifferenceResult = unionS.differenceSet(intersectionS);

    return symmetricDifferenceResult;
}