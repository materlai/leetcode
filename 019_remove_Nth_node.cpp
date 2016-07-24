/*
  leetcode algorithm 019:
                      remove Nth node from the end of linked list  
 */


#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
	    ListNode * last_node=head;
		while(n>0){
            last_node=last_node->next;
			n--;
		}
		ListNode * node=head;
		while(last_node){
			node=node->next;
			last_node=last_node->next;			
		}
		//now node it the Nth node from the end of linked list
		if(node->next){
			node->val=node->next->val;
			node->next=node->next->next;
			return head;
		}else{
			if(node==head) {
                return NULL;				
			}
			else{
                ListNode * p=head;
				while(p->next!=node)
					p=p->next;
				p->next=NULL;
				return head;
			}			
		}		
    }
};
