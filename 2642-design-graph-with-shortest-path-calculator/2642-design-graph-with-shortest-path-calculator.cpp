class Graph {
    vector<vector<int>> graph;
    int size;
    const int MAX_VAL = 1e9 + 7;
public:
    Graph(int n, vector<vector<int>>& edges) {
        size = n;
        graph = vector<vector<int>> (size, vector<int>(size, MAX_VAL));
        for(int u = 0; u < size; ++u){
            graph[u][u] = 0;
        }  
        for(auto& edge : edges){
            graph[edge[0]][edge[1]] = edge[2];
        }

        for(int bridge = 0; bridge < size; ++bridge){
            for(int u = 0; u < size; ++u){
                for(int v = 0; v < size; ++v){
                    graph[u][v] = min(graph[u][v], graph[u][bridge] + graph[bridge][v]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        if(graph[edge[0]][edge[1]] <= edge[2])
            return;
        graph[edge[0]][edge[1]] = edge[2];
        for(int u = 0; u < size; ++u){
            for(int v = 0; v < size; ++v){
                graph[u][v] = min(graph[u][v], graph[u][edge[0]] + edge[2] + graph[edge[1]][v]);
            }
        }  
    }
    
    int shortestPath(int node1, int node2) {
        if (graph[node1][node2] == MAX_VAL) {
            return -1;
        }
        return graph[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */