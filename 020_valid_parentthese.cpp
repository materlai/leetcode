/*
  leetcode algorithm 019:
                      remove Nth node from the end of linked list  
 */


#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
#include <vector>

using namespace std;

 
class Solution {
public:
    bool isValid(string s)
	{
		std::vector<char>  vector;
        for(int index=0;index<s.size();index++){
			if(s[index]=='[' ||  s[index]=='{' ||  s[index]=='('){
				vector.push_back(s[index]);
			}
			else{
				if(vector.size()==0 || (s[index] =='(' &&  vector.back()!= ')' )
				   || (s[index]=='[' && vector.back()!=']' ) || (s[index]=='{' && vector.back()!= '}' )  ){
					return 	false;				
				}
				vector.pop_back();
			}			
		}
		return vector.size()==0?true:false;  
    }
};



int main(int argc,char ** argv)
{
	Solution s;
	std::string  match_string="()";
	fprintf(stdout,"%s %s correct patten string\n", match_string.c_str(), s.isValid(match_string)? "is" : "is not" );
	return 0;
}
