/*
   leetcode algorithm 151:
                         find minimum from rotated array(may contain duplicated element) 
 */


#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums)
    {
		int low_index=0;
		int high_index=nums.size()-1;
		while(low_index<high_index && nums[low_index]>=nums[high_index] ){
			int  middle_index= low_index +((high_index-low_index)>>1);
			if(nums[middle_index]>nums[low_index])  low_index=middle_index+1;
			else if(nums[middle_index]<nums[high_index])  high_index=middle_index;
			else{
				low_index++;
			}			
		}
		return nums[low_index];
    }
};
