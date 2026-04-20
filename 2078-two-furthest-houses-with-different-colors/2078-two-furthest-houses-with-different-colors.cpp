class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int dist = 0;
        int size = colors.size();
        for(int ind = size - 1; ind > 0 ; --ind){
            if(colors[ind] != colors[0]){
                dist = max(dist, ind);
                break;
            }
        }
        for(int ind = 0; ind < size - 1; ++ind){
            if(colors[ind] != colors[size - 1]){
                dist = max(dist, size - 1 - ind);
                break;
            }
        }
        return dist;
    }
};