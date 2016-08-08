/*
leetcode algorithm 079:
                    word search 
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()<=0 || board[0].size()<=0)  return false;
        find_target=false;
        int m=board.size();
        int n=board[0].size();
        for(int index=0;index<m;index++)
         for(int j=0;j<n;j++){
             if(board[index][j]==word[0]){
		         std::vector<std::vector<int>> nodes(m,std::vector<int>(n,0));
                 find_all(board,nodes,index,j,0,word);
                 if(find_target)  break;
             }
         }
         return find_target;
    }
    
    void find_all(std::vector<std::vector<char>> & vector, std::vector<std::vector<int>> &nodes,
				  int row_index,int col_index,int index,std::string &word){
		    if(index==word.size()){
                find_target=true;
                return ;
            }
            if(row_index<0 || row_index>=vector.size())   return ;
            if(col_index<0 || col_index>=vector[0].size()) return ;
            if(vector[row_index][col_index]!=word[0])   return ;
            if(nodes[row_index][col_index])   return ;
            find_all(vector,nodes,row_index+1,col_index,index+1,word);
            find_all(vector,nodes,row_index-1,col_index,index+1,word);
            find_all(vector,nodes,row_index,col_index-1,index+1,word);
            find_all(vector,nodes,row_index,col_index+1,index+1,word);
            nodes[row_index][col_index]=0;
    }
private:
   bool find_target;
};


int main(int argc,char **argv)
{

	std::vector<char> vec={'A','A'};
	std::vector<std::vector<char>> vector;
	vector.push_back(vec);
	Solution s;
	bool find_target=s.exist(vector,std::string("AAA"));

	return 0;
	
}
