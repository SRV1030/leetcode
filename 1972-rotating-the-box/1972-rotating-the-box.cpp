class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(auto&i:box){
            int block=i.size();
            for(int j=block-1;j>=0;j--){
                if(i[j]=='#'){
                    char t=i[j];
                    i[j]='.';
                    i[block-1]=t;
                    block--;
                }
                if(i[j]=='*')block=j;
            }
        }
        vector<vector<char>> res(box[0].size(), vector<char>(box.size(), '.'));
        for (int i = 0; i < box.size(); i++) {
            for (int j = 0; j < box[0].size(); j++) {
                res[j][(box.size() - 1) - i] = box[i][j];
            }
        }
        return res;
    }
};