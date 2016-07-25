/*
  leetcode algorithm 015:
                        3sum closest
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {  
        sort(nums.begin(),nums.end());
		int target_sum=nums[0]+nums[1]+nums[2];
		for(int index=0;index<nums.size();index++){
			int first_index=index+1;
			int last_index=nums.size()-1;
			while(first_index < last_index){
				int sum= nums[index]+ nums[first_index]+nums[last_index];
				if(std::abs(sum-target)<std::abs(target_sum-target)){
					target_sum=sum;					
				}
				if(sum < target )
					first_index++;
				else if(sum>target ){
                    last_index--;			  		
				}else{
					/*exactly match */
                    return sum;					
				}				
			}
		}
	return target_sum;	
    }
};
