/*
leetcode algorithm 347:
                    find the k frequent element from array 

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int>  vector;
        if(nums.size()<=0)  return vector;;
       
        for(int index=0;index<nums.size();index++){ 
            if(map.find(nums[index])==map.end()){
                map[nums[index]]=1;
            }else{
                map[nums[index]]++;
            }
        }
		
		std::vector<int>  freq_vector;
		std::map<int,int>::iterator it=map.begin();
		int index=0;
		while(index<k && it!=map.end()){
			freq_vector.push_back(it->first);
			it++;
			index++;
		}
		//build min heap
		build_min_heap(freq_vector);
		while(it!=map.end()){
			if(it->second> map[freq_vector[0]]){
				freq_vector[0]=it->first;
				adajust(freq_vector,0);
			}
			it++;
		}
		vector=freq_vector;
		return vector;
    }

	void build_min_heap(std::vector<int> & heap){
		int index=heap.size()/2-1;
		while(index>=0){
			adajust(heap,index);
			index--;
		}		
	}
	void adajust(std::vector<int> & vector,int k)
	{
		if(k>=vector.size())  return ;
		int left_index=2*k+1;
		int right_index=2*k+2;
		int min=k;
		if(left_index<vector.size() && map[vector[left_index]]< map[vector[min]] )    min=left_index;
		if(right_index< vector.size() &&  map[vector[right_index]]<map[vector[min]] )  min=right_index;
		if(min!=k){
            int c=vector[k];
			vector[k]=vector[min];
			vector[min]=c;
			adajust(vector,min);			
		}		
	}

	

private:
    std::map<int,int>  map;
};

int main(int argc,char ** argv)
{
	std::vector<int> vector={4,1,-1,2,-1,2,3};
	Solution s;
	std::vector<int> v=s.topKFrequent(vector,2);
    for(int index=0;index<v.size();index++)
		fprintf(stdout," %d ",v[index]);
	return 0;
}
