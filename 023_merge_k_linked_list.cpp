/*
   leetcode algorithm 023:
              merged k sorted linked list 
 
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		ListNode * head=NULL;
		ListNode * last=head;

		while(lists.size()>0){
			ListNode * node=lists[0];
			int target_node_index=0;
			for(int index=1;index<lists.size();index++)
				if(lists[index]){
                    if(!node) {
						node=lists[index];
						target_node_index=index;						
					}else{
                        if(lists[index]->val<node->val){
						  node=lists[index];
						  target_node_index=index;						
						}
					}
				}

			if(!node)  break;

			if(!last){
				head=node;
				last=head;				
			}else{
                last->next=node;
				last=node;				
			}
			lists[target_node_index]=lists[target_node_index]->next;						
		}
		return head;
    }

	/* merge k linked list */
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
		ListNode * head=NULL;
		for(int index=0;index<lists.size();index++){
		  if(lists[index]==NULL)  continue;
		  ListNode * line_node=lists[index];
		  if(!head) {
              ListNode * node =new ListNode(line_node->val);
  			  head=node;			  			  
			  line_node=line_node->next;
		  }

		  while(line_node!=NULL) {

			  if(line_node->val<head->val){
				  ListNode * node=new ListNode(line_node->val);
				  node->next=head;
				  head=node;				 
			  }
			  else{
  			     ListNode * p=head;
			     while(p->next && p->next->val<line_node->val)
				      p=p->next;
			     if(p->next==NULL){
				      ListNode * node=new ListNode(line_node->val);
				      p->next=node;
			     }else{
                      ListNode * node=new ListNode(line_node->val);
				      node->next=p->next;
				      p->next=node;
			    }
			 }
		     line_node=line_node->next;
		  }
		  
		}
		
	   return head;
	}
	
};
