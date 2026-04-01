class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> leftStack;
        vector<vector<int>> rightStack;
        vector<vector<int>> superSet;
        for(int index = 0; index < positions.size(); ++index){
            superSet.push_back({positions[index], healths[index], directions[index] == 'R', index});
        }
        sort(superSet.begin(), superSet.end());
        for(auto& arr : superSet){
            if(arr[2]){
                rightStack.push_back({arr[3], arr[1]});
            }
            else{
                bool noEntry = false;
                while(!rightStack.empty()){
                    if(arr[1] > rightStack.back()[1]){
                        --arr[1];
                        rightStack.pop_back();
                    }
                    else if(arr[1] < rightStack.back()[1]){
                        noEntry = true;
                        --rightStack.back()[1];
                        break;
                    }
                    else{
                        noEntry = true;
                        rightStack.pop_back();
                        break;
                    }
                }
                if(!noEntry && rightStack.empty()){
                    leftStack.push_back({arr[3], arr[1]});
                }
            }
        }
        map<int, int> merger;
        for(auto& arr: leftStack)
            merger[arr[0]] = arr[1];
        for(auto& arr: rightStack)
            merger[arr[0]] = arr[1];
        
        vector<int> res;
        for(auto&[key, val] : merger)
            res.push_back(val);
        return res;
    }
};