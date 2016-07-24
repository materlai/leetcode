/*
  leetcode algorithm :029
                    divide two  numbers

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <limits>
using namespace std;
					
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)  return  std::numeric_limits<int>::max();
		if(dividend==0)  return 0;
		long long div_sum=0;
		long long  div_a= dividend >0? dividend:-(long long)dividend ;
		long long div_b=  divisor>0? divisor: -(long long) divisor;

		int move_nbit=31;
		while(move_nbit>=0){
			if( div_a >= div_b<<move_nbit  ){
				div_a-= div_b <<move_nbit;
				div_sum+=0x01UL << move_nbit; 				
			}
			move_nbit--;			
		}
		if( (dividend >0 && divisor<0) || (dividend<0 && divisor>0) )
			div_sum=-div_sum;
		if(div_sum> std::numeric_limits<int>::max())    return  std::numeric_limits<int>::max();
		return (int)div_sum;
    }
};


int main(int argc,char **argv)
{
	Solution s;
	int dividend= std::numeric_limits<int>::min();
	int divisor=-1;
	fprintf(stdout," %d divide %d = %d\n",dividend,divisor,s.divide(dividend,divisor));
	return 0;

	
}
