/*
  leetcode algorithm 173:
                        construct binary search tree  iterator
						
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
         head=convert_bst_linkedlist(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      if(!head )  return false;
      return true;
    }

    /** @return the next smallest number */
    int next() {
       int val=head->val;
       head=head->right;
       return val;
    }
private:
    TreeNode * convert_bst_linkedlist(TreeNode * root)
    {
         if(!root)  return NULL;
         TreeNode * last=NULL;
         convert(root,last);
         while(last->left) last=last->left;
         return last;
    } 
    
    void convert(TreeNode * node, TreeNode * &last)
    {
		if(!node){
			if(last) last->right=NULL;
			return ;			
		}
		convert(node->left,last);
		node->left=last;
		if(last)  last->right=node;
		last=node;
		convert(node->right,last);
    }
    
private:
    TreeNode* head;
};


int main(int argc,char **argv)
{
	//construct a binary search tree
    TreeNode * node=new TreeNode(1);
	node->right=new TreeNode(2);

	BSTIterator it= BSTIterator(node);
	while(it.hasNext()) {
		fprintf(stdout," %d ",it.next());		
	}
	fprintf(stdout,"\n");

	return 0;

	
	
}
