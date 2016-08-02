/*
   leetcode algorithm 106:
                        construct binary tree from inorder and postorder traversal
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

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		return createTree(inorder,0,inorder.size()-1,
						  postorder,0,postorder.size()-1);        
    }

	TreeNode * createTree(std::vector<int> & inorder, int in_low_index, int in_high_index,
						  std::vector<int> & postorder,int post_low_index,int post_high_index )
	{
        if(in_low_index>in_high_index)   return NULL;
		TreeNode * node=new TreeNode(postorder[post_high_index]);

		//find the element from inorder
		int index=in_low_index;
		while(inorder[index]!=postorder[post_high_index])   index++;
		int left_tree_count=index-in_low_index;
		int right_tree_count=in_high_index-index;

		if(left_tree_count>0){
			node->left=createTree(inorder,in_low_index,index-1,
								  postorder,post_low_index,post_low_index+left_tree_count-1);			
		}
		if(right_tree_count>0){
			node->right=createTree(inorder,index+1,in_high_index,
								   postorder,post_low_index+left_tree_count,post_high_index-1);
		}
		return node;
	}
	
};
