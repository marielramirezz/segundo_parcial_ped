
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void ReverseList(Node*& head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
 temp = current->prev;
current->prev = current->next;
current->next = temp;
current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

void SwapAdjacentPairs(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        Node* first = current;
        Node* second = current->next;
        Node* previous = first->prev;
        Node* nextPair = second->next;

        second->prev = previous;
        second->next = first;
        first->prev = second;
        first->next = nextPair;

        if (previous != nullptr) {
            previous->next = second;
        } else {
            head = second;
        }

        if (nextPair != nullptr) {
            nextPair->prev = first;
        }

        current = nextPair;
    }
}

void RemoveConsecutiveDuplicates(stack<int>& values) {
    stack<int> auxiliary;

    while (!values.empty()) {
        int current = values.top();
        values.pop();

        if (auxiliary.empty() || auxiliary.top() != current) {
            auxiliary.push(current);
        }
    }

    while (!auxiliary.empty()) {
        values.push(auxiliary.top());
        auxiliary.pop();
    }
}

void SeparateRequests(queue<int>& requests, queue<int>& priority) {
    int size = requests.size();

    for (int i = 0; i < size; i++) {
        int current = requests.front();
        requests.pop();

        if (current % 3 == 0) {
            priority.push(current);
        } else {
            requests.push(current);
        }
    }
}

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 &&
               ((arr[j] % 2 != 0 && key % 2 == 0) ||
                ((arr[j] % 2 == 0) == (key % 2 == 0) &&
arr[j] > key))) {
arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int FindLargestSmaller(const int values[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (values[mid] < target) {
            result = mid;
            
left = mid + 1;
} else {
right = mid - 1;
}
    }

    return result;
}

int CountMatches(const int values[], int n) {
    int count = 0;

for (int i = 0; i < n; i++) {
for (int j = 0; j < 3; j++) {
if (values[i] == j) {
count++;
}
}
}

    return count;
}

int CountComparisons(const int values[], int n) {
    int count = 0;
for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j += 2) {
if (values[i] < values[j]) {
count++;
}
} }

    return count;
}

int main() {
    return 0;
}
