list<pair<int,int>> List;
int cacheSize;
unordered_map<int, list<pair<int,int>>::iterator> address;

LRUCache(int capacity) {
    List.clear();
    address.clear();
    cacheSize = capacity;
}

int get(int key) {
    if(address.find(key) == address.end())
        return -1;
    int value = address[key]->second;
    List.erase(address[key]);
    List.push_front({key, value});
    address[key] = List.begin();
    return value;
}

void put(int key, int value) {
    if(address.find(key) != address.end())
        List.erase(address[key]);
    
    else {
        if(List.size() >= cacheSize) {
            address.erase(List.rbegin()->first);
            List.pop_back();
        }
    }
    List.push_front({key, value});
    address[key] = List.begin();
}
