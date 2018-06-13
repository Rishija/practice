/*
 Alice has a hand of cards, given as an array of integers.
 
 Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
 
 Return true if and only if she can.
  */

bool isNStraightHand(vector<int>& hand, int W) {
    int n = hand.size();
    if(n % W != 0)
        return false;
    
    map<int, int> num;
    for(int x : hand)
        num[x]++;
    if(num.size() < W)
        return false;
    
    int start, next, count;
    for(int j = 0; j < n/W; ++j) {
        start = num.begin() -> first;
        count = 0;
        while(count < W) {
            next = num[start + 1];
            if(next == 0) {
                if(count != W - 1)
                    return false;
                num.erase(start + 1);
            }
            --num[start];
            if(num[start] == 0)
                num.erase(start);
            ++start;
            ++count;
        }
    }
    
    return true;
}
