//problem URL: https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
public:
    /** initialize your data structure here. */
    int l;
    int r;
    multiset<int> m;
    MedianFinder() {
        l = -1, r = 0;
    }
    
    void addNum(int num) {
        (l < r)?l++:r++;
        m.insert(num);
    }
    
    double findMedian() {
        int n = m.size();
        auto it = m.begin();
        advance(it,n/2);
        if(l == r){
            return (double)*it;
        }
        else{
            auto it2 = it--;
            return (double)((double)(*it2 + *it)/2);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
