#include <string>
#include <iostream>
#include <vector>
using namespace std;

string JoinString(vector<string> vString, string Delim) {
    string S1 = "";
    int vStringLength = vString.size() - 1;

    for (string& s : vString) {

        if (vString[vStringLength] == s)
        {
            S1 = S1 + s;
            continue;
        }
        S1 = S1 + s + Delim;
    }
    return S1;
}

int main() {
    vector<string> vString = { "Mohammed", "Waleed", "Ali", "Almomany" };

    cout << "\nVector after join: \n";
    cout << JoinString(vString, "  ");

    system("pause>0");
}
