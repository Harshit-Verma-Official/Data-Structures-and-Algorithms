#include <bits/stdc++.h>
using namespace std;

// Method 1 (Using Map)
// O(m + n)
void printUnionByUsingMap(int arr1[], int arr2[], int m, int n) {
    map<int, int> map;

    for (int i = 0; i < m; ++i)
        map.insert({arr1[i], i});
    for (int i = 0; i < n; ++i)
        map.insert({arr2[i], i});

    for (auto i = map.begin(); i != map.end(); ++i)
        cout << i->first << " ";
}

// O(m + n)
void printIntersectionUsingMap(int arr1[], int arr2[], int m, int n) {
    map<int, int> map;

    for (int i = 0; i < m; ++i)
        map.insert({arr1[i], i});
    for (int i = 0; i < n; ++i)
        if (map.find(arr2[i]) != map.end())
            cout << arr2[i] << " ";
}

int binarySearch(int arr[], int target, int left, int right) {
    if (left > right)
        return -1;

    int middle = (left + right) / 2;
    if (arr[middle] == target)
        return middle;
    if (target < arr[middle])
        return binarySearch(arr, target, left, middle - 1);
    return binarySearch(arr, target, middle + 1, right);
}

// Method 2 : Sorting and Searching (disinct elements)
void printUnionBySortingAndSearching(int arr1[], int arr2[], int m, int n) {
    if (m > n) {
        int *temp = arr1;
        arr1 = arr2;
        arr2 = temp;

        m = m + n;
        n = m - n;
        m = m - n;
    }

    sort(arr1, arr1 + m);
    for (int i = 0; i < m; ++i)
        cout << arr1[i] << " ";
    for (int i = 0; i < n; ++i) {
        if (binarySearch(arr1, arr2[i], 0, m - 1) == -1)
            cout << arr2[i] << " ";
    }
}

void printIntersectionUsingSortingAndSearching(int arr1[], int arr2[], int m, int n) {
    if (m > n) {
        int *temp = arr1;
        arr1 = arr2;
        arr2 = temp;

        m = m + n;
        n = m - n;
        m = m - n;
    }

    sort(arr1, arr1 + m);

    for (int i = 0; i < n; ++i) {
        if (binarySearch(arr1, arr2[i], 0, m - 1) != -1)
            cout << arr2[i] << " ";
    }
}

// Method 3 : (Using Hashing : Sets)
void printUnionUsingSets(int arr1[], int arr2[], int m, int n) {
    set<int> hs;
    for (int i = 0; i < m; ++i)
        hs.insert(arr1[i]);
    for (int i = 0; i < n; ++i)
        hs.insert(arr2[i]);
    for (auto i = hs.begin(); i != hs.end(); ++i)
        cout << *i << " ";
}

void printInterSectionUsingSets(int arr1[], int arr2[], int m, int n) {
    set<int> hs;
    for (int i = 0; i < m; ++i)
        hs.insert(arr1[i]);
    for (int i = 0; i < n; ++i)
        if (hs.find(arr2[i]) != hs.end())
            cout << arr2[i] << " ";
}

// Handling Duplicates : Very Important
// O(nlogn + mlogm + n + m)
void printUnionHandlingDuplicates(int arr1[], int arr2[], int m, int n) {
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    int i = 0;
    int j = 0;

    while (i < m and j < n) {
        if (i == 0 or j == 0 or arr1[i] != arr1[i - 1] and arr2[j] != arr2[j - 1]) {
            if (arr1[i] < arr2[j])
                cout << arr1[i++] << " ";
            else if (arr2[j] < arr1[i])
                cout << arr2[j++] << " ";
            else {
                cout << arr1[i++] << " ";
                j++;
            }
        } else {
            if (arr1[i] == arr1[i - 1])
                i++;
            if (arr2[j] == arr2[j - 1])
                j++;
        }
    }

    while (i < m) {
        if (arr1[i] != arr1[i - 1])
            cout << arr1[i] << " ";
        i++;
    }
    while (j < n) {
        if (arr2[j] != arr2[j - 1])
            cout << arr2[j] << " ";
        j++;
    }
}

// Handling Duplicates : Very Important
// O(nlogn + mlogm + n + m)
void printIntersectionHandlingDuplicates(int arr1[], int arr2[], int m, int n) {
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    int i = 0;
    int j = 0;

    while (i < m && j < n) {
        if (i == 0 or j == 0 or arr1[i] != arr1[i - 1] and arr2[j] != arr2[j - 1]) {
            if (arr1[i] < arr2[j])
                i++;
            else if (arr2[j] < arr1[i])
                j++;
            else {
                cout << arr1[i++] << " ";
                j++;
            }
        } else {
            if (arr1[i] == arr1[i - 1])
                i++;
            if (arr2[j] == arr2[j - 1])
                j++;
        }
    }
}

int main() {

    int arr1[] = {1, 2, 3, 3, 3, 3, 4, 5};
    int arr2[] = {2, 3, 3, 3, 4, 5, 4, 5, 5, 4};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    printIntersectionHandlingDuplicates(arr1, arr2, m, n);

    return 0;
}