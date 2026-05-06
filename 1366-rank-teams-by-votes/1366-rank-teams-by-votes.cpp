class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int size = votes[0].size();
        vector<vector<int>> ranks(26, vector<int>(size, 0));

        for (auto& vote : votes) {
            for (int index = 0; index < vote.size(); ++index) {
                ranks[vote[index] - 'A'][index]++;
            }
        }

        string res = votes[0];

        sort(res.begin(), res.end(), [&](const char& a, const char& b) {
            int ai = a - 'A', bi = b - 'A';

            for (int ind = 0; ind < size; ++ind) {
                if (ranks[ai][ind] != ranks[bi][ind])
                    return ranks[ai][ind] > ranks[bi][ind];
            }

            return ai < bi;
        });

        return res;
    }
};