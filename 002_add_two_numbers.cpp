/*
  leetcode problem 002:

*/

#include <cstdio>
#include <cstring>
#include <cstdlib>


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
		ListNode * head=NULL;
		ListNode * last=head;
		int add_buffer=0;
		while(l1!=NULL && l2!=NULL){
			ListNode * node=(ListNode*)malloc(sizeof(ListNode));
			node->next=NULL;
			node->val= l1->val+l2->val+add_buffer;
			add_buffer=0;
			if(node->val>=10){
				node->val%=10;
				add_buffer=1;
			}
			if(last==NULL){
				head=node;
				last=head;
			}else{
				last->next=node;
				last=node;
			}
			
			l1=l1->next;
			l2=l2->next;
		}

		while(l1){
			l1->val+=add_buffer;
			add_buffer=0;
			if(l1->val>=10){
				l1->val%=10;
				add_buffer=1;
			}
			last->next=l1;
			last=l1;
			l1=l1->next;
		}

		while(l2){
			l2->val+=add_buffer;
			add_buffer=0;
			if(l2->val>=10){
				l2->val%=10;
				add_buffer=1;				
			}
			last->next=l2;
			last=l2;
			l2=l2->next;			
		}

		if(add_buffer){
				ListNode * node=(ListNode*) malloc(sizeof(ListNode));
				node->val=add_buffer;
				node->next=NULL;
				last->next=node;
		}			
		return head;
    }
	
};


int main(int argc,char**argv)
{
   
  
	
}



