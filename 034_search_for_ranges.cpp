/*
  leetcode algorithm:034
                     search ranges for integer from sorted array 

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
	{
		std::vector<int>  vector ={-1,-1};
		int low_index=0;
		int high_index=nums.size()-1;
		while(low_index<=high_index){
			int middle_index= low_index+((high_index-low_index)>>1);
			if(nums[middle_index]<target){
				low_index=middle_index+1;
				continue;
			}
			high_index=middle_index-1;			
		}
		if(nums[low_index]!=target)
		    return vector;
		vector.clear();
		vector.push_back(low_index);
		high_index=nums.size()-1;
		while(low_index<=high_index){
			int middle_index=low_index+((high_index-low_index)>>1);
			if(nums[middle_index]>target ){
				high_index=middle_index-1;
				continue;
			}
			low_index=middle_index+1;
		}
		vector.push_back(high_index);
		return vector;
    }
};



int main(int argc,char **argv)
{
    Solution s;
	std::vector<int>  vector= {2,2};
	std::vector<int> v= s.searchRange( vector, 2);
    fprintf(stdout,"array index=%d,%d\n",v[0],v[1]);
	return 0;
}
