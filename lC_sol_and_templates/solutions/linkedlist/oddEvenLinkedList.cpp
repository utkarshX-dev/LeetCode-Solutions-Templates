//lc 328
#include <iostream>
#include <bits/stdc++.h>

   struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* dummyOdd = new ListNode(-1);
        ListNode* dummyEven = new ListNode(-1);
        ListNode* tempOdd = dummyOdd;
        ListNode* tempEven = dummyEven;
        ListNode* temp = head;
        bool odd = true;
        while(temp != NULL){
            if(odd){
                tempOdd->next = temp;
                temp = temp->next;
                tempOdd = tempOdd->next;
                tempOdd->next = NULL;
            }else{
                tempEven->next = temp;
                temp = temp->next;
                tempEven = tempEven->next;
                tempEven->next = NULL;
            }
            odd = !odd;
        }
        tempOdd->next = dummyEven->next;
        return dummyOdd->next;
    }
};
using namespace std;
int main(){
    
    return 0;
}