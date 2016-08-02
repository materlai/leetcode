/*
  leetcode  algorithm:
                    find the first missing integer in unsorted array 
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
		for(int index=0;index<nums.size();index++){
			if(nums[index]!=index+1  && nums[index]>=1 && nums[index]<=n && nums[nums[index]-1]!=nums[index] )
				swap(nums[nums[index]-1],nums[index]);
			else index++;
		}
        for(int index=0;index<nums.size();index++)
			if(nums[index]!=index+1)   return index+1;
		return nums.size()+1;		
    }
	void swap(int &a,int &b)
	{
		int c=a;
		a=b;
		b=c;
	}
};
