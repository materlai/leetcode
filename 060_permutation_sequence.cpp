/*
leetcode algorithm  060 :
                       find kth sequence from permutation 
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string getPermutation(int n, int k){
		std::vector<std::string> vector;
		std::vector<int> nums(n);
		for(int index=0;index<n;index++)
			nums[index]=index+1;
		find_all(vector,nums,0,nums.size());
		return vector[k-1];
    }
    void find_all(std::vector<string> & vector,std::vector<int> & nums,
				  int start_index,int count){
		if(start_index==count){
			std::string s;
			int index=0;
			while(index<nums.size()){
				s.push_back(nums[index]+'0');
				index++;
			}
			vector.push_back(s);
			return ;			
		}
		for(int index=start_index;index<count;index++){
			//move nums[index] to nums[start_index];
			int buf=nums[index];
			int j=index-1;
			while(j>=start_index ) {
				  nums[j+1]=nums[j];
				  j--;				
			}
			nums[j+1]=buf;
			find_all(vector,nums,start_index+1,count);
			//move back
			buf=nums[start_index];
			j=start_index+1;
			while(j<=index){
				nums[j-1]=nums[j];
				j++;				
			}
			nums[j-1]=buf;
		}
		return ;
	}	
};
