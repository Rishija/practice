/*
 Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

 Example 1:

 Input: 123
 Output: "One Hundred Twenty Three"
 Example 2:

 Input: 12345
 Output: "Twelve Thousand Three Hundred Forty Five"
 Example 3:

 Input: 1234567
 Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 Example 4:

 Input: 1234567891
 Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 */

class Solution {
    vector<string> ONES;
    vector<string> ELEVENS;
    vector<string> TENS;
public:
    string chunk(int num) {

        if(num <= 10)   return ONES[num];
        if(num <= 20)   return ELEVENS[num - 10];
        if(num <= 99)   return TENS[num/10] + ONES[num % 10];
        return ONES[num/100] + " Hundred" + chunk(num % 100);
    }

    string helper(int num) {
        string ans = "";
        vector<string> group = {"", " Thousand", " Million", " Billion"};
        int index = 0;

        while(num != 0) {
            if(num % 1000 != 0)
                ans = chunk(num % 1000) + group[index] + ans;
            index++;
            num = num/1000;
        }
        return ans;
    }

    string numberToWords(int num) {
        if(num == 0)    return "Zero";
        ONES = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten"};
        ELEVENS = {"", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen", " Twenty"};
        TENS = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        return helper(num).substr(1);
    }
};
