#include "SetOnNodeStruct.h"

SetOnNodeStruct* createEmptySet() {
    return nullptr;
}

bool isEmpty(SetOnNodeStruct* set) {
    return set == nullptr;
}

bool isElementInSet(int value, SetOnNodeStruct* set) {
    if (isEmpty(set))
        return false;

    while (set) {
        if (set->data == value) {
            return true;
        }
        set = set->next;
    }
    return false;
}

SetOnNodeStruct* addFrontElementToSet(int value, SetOnNodeStruct*& set) {
    if (!isElementInSet(value, set)) {
        SetOnNodeStruct* newNode = new SetOnNodeStruct; 
        newNode->data = value;
        newNode->next = set;
        set = newNode;
    }
    return set;
}

SetOnNodeStruct* fillSet(const vector<int>& arr) {
    SetOnNodeStruct* set = createEmptySet();
    for (int value : arr) {
        addFrontElementToSet(value, set);
    }
    return set;
}

int getSetCapacity(SetOnNodeStruct* set) {
    int count = 0;
    if (isEmpty(set)) return count;
    while (set) {
        count++;
        set = set->next;
    }
    return count;
}

string printSet(SetOnNodeStruct* set, char splitter) {
    string result;
    if (isEmpty(set)) return result;
    while (set) {
        result += to_string(set->data);
        set = set->next;
        result += splitter;
    }
    result.pop_back();
    return result;
}

SetOnNodeStruct* deleteSet(SetOnNodeStruct*& set) {
    while (set) {
        SetOnNodeStruct* temp = set;
        set = set->next; 
        delete temp;
    }
    return nullptr;
}

bool isSubset(SetOnNodeStruct* setA, SetOnNodeStruct* setB) {
    if (isEmpty(setA))
        return true;

    while (setA) {
        if (!isElementInSet(setA->data, setB)) {
            return false;
        }
        setA = setA->next;
    }
    return true;
}

bool isEqual(SetOnNodeStruct* setA, SetOnNodeStruct* setB) {
    return isSubset(setA, setB) && isSubset(setB, setA);
}

SetOnNodeStruct* unionSet(SetOnNodeStruct* setA, SetOnNodeStruct* setB) {
    if (isEmpty(setA) || isEmpty(setB)) return nullptr;

    SetOnNodeStruct* unionResult = createEmptySet();
    while (setA) {
        addFrontElementToSet(setA->data, unionResult);
        setA = setA->next;
    }
    while (setB) {
        addFrontElementToSet(setB->data, unionResult);
        setB = setB->next;
    }
    return unionResult;
}

SetOnNodeStruct* intersectionSet(SetOnNodeStruct* setA, SetOnNodeStruct* setB) {
    if (isEmpty(setA) || isEmpty(setB)) return nullptr;

    SetOnNodeStruct* intersectionResult = createEmptySet();
    while (setA) {
        if (isElementInSet(setA->data, setB)) {
            addFrontElementToSet(setA->data, intersectionResult);
        }
        setA = setA->next;
    }
    return intersectionResult;
}

SetOnNodeStruct* differenceSet(SetOnNodeStruct* setA, SetOnNodeStruct* setB) {
    if (isEmpty(setA) || isEmpty(setB)) return nullptr;

    SetOnNodeStruct* differenceResult = createEmptySet();
    while (setA) {
        if (!isElementInSet(setA->data, setB)) {
            addFrontElementToSet(setA->data, differenceResult);
        }
        setA = setA->next;
    }
    return differenceResult;
}

SetOnNodeStruct* symmetricDifference(SetOnNodeStruct* setA, SetOnNodeStruct* setB) {
    SetOnNodeStruct* unionAB = unionSet(setA, setB);
    SetOnNodeStruct* intersectionAB = intersectionSet(setA, setB);
    SetOnNodeStruct* symmetricDifferenceResult = differenceSet(unionAB, intersectionAB);

    deleteSet(unionAB);
    deleteSet(intersectionAB);
    return symmetricDifferenceResult;
}