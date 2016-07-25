/*
   leetcode algorithm 026:
                         remove duplicated elements in sorted array 

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
	{
		if(nums.size()<=1)   return nums.size();
		int last_index=0;
		for(int index=last_index+1;index<num.size();index++){
			if(nums[index]==nums[last_index])  continue;
			last_index++;
			nums[last_index]=nums[index];
		}
		return last_index+1;		
    }
};
