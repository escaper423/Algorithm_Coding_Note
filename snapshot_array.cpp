//Problem URL: https://leetcode.com/problems/snapshot-array/

class SnapshotArray {
public:
    SnapshotArray(int length) {
        obj.resize(length, vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        obj[index].push_back(make_pair(snap_id,val));
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        if (obj[index].size() == 0)
            return 0; 
        
        int mn = 0;
        int mx = obj[index].size()-1;
        int md;
        while(mn < mx){
            md = mn + (mx - mn + 1)/2;
            if(obj[index][md].first > snap_id){
                mx = md - 1;
            }
            else if (obj[index][md].first <= snap_id){
                mn = md;
            }
        }
        return obj[index][mn].second;
    }
    //pair: snap_id, val
private:
    vector<vector<pair<int,int>>> obj;
    int snap_id = 0;
    
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */