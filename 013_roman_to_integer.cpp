/*
  leetcode algorithm 013:
                         roman to integer 
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
	{
		int roman_integer=0;
		for(int index=0;index<s.size();index++){
			int con_integer=convert_roman_integer(s[index]);
			if(index==s.size()-1){
                roman_integer+=con_integer;
				continue;				
			}else{
				int con_integer_2=convert_roman_integer(s[index+1]);
				if(con_integer_2>con_integer){
					/*  - */
					roman_integer+=(con_integer_2-con_integer);
					index++;					
				}else{
                    roman_integer+=con_integer;					
				}
			}
		}
	    return roman_integer;
    }

	int convert_roman_integer(char roman)
    {
		switch(roman){
		   case 'I':    return 1;
		   case 'V':    return 5;	
		   case 'X':    return 10;	
		   case 'L':    return 50;	
		   case 'C':    return 100;	
		   case 'D':    return 500;	
		   case 'M':    return 1000;	
		}
	}
};

int main(int argc,char ** argv)
{
    Solution s;
	std::string s1="XCIX";
	std::string s2="VIII";
	fprintf(stdout," roman string :%s converted to integer:%d\n",s1.c_str(),s.romanToInt(s1));
	fprintf(stdout," roman string :%s converted to integer:%d\n",s2.c_str(),s.romanToInt(s2));
	return 0;
		
}
