/*
   leetcode algorithm 023:
                  reverse linked list nodes with k-group 
 
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
    ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode * p=head;
		head=NULL;
		ListNode * group_last=head;
		while(p){
			//find the kth node from p
			ListNode * node=p;
			ListNode * back_node=node;
			int index=k;
			while(index>0 && p){
				p=p->next;
				index--;
			}
			if(index>0)  {    // do not reach k elements for group
				p=node;
				break;				
			} 
			//reverse linked node from node to p
		    ListNode * last=NULL;
			while(node!=p){
				ListNode * next=node->next;
				node->next=last;
				last=node;
				node=next;
			}
			if(!group_last){
				head=last;
				group_last=back_node;
			}else{
                group_last->next=last;
				group_last=back_node;
			}
		}
		//append the left element to linked list
		if(!group_last){
			head=p;			
		}else{
            group_last->next=p;			
		}		
		return head;	
    }
};
