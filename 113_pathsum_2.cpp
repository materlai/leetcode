/*
   leetcode algorithm 113:
                        return node from root node to leaf node which sum is the target 
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
    vector< vector<int> > pathSum(TreeNode* root, int sum)
	{
		std::vector< std::vector<int> >  vector;
		if(!root)  return vector;
		std::vector<int> list_v;
		specified_sum_path(vector,sum,list_v,root);
		return vector;
    }

	void specified_sum_path(std::vector< std::vector<int> > &vector,
							int target,std::vector<int>&list_nodes,TreeNode*node)
	{
		if(!node)   return ;
		if(node->left==NULL && node->right==NULL ){
			if(node->val==target){
                /* we find one path */
				list_nodes.push_back(node->val);
				vector.push_back(list_nodes);								
			}
			return ;		
		}
		list_nodes.push_back(node->val);
		specified_sum_path(vector,target-node->val,list_nodes,node->left);
		specified_sum_path(vector,target-node->val,list_nodes, node->right);
		list_nodes.pop_back();
	}	
};
