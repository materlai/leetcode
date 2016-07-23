/*
  leetcode algorithm 014:
            longest common prefix of string  array 

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.size()<=0)  return "";
		std::string common_string;
		
		for(int index=0;index<strs[0].size();index++){
			for(int j=1;j<strs.size();j++){
				if(strs[j][index]!=strs[0][index])
					return common_string;				
			}
			common_string.push_back(strs[0][index]);				
		}
		return common_string;
    }
};


int main(int argc,char **argv)
{

	Solution s;
	std::vector<std::string>  vector= { "abcabc","abcabd","abcad","abcd" };
	fprintf(stdout,"common string prefix is :%s\n", s.longestCommonPrefix(vector).c_str() );
	return 0;
	
}
