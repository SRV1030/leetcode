class Solution {
    class DSU{
        int size;
        vector<int> parents, ranks;
        vector<int> minScore;
    public:
        DSU(int _size){
            this->size = _size + 1;
            parents = vector<int> (size);
            ranks = vector<int> (size, 1);
            iota(parents.begin(), parents.end(), 0);
            minScore = vector<int> (size, INT_MAX);
        }

        int find(int node){
            return parents[node] == node ? node : (parents[node] = find(parents[node]));
        }

        void unite(int node1, int node2, int cost){
            int p1 = find(node1), p2 = find(node2);
            if(p1 != p2){
                if(ranks[p1] < ranks[p2]){
                    parents[p1] = p2;
                    ranks[p1] += ranks[p2];
                }
                else{
                    parents[p2] = p1;
                    ranks[p2] += ranks[p1];
                }
            }
            int score = min({minScore[p1], minScore[p2], cost});
            minScore[p1] = score;
            minScore[p2] = score;
        }

        int getScore(){
            return minScore[find(1)];
        }
    };
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU uf(n);
        for(auto& road : roads){
            uf.unite(road[0], road[1], road[2]);
        }
        return uf.getScore();
    }
};