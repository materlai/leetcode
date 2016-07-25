/*
  leetcode problem 004

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		std::vector<int> vector;
		int index_1=0,index_2=0;
		while(index_1 < nums1.size() && index_2 < nums2.size()){
			if(nums1[index_1]<nums2[index_2]){
				vector.push_back(nums1[index_1++]);
			}
			else{
				vector.push_back(nums2[index_2++]);
			}			
		}
		while(index_1 < nums1.size())
			vector.push_back(nums1[index_1++]);
		while(index_2 < nums2.size())
			vector.push_back(nums2[index_2++]);

		if(vector.size()%2){
			return  (double)vector[vector.size()/2];			
		}
		else  return ((double)vector[vector.size()/2-1]+vector[vector.size()/2])/2;        
    }
};


