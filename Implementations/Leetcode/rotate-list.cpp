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
 
 //problem URL: https://leetcode.com/problems/rotate-list/
class Solution {
public:
    void reverseList(ListNode *& head){
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *tmp = nullptr;
        
        while(cur != nullptr){
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        head = prev;
    }
    
    ListNode* insertNode(ListNode *head, int val){
        if (head == nullptr){
            return new ListNode(val);
        }
        
        else{
            ListNode* newnode = new ListNode(val);
            newnode->next = head;
            head = newnode;
            return head;
        }
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        
        int list_size = 1;
        
        ListNode* tmp = head;
        ListNode* cur = head;
        
        while (cur->next != nullptr){
            cur = cur->next;
            list_size++;
        }
        
        cur->next = tmp;
        cur = head;
        
        if (k > list_size){
            k %= list_size;
        }
        
        int rot = (list_size - k)%list_size;
        for(int i = 0; i < rot; i++){
            cur = cur->next;
        }
        
        ListNode* res = nullptr;
        
        for(int i = 0; i < list_size; i++){
            //cout << cur->val << " ";
            res = insertNode(res, cur->val);
            cur = cur->next;
        }
        
        reverseList(res);
        return res;
    }
};
