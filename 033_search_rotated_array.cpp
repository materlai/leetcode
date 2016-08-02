/*
   leetcode algorithm 033:
                         search element in rotated array 
 */


#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target)
    {
		return find(nums,0,nums.siz(),target);
    }
private:
	int find(std::vector<int> &nums,int low_index,int high_index,in target)
    {
		if(low_index>high_index)  return -1;
		int element_index=-1;
		if(nums[low_index]<=nums[high_index]){
		  	/* binary search */
			while(low_index<=high_index){
				int middle_index=low_index+((high_index-low_index)>>1);
				if(nums[middle_index]==target) {element_index= middle_index ; break;}
				else if(nums[middle_index]>target)  high_index=middle_index-1;
				else low_index=middle_index+1;				
			}
			
		}else{
		      	/* this is a rotated sorted array   */
			int middle_index=low_index+((high_index-low_index)>>1);
			if(nums[middle_index]==target)  element_index=middle_index;
			else{
				element_index= find(nums,low_index,middle_index-1,target);
				element_index=element_index==-1? find(nums,middle_index+1,high_index,target);
			}
		}
	    return element_index;			
	}

	int findMin(vector<int> &num)
	{
		int low_index=0;
		int high_index=num.size()-1;
		while(num[low_index]>num[high_index]){
			int middle_index=low_index +((high_index-low_index)>>1);
			if(num[middle_index]>=num[low_index])
				low_index=middle_index+1;
			else 
			    high_index=middle_index;			
		}
		return num[low_index];
    }
};
