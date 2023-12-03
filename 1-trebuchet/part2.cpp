#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("../1-trebuchet/input");
    string txt;

    map<string, int> number_map;
    number_map["one"] = 1;
    number_map["two"] = 2;
    number_map["three"] = 3;
    number_map["four"] = 4;
    number_map["five"] = 5;
    number_map["six"] = 6;
    number_map["seven"] = 7;
    number_map["eight"] = 8;
    number_map["nine"] =  9;

    string number_names[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int total_sum = 0;

    while (getline(file, txt)) {
        int first_digit = -1;
        int last_digit = -1;
        int index_first_digit = -1, index_last_digit = -1;

        for (int i = 0; i < txt.size(); i++) {
            char c = txt[i];
            int c_int = (int) c;
            if (c_int >= 48 && c_int <= 57) {
                c_int -= 48;
                if (first_digit == -1) {
                    index_first_digit = i;
                    first_digit = c_int;
                }
                index_last_digit = i;
                last_digit = c_int;
            }
        }

        int first_digit_whole_number = -1, last_digit_whole_number = -1;
        int index_first_digit_whole_number = -1, index_last_digit_whole_number = -1;
        for (int i = 0; i < txt.size(); i++) {
            for (string number : number_names) {
                if (txt.compare(i, number.size(), number) == 0) {
                    int digit = number_map[number];
                    if (first_digit_whole_number == -1) {
                        first_digit_whole_number = digit;
                        index_first_digit_whole_number = i;
                    }
                    index_last_digit_whole_number = i;
                    last_digit_whole_number = digit;
                }
            }
        }


        if (index_first_digit_whole_number >= 0) {
            if (index_first_digit_whole_number < index_first_digit) {
                first_digit = first_digit_whole_number;
            }
        }
        if (index_last_digit_whole_number > index_last_digit) {
            last_digit = last_digit_whole_number;
        }

        int calibration_digit = first_digit*10 + last_digit;

        total_sum += calibration_digit;
    }

    cout << "sum of all lines: " << total_sum << endl;

    file.close();

    return 0;
}
