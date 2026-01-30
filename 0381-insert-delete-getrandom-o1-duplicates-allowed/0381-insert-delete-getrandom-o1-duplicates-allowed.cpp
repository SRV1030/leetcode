class RandomizedCollection {
    unordered_map<int, unordered_set<int>> mp;
    vector<int> v;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size() - 1);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        auto itr  = mp.find(val);
        if(itr != mp.end()){
            int ri = *itr->second.begin();
            v[ri] = v.back();
            itr->second.erase(itr->second.begin());
            mp[v.back()].insert(ri);
            mp[v.back()].erase(v.size() - 1);
            v.pop_back();
            if(!size(itr->second))
                mp.erase(itr);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        if(!v.size())
            return -1;
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */