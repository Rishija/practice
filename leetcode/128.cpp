int longestConsecutive(vector<int>& nums) {
    
    int n = nums.size();
    if(n < 2)   return n;
    
    unordered_map<int, bool> map;
    for(int x : nums)   map[x] = false;
    
    int start = -1, end = -1;
    auto it = map.begin();
    
    while(true) {
        int s = it->first, e = it->first;
        map[it->first] = true;
        while(map.find(s - 1) != map.end()) {
            s--;
            map[s] = true;
        }
        while(map.find(e + 1) != map.end()) {
            e++;
            map[e] = true;
        }
        if(e - s + 1 > end - start + 1) {
            start = s;
            end = e;
        }
        while(it != map.end() && it->second == true)
            ++it;
        if(it == map.end())
            break;
    }
    
    //    vector<int> ans;
    //    for(int i = start; i <= end; ++i)
    //        ans.push_back(i);
    return end - start + 1;
}
