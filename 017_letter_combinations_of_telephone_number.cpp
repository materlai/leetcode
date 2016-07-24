/*
  leetcode algorithm 015:
                        3sum closest
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
	{
		if(digits.size()==0)   return std::vector<std::string>();
		vector<string> letter_vector= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<std::string>   vector;
		for(int index=0;index<digits.size();index++)
			vector.push_back(letter_vector[digits[index]-'0'] );

		std::vector<std::string> combinations_string;
		std::string s;
		combinations(vector,0,combinations_string,s);

		return combinations_string;
    }

	void combinations(std::vector<std::string> & vector, int start_index,
					  std::vector<std::string>& combination_vector, std::string &s ){
	   if(start_index >= vector.size()){
		   combination_vector.push_back(s);
		   return ;		   
	   }
	   std::string letter_string=vector[start_index];
	   for(int index=0;index<letter_string.size();index++){
		   s.push_back(letter_string[index]);
		   combinations(vector,start_index+1, combination_vector,s);
		   s.pop_back();		   
	   }			
    }
};


int main(int argc,char ** argv)
{
	Solution s;
	std::string telephone_digits="23";
	std::vector<std::string>  combination_string= s.letterCombinations(telephone_digits);
	for(int index=0;index<combination_string.size();index++){
		fprintf(stdout,"match telephone string :%s\n", combination_string[index].c_str())	;	
	}
	return 0;
}
