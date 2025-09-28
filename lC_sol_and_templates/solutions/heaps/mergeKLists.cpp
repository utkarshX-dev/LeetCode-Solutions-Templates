#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

    for (int i = 0; i < n; i++)
    {
        if (lists[i] != NULL)
        {
            pq.push({lists[i]->val, lists[i]});
        }
    }
    ListNode *dummyHead = new ListNode(-1);
    auto temp = dummyHead;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        temp->next = node.second;
        temp = temp->next;
        if (node.second->next)
        {
            pq.push({node.second->next->val, node.second->next});
        }
    }
    return dummyHead->next;
}
