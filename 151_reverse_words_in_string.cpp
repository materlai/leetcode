/*
   leetcode algorithm 151:
                        reverse words in a string
 */


#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s)
	{
        reverse_string(s.c_str(),s_c_str()+s.size()-1);
		//now reverse every words now
		char *p=s.c_str();
		char * next=NULL;
		while(*p){
			next=p;
			while(*next &&  *next!=' ') next++;
			if(!*next)   break;
			reverse_string(p,next-1);
			p=next;
			while(*p && *p==' ') p++;			
		}
		if(*p)  reverse_string(p,next-1);				
    }

	void reverse_string(char *p_start,char *p_end)
	{
		while(p_start<p_end){
			char c=*p_start;
			*p_start=*p_end;
			*p_end=c;
			p_start++;
			p_end--;			
		}
	}
};

