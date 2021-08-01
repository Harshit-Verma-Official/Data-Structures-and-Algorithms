#include <bits/stdc++.h>
using namespace std;

void eraseSubStr(std::string & mainStr, const std::string & toErase)
{
    // Search for the substring in string
    size_t pos = mainStr.find(toErase);

    if (pos != std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

int main() {
	string str = "apple5abc11d";
    int n = str.length();

    int i = 1;
    while (true) {
        if (n <= 10 * i) {
            n--;
            break;
        }
        i++;
    }

    string len = to_string(n);


    eraseSubStr(str, len);

    cout << str;

}