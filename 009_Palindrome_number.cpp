/*
  leetcode algorithm 009:
  
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
	{
		/*  can not alloc extra space for this algorithm problem 009 */
		if(x<0)  return false;
		if(x==0)   return true;
		int target_number=0;
		int ori_x=x;
		while(x!=0){
            int digit=x%10;
			x=x/10;
			target_number=target_number*10+ digit;
		}
	    return  target_number==ori_x? true:false;
    }
};

int main(int argc,char **argv)
{
	int target_number[]={123321,123321,0,1,-123321,-12321,90545};
    Solution s;
	for(int index=0;index<sizeof(target_number)/sizeof(target_number[0]) ;index++){
		fprintf(stdout,"number:%d %s palindrome number \n",target_number[index],
				s.isPalindrome(target_number[index])?"is":"is not" );
	}
	return 0;
}



