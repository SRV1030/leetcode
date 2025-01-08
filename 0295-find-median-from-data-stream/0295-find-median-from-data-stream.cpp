class MedianFinder {
public:
    priority_queue<int>mxhp;
    priority_queue<int,vector<int>,greater<int>>mnhp;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxhp.size()==0)mxhp.push(num);
        else{
            if(num>mxhp.top()){
                mnhp.push(num);
                if(mxhp.size()+1==mnhp.size()){
                    mxhp.push(mnhp.top());
                    mnhp.pop();
                }
            }
            else{
                mxhp.push(num);
                if(mxhp.size()>mnhp.size()+1){
                    mnhp.push(mxhp.top());
                    mxhp.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if((mxhp.size()+mnhp.size())%2) return mxhp.top();
        else return (mxhp.top()+mnhp.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */