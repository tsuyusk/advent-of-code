#include <bits/stdc++.h>
#include <format>

using namespace std;

int main() {
    ifstream file("../2-Cube-Conundrum/input");
    string txt;

    int total_sum = 0;

    while (getline(file, txt)) {
        int id;
        bool is_possible = true;
        sscanf(txt.c_str(), "Game %d", &id);

        int size_of_id = to_string(id).size();

        txt = txt.substr(7 + size_of_id);
        string current_semicolon_section;

        int semicolon_pos = -2;
        do {
            int green = 0, blue = 0, red = 0;
            semicolon_pos = txt.find(";");
            if (semicolon_pos == -1) {
                current_semicolon_section = txt;
            } else {
                current_semicolon_section = txt.substr(0, semicolon_pos);
                txt = txt.substr(semicolon_pos+2);
            }

            int comma_pos = -2;
            string section;
            do {
                if (!is_possible) {
                    break;
                }

                comma_pos = current_semicolon_section.find(",");
                if (comma_pos == -1) {
                    section = current_semicolon_section;
                } else {
                    section = current_semicolon_section.substr(0, comma_pos);
                    current_semicolon_section = current_semicolon_section.substr(comma_pos + 2);
                }

                int space_pos = section.find(" ");
                int amount = stoi(section.substr(0, space_pos));
                string type = section.substr(space_pos + 1);

                if (type == "blue") {
                    blue += amount;
                } else if (type == "red") {
                    red += amount;
                } else if (type == "green") {
                    green += amount;
                }

                if (red > 12 || green > 13 || blue > 14) {
                    is_possible = false;
                }
            } while (comma_pos != -1);

        } while (semicolon_pos != -1);

        if (is_possible) {
            total_sum += id;
        }
    }

    cout << "total_sum: " << total_sum << endl;

    file.close();

    return 0;
}
