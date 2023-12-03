#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("./input");
    string txt;

    int total_sum = 0;

    while (getline(file, txt)) {
        int first_digit = -1;
        int last_digit = -1;

        for (char c : txt) {
            int c_int = (int) c;
            if (c_int >= 48 && c_int <= 57) {
                c_int -= 48;
                if (first_digit == -1) {
                    first_digit = c_int;
                }
                last_digit = c_int;
            }
        }

        int calibration_digit = first_digit*10 + last_digit;

        total_sum += calibration_digit;
    }

    cout << "sum of all lines: " << total_sum << endl;

    file.close();

    return 0;
}

