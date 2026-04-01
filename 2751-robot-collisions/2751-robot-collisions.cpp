class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int size = positions.size();
        vector<int> finalHealth(size, -1);
        vector<vector<int>> rightStack;
        vector<vector<int>> superSet;
        for(int index = 0; index < size; ++index){
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
                    finalHealth[arr[3]] = arr[1];
                }
            }
        }
        
        for(auto& arr: rightStack)
            finalHealth[arr[0]] = arr[1];
        
        vector<int> res;
        for(auto&val : finalHealth)
            if(val != -1)
                res.push_back(val);
        return res;
    }
};