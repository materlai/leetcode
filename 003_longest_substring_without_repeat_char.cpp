/*
   leetcode problem003

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string &&s)
	{
		int longest_substring_length=0;
		int string_index[256];
		for(int index=0;index<sizeof(string_index)/sizeof(string_index[0]);index++)
			string_index[index]=-1;

		int last_repeat_index=-1;	  
		for(int index=0;index<s.size();index++){
			int last_index=string_index[s[index]];
			if(last_index!=-1){
				last_repeat_index=std::max(last_repeat_index,last_index);				                 				
			}
			string_index[s[index]]=index;
			longest_substring_length=std::max(longest_substring_length, index-last_repeat_index);			
		}
		return longest_substring_length;
    }
};

int main(int argc,char **argv)
{

	Solution s;
	fprintf(stdout,"longest substring without repeat char is %d\n", s.lengthOfLongestSubstring("abcabcbb"));
	fprintf(stdout,"longest substring without repeat char is %d\n", s.lengthOfLongestSubstring("bbbbbb"));
    return 0;   
	
}
