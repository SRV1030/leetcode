class MyCalendar {
public:
    set<pair<int,int>>cld;
    
    bool book(int start, int end) {
        const pair<int,int>ev{start,end};
        const auto next = cld.lower_bound(ev);
        if(next!=cld.end() && next->first < end)return false;
        if(next!=cld.begin()){
            const auto pre = prev(next);
            if(pre->second>start) return false;
        }
        cld.insert(ev);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */