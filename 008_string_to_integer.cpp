/*
   leetcode algorithm:008

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str)
	{
		/*  atoi() */
		int index=0;
		int negative_number=0;
		int target_number=0;
		while(isspace(str[index]) && index< str.size())
			index++;
		if(str[index]=='-' || str[index]=='+'){
			if(str[index]=='-')  negative_number=1;
			index++;
		}
        while(index< str.size()){
			if(str[index]>='0' && str[index]<='9') {
				/*check it overflow */
				const int max_positive_number= (0x01UL<<31)-1;
				const int max_negative_number= 0x01UL<<31;
				if( !negative_number && (target_number>max_positive_number/10 || (target_number==max_positive_number/10 &&
																				  str[index]-'0'>max_positive_number%10  ) ) ){
				    target_number = max_positive_number;
					break;
				}
				else if( negative_number && ( target_number>max_positive_number/10 ||  (target_number==max_positive_number/10 &&
																str[index]-'0'>(max_positive_number%10+1)  ) ) ){

					target_number= max_negative_number;
					negative_number=0;
					break;
				}
				target_number=target_number * 10 + str[index]-'0';
				index++;
			}
			else{
				
				break;
			}
		}
        if(negative_number)  target_number=-target_number;
		return target_number;
    }
};



int main(int argc,char ** argv)
{

	std::string target_string="1";
	Solution s;
	fprintf(stdout,"myatoi(\"%s\")  = %d\n",target_string.c_str() ,s.myAtoi(target_string));
	return 0;
}
