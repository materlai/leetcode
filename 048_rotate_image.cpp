/*
leetcode algorithm 048:
                   rotate matrix
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector< vector<int> >& matrix) {
       int n=matrix.size();
       if(n<=0)  return;
       int step=0;
       while(step<n/2){
           int row_index=step;
           int col_index=step;
           std::vector<int> left_buf(n-step*2);
           for(int index=row_index;index<n-row_index;index++)
             left_buf[index-row_index]=matrix[index][col_index];
           
           //move the bottom to left
           for(int index=row_index;index<n-row_index;index++){
               matrix[index][col_index]=matrix[n-row_index-1][col_index+index-row_index];
           }
           //move from right to bottom 
           for(int index=col_index;index<n-col_index;index++){
               matrix[n-row_index-1][index]=matrix[n-row_index-1-(index-col_index)][n-col_index-1];
           }
		   //move from top to  right
		   for(int index=n-row_index-1;index>=row_index;index--){
			   matrix[index][n-col_index-1]=matrix[row_index][index];			   
		   }
           //move from left to top 
           for(int index=col_index;index<n-col_index;index++)
                matrix[row_index][index]=left_buf[n-2*row_index-1-(index-col_index)];
           step++;   
       }
        
    }
};

int main(int argc,char ** argv)
{
	std::vector< std::vector<int> > vector;
	std::vector<int> vec_1={1,2,3};
	std::vector<int> vec_2={4,5,6};
    std::vector<int> vec_3={7,8,9};
	vector.push_back(vec_1);
	vector.push_back(vec_2);
	vector.push_back(vec_3);
	
	Solution s;
	s.rotate(vector);
	for(int index=0;index<vector.size();index++){
		std::vector<int> & v=vector[index];
		for(int j=0;j<v.size();j++){
			fprintf(stdout,"%d",v[j]);			
		}
		fprintf(stdout,"\n");
	}
	return 0;
}
