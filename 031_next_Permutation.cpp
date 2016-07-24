/*
  leetcode algorithms 031:
                          the next Permutation
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
	{
		int index=nums.size()-1;
		while(index>=1 && nums[index-1]>=nums[index] )
			index--;
		if(index==0){
			sort(nums.begin(),nums.end());
			return ;			
		}
		int next_num=nums[index];
		int next_index=index;
		for(int j=index+1;j<nums.size();j++)
			if(nums[j]>nums[index-1] && nums[j]<next_num ){
                next_num=nums[j];
				next_index=j;
			}
		
		//swap the nums[index-1] and nums[next_index];
		swap(nums[index-1],nums[next_index]);
		sort(nums.begin()+index,nums.end());
		
    }

	void swap(int & a,int &b)
	{
        int c=a;
		a=b;
		b=c;
	}
};


int main(int argc,char ** argv)
{
	Solution s;
	std::vector<int>vector = {1,2,3,45,9};
	s.nextPermutation(vector);
	fprintf(stdout,"next Permutation is :");
	for(int index=0;index<vector.size();index++)
		fprintf(stdout,"%d\n",vector[index]);
	fprintf(stdout,"\n");
	return 0;
}
