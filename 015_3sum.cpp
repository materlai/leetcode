/*
  leetcode algorithm 015:
                        3sum 
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
    vector< vector<int> > threeSum(vector<int>& nums)
	{
        vector< vector<int> >  vector;
		sort(nums.begin(),nums.end());
        /* check the sum of number   */
		for(int index=0;index<((int)nums.size())-2;index++) {
			if(index>0 && nums[index]== nums[index-1] )  continue;

            int  target_sum=-nums[index];
			int first_index=index+1;
			int last_index=nums.size()-1;
			while(first_index<last_index){
				if(first_index>index+1  && nums[first_index]==nums[first_index-1])  {
					first_index++;
					continue;
				}
				if(last_index < nums.size() -1 &&  nums[last_index]==nums[last_index+1]) {
					last_index--;
					continue;
				}
                if(nums[first_index] + nums[last_index]< target_sum )
					first_index++;
				else if(nums[first_index]+nums[last_index]>target_sum)
					last_index--;
				else{
					std::vector<int>  v;
					v.push_back(nums[index]);
					v.push_back(nums[first_index]);
					v.push_back(nums[last_index]);
					vector.push_back(v);
					first_index++;
					last_index--;
				}
			}			
		}
	  return vector;
    }
};


int main(int argc,char **argv)
{
	std::vector<int> vector={-1, 0, 1, 2, -1, -4};
	Solution s;
	std::vector<std::vector<int>> v= s.threeSum(vector);
	for(int index=0;index<v.size();index++){
		std::vector<int> & target_vector= v[index];
		fprintf(stdout,"get vector element:");
		for(int j=0;j<target_vector.size();j++)
			fprintf(stdout," %d ",target_vector[j]);
		fprintf(stdout,"\n");
	}

	return 0;
	
}
