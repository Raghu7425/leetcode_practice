class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        unordered_set<string> q1{beginWord}, q2{endWord}, next;
        int steps = 1, L = beginWord.size();
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) swap(q1, q2);
            next.clear();
            for (auto it = q1.begin(); it != q1.end(); ++it) dict.erase(*it);
            for (const string &w : q1) {
                string cur = w;
                for (int i = 0; i < L; ++i) {
                    char old = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        cur[i] = c;
                        if (q2.count(cur)) return steps + 1;
                        if (dict.count(cur)) {
                            next.insert(cur);
                            dict.erase(cur);
                        }
                    }
                    cur[i] = old;
                }
            }
            steps++;
            q1.swap(next);
        }
        return 0;
    }
};