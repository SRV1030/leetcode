class Solution {
    class DSU{
        int numberOfNodes;
        int numberOfGroups;
        vector<int> parents, ranks;
    public:
        DSU(int n){
            numberOfNodes = n;
            numberOfGroups = n;
            parents = vector<int> (n);
            ranks = vector<int> (n, 1);
            iota(parents.begin(), parents.end(), 0);
        }

        int find(int node){
            return node == parents[node] ? node : parents[node] = find(parents[node]);
        }

        void unite(int node1, int node2){
            int p1 = find(node1), p2 = find(node2);
            if(p1 == p2)
                return;
            if(ranks[p1] < ranks[p2]){
                parents[p1] = p2;
                ranks[p2] += ranks[p1];
            }
            else{
                parents[p2] = p1;
                ranks[p1] += ranks[p2];
            }
            --numberOfGroups;
        }

        int getGroups(){
            vector<int> parentFr(numberOfNodes);
            int count = 0;
            for(int node = 0; node < numberOfNodes; ++node)
                parentFr[find(node)]++;
            for(auto& fr : parentFr)
                if(fr > 1)
                    ++count;
            return count;
        }
    };
public:
    int prefixConnected(vector<string>& words, int k) {
        int size = words.size(), res = 0;
        sort(words.begin(), words.end());
        for(int index = 0; index < size; ++index){
            if(words[index].size() < k){
                continue;
            }
            string key = words[index].substr(0, k);
            int next = index + 1;
            for(; next < size && words[next].size() >= k; ++next){
                if(key != words[next].substr(0, k))
                    break;
            }
            if(next - index > 1)
                ++res;
            index = next - 1;
        }

        return res;
    }
};