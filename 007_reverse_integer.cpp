/*

  leetcode algorithm 007

 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Solution {
public:
    int reverse(int x)  
	{
		const int max_positive_numbers=(0x01UL<<31)-1;
		const int max_negative_numbers=0x01UL<<31;
		int digits[32];
		int digits_numbers=0;
		while(x!=0){
            int digit=x%10;
			digits[digits_numbers++]=digit;
			x=x/10;			
		}
		//start to put digits together
		int target_numbers=0;
		for(int index=0;index<digits_numbers;index++){
			if(target_numbers>0 && (target_numbers>max_positive_numbers/10 ||
									 target_numbers==max_positive_numbers/10 && digits[index]>max_positive_numbers%10 ))
			{
				/*overflow */
				return 0;				
			}
			else if(target_numbers<0 && ( target_numbers< max_negative_numbers/10 ||  (target_numbers==max_negative_numbers/10
											   && digits[index]< max_negative_numbers%10 )) ){
				/*overflow */
				return 0;
			}				
		   	target_numbers=target_numbers*10 + digits[index];
		}
		return target_numbers;
    }
};


int main(int argc,char ** argv)
{
    int reverse_number1=1534236469;
	int reverse_number2=-214748364;
	Solution s;
	fprintf(stdout,"reverse number of %d is %d\n",reverse_number1,s.reverse(reverse_number1));
	fprintf(stdout,"reverse number of %d is %d\n",reverse_number2,s.reverse(reverse_number2));
    return 0;
}
