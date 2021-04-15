#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//problem URL : https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;

    if (l1 == nullptr)
        return l2;

    if (l2 == nullptr)
        return l1;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            if (head == nullptr) {
                head = new ListNode(l1->val);
                tail = head;
            }

            else {
                ListNode* newnode = new ListNode(l1->val);
                tail->next = newnode;
                tail = newnode;
            }
            l1 = l1->next;
        }
        else {
            if (head == nullptr) {
                head = new ListNode(l2->val);
                tail = head;
            }

            else {
                ListNode* newnode = new ListNode(l2->val);
                tail->next = newnode;
                tail = newnode;
            }
            l2 = l2->next;
        }

    }

    while (l1 != nullptr) {
        tail->next = l1;
        tail = l1;
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        tail->next = l2;
        tail = l2;
        l2 = l2->next;
    }

    return head;
}

ListNode* makeList(vector<int> v) {
	ListNode* head = nullptr;
	ListNode* tail = nullptr;

	for (auto& it : v) {
		if (head == nullptr) {
			head = new ListNode(it);
			tail = head;
		}
		else {
			ListNode* newnode = new ListNode(it);
			tail->next = newnode;
			tail = newnode;
		}
	}
    return head;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ListNode* l1 = nullptr;
	ListNode* l2 = nullptr;


	vector<int> v1({ -9,3 });
	vector<int> v2({ 5,7 });

	l1 = makeList(v1);
	l2 = makeList(v2);

    ListNode* lm = mergeTwoLists(l1, l2);
    while (lm != nullptr) {
        cout << lm->val << " ";
        lm = lm->next;
    }
        
	
	return 0;
}
