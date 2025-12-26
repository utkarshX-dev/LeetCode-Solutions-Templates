#include <iostream>
#include <bits/stdc++.h>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *curr = head, *forward = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return ;
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow;
        ListNode* part1 = head;
        ListNode* part2 = slow->next;
        temp->next = NULL;
        part2 = reverse(part2);

        ListNode* dummyHead = new ListNode(-1), *dummyTemp = dummyHead;
        while(part1 || part2){
            if(part1){
                dummyTemp->next = part1;
                part1 = part1->next;
                dummyTemp = dummyTemp->next;
            }
            if(part2){
                dummyTemp->next = part2;
                part2 = part2->next;
                dummyTemp = dummyTemp->next;
            }
            dummyTemp->next = NULL;
        }
        head = dummyHead->next;
    }
};