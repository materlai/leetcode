/*
leetcode algorithm 216:
                     find the combination sum 
  
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum3(int k, int n){
		std::vector<std::vector<int>> vector;
		if(k==0 || n==0)  return vector;
		std::vector<int> nums;
		std::vector<int> vec;
		for(int index=0;index<9;index++)
			nums.push_back(index+1);
		find_all(vector,vec,nums,n,k,0);
		return vector;
    }

	void find_all(std::vector<std::vector<int>> & vector,  std::vector<int> &v,
				  std::vector<int> &nums, int n,int k,int start_index){
		if(v.size()==k) {
			int sum=0;
			for(int index=0;index<v.size();index++)
				sum+= v[index];				
			if(sum==n){
				vector.push_back(v);				
			}
			return ;			
		}
		for(int j=start_index;j<nums.size();j++){
			v.push_back(nums[j]);
			find_all(vector,v,nums,n,k,j+1);
			v.pop_back();
		}			
	}
};
