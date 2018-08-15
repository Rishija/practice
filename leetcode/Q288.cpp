/*
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:


Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

unordered_map<string, string> map;
ValidWordAbbr(vector<string> dictionary) {
    for(auto &word : dictionary) {
        string abbr = word[0] + to_string(word.size()-2) + word[word.size()-1];
        if(map.find(abbr) != map.end() && map[abbr] != word) map[abbr] = "";
        else    map[abbr] = word;
    }
}

bool isUnique(string word) {
    string abbr = word[0] + to_string(word.size()-2) + word[word.size()-1];
    return map.find(abbr) == map.end() || map[abbr] == word;
}
