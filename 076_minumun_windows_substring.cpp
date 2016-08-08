/*
leetcode algorithm 076:
                  find the minumum window which will contain the substring 
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t){
		if(s.size()<=0 || t.size()<=0)  return std::string();
		std::unordered_map<char,int> map;
		for(int index=0;index<t.size();index++){
			if(map.find(t[index])==map.end())
			   map[t[index]]=1;
			else
			   map[t[index]]++;
		}
		
		int count=0;
		int min_length=INT_MAX;
		int min_length_start_index=-1;
		int min_length_end_index=-1;

		std::unordered_map<char,int> sub_map;
		int low_index=0;
		int high_index=low_index;
		while(low_index<s.size()) {
			while(count<t.size() && high_index<s.size()){
				if(map.find(s[high_index])==map.end()){
					high_index++;
					continue;
				}
				if(sub_map.find(s[high_index])==sub_map.end())
					sub_map[s[high_index]]=1;
				else sub_map[s[high_index]]++;
				if(sub_map[s[high_index]]<=map[s[high_index]])
					count++;
				high_index++;
			}
			if(count==t.size()){
				/*we find the substring */
				if(high_index-low_index<min_length){
					min_length=high_index-low_index;
					min_length_start_index=low_index;
					min_length_end_index=high_index;
				}
				if(map.find(s[low_index])!=map.end()){
					sub_map[s[low_index]]--;
					if(sub_map[s[low_index]]<map[s[low_index]])
						count--;
				}
				low_index++;				
			}else{
				/*we reach the end of string */
				if(low_index==0 && high_index==s.size())   return std::string();
				break;				
			}
		}    	
		return s.substr(min_length_start_index,min_length_end_index-min_length_start_index);	
    }
};

