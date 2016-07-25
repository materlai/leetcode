/*
   leetcode algorithm 021:
              merged two sorted linked list 
 
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode * head=NULL;
		ListNode * last=head;
		while(l1 && l2){
			if(l1->val<l2->val){
				if(!last){
					head=l1;
					last=head;
				}else{
					last->next=l1;
					last=l1;
				}
				l1=l1->next;	
			}else{
                if(!last){
					head=l2;
					last=head;
				}else{
                    last->next=l2;
					last=l2;
				}
				l2=l2->next;
			}
	   }
	   if(l1){
		   if(!head)  head=l1;
		   else{
			   last->next=l1;			   
		   }
	   }
	   if(l2){
           if(!head)   head=l2;
		   else  last->next=l2;
	   }
	   return head;        
    }
};
