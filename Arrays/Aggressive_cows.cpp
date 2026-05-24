#include <bits/stdc++.h>
using namespace std;

/**
 * Checks if we can place 'cows' cows in 'stalls' such that
 * the minimum distance between any two cows is at least 'dist'.
 */
bool canPlaceCows(const vector<int> &stalls, int cows, int dist) {
    int count = 1; // Place first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < (int)stalls.size(); i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
            if (count >= cows) return true; // All cows placed
        }
    }
    return false;
}

/**
 * Finds the largest minimum distance possible between cows.
 */
int aggressiveCows(vector<int> stalls, int cows) {
    if (stalls.empty() || cows <= 0 || cows > (int)stalls.size()) {
        throw invalid_argument("Invalid stalls or cows count");
    }

    sort(stalls.begin(), stalls.end());

    int low = 1; // Minimum possible distance
    int high = stalls.back() - stalls.front(); // Max possible distance
    int best = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, cows, mid)) {
            best = mid;      // Mid is possible, try for bigger distance
            low = mid + 1;
        } else {
            high = mid - 1;  // Mid not possible, try smaller distance
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cout << "Enter number of stalls and cows: ";
    if (!(cin >> n >> k) || n <= 0 || k <= 0) {
        cerr << "Invalid input.\n";
        return 1;
    }

    vector<int> stalls(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> stalls[i])) {
            cerr << "Invalid stall position.\n";
            return 1;
        }
    }

    try {
        int result = aggressiveCows(stalls, k);
        cout << "Largest minimum distance: " << result << "\n";
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
