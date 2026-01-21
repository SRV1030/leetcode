class AllOne {
    unordered_map<string, int> counter;
    map<int, set<string>> countToStringMap;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(counter.count(key)){
            int count = counter[key];
            countToStringMap[count].erase(key);
            if(countToStringMap[count].empty())
                countToStringMap.erase(count);
        }
        counter[key]++;
        countToStringMap[counter[key]].insert(key);
    }
    
    void dec(string key) {
        int count = counter[key];
        countToStringMap[count].erase(key);
        if(countToStringMap[count].empty())
            countToStringMap.erase(count);
        if(count == 1)
            counter.erase(key);
        else{
            countToStringMap[count - 1].insert(key);
            counter[key]--;
        }
    }
    
    string getMaxKey() {
        if(countToStringMap.empty())
            return "";
        auto itr = countToStringMap.end();
        --itr;
        return *itr->second.begin();
    }
    
    string getMinKey() {
        if(countToStringMap.empty())
            return "";
        auto itr = countToStringMap.begin();
        return *itr->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */