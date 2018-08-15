/*
 Implement an iterator to flatten a 2d vector.
 
 Example:
 
 Input: 2d vector =
 [
 [1,2],
 [3],
 [4,5,6]
 ]
 Output: [1,2,3,4,5,6]
 
 Explanation: By calling next repeatedly until hasNext returns false,
 the order of elements returned by next should be: [1,2,3,4,5,6].
 */

class Vector2D {
    vector<int> vec;
    int index;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(auto v : vec2d) for(auto x : v) vec.push_back(x);
        index = 0;
    }
    
    int next() {
        return vec[index++];
    }
    
    bool hasNext() {
        return index < (vec.size());
    }
};
