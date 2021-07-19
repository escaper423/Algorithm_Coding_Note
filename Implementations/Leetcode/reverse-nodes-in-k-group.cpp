//problem URL: https://leetcode.com/problems/reverse-nodes-in-k-group/
//referenced: https://leetcode.com/discuss/explore/july-leetcoding-challenge-2021/1345510/Reverse-Nodes-in-k-Group-or-Iterative-%2B-Recursion-wExplanation
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        
        int cnt = 0;
        
        for(int i = 0; i < k; i++){
            if (!cur)
                return head;
            cur = cur->next;
        }
        
        cur = head;
        
        while(cur && cnt < k){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }
        
        if(cur){
            head->next = reverseKGroup(cur,k);
        };
        
        return prev;
    }
};
