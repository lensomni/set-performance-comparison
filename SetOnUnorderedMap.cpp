#include "SetOnUnorderedMap.h"

SetOnUnorderedMap::SetOnUnorderedMap() {}

bool SetOnUnorderedMap::isEmpty() {
    return set.empty();
}

bool SetOnUnorderedMap::isElementInSet(int value) {
    return set.find(value) != set.end();
}

bool SetOnUnorderedMap::addFrontElementToSet(int value) {
    return set.insert({ value, true }).second;
}

void SetOnUnorderedMap::fillSet(const vector<int>& arr) {
    for (int value : arr) {
        set.insert({ value, true });
    }
}

int SetOnUnorderedMap::getSetCapacity() {
    return set.size();
}

string SetOnUnorderedMap::printSet(char splitter) {
    string result;
    if (isEmpty()) return result;
    for (const auto& pair : set) {
        result += to_string(pair.first) + splitter;
    }
    result.pop_back();
    return result;
}

SetOnUnorderedMap::~SetOnUnorderedMap() {
    set.clear();
}

bool SetOnUnorderedMap::isSubset(SetOnUnorderedMap& setB) {
    for (const auto& pair : setB.set) {
        if (!isElementInSet(pair.first)) {
            return false;
        }
    }
    return true;
}

bool SetOnUnorderedMap::isEqual(SetOnUnorderedMap& setB) {
    return isSubset(setB) && setB.isSubset(*this);
}

SetOnUnorderedMap SetOnUnorderedMap::unionSet(SetOnUnorderedMap& setB) {
    SetOnUnorderedMap unionResult;

    for (const auto& pair : set) {
        unionResult.addFrontElementToSet(pair.first);
    }
    for (const auto& pair : setB.set) {
        unionResult.addFrontElementToSet(pair.first);
    }
    return unionResult;
}

SetOnUnorderedMap SetOnUnorderedMap::intersectionSet(SetOnUnorderedMap& setB) {
    SetOnUnorderedMap intersectionResult;

    for (const auto& pair : setB.set) {
        if (isElementInSet(pair.first)) {
            intersectionResult.addFrontElementToSet(pair.first);
        }
    }
    return intersectionResult;
}

SetOnUnorderedMap SetOnUnorderedMap::differenceSet(SetOnUnorderedMap& setB) {
    SetOnUnorderedMap differenceResult;

    for (const auto& pair : set) {
        if (!setB.isElementInSet(pair.first)) {
            differenceResult.addFrontElementToSet(pair.first);
        }
    }
    return differenceResult;
}

SetOnUnorderedMap SetOnUnorderedMap::symmetricDifference(SetOnUnorderedMap& setB) {
    SetOnUnorderedMap unionS = unionSet(setB);
    SetOnUnorderedMap intersectionS = intersectionSet(setB);
    SetOnUnorderedMap symmetricDifferenceResult = unionS.differenceSet(intersectionS);

    return symmetricDifferenceResult;
}