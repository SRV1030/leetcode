class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> firstOcuurence(26, -1), lastOccurence(26, -1), answer;
        vector<vector<int>> ocuurences, mergerdOccurences;
        for (int i = 0; i < s.size(); i++) {
            if (firstOcuurence[s[i] - 'a'] == -1)
                firstOcuurence[s[i] - 'a'] = i;
            lastOccurence[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++)
            if (firstOcuurence[i] != -1)
                ocuurences.push_back({firstOcuurence[i], lastOccurence[i]});
        sort(ocuurences.begin(), ocuurences.end());
        mergerdOccurences.push_back(ocuurences[0]);
        for (int i = 1; i < ocuurences.size(); i++) {
            if (ocuurences[i][0] < mergerdOccurences.back()[1])
                mergerdOccurences.back()[1] =
                    max(mergerdOccurences.back()[1], ocuurences[i][1]);
            else
                mergerdOccurences.push_back(ocuurences[i]);
        }
        for (auto& i : mergerdOccurences)
            answer.push_back(i[1] - i[0] + 1);
        return answer;
    }
};