/*
   leetcode algorithm 129:
                        return sum of all path
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
    int sumNumbers(TreeNode* root)
	{
		if(!root)  return 0;
		int sum=0;
		std::vector<int> vector;
		traversal(vector,root,sum);
		return sum;		
    }

	void traversal(std::vector<int> & vector, TreeNode * node,int &sum)
    {
		if(!node)  return ;
		if(node->left==NULL && node->right==NULL){
			vector.push_back(node->val);
			int sum_vector=0;
			for(int index=0;index<vector.size();index++)
				sum_vector=sum_vector*10+vector[index];
			sum+=sum_vector;
			vector.pop_back();
			return ;						
		}
		vector.push_back(node->val);
		traversal(vector,node->left,sum);
		traversal(vector,node->right,sum);
		vector.pop_back();		
	}
	
};
