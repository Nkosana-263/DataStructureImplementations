
"Reversing a linked list"

#include <bits/stdc++.h>
using namespace std;
class ListNode{
   public:
      int val;
      ListNode *next;
      ListNode(int data){
         val = data;
         next = NULL;
      }
   };
   ListNode *make_list(vector<int> v){
      ListNode *head = new ListNode(v[0]);
      for(int i = 1; i<v.size(); i++){
         ListNode *ptr = head;
         while(ptr->next != NULL){
            ptr = ptr->next;
         }
         ptr->next = new ListNode(v[i]);
      }
      return head;
   }
   void print_list(ListNode *head){
      ListNode *ptr = head;
      cout << "[";
      while(ptr){
         cout << ptr->val << ", ";
         ptr = ptr->next;
      }
      cout << "]" << endl;
 }
 class Solution {
   public:
      ListNode* successor = NULL;
      ListNode* reverseN(ListNode* head, int n ){
         if(n == 1){
            successor = head->next;
            return head;
         }
         ListNode* last = reverseN(head->next, n - 1);
         head->next->next = head;
         head->next = successor;
         return last;
      }
      ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(m == 1){
            return reverseN(head, n);
      }
      head->next = reverseBetween(head->next, m - 1, n - 1);
            return head;
   }
 };
main(){
   Solution ob;
   vector<int> v = {1,2,3,4,5,6,7,8};
   ListNode *head = make_list(v);
   print_list(ob.reverseBetween(head, 2, 6));
}