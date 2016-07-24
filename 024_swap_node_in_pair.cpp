/*
   leetcode algorithm 023:
                  swap node in pair
 
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
    ListNode* swapPairs(ListNode* head)
    {
		ListNode * last=NULL;
		ListNode *p=head;
		while(p && p->next){
		   ListNode * next=p->next;
		   p->next=next->next;
		   next->next=p;
		   if(last){
			   last->next=next;
			   last=p;			   
		   }else{
               head=next;
			   last=p;			   
		   }
	       p=p->next;	   
	   }
	  return head;	        
    }
};
