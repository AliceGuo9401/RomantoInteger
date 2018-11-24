#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s) {
    map<char, int> symbolValue{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C',100},
            {'D',500}, {'M', 1000}};
    int integer(0);
    for (int i = 0; i < s.size(); ++i) {
        char temp = s[i];
        char temp1 = s[i + 1];
        if (i < s.size() - 1 && symbolValue[temp] >= symbolValue[temp1])  /**/
            integer = integer + symbolValue[temp];
        else if (i < s.size() - 1 && symbolValue[temp] < symbolValue[temp1]) {
            integer = integer + symbolValue[temp1] - symbolValue[temp];
            ++i;
        }else if (i == s.size() - 1) {
            integer = integer + symbolValue[temp];
        }
    }
    return integer;
}
int main() {
    string s("MCMXCIV");
    int integer = romanToInt(s);
    cout << integer;
    return 0;
}
