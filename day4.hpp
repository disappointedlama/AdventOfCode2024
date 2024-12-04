#pragma once
#include"solution.hpp"

class Day4 :public Solution {
    size_t line_width;
    std::string s;
protected:
    void parse_for_part1() {
        std::ifstream infile(std::filesystem::current_path() / "inputs" / "day4.txt");
        if (infile.is_open()) {
            std::string line;
            while (std::getline(infile, line)) {
                line_width = line.size();
                s += line;
            }
        }
        else {
            std::cout << "unable to open file\n";
        }
    }
    void prepare_for_part2() {};
    std::string solve_part1() {
        const size_t highest_rows{ s.size() / line_width };
        size_t count{ 0 };
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != 'X') continue;
            const size_t row{ i / line_width };
            const size_t col{ i % line_width };
            const bool right{ col < line_width - 3 };
            const bool left{ col > 2 };
            const bool up{ row > 2 };
            const bool down{ row < highest_rows - 3 };
            if (up) {
                count += s[i - line_width] == 'M' && s[i - 2 * line_width] == 'A' && s[i - 3 * line_width] == 'S';
                if (left) {
                    count += s[i - line_width - 1] == 'M' && s[i - 2 * line_width - 2] == 'A' && s[i - 3 * line_width - 3] == 'S';
                }
                if (right) {
                    count += s[i - line_width + 1] == 'M' && s[i - 2 * line_width + 2] == 'A' && s[i - 3 * line_width + 3] == 'S';
                }
            }
            if (down) {
                count += s[i + line_width] == 'M' && s[i + 2 * line_width] == 'A' && s[i + 3 * line_width] == 'S';
                if (left) {
                    count += s[i + line_width - 1] == 'M' && s[i + 2 * line_width - 2] == 'A' && s[i + 3 * line_width - 3] == 'S';
                }
                if (right) {
                    count += s[i + line_width + 1] == 'M' && s[i + 2 * line_width + 2] == 'A' && s[i + 3 * line_width + 3] == 'S';
                }
            }
            if (left) {
                count += s[i - 1] == 'M' && s[i - 2] == 'A' && s[i - 3] == 'S';
            }
            if (right) {
                count += s[i + 1] == 'M' && s[i + 2] == 'A' && s[i + 3] == 'S';
            }
        }

        return std::to_string(count);
    }
    std::string solve_part2() {
        const size_t highest_rows{ s.size() / line_width };
        size_t count{ 0 };
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != 'A') continue;
            const size_t row{ i / line_width };
            const size_t col{ i % line_width };
            if (row == 0 || row == highest_rows) continue;
            if (col == 0 || row == line_width-1) continue;
            const bool slash{
                (s[i - line_width - 1] == 'M' && s[i + line_width + 1] == 'S')
                || (s[i - line_width - 1] == 'S' && s[i + line_width + 1] == 'M')
            };
            const bool back_slash{
                (s[i - line_width + 1] == 'M' && s[i + line_width - 1] == 'S')
                || (s[i - line_width + 1] == 'S' && s[i + line_width - 1] == 'M')
            };
            count += slash && back_slash;
        }
        return std::to_string(count);
    }
public:
    Day4() :Solution{ '4' }, line_width{ 0 }, s{} {}
};