/*
   leetcode algorithm 011: container with most water 
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
	{
		/* can not pass time limited with O(n*n)  */
		int first_index=0;
		int last_index=height.size()-1;
		int max_container_count=0;
		while(first_index<last_index){
			int container_count;
            if(height[first_index]< height[last_index] ){
                container_count= (last_index-first_index)* height[first_index];
				first_index++;				
			}else{
				container_count=(last_index-first_index)* height[last_index];
				last_index--;
			}
			if(container_count > max_container_count)
				max_container_count=container_count;
		}

		return max_container_count;

    }
};
