#include <stdio.h>
#include<iostream>
#include <string.h>
#include<stdlib.h>
#include <set>
#include <vector>
#include <ctype.h>
#include <time.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <ios>
#include <fstream>
using namespace std;
/*Delete hyperedge from hypergraph when element x appears*/
void Delete(std::vector<std::vector<int> > &v, int x)
{
     v.erase(std::remove_if(v.begin(), v.end(),[x](const std::vector<int>& v) { return std::find(v.begin(), v.end(), x) != v.end(); }),v.end());
}
/*max frequency nodes in hypergraph*/
std::map<int, unsigned int> occurence(vector<vector<int>> &edge, unsigned int &max_count){
 
  std::map<int, unsigned int> counts;
  for (const std::vector<int> &row : edge) {
    for (const int &ele : row) {
      if (++counts[ele] > max_count) {
        max_count = counts.at(ele);
      }
    }
  }
  return counts;
}
/*GetMinTrans function*/
vector<int> GetMinTrans(vector< vector<int> > &edge, int ENum, set<int> AllVert){
     vector<vector<int>> edge2;
     vector<int> TM;
     vector <int> T;
     int min =ENum;

     set<int, greater<int> >::iterator it;
     for (it  = AllVert.begin(); it != AllVert.end(); it++) {
         TM.clear();
         TM.push_back(*it);
         edge2 = edge;                     // stocke the rest of matrix in edge2
         Delete(edge2, *it);               // delete hyperedge where element x apears

         while(edge2.size() != 0){
            unsigned int max_count = 0;
            std::map<int, unsigned int> counts = occurence(edge, max_count);
            for (const auto& [val, count] : counts) {
                     if (count == max_count) {
                            TM.push_back(val);
                            
                     }Delete(edge2, val);
            }
         }
         if(min > TM.size()){

             min = TM.size();
             T =TM;
         }

    }
 return T;
}


int main() {
  std::vector<std::vector<int>> edge
  {
    {2, 1},
    {2, 3, 7},
    {3, 4, 5},
    {4, 6},
    {6, 7, 4},
    {7, 9}
  };
  set<int> AllVert = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int ENum = 6;
  vector <int> T = GetMinTrans(edge, ENum, AllVert);
  printf("size  =%d", T.size());
  printf("size  =%d", T[0]);
  printf("size  =%d", T[1]);
  printf("size  =%d", T[2]);
  return 0;
}