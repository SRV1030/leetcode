class SnapshotArray {
public:
    map<int,map<int,int>> snapShotMap;
    int snap_id;
    SnapshotArray(int length) {
        snap_id = 0;
        for (int i = 0; i < length; i++) {
            map<int, int> shotMap; 
            shotMap[0] = 0;
            snapShotMap[i] = shotMap;
        }
    }
    
    void set(int index, int val) {
        snapShotMap[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id_) {
        auto it = snapShotMap[index].upper_bound(snap_id_);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */