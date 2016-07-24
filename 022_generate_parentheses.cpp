/*
    leetcode algorithm 022:
	                      generate parentheses for n 

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n)
	{
		std::vector<std::string>  vector;
		std::string s;
		allParenthesis(s,vector,0,0,n);
		return vector;
    }

	void allParenthesis(std::string & s,std::vector<std::string> &vector,
						int l,int r,int n)
	{
		if(r==n){
            vector.push_back(s);			
		}
		else if(l==n){
            s.push_back(')');
			allParenthesis(s,vector,l,r+1,n);
			s.pop_back();
		}
		else{
            if(l>r) {
				s.push_back(')');
				allParenthesis(s,vector,l,r+1,n);
				s.pop_back();
			}
			s.push_back('(');
			allParenthesis(s,vector,l+1,r,n);
			s.pop_back();
		}
	}
};


int main(int argc,char **argv)
{
	Solution s;
	int n=3;
	std::vector< std::string > vector= s.generateParenthesis(n);
	for(int index=0;index<vector.size();index++)
		fprintf(stdout,"match parenthesis is :%s\n",vector[index].c_str());
	return 0;
	
}
