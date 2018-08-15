/*
 Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
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
