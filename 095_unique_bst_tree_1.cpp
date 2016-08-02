/*
   leetcode algorithm 095:
                        unique binary search tree 
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
	{
		return  generate(0,n-1); 
    }

	vector<TreeNode*> generate(int low,int high)
	{
		std::vector<TreeNode*> v;
		if(low>high) {
			v.push_back(NULL);
			return v;			
		}
		
		for(int index=low;index<=high;index++){
			std::vector<TreeNode*> l_v=generate(low,index-1);
			std::vector<TreeNode *> r_v=generate(index+1,high);
			TreeNode * node =new TreeNode(index+1);
			for(int i=0;i<l_v.size();i++)
				for(int j=0;j<r_v.size();j++){
					node->left= l_v[i];
					node->right=r_v[j];
					v.push_back(node);
				}
		}
		return v;
	}
};
