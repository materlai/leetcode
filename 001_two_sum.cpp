/*
   leetcode algorithms:001 

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
		std::map<int,int> nums_map;
				
		for(int index=0;index<nums.size();index++){
            int target_num=target-nums[index];
			std::map<int,int>::iterator it=nums_map.find(target_num);
			if(it!=nums_map.end() && it->second!=index){
				std::vector<int>  vector;
				vector.push_back(index);
				vector.push_back(it->second);
				if(vector[0]>vector[1]){
                    int c=vector[0];
					vector[0]=vector[1];
					vector[1]=c;
				}
				return vector;
			}
			nums_map.insert(std::pair<int,int>(nums[index],index));
		}
		return std::vector<int>();    
    }
	 
};


int main(int argc,char ** argv)
{
	int array_nums[]={3,2,4};
	int target=6;
	std::vector<int>  vector(array_nums,array_nums+sizeof(array_nums)/sizeof(array_nums[0]));

	Solution s;
	std::vector<int> target_vector  = s.twoSum(vector,target);
	if(target_vector.size()){
		fprintf(stdout,"target index= %d,%d\n",target_vector[0],target_vector[1]);
		
	}
	else fprintf(stdout,"can not find index forr target!\n");
	
	return 0;
}





