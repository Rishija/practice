/*

 The count-and-say sequence is the sequence of integers with the first five terms as following:

 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth term of the count-and-say sequence.

 Note: Each term of the sequence of integers will be represented as a string.

 Example 1:

 Input: 1
 Output: "1"
 Example 2:

 Input: 4
 Output: "1211"
 */

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)  return "";
        string last = "1";
        while(--n) {
            string neww;
            int i = 0, count = 0;
            while(i < last.size()) {
                char x = last[i];
                while(i < last.size() && last[i] == x) {
                    ++i;
                    ++count;
                }
                neww += to_string(count) + x;
                count = 0;
            }
            last = neww;
        }
        return last;
    }
};
