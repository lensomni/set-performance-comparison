#include "SetOnUnorderedMultiMap.h"

SetOnUnorderedMultiMap::SetOnUnorderedMultiMap() {}

bool SetOnUnorderedMultiMap::isEmpty() {
    return set.empty();
}

bool SetOnUnorderedMultiMap::isElementInSet(int value) {
    return set.find(value) != set.end();
}

void SetOnUnorderedMultiMap::addFrontElementToSet(int value) {
    set.insert({ value, true });
}

void SetOnUnorderedMultiMap::fillSet(const vector<int>& arr) {
    for (int value : arr) {
        set.insert({ value, true });
    }
}

int SetOnUnorderedMultiMap::getSetCapacity() {
    return set.size();
}

string SetOnUnorderedMultiMap::printSet(char splitter) {
    string result;
    if (isEmpty()) return result;
    for (const auto& pair : set) {
        result += to_string(pair.first) + splitter;
    }
    result.pop_back();
    return result;
}

SetOnUnorderedMultiMap::~SetOnUnorderedMultiMap() {
    set.clear();
}

bool SetOnUnorderedMultiMap::isSubset(SetOnUnorderedMultiMap& setB) {
    for (const auto& pair : setB.set) {
        if (!isElementInSet(pair.first)) {
            return false;
        }
    }
    return true;
}

bool SetOnUnorderedMultiMap::isEqual(SetOnUnorderedMultiMap& setB) {
    return isSubset(setB) && setB.isSubset(*this);
}

SetOnUnorderedMultiMap SetOnUnorderedMultiMap::unionSet(SetOnUnorderedMultiMap& setB) {
    SetOnUnorderedMultiMap unionResult;

    for (const auto& pair : set) {
        unionResult.addFrontElementToSet(pair.first);
    }
    for (const auto& pair : setB.set) {
        if (!unionResult.isElementInSet(pair.first)) {
            unionResult.addFrontElementToSet(pair.first);
        }
    }
    return unionResult;
}

SetOnUnorderedMultiMap SetOnUnorderedMultiMap::intersectionSet(SetOnUnorderedMultiMap& setB) {
    SetOnUnorderedMultiMap intersectionResult;

    for (const auto& pair : setB.set) {
        if (isElementInSet(pair.first)) {
            intersectionResult.addFrontElementToSet(pair.first);
        }
    }
    return intersectionResult;
}

SetOnUnorderedMultiMap SetOnUnorderedMultiMap::differenceSet(SetOnUnorderedMultiMap& setB) {
    SetOnUnorderedMultiMap differenceResult;

    for (const auto& pair : set) {
        if (!setB.isElementInSet(pair.first)) {
            differenceResult.addFrontElementToSet(pair.first);
        }
    }
    return differenceResult;
}

SetOnUnorderedMultiMap SetOnUnorderedMultiMap::symmetricDifference(SetOnUnorderedMultiMap& setB) {
    SetOnUnorderedMultiMap unionS = unionSet(setB);
    SetOnUnorderedMultiMap intersectionS = intersectionSet(setB);
    SetOnUnorderedMultiMap symmetricDifferenceResult = unionS.differenceSet(intersectionS);
    return symmetricDifferenceResult;
}