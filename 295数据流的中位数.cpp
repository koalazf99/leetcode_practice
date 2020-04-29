
class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    // priority_queue<int, vector<int>, greater<int>> large;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (small.size()==0) {small.push(num); return;}
        if (small.size()>large.size()){
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        else{
            if (num>large.top()) {
                small.push(large.top());
                large.pop();
                large.push(num);
            }
            else{
                small.push(num);
            }
        }
    }
    
    double findMedian() {
        if (small.size()>large.size()) return small.top();
        else return (small.top()+large.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */