class Solution {
    set<int> positions, lengths;
    vector<int> frequency;
public:
    void addLen(int len){
        frequency[len]++;
        if(frequency[len] == 1){
            lengths.insert(len);
        }
    }

    void removeLen(int len){
        frequency[len]--;
        if(frequency[len] == 0){
            lengths.erase(len);
        }
    }

    void addPosition(int pos){
        auto it = positions.lower_bound(pos);
        auto nxt = *it, prv = *prev(it);
        removeLen(nxt - prv);
        addLen(pos - prv);
        addLen(nxt - pos);
        positions.insert(pos);
    }

    void removePosition(int pos){
        auto it = positions.find(pos);
        auto nxt = *next(it), prv = *prev(it);
        removeLen(nxt - pos);
        removeLen(pos - prv);
        addLen(nxt - prv);
        positions.erase(pos);
    }

    void updatePos(int pos, bool isBoundary){
        if(!isBoundary){
            removePosition(pos);
        }
        else{
            addPosition(pos);
        }
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int size = s.size();
        int k = queryCharacters.size();
        frequency.resize(size + 1);
        positions.insert(0);
        positions.insert(size);
        int left = 0;
        for(int right = 1; right < size; ++right){
            if(s[left] != s[right]){
                addLen(right - left);
                positions.insert(right);
                left = right;
            }
        }
        addLen(size - left);

        vector<int> result;

        for(int ind = 0; ind < k; ++ind){
            int qInd = queryIndices[ind];
            char qCh = queryCharacters[ind];
            if(qInd > 0){
                bool wasBoundary = s[qInd] != s[qInd - 1];
                bool isBoundary = qCh != s[qInd - 1];

                if(wasBoundary != isBoundary){
                    updatePos(qInd, isBoundary);
                }
            }

            if(qInd + 1 < size){
                bool wasBoundary = s[qInd] != s[qInd + 1];
                bool isBoundary = qCh != s[qInd + 1];

                if(wasBoundary != isBoundary){
                    updatePos(qInd + 1, isBoundary);
                }
            }
            s[qInd] = qCh;
            result.push_back(*lengths.rbegin());
        }
        return result;
    }
};