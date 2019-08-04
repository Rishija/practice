/*
 
 The API: int read4(char *buf) reads 4 characters at a time from a file.
 
 The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
 
 By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 */

/**
 * @param buf Destination buffer
 * @param n   Maximum number of characters to read
 * @return    The number of characters read
 */
int read(char *buf, int n) {
    int cnt = 0, x = read4(buf);
    while(n >= 4 && x == 4) {
        cnt++;
        n -= 4;
        buf += 4;
        x = read4(buf);
    }
    cnt = cnt * 4 + min(n, x);
    return cnt;
}
