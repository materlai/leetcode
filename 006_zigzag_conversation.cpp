/*
   leetcode algorithm:006

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
	{
		if(numRows==1)   return s;
		int zigzag_count=2*numRows-2;
		std::string zigzag_string;
		for(int index=0;index<numRows;index++){
            for(int j=index;j<s.size();j+=zigzag_count){
				zigzag_string.push_back(s[j]);
				if(index!=0 && index !=numRows-1){
					int next_index= j+ zigzag_count-2*index;
					if(next_index< s.size())
						zigzag_string.push_back(s[next_index]); 
				}
			}
			
		}
	   return zigzag_string;
    }
};



int main(int argc,char **argv)
{
	std::string zigzag_string="PAYPALISHIRING";
	Solution s;
	fprintf(stdout,"zigzag conversion result with nRows=3 is :%s\n",s.convert(zigzag_string,3).c_str());
	return 0;
}
