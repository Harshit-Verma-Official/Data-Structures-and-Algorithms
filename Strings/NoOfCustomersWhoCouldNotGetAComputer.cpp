#include <bits/stdc++.h>
using namespace std;

int countCustomer(int k, string str) {
    set<char> active;
    set<char> notActive;

    int unserv = 0;
    int count = k;

    for (int i = 0; i < str.length(); ++i) {
        if (count > 0) {
            if (active.find(str[i]) == active.end()) {
                active.insert(str[i]);
                count--;
            } else {
                active.erase(str[i]);
                count++;
            }
        } else if (active.find(str[i]) != active.end()) {
            active.erase(str[i]);
            count++;
        } else {
            if (notActive.find(str[i]) == notActive.end()) {
                notActive.insert(str[i]);
                unserv++;
            }
        }
    }

    return unserv;
}

int main() {
    cout << countCustomer(2, "ABBAJJKZKZ") << endl;
    cout << countCustomer(3, "GACCBDDBAGEE") << endl;
    cout << countCustomer(3, "GACCBGDDBAEE") << endl;
    cout << countCustomer(1, "ABCBCA") << endl;
    cout << countCustomer(1, "ABCBCADEED") << endl;

    return 0;
}