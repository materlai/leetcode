/*
     leetcode algorithm 081:
	                        search element in rotated array if duplicated is allowed 
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target)
	{
		return find(nums,target,0,nums.size()-1);
    }
	bool find(std::vector<int> & nums,int target,int low_index,int high_index)
	{
		if(low_index>high_index)  return false;
		else if(low_index==high_index){
			if(nums[low_index]==target)  return true;
			else return false;
		}
		if(nums[low_index]<nums[high_index]) {
                 /* binary search */
				int l=low_index;
				int h=high_index;
				while(l<=h){
                    int m=l+((h-l)>>1);
					if(nums[m]<target)  l=m+1;
					else if(nums[m]>target)  h=m-1;
					else  return true;
				}
				return false;				
	   }else{
			int middle_index= low_index+((high_index-low_index)>>1);
			 if(nums[middle_index]==target)   return true;
			 bool find_element=	find(nums,target,low_index,middle_index-1);
			 if(!find_element)  find_element= find(nums,target,middle_index+1,high_index);
			 return find_element;
	  }			
   }
};
