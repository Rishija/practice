/*
 Write an efficient algorithm that searches for a value in an m x n matrix
 Given:
 - Integers in each row are sorted in ascending from left to right.
 - Integers in each column are sorted in ascending from top to bottom.
 
 This is called Youngs Tableau
 */

/*
 Time : O( Log4/3 (n*m) * Log2(max(n,m)) )
 Space : O(n)
 */
#include <iostream>
#include <vector>
#include <utility>
#define p(x) cout<<(#x)<<" -> "<<search(x, v, 0, 3, 0, 4)<<endl;
using namespace std;

int bsearch(int elem, vector<int> arr, int loww, int highh) {
    
    int low = loww, high = highh, mid;
    while(low <= high) {
        
        mid = low + (high - low) / 2;
        
        if(arr[mid] == elem)
            return mid;
        if(arr[mid] < elem)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


pair<int,int> search(int elem, vector<vector<int> > &vec, int rowStart, int rowEnd, int colStart, int colEnd) {
    
    pair<int,int> null = {-1,-1};
    if(rowStart > rowEnd || colStart > colEnd  || rowStart < 0 || colStart < 0)
        return {-1,-1};
    
    if(rowStart == rowEnd && colStart == colEnd)
        return elem == vec[rowStart][colStart] ? make_pair(rowStart, colStart) : make_pair(-1, -1);
    
    int rMid = rowStart + (rowEnd - rowStart) / 2,
    cMid = colStart + (colEnd - colStart) / 2;
    
    if(vec[rMid][cMid] == elem)
        return {rMid, cMid};
    
    pair<int, int> temp;
    
    if(vec[rMid][cMid] > elem) {
        // 1st Quadrant
        temp = search(elem, vec, rowStart, rMid, colStart, cMid);
    }
    
    else {
        // current row
        int tempp = bsearch(elem, vec[rMid], cMid + 1, colEnd);
        if(tempp != -1)
            return {rMid, tempp};
        
        // current column
        vector<int> colVector;
        for(int i = rMid + 1; i <= rowEnd; ++i)
            colVector.push_back(vec[i][cMid]);
        
        tempp = bsearch(elem, colVector, 0, rowEnd - rMid - 1);
        if(tempp != -1)
            return {tempp + rMid + 1, cMid};
        
        // 4th Quadrant
        temp = search(elem, vec, rMid + 1, rowEnd, cMid + 1, colEnd);
    }
    
    if(temp != null)
        return temp;
    
    // 2nd Quadrant
    temp = search(elem, vec, rowStart, rMid - 1, cMid + 1, colEnd);
    if(temp != null)
        return temp;
    
    // 3rd Quadrant
    return search(elem, vec, rMid + 1, rowEnd, colStart, cMid - 1);
}


ostream& operator << (ostream &out, const pair<int,int> p) {
    
    out << "[" << p.first << ", " << p.second << "] ";
    return out;
}


int main() {
    
    vector<vector<int> > v = {
        {1,25,27,28,29},
        {4,26,31,310,400},
        {5,30,90,900, 901},
        {100,310,910,911,912} };
    
    // not present
    p(0); p(2); p(3); p(1000); p(500); p(410);
    
    // present
    p(1); p(25); p(27); p(28); p(29);
    p(4); p(26); p(31); p(310); p(400);
    p(5); p(30); p(90); p(900); p(901);
    p(100); p(310); p(910); p(911); p(912);
    
    return 0;
}
