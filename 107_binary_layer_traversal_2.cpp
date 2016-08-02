/*
  leetcode algorithm 107:
                        binary tree layer traversal II
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
    vector< vector<int> > levelOrderBottom(TreeNode* root)
	{
		std::vector< std::vector<int> >  vector;
		if(!root)  return vector;
		std::vector<TreeNode*> v;
		std::vector<int> layer_index;
		v.push_back(root);
		int index=0;
		while(index<v.size()){
			layer_index.push_back(index);
			int count=v.size();
			while(index<count){
                if(v[index]->left)   v.push_back(v[index]->left);
				if(v[index]->right)  v.push_back(v[index]->right);
				index++;
			}			
		}

		//start to collect node
	    index=layer_index.size()-1;
		while(index>=0){
			std::vector<int> layer_v;
            int start_index=layer_index[index];
			int end_index= (index==layer_index.size()-1)?v.size()-1:layer_index[index+1]-1;
			while(start_index<=end_index){
				layer_v.push_back(v[start_index]->val);
				start_index++;
			}		
			vector.push_back(layer_v);
			index--
		}
	    return vector;
    }
};
