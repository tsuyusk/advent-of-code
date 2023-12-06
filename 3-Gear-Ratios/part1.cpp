#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("../3-Gear-Ratios/test-input");
    string txt;

    int h_size = 0, v_size = 0;
    while (getline(file, txt)) {
        h_size = txt.size();
        v_size++;
    }

    char table[v_size][h_size];
    int i = 0;
    while (getline(file, txt)) {
        for (int j = 0; j < h_size; j++) {
            table[i][j] = txt[j];
        }
        i++;
    }

    file.close();

    

    return 0;
}
