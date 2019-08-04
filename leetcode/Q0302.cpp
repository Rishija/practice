/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

Example:

Input:
[
 "0010",
 "0110",
 "0100"
 ]
and x = 0, y = 2

Output: 6
*/

int leftt, rightt, top, bottom;
void helper(vector<vector<char>>* &A, int i, int j, const int &n, const int &m) {
    
    leftt = min(leftt, j);    rightt = max(rightt, j);
    top = min(top, i);        bottom = max(bottom, i);
    (*A)[i][j] = '0';
    
    if(i < n-1 && (*A)[i+1][j] == '1') helper(A, i+1, j, n, m);
    if(j < m-1 && (*A)[i][j+1] == '1') helper(A, i, j+1, n, m);
    if(i > 0 && (*A)[i-1][j] == '1')   helper(A, i-1, j, n, m);
    if(j > 0 && (*A)[i][j-1] == '1')   helper(A, i, j-1, n, m);
}
int minArea(vector<vector<char>>& image, int x, int y) {
    int n = image.size(), m = image[0].size();
    leftt = y; rightt = y;
    top = x;   bottom = x;
    vector<vector<char>> *A = &image;
    helper(A, x, y, n, m);
    return (rightt - leftt + 1) * (bottom - top + 1);
}
