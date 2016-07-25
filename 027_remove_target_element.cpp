/*
    leetcode algorithm 027:
	                       remove target element from array 
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
using namespace std ;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
	{
		int unique_index=0;
        for(int index=0;index<nums.size();index++){
			if(nums[index]==val)   continue;
			nums[unique_index]=nums[index];
			unique_index++;
		}
		return unique_index;
    }
};
