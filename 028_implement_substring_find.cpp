
/*
  leetcode algorithm 028:
                          implement strstr();
						  notes:  KMP  

 */

class Solution {
public:
    int strStr(string haystack, string needle)
	{
	   /* KMP algorithm will be use later  */
		for(int index=0;index<=(int)haystack.size()-(int)needle.size();index++){
            int j=0;
			while(j<needle.size() && haystack[index+j]==needle[j])
				j++;
			if(j==needle.size())   return index;			
		}
		return -1;
    }
};


