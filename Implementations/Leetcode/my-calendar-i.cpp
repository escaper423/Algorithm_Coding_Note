//problem URL: https://leetcode.com/problems/my-calendar-i/
class MyCalendar {
private:
    struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
    int s;
    int e;
    Node(int st, int ed) : s(st), e(ed){}
    };

public:
    Node* root = nullptr;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (!root){
            root = new Node(start,end);
            return true;
        }
        
        Node* cur = root;
        
        while(cur){
            if(end <= cur->s){
                if(!cur->left){
                    cur->left = new Node(start,end);
                    return true;
                }
                else{
                    cur = cur->left;
                }
            }
            else if (cur->e <= start){
                if (!cur->right){
                    cur->right = new Node(start,end);
                    return true;
                }
                else{
                    cur = cur->right;
                }
            }
            else return false;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
