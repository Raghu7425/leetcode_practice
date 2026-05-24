#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);

        unordered_map<int, vector<int>> mp;

        // Step 1: group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for (auto& [val, v] : mp) {
            int k = v.size();
            vector<long long> prefix(k + 1, 0);

            // build prefix sum of indices
            for (int i = 0; i < k; i++) {
                prefix[i + 1] = prefix[i] + v[i];
            }

            // compute result
            for (int i = 0; i < k; i++) {
                long long pos = v[i];

                long long left = pos * i - prefix[i];
                long long right = (prefix[k] - prefix[i + 1]) - pos * (k - i - 1);

                res[pos] = left + right;
            }
        }

        return res;
    }
};



