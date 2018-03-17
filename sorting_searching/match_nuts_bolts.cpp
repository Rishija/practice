/*
 Given N nuts and N bolts. There is 1:1 mapping between nuts and bolts. You can't compare nut with other nuts or bolt with bolt. But you can compare nut with bolt. When you compare a nut with bolt you get a result saying 1) if nut is bigger 2) if bolt is bigger 3) if they match. Match each nut with bolt.
 */
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    
    int temp = a;
    a = b;
    b = temp;
}

void match(char *nuts, int *bolts, int n) {
    
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(bolts[j] == static_cast<int>(nuts[i])) {
                swap(bolts[i], bolts[j]);
                break;
            }
        }
    }
}

int main() {
    
    char nuts[10] = {'g', 'a', 'j', 'd', 'e', 'c', 'h', 'f', 'b', 'i'};
    int bolts[10] = {106, 100, 98, 97, 101, 104, 105, 100, 103, 102};
    
    match(nuts, bolts, 10);
    
    for(int i = 0; i < 10; ++i) {
        cout << nuts[i] << " -> " << bolts[i] << endl;
    }
    
    return 0;
}
