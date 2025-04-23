class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> previousPoints;
        for(auto&point:points[0])previousPoints.push_back(point);

        for(int i=1;i<points.size();i++){
            int size = points[0].size();
            vector<long long> currentPoints(size);
            vector<long long>leftPoints(size,-1),rightPoints(size,-1);

            leftPoints[0] = previousPoints[0];
            for(int k=1;k<points[0].size();k++)
                leftPoints[k] = max(leftPoints[k-1],previousPoints[k] + k);
            
            rightPoints[size-1] = previousPoints[size-1] - size + 1;
            for(int k=size-2;k>=0;k--)
                rightPoints[k] = max(rightPoints[k+1],previousPoints[k] - k);

            for(int j=0;j<points[0].size();j++){
                currentPoints[j]=max(leftPoints[j] - j,rightPoints[j] + j) + points[i][j];
                // for(int k=0;k<points[0].size();k++){
                //     currentPoints[j]=max(currentPoints[j],(long long)(previousPoints[k]+points[i][j]-abs(k-j)));
                // }
            }
            previousPoints = currentPoints;
            // for(auto&i:previousPoints) cout<<i<<" ";
            // cout<<"\n";
        }
        return *max_element(previousPoints.begin(),previousPoints.end());
    }
};