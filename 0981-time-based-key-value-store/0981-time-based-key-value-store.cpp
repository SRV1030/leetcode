class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string result = "";
        auto& space = store[key];
        int low = 0, high = space.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(space[mid].first <= timestamp){
                result = space[mid].second;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */