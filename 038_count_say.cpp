/*
   leetcode algorithm : 038
                        count and say
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
    string countAndSay(int n)
	{
		std::string s="1";
		n--;
		char num_buf[32];
		while(n>0){
            n--;
			std::string next_string;
			const char * p= s.c_str();
			while(*p){
                const char * p_next=p+1;
				while(*p_next==*p)  p_next++;
				int num_length=p_next-p;
				snprintf(num_buf,sizeof(num_buf),"%d",num_length);
				std::string sub_string=num_buf;
				next_string.append(sub_string);
				next_string.push_back(*p);
				p=p_next;
			}
			s=next_string;	
		}
		return s;	
    }
};

int main(int argc,char **argv)
{
    Solution s;
	int n=5;
	std::string string=s.countAndSay(n);
	fprintf(stdout,"count and say return :%s\n",string.c_str() );
	return 0;
}
