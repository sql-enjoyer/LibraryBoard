#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Format {
public:
    string format(string* str, int n, vector<char> paste) {
        int index = 0;

        for (int i = 0; i < n; i++) {
            if ((*str)[i] == '*') {
                (*str)[i] = paste[index];
                ++index;
            }
        }

        return *str;
    }
};