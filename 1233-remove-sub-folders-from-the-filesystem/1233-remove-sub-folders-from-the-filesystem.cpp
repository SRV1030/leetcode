class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        result.push_back(folder[0]);
        for(int index = 1; index < folder.size(); ++index){
            string lastFolder = result.back() + "/";
            string prefix = folder[index].substr(0, lastFolder.size());
            if(prefix != lastFolder)
                result.push_back(folder[index]);
        }
        return result;
    }
};