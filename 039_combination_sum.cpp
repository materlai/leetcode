/*
   leetcode algorithm:039
                      combination sum 
*/


#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target)
	{
		std::vector< std::vector<int> > vector;
		sort(candidates.begin(),candidates.end());
		int * index= new int [1000];
        memset(index,0,1000*sizeof(int));
        findsum(candidates,target,vector,0,index,0);		
	    delete[] index;
		return vector;        
    }

	void findsum(std::vector<int> & candidates,int target,std::vector< std::vector<int> > &vector,
				 int sum,int *index, int n)
	{
		if(sum>target)  return ;
		if(sum==target) {
			std::vector<int> v;
            for(int j=1;j<=n;j++)
				v.push_back(candidates[index[j]]);
			vector.push_back(v);
			return ;
		}
		for(int i=index[n];i<candidates.size();i++){
			index[n+1]=i;
			findsum(candidates,target,vector,sum+candidates[i],index,n+1);			
		}	       		
	}
	
};
