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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        int len = 1;
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            len++;
            temp = temp->next;
        }
        temp->next = head; // make circular;
        k = k % len;       // no need to change steps multiple of size which results in same structure again
        if (k == 0)
        {
            temp->next = nullptr;
            return head;
        }
        int steps = len - k - 1;
        temp = head;
        while (steps)
        {
            temp = temp->next;
            steps--;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};