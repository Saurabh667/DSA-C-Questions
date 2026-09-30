class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) const {

            if (a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;

        for (string w : words) {
            mp[w]++;
        }

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            Compare
        > pq;

        for (auto x : mp) {
            pq.push({x.second, x.first});
        }

        vector<string> out;

        while (k--) {
            out.push_back(pq.top().second);
            pq.pop();
        }

        return out;
    }
};
