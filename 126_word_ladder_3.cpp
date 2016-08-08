/*
leetcode algorithm 126:
                      find the word ladder II
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution  {
public:

    struct ladder_node {
      std::string word;
      int len;
      int last_index;
      ladder_node(std::string str,int length,int index):word(str),len(length),last_index(index){}
    };


    vector< vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList){
		std::vector<std::vector<std::string>> vector;
		wordList.insert(endWord);
		std::vector<ladder_node> nodes;
		nodes.push_back(ladder_node(beginWord,1,-1));
		std::vector<std::string> layer_words;
		int layer_nums;
		int index=0;
		int min_path_len=0;
		while(index<nodes.size()){
			ladder_node node=nodes[index];
			if(min_path_len!=0 && node.len> min_path_len)  break;
			if(layer_nums<node.len){
				for(int j=0;j<layer_words.size();j++)
					wordList.erase(layer_words[j]);
			    layer_words.clear();
				layer_nums=node.len;
			}
			if(node.word==endWord){
				std::vector<std::string> v;
				v.push_back(endWord);
				int last_index=node.last_index;
			    while(last_index!=-1){
					ladder_node  next_node=nodes[last_index];
					v.push_back(next_node.word);
					last_index=next_node.last_index;					
				}
				reverse(v.begin(),v.end());
				min_path_len=v.size();
				vector.push_back(v);
			}else{
				std::string curr_string =node.word;
				for(int j=0;j<curr_string.size();j++)
					for(int num=0;num<26;num++){
						if(curr_string[j]==num+'a')  continue;
						char c=curr_string[j];
						curr_string[j]='a'+num;
						if(wordList.count(curr_string)){						   
							nodes.push_back(ladder_node(curr_string,node.len+1,index));
							layer_words.push_back(curr_string);							
						}
						curr_string[j]=c;
					}							
			}
			index++;
		}
		return vector;		
	}
    
};


int main(int argc,char ** argv)
{
	std::unordered_set<std::string>  wordLists;
	std::vector<std::string> v= {"hot","dot","dog","lot","log"};
	for(int index=0;index<v.size();index++)
		wordLists.insert(v[index]);
	Solution s;
	std::vector<std::vector<string>> vector = s.findLadders("hit","cog",wordLists);
	for(int index=0;index<vector.size();index++){
		fprintf(stdout,"find word ladder:\n");
		std::vector<std::string> &vec=vector[index];
		for(int j=0;j<vec.size();j++){
			fprintf(stdout,"%s %s ",j==0?"":"-->",vec[j].c_str());			
		}
		fprintf(stdout,"\n");				
	}
	return 0;	
}
