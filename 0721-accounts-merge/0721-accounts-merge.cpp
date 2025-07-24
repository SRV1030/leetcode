class Solution {
    unordered_map<string, string> parents, owner;
    unordered_map<string, set<string>> unions;

    string find(string child){
        return child == parents[child] ? child : find(parents[child]);
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int index = 0; index < accounts.size(); ++index){
            for(int nextIndex = 1; nextIndex < accounts[index].size(); ++nextIndex){
                parents[accounts[index][nextIndex]] = accounts[index][nextIndex];
                owner[accounts[index][nextIndex]] = accounts[index][0];
            }
        }

        for(int index = 0; index < accounts.size(); ++index){
            string parent = find(accounts[index][1]);
            for(int nextIndex = 2; nextIndex < accounts[index].size(); ++nextIndex){
                parents[find(accounts[index][nextIndex])] = parent;
            }
        }

        for(int index = 0; index < accounts.size(); ++index){
            for(int nextIndex = 1; nextIndex < accounts[index].size(); ++nextIndex){
                unions[find(accounts[index][nextIndex])].insert(accounts[index][nextIndex]);
            }
        }

        vector<vector<string>> result;

        for(auto&[parent, group] : unions){
            vector<string> emails(group.begin(), group.end());
            emails.insert(emails.begin(), owner[parent]);
            result.push_back(emails);
        }

        return result;
    }
};