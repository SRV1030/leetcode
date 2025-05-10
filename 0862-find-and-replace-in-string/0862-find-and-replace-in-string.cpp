class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, string> indexToSubstringMap;
        int numberOfOperations = indices.size(), sizeOfString = s.size();
        vector<vector<int>> updatedIndices;
        for(int index = 0; index < numberOfOperations; index++){
            int startOfUpdate = indices[index];
            string sourceString = sources[index];
            string targetString = targets[index];
            if(s.substr(startOfUpdate, sourceString.size()) != sourceString)
                continue;
            indexToSubstringMap[startOfUpdate] = targetString;
            updatedIndices.push_back({startOfUpdate, (int) sourceString.size() - 1});
        }

        string replacedString = "";
        sort(updatedIndices.begin(),updatedIndices.end());
        // for(auto&i:updatedIndices)
        //     cout<<i[0]<<" "<<i[1]<<"\n";
        // for(auto&[k,v]:indexToSubstringMap)
        //     cout<<k<<" "<<v<<"\n";
        for(int index = 0,updatedIndex = 0; index < sizeOfString; index++){
            if(updatedIndex < updatedIndices.size() && index == updatedIndices[updatedIndex][0]){
                // cout<<updatedIndex<<"\n";
                replacedString += indexToSubstringMap[index];
                index += (updatedIndices[updatedIndex][1]);
                updatedIndex++;
            }
            else replacedString.push_back(s[index]);
        }
        return replacedString;
    }
};