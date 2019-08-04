/*
 Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
 
 Example:
 
 Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 Output: ["2", "4->49", "51->74", "76->99"]
 */

vector<string> findMissingRanges(vector<int>& A, int lower, int upper) {
    long long int n = A.size(), last = lower - 1ll;
    
    vector<string> ans;
    for(int i = 0; i < n; ++i) {
        auto gap = A[i] - last;
        if(gap == 2)
            ans.push_back(to_string(last + 1));
        else if(gap > 2) {
            string temp = to_string(last + 1);
            temp += "->";
            temp += to_string(A[i] - 1ll);
            ans.push_back(temp);
        }
        last = A[i];
    }
    auto gap = upper + 1ll - last;
    if(gap == 2)
        ans.push_back(to_string(last + 1));
    else if(gap > 2) {
        string temp = to_string(last + 1);
        temp += "->";
        temp += to_string(upper);
        ans.push_back(temp);
    }
    return ans;
}


// Method 2
vector<string> findMissingRanges(vector<int> A, int l, int u) {
    vector<string> ans;
    string arrow = "->";
    int n = A.size();
    
    long lower = l;
    long upper = u;
    if(n == 0) {
        if(lower == upper)
            return {to_string(lower)};
        return {to_string(lower) + arrow + to_string(upper)};
    }
    if(A[0] == lower + 1)
        ans.push_back(to_string(lower));
    else if(A[0] > lower + 1)
        ans.push_back(to_string(lower) + arrow + to_string(A[0] - 1l));
    
    long last = A[0] - 1l;
    for(int i = 0; i < n; ++i) {
        if(A[i] == last + 2)
            ans.push_back(to_string(last + 1));
        else if(A[i] > last + 2)
            ans.push_back(to_string(last + 1) + arrow + to_string(A[i] - 1l));
        last = A[i];
    }
    
    if(last == upper - 1)
        ans.push_back(to_string(upper));
    else if(last < upper - 1)
        ans.push_back(to_string(last + 1) + arrow + to_string(upper));
    return ans;
}
