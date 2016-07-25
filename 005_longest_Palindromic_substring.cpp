/*
   leetcode problem:004

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
		std::string longest_palindrome_string;
		int longest_palindrome_length=0;
		for(int index=0;index<s.size();index++){
			std::string palindromic_string=find_longest_Palindromic_string(s,index);
			if(palindromic_string.size()>longest_palindrome_length){
				longest_palindrome_string=palindromic_string;
				longest_palindrome_length=longest_palindrome_string.size();
			}
		}
		return longest_palindrome_string;
    }

	string find_longest_Palindromic_string(string & s,int index)
	{
		int longest_Palindromic_length=0;
        int first_index=index-1;
		int last_index=index+1;
		while(first_index>=0 && last_index<s.size()){
			if(s[first_index]==s[last_index]){
                first_index--;
				last_index++;				
			}else{
                break;
			} 			
		}
        //check if another 	palindrome substring
		int middle_first_index=index;
		int middle_last_index=index+1;
		while(middle_first_index>=0 && middle_last_index< s.size())	{
			if(s[middle_first_index]==s[middle_last_index]){
				middle_first_index--;
				middle_last_index++;
			}else{
				break;				
			}
		}
        if(middle_last_index-middle_first_index-1> last_index-first_index-1){
			int longest_Palindromic_length=middle_last_index-middle_first_index-1;
			return s.substr(middle_first_index+1,middle_last_index-middle_first_index-1);
		}
		else{
			int longest_Palindromic_length=last_index-first_index-1;
			return s.substr(first_index+1,last_index-first_index-1);			
		}		
	}
	
};
