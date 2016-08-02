/*
   leetcode algorithm 030:
                          Substring with Concatenation of All Words

 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
	{
		if(words.size()<=0 || words[0].size()<=0)  return std::vector<int>();
		std::vector<int> v;
		std::map<std::string,int>map;
		for(int index=0;index<words.size();index++){
			if(map.find(words[index])==map.end())
				map[words[index]]=1;
			else map[words[index]]++;			
		}

		int wlen=words[0].size();
		for(int offset=0;offset<wlen;offset++){
			int match_count=0;
			std::map<std::string,int> match_map;
			for(int index=offset;index+wlen<=s.size();index+=wlen){
			    std:string 	word= s.substr(index,wlen);
				if(map.find(word)==map.end()){
					match_map.clear();
					match_count=0;
				}else{
					match_count++;
					if(match_map.find(word)==match_map.end())
						match_map[word]=1;
					else match_map[word]++;
					
					/*we have overflow a word */
					while(match_map[word]>map[word]){
						std::string last_word= s.substr(index-(match_count-1)*wlen,wlen);
						match_map[last_word]--;
						match_count--;						
					}
				}
				if(match_count>=words.size())
					v.push_back(index-(match_count-1)*wlen);
			}
		}
		return v;    
    }
};

int main(int argc,char ** argv)
{
	Solution s;
	std::string str="barfoothefoobarman";
	std::vector<std::string> words= {"bar","foo"};

	std::vector<int>v=s.findSubstring(str,words);
	fprintf(stdout,"match index:");
	for(int index=0;index<v.size();index++)
		fprintf(stdout," %d ",v[index]);
	fprintf(stdout,"\n");
	return 0;
}

