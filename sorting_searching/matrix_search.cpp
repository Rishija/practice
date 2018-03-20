/*
 Write an efficient algorithm that searches for a value in an m x n matrix
 Given:
 - Integers in each row are sorted in ascending from left to right.
 - Integers in each column are sorted in ascending from top to bottom.
 
 This is called Youngs Tableau
 */

/*
 Time : O( Log4/3 (n*m)) )
 Space : O( log2 (max(n,m) ) )
 */
#include <iostream>
#include <vector>
#include <utility>
#define p(x) cout<<(#x)<<" -> "<<search(x, v, 0, 3, 0, 4)<<endl;
using namespace std;


pair<int,int> search(int elem, vector<vector<int> > &vec, int rowStart, int rowEnd, int colStart, int colEnd) {
    
    pair<int,int> null = {-1,-1};
    if(rowStart > rowEnd || colStart > colEnd)
        return {-1,-1};
    
    if(rowStart == rowEnd && colStart == colEnd)
        return elem == vec[rowStart][colStart] ? make_pair(rowStart, colStart) : make_pair(-1, -1);
    
    int rMid = rowStart + (rowEnd - rowStart) / 2,
    cMid = colStart + (colEnd - colStart) / 2;
    
    if(vec[rMid][cMid] == elem)
        return {rMid, cMid};
    
    pair<int, int> temp;
    
    // 1st Quadrant
    if(vec[rMid][cMid] > elem)
        temp = search(elem, vec, rowStart, rMid, colStart, cMid);
    
    // 4rth Quadrant
    else
        temp = search(elem, vec, rMid + 1, rowEnd, cMid + 1, colEnd);
    
    if(temp != null)
        return temp;
    
    // 2nd Quadrant
    temp = search(elem, vec, rowStart, rMid, cMid + 1, colEnd);
    if(temp != null)
        return temp;
    
    // 3rd Quadrant
    return search(elem, vec, rMid + 1, rowEnd, colStart, cMid);
}


ostream& operator << (ostream &out, const pair<int,int> p) {
    
    out << "[" << p.first << ", " << p.second << "] ";
    return out;
}


int main() {
    
    vector<vector<int> > v = {
        {1,    25,     27,    28,    29},
        {4,    26,     31,    312,   400},
        {5,    30,     90,    900,   901},
        {100,  310,    910,   911,   912} };
    
    // not present
    p(0); p(2); p(3); p(1000); p(500); p(410);
    
    // present
    p(1); p(25); p(27); p(28); p(29);
    p(4); p(26); p(31); p(312); p(400);
    p(5); p(30); p(90); p(900); p(901);
    p(100); p(310); p(910); p(911); p(912);
    
    return 0;
}
