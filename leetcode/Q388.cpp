/*
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/

int lengthLongestPath(string input) {
    stack<string> s;
    vector<string> names = split(input);
    int maxx = 0, current = 0, level;

    for(string name : names) {
        level = findLevel(name);
        while(level < s.size()) {
            current -= s.top().size() - findLevel(s.top()) + 1;
            s.pop();
        }
        current += name.size() - level + 1;
        if(name.find(".") != string::npos) {
            maxx = max(current, maxx);
            current -= name.size() - level + 1;
        }
        else
            s.push(name);
    }
    return maxx == 0 ? 0 : maxx - 1;
}

int findLevel(string s) {
    int i = 0;
    while(i < s.size() && s[i] == '\t')
        ++i;
    return i;
}

vector<string> split(string s) {
    if(s.empty())
        return {};
    int pos = 0;
    vector<string> ans;

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '\n') {
            ans.push_back(s.substr(pos, i - pos));
            pos = i + 1;
        }
    }
    ans.push_back(s.substr(pos, s.size() - pos));
    return ans;
}
