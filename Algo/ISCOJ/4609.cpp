#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

void pairRNA (string &s) {
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'A') s[i] = 'U';
        else if (s[i] == 'T') s[i] = 'A';
        else if (s[i] == 'C') s[i] = 'G';
        else if (s[i] == 'G') s[i] = 'C';
    }
}

string getAA (string s) {
    pairRNA(s);
    if (s == "AUG") return "Start";
    if (s == "UAA" || s == "UAG" || s == "UGA") return "Stop";
    if (s == "UUU" || s == "UUC") return "Phe";
    if (s == "UUA" || s == "UUG") return "Leu";
    if (s == "UCU" || s == "UCC" || s == "UCA" || s == "UCG") return "Ser";
    if (s == "CUU" || s == "CUC" || s == "CUA" || s == "CUG") return "Leu";
    if (s == "CCU" || s == "CCC" || s == "CCA" || s == "CCG") return "Pro";
    if (s == "AUU" || s == "AUC" || s == "AUA") return "Ile";
    if (s == "ACU" || s == "ACC" || s == "ACA" || s == "ACG") return "Thr";
    if (s == "GUU" || s == "GUC" || s == "GUA" || s == "GUG") return "Val";
    if (s == "GCU" || s == "GCC" || s == "GCA" || s == "GCG") return "Ala";
    if (s == "GAU" || s == "GAC") return "Asp";
    if (s == "GAA" || s == "GAG") return "Glu";
    if (s == "UAU" || s == "UAC") return "Tyr";
    if (s == "UGG") return "Trp";
    return "";
}

void solve () {
    string s;
    cin >> s;
    bool started = 0;
    for (int i = 0; i < SZ(s); i += 3) {
        string AA = getAA(s.substr(i, 3));
        if (AA == "Start") started = 1;
        if (started) cout << AA;
        if (AA == "Stop") {
            cout << '\n';
            return;
        }
        if (started && AA != "") cout << '-';
    }
}

int main () {
    fastio;
    solve();
    return 0;
}