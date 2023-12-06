#include <bits/stdc++.h>
using namespace std;

int num_size(int num) {
    int size = 1;
    while ((num /= 10) > 0) {
        size++;
    }

    return size;
}

int main () {
    ifstream file("../4-Scratchcards/input");
    string txt;

    int total_sum = 0;
    while (getline(file, txt)) {
        vector<int> correct_numbers;

        int id;
        sscanf(txt.c_str(), "Card %d: ", &id);

        txt = txt.substr(10);

        while (txt.find(" | ") != string::npos)  {
            int num;
            sscanf(txt.c_str(), "%d ", &num);
            correct_numbers.push_back(num);
            int size_of_num = num_size(num);
            txt = txt.substr(max(size_of_num, 2) + 1);
        }

        txt = txt.substr(2); // length of "| "

        int matches = 0;
        while (txt.size() > 0) {
            int num;
            sscanf(txt.c_str(), "%d ", &num);
            int size_of_num = num_size(num);

            for (int number : correct_numbers) {
                if (num == number) {
                    matches++;
                    continue;
                }
            }

            if (txt.size() > max(size_of_num, 2)+1) {
                txt = txt.substr(max(size_of_num, 2) + 1);
            } else {
                txt = txt.substr(max(size_of_num,2));
            }
        }
        if (matches > 0) {
            total_sum += pow(2, matches-1);
        }
    }

    cout << "\ntotal_sum " << total_sum << "\n";

    file.close();
}
