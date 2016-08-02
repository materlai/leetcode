/*
   leetcode algorithm : 032
                       find longest valid parentheses 
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
	{
		int longest_length=0;
		if(s.size()<=0)  return longest_length;
		std::stack<const char*>stack;
		const char * p=s.c_str();
		while(*p){
			if(*p=='(')
				stack.push(p);
			else{
				if(stack.size()>0 && *stack.top()=='('){
					stack.pop();
                    longest_length=std::max(longest_length, (int)(stack.size()==0?p-s.c_str()+1:p-stack.top()) );
				}else{
					stack.push(p);					
				}				
			}
			p++;
		}
		return longest_length;
    }
};
