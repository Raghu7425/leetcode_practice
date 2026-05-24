#include <bits/stdc++.h>
using namespace std;

// Helper function to check if allocation is possible with given maxPages
bool canAllocate(const vector<int> &pages, int students, int maxPages) {
    int requiredStudents = 1; // start with first student
    long long currentSum = 0;

    for (int p : pages) {
        if (p > maxPages) return false; // single book exceeds limit
        if (currentSum + p > maxPages) {
            requiredStudents++;
            currentSum = p;
            if (requiredStudents > students) return false;
        } else {
            currentSum += p;
        }
    }
    return true;
}

// Main function to find minimum possible maximum pages
int allocateBooks(const vector<int> &pages, int students) {
    int n = pages.size();
    if (n == 0 || students <= 0 || students > n) return -1;

    int low = *max_element(pages.begin(), pages.end()); // largest single book
    long long high = accumulate(pages.begin(), pages.end(), 0LL); // sum of all pages
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(pages, students, mid)) {
            result = mid;
            high = mid - 1; // try smaller max
        } else {
            low = mid + 1; // increase limit
        }
    }
    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int answer = allocateBooks(books, students);
    if (answer != -1)
        cout << "Minimum possible maximum pages: " << answer << "\n";
    else
        cout << "Allocation not possible\n";

    return 0;
}