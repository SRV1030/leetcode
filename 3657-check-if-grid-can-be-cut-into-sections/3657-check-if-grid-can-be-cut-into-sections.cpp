class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x_axis,y_axis;
        for(auto&rectangle:rectangles){
            x_axis.push_back({rectangle[0],rectangle[2]});
            y_axis.push_back({rectangle[1],rectangle[3]});
        }
        sort(x_axis.begin(),x_axis.end());
        sort(y_axis.begin(),y_axis.end());
        int curr_x_end=x_axis[0][1],curr_y_end=y_axis[0][1],x=0,y=0;
        for(int i=1;i<x_axis.size();i++){
            if(curr_x_end<=x_axis[i][0]) x++;
            if(curr_y_end<=y_axis[i][0]) y++;
            curr_y_end=max(curr_y_end,y_axis[i][1]);
            curr_x_end=max(curr_x_end,x_axis[i][1]);
        }
        return max(x,y)>=2;
    }
};