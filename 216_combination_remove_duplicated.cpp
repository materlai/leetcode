/*
leetcode algorithm 216
                   pick all unique  combinations from nums which may contain duplicated element  
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:	
	std::vector<std::vector<int>> combination_remove_duplicated(std::vector<int> nums,
																 int k){
		std::vector<std::vector<int>> vector;
		if(nums.size()<=0 || k<=0)   return vector;
		sort(nums.begin(),nums.end());
		std::vector<int> vec;
		find_all(vector,vec,nums,k,0);
		return vector;
	}

	void find_all(std::vector<std::vector<int>> & vector,std::vector<int> & vec,
				  std::vector<int> &nums,int k,int start_index){
		if(vec.size()==k){
			vector.push_back(vec);
			return ;			
		}
		for(int j=start_index;j<nums.size();j++){
			if(contain_element(vec,nums[j]))  continue;
			vec.push_back(nums[j]);
			find_all(vector,vec,nums,k,j+1);
			vec.pop_back();
			while(j<nums.size()-1 && nums[j]==nums[j+1])  j++;
		}
	   return ;	
	}

	bool contain_element(std::vector<int> & vec,int target){
		for(int index=0;index<vec.size();index++)
			if(vec[index]==target)   return true;
		return false;	
		
	}

};


int main(int argc,char ** argv){

	std::vector<int> vec={1,1,9,4,7,0,4,3,9,0};
	Solution s;
	std::vector< std::vector<int> > vector=s.combination_remove_duplicated(vec,4);
	for(int index=0;index<vector.size();index++){
		std::vector<int>  v=vector[index];
		fprintf(stdout,"vector: ");
		for(int j=0;j<v.size();j++)
			fprintf(stdout," %d ",v[j]);
		fprintf(stdout,"\n");			
	}
	return 0;	
}
