/*

  leetcode algorithm 012:  integer to roman number  

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num)
	{
		std::string roman_buffer[]={"I","IV","V", "IX", "X", "XL", "L",  "XC",  "C", "CD","D", "CM", "M"  };
		int roman_integer[]=       { 1,  4,   5,   9,   10,  40,   50,   90,    100,  400, 500, 900, 1000};

		std::string convert_roman_string;
		while(num>0) {
			int index=sizeof(roman_integer)/sizeof(roman_integer[0])-1;
			while(roman_integer[index]> num )
				index--;
			
			convert_roman_string.append(roman_buffer[index]);
			num-=roman_integer[index];
		}
		return convert_roman_string;
    }
};


int main(int argc,char ** argv)
{
	Solution s;
   int target_num[]={ 99,3999,399,456,676,88};
   for(int index=0;index< sizeof(target_num)/sizeof(target_num[0]);index++)
	   fprintf(stdout,"number :%d is converted to roman string:%s\n",target_num[index],s.intToRoman(target_num[index]).c_str());

   return 0;
}

