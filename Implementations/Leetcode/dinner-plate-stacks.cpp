//problem URL: https://leetcode.com/problems/dinner-plate-stacks/
class DinnerPlates {
public:
    stack<int> cache[200020];
    priority_queue<int, vector<int>, greater<int>> leftmost_heap;
    priority_queue<int> rightmost_heap;
    
    int size;
    int elements;
    
    DinnerPlates(int capacity) {
        size = capacity;
        elements = 0;
    }
    
    void push(int val) {
        
        if (elements == 0){
            leftmost_heap.push(0);
        }
        
        int cursor = leftmost_heap.top();
        //cout << "push At " << cursor << endl;
        if (cache[cursor].empty()){
            rightmost_heap.push(cursor);
        }
        
        cache[cursor].push(val);
        
        if (cache[cursor].size() == size){
            leftmost_heap.pop();
            
            if (leftmost_heap.empty()){
                leftmost_heap.push(cursor+1);
            }
        }
        elements++;
    }
    
    int pop() {
        if (elements == 0){
            return -1;    
        }
        
        int cursor = rightmost_heap.top();
        
        while(cache[cursor].empty()){
            rightmost_heap.pop();
            cursor = rightmost_heap.top();
        }
        
        //cout << "pop At "  << cursor <<  endl;
        if (cache[cursor].size() == size){
            leftmost_heap.push(cursor);
        }
        
        int val = cache[cursor].top(); 
        cache[cursor].pop();
        
        if (cache[cursor].empty()){
            rightmost_heap.pop();    
        }
        
        elements--;
        return val;
    }
    
    int popAtStack(int index) {
        //cout << "popAtStack " << index << endl;
        if (cache[index].empty())
            return -1;
        
        if (cache[index].size() == size){
            leftmost_heap.push(index);
        }
        
        int val = cache[index].top();
        cache[index].pop();
        
        elements--;
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
