//problem URL: https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        
        ListNode* prev = nullptr;
        ListNode *cur = head;
        ListNode* leftPrev = nullptr;
        ListNode* rightNext = nullptr;
        ListNode* leftmost = nullptr;
        ListNode* rightmost = nullptr;
        
        for(int i = 0; i < right; i++){
            if (i + 1 == left){
                leftPrev = prev;
            }
            prev = cur;
            cur = cur->next;
        }
        rightNext = cur;
        
        leftmost = (leftPrev)?leftPrev->next:head;
        rightmost = prev;
        
        cur = leftmost->next;
        prev = leftmost;
        
        
        int idx = 0;
        while(idx < right - left){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            idx++;
        }
        
        leftmost->next = rightNext;
        if(leftPrev)
            leftPrev->next = rightmost;
        else
            head = rightmost;
        
        return head;
    }
};
