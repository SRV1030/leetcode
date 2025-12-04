class MyCalendar {
public:
    map<int,int>calendar;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto calendarItr = calendar.upper_bound(startTime);
        if(calendarItr == calendar.end() || endTime <= calendarItr->second){
            calendar[endTime] = startTime;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */