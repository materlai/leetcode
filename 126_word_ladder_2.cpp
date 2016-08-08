
/*
  leetcode algorithm 126:
                       work ladder II

 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Solution {
public:
	struct graph_edge{
		std::string val;
		int index;
		graph_edge * next;
		graph_edge(const std::string &s):val(s),next(NULL){}
	};
    struct graph_vex{
		std::string val;
		graph_edge* next;
		graph_vex(const std::string &s): val(s),next(NULL){}
		graph_vex(){}
	};
	struct graph{
        graph_vex * vex_set;
		int vex_count;
		graph(int vexs):vex_count(vexs){}
	};	
private:
	bool conn_string(std::string s1,std::string s2)
	{
		int count=0;
		int index=0;
		while(index<s1.size()){
			if(s1[index]!=s2[index]) count++;
			index++;
		}
		return count==1?true:false;		
	}
public:	
	graph * construct_graph(unordered_set<string> &wordList) {
		if(wordList.size()<=0)  return NULL;
		int sizes=wordList.size();
		graph * g=new graph(sizes);
		g->vex_set=new graph_vex[sizes];

		int index=0;
		unordered_set<string>::iterator it=wordList.begin();
		while(it!=wordList.end()){
            g->vex_set[index].val=*it;
			g->vex_set[index].next=NULL;
			it++;
			index++;
		}
		
		it=wordList.begin();
		int start_index=0;
		while(it!=wordList.end()){
			graph_vex * vex=&g->vex_set[start_index];
			unordered_set<string> ::iterator iter=wordList.begin();
			int j=0;
			for(;iter!=wordList.end();j++,iter++){
				if(start_index==j) continue;
				if(conn_string(*it,*iter)){
                    graph_edge * edge=new graph_edge(*iter);
					edge->index=j;
					edge->next=vex->next;
					vex->next=edge;
				}				
			}
			it++;
			start_index++;
		}
		return g;
	}

	void dump_graph(graph*g)
	{
		if(!g)   return ;
		int index=0;
		while(index<g->vex_count){
			graph_vex * vex=&g->vex_set[index];
			fprintf(stdout,"vertex:%s",vex->val.c_str());
			graph_edge * edge=vex->next;
			while(edge!=NULL){
				fprintf(stdout," --> %s",edge->val.c_str());
				edge=edge->next;
			}
			fprintf(stdout,"\n");
			index++;
		}		
	}

    vector< vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
	{
		std::vector< std::vector<string> > vector;
		if(wordList.size()<=0)  return vector;

		wordList.insert(endWord);
		wordList.insert(beginWord);	   
		graph * g= construct_graph(wordList);
		dump_graph(g);
		int start_index=0;
		while(start_index<g->vex_count && g->vex_set[start_index].val!=beginWord)
			  start_index++;

		std::vector<std::string> v;
		findpath(g,vector,v,start_index,endWord);
		if(vector.size()<=0)  return vector;
		
		int shortest_length=vector[0].size();
		start_index=1;
		while(start_index<vector.size()){
            if(vector[start_index].size()<shortest_length)
				shortest_length=vector[start_index].size();
			start_index++;
		}
		std::vector< std::vector<std::string> >  ladder_vector; 
		start_index=0;
		while(start_index<vector.size()){
			if(vector[start_index].size()==shortest_length)
				ladder_vector.push_back(vector[start_index]);
			start_index++;
		}
		return ladder_vector;
	
    }

	void findpath(graph *g, std::vector< std::vector<std::string> > & vector, std::vector<std::string> &v,
				  int start_index, std::string & endword)
	{
		if(start_index>=g->vex_count)  return ;
		if(g->vex_set[start_index].val==endword){
			v.push_back(endword);
			vector.push_back(v);
			v.pop_back();
			return ;
		}
		graph_vex * vex=&g->vex_set[start_index];
		v.push_back(vex->val);
        graph_edge * edge=vex->next;
		while(edge) {
            int next_index=edge->index;
			std::string val=edge->val;
			int j;
			for(j=0;j<v.size();j++){
				if(v[j]==val)  break;				
			}
			if(j!=v.size()){
				edge=edge->next;
				continue;
			}
			findpath(g,vector,v,next_index,endword);
			edge=edge->next;
		}
		v.pop_back();
		return ;
	}
};

int main(int argc,char **argv)
{

	std::unordered_set<string> set;
	std::string beginword="qa";
	std::string endword="sq";
	std::string wordslist[] ={"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln",
							  "tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","yb"};
	for(int index=0;index<sizeof(wordslist)/sizeof(wordslist[0]);index++)
		set.insert(wordslist[index]);
	Solution s;
	std::vector<std::vector<std::string>> vector=  s.findLadders(beginword,endword,set);
    int index=0;
	while(index<vector.size()){
		std::vector<std::string> &vector_path=vector[index];
		fprintf(stdout,"find wordlists:");
		int j=0;
		while(j<vector_path.size()){
			fprintf(stdout," %s ",vector_path[j].c_str());
			j++;
		}
		fprintf(stdout,"\n");
		index++;
	}
	return 0;
	
}
