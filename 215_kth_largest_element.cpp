/*
 leetcode algorithm 215:
     find the kth  largest element from array 

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <stack>

using namespace std;



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size()-k+1;
        return find(nums,0,nums.size()-1,n);
    }
    
    int find(std::vector<int> & vector,int low_index,int high_index,int n){
        
        int count=partition(vector,low_index,high_index);
        if(count==n) {
               return   vector[low_index+count-1]; 
        }else if(count>n){
             return  find(vector,low_index,low_index+count-2,n); 
        }else  return find(vector,low_index+count,high_index,n-count);
    }
    
    int partition(std::vector<int> & vector,int low_index,int high_index)
    {
        int buf=vector[high_index];
        int last_index=low_index;
        for(int index=low_index;index<high_index;index++){
             if(vector[index]<buf){
                   if(index!=last_index)
                        swap(vector[index],vector[last_index]);
				   last_index++;                    
             }else{
				 
             }
        }
        swap(vector[last_index],vector[high_index]);
        return last_index-low_index+1;
    }
    
    void swap(int & a, int &b){
        int c=a;
        a=b;
        b=c;
    }
};


int main(int argc,char ** argv)
{
	std::vector<int>  ele_vector={-1,2,0};
	Solution s;
	int element=s.findKthLargest(ele_vector,2);
	fprintf(stdout,"%d\n",element);
	return 0;	
}
