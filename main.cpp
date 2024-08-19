#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>
#include <windows.h>
#include <functional>

#include "SetOnList.h"
#include "SetOnNodeClass.h"
#include "SetOnNodeStruct.h"
#include "SetOnSet.h"
#include "SetOnUnorderedMap.h"
#include "SetOnUnorderedMultiMap.h"
using namespace std;

const int columnWidth = 25, totalWidth = 182;
const char delimiter = '-';
const int MIN_SIZE = 1000, MAX_SIZE = 10000, minValue = 0, multCoef = 10;

SetOnNodeStruct* setOnNodeStruct, * setOnNodeStructB;
SetOnNode setOnNode, setOnNodeB;
SetOnList setOnList, setOnListB;
SetOnSet setOnSet, setOnSetB;
SetOnUnorderedMap setOnUnorderedMap, setOnUnorderedMapB;
SetOnUnorderedMultiMap setOnUnorderedMultiMap, setOnUnorderedMultiMapB;

vector<string> headers = {
    "",
    " Односвязный список ",
    " Класс 'Список' ",
    " List ",
    " Set ",
    " Unordered_map ",
    " Unordered_multimap "
};

vector<string> rows = {
    " Создание множества",
    " Мощность",
    " Подмножество A-A",
    " Подмножество B-A",
    " Равенство A-A",
    " Равенство B-A",
    " Объединение",
    " Пересечение",
    " Разность A-B",
    " Разность B-A",
    " Симметричная разность"
};

template<typename Func>
double measureExecutionTime(Func func)
{
    auto start = chrono::steady_clock::now();
    func();
    auto end = chrono::steady_clock::now();
    return chrono::duration<double>(end - start).count();
}

template<typename T>
vector<double> measureAllOperations(T* set, T* setB, const vector<int>& arrA)
{
    vector<double> results;
    results.push_back({ measureExecutionTime([&]() { set = fillSet(arrA); }) });
    results.push_back({ measureExecutionTime([&]() { getSetCapacity(set); }) });
    results.push_back({ measureExecutionTime([&]() { isSubset(set, set); }) });
    results.push_back({ measureExecutionTime([&]() { isSubset(set, setB); }) });
    results.push_back({ measureExecutionTime([&]() { isEqual(set, set); }) });
    results.push_back({ measureExecutionTime([&]() { isEqual(set, setB); }) });
    results.push_back({ measureExecutionTime([&]() { unionSet(set, setB); }) });
    results.push_back({ measureExecutionTime([&]() { intersectionSet(set, setB); }) });
    results.push_back({ measureExecutionTime([&]() { differenceSet(set, setB); }) });
    results.push_back({ measureExecutionTime([&]() { differenceSet(setB, set); }) });
    results.push_back({ measureExecutionTime([&]() { symmetricDifference(set, setB); }) });
    return results;
}

template<typename T>
vector<double> measureAllOperations(T& set, T& setB, const vector<int>& arrA)
{
    vector<double> results;
    results.push_back({ measureExecutionTime([&]() { set.fillSet(arrA); }) });
    results.push_back({ measureExecutionTime([&]() { set.getSetCapacity(); }) });
    results.push_back({ measureExecutionTime([&]() { set.isSubset(set); }) });
    results.push_back({ measureExecutionTime([&]() { set.isSubset(setB); }) });
    results.push_back({ measureExecutionTime([&]() { set.isEqual(set); }) });
    results.push_back({ measureExecutionTime([&]() { set.isEqual(setB); }) });
    results.push_back({ measureExecutionTime([&]() { set.unionSet(set); }) });
    results.push_back({ measureExecutionTime([&]() { set.intersectionSet(set); }) });
    results.push_back({ measureExecutionTime([&]() { set.differenceSet(setB); }) });
    results.push_back({ measureExecutionTime([&]() { setB.differenceSet(set); }) });
    results.push_back({ measureExecutionTime([&]() { set.symmetricDifference(setB); }) });
    return results;
}

static int parseInt(int m, int M)
{
    int N;
    for (;;) {
        cout << "Введите мощность : (целое от " << m << " до " << M << "): " << flush;
        if ((cin >> N).good() && (m <= N) && (N <= M))  return N;
        if (cin.fail()) {
            cin.clear();
            cout << "Неверный ввод, повторите.\n";
        } else {
            cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
        }
        cin.ignore(LONG_MAX, '\n');
    }
}

static void printTable(vector<vector<double>>& all_results)
{
    cout << setfill(delimiter) << setw(totalWidth) << "" << endl;
    for (int i = 0; i < headers.size(); i++) {
        cout << left << setw(columnWidth) << setfill(' ') << headers[i] << "|";
    }
    cout << endl << setfill(delimiter) << setw(totalWidth) << "" << endl;

    for (int i = 0; i < rows.size(); i++) {
        cout << setw(columnWidth) << setfill(' ') << rows[i] << "|";
        for (int j = 0; j < all_results.size(); j++) {
            cout << left << setw(columnWidth) << setfill(' ') << all_results[j][i] << "|";
        }
        cout << endl << setfill(delimiter) << setw(totalWidth) << "" << endl;
    }
}

static vector<int> createRandomArray(int size) {
    vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        bool isUnique = false;
        while (!isUnique) {
            int randomNumber = rand() % (multCoef * size + 1);
            auto it = find(array.begin(), array.begin() + i, randomNumber);
            if (it == array.begin() + i) {
                array[i] = randomNumber;
                isUnique = true;
            }
        }
    }
    return array;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    HWND hwnd = GetConsoleWindow();
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    if (hwnd != NULL) MoveWindow(hwnd, 0, 250, screenWidth, 600, TRUE); 

    int SET_SIZE = parseInt(MIN_SIZE, MAX_SIZE);
    vector<int> arrayA = createRandomArray(SET_SIZE);
    vector<int> arrayB = createRandomArray(SET_SIZE);

    setOnNodeStructB = fillSet(arrayB);
    setOnNodeB.fillSet(arrayB);
    setOnListB.fillSet(arrayB);
    setOnSetB.fillSet(arrayB);
    setOnUnorderedMapB.fillSet(arrayB);
    setOnUnorderedMultiMapB.fillSet(arrayB);

    vector<vector<double>> all_results = {
        measureAllOperations(setOnNodeStruct, setOnNodeStructB, arrayA),
        measureAllOperations(setOnNode, setOnNodeB, arrayA),
        measureAllOperations(setOnList, setOnListB, arrayA),
        measureAllOperations(setOnSet, setOnSetB, arrayA),
        measureAllOperations(setOnUnorderedMap, setOnUnorderedMapB, arrayA),
        measureAllOperations(setOnUnorderedMultiMap, setOnUnorderedMultiMapB, arrayA)
    };

    printTable(all_results);
}