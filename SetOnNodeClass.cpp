#include "SetOnNodeClass.h"

SetOnNode::SetOnNode() : head(nullptr) {}

bool SetOnNode::isEmpty() {
    return head == nullptr;
}

bool SetOnNode::isElementInSet(int value) {
    Node* current = head;
    if (isEmpty()) return false;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

SetOnNode::Node* SetOnNode::addFrontElementToSet(int value) {
    if (!isElementInSet(value)) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void SetOnNode::fillSet(const vector<int>& arr) {
    for (int value : arr) {
        addFrontElementToSet(value);
    }
}

int SetOnNode::getSetCapacity() {
    int count = 0;
    Node* current = head;
    if (isEmpty()) return count;

    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

string SetOnNode::printSet(char splitter) {
    string result;
    Node* current = head;
    if (isEmpty()) return result;

    while (current) {
        result += to_string(current->data);
        result += splitter;
        current = current->next;
    }
    result.pop_back();
    return result;
}

SetOnNode::~SetOnNode() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

bool SetOnNode::isSubset(SetOnNode& setB) {
    Node* current = setB.head;
    if (isEmpty()) return true;

    while (current) {
        if (!isElementInSet(current->data)) {
            return false;
        }
        current = current->next;
    }
    return true;
}

bool SetOnNode::isEqual(SetOnNode& setB) {
    return isSubset(setB) && setB.isSubset(*this);
}

SetOnNode SetOnNode::unionSet(SetOnNode& setB) {
    SetOnNode unionResult;
    Node* current = setB.head;

    if (this->isEmpty() || setB.isEmpty()) return unionResult;
    while (current) {
        unionResult.addFrontElementToSet(current->data);
        current = current->next;
    }
    current = this->head;
    while (current) {
        unionResult.addFrontElementToSet(current->data);
        current = current->next;
    }
    return unionResult;
}

SetOnNode SetOnNode::intersectionSet(SetOnNode& setB) {
    SetOnNode intersectionResult;
    Node* current = setB.head;

    if (isEmpty() || setB.isEmpty()) return intersectionResult;
    while (current) {
        if (isElementInSet(current->data)) {
            intersectionResult.addFrontElementToSet(current->data);
        }
        current = current->next;
    }
    return intersectionResult;
}

SetOnNode SetOnNode::differenceSet(SetOnNode& setB) {
    SetOnNode differenceResult;
    Node* current = this->head;

    if (isEmpty() || setB.isEmpty()) return differenceResult;
    while (current) {
        if (!setB.isElementInSet(current->data)) {
            differenceResult.addFrontElementToSet(current->data);
        }
        current = current->next;
    }
    return differenceResult;
}

SetOnNode SetOnNode::symmetricDifference(SetOnNode& setB) {
    SetOnNode unionSet = this->unionSet(setB);
    SetOnNode intersection = this->intersectionSet(setB);
    SetOnNode symmetricDifferenceResult = unionSet.differenceSet(intersection);

    return symmetricDifferenceResult;
}