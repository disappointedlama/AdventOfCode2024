#pragma once
#include"solution.hpp"

class Day2:public Solution{
    std::vector<std::vector<int>> arr;
protected:
    void parse_for_part1() {
        std::ifstream infile(std::filesystem::current_path() / "inputs" / "day2.txt");
        if (infile.is_open()) {
            std::string line;
            int sum{ 0 };
            while (std::getline(infile, line)) {
                arr.push_back({});
                int num{ 0 };
                for (char* p = line.data(); *p; ++p) {
                    const char c{ *p };
                    if (c == ' ') {
                        arr.back().push_back(num);
                        num = 0;
                    }
                    else {
                        num *= 10;
                        num += c - '0';
                    }
                }
                arr.back().push_back(num);
            }
        }
        else {
            std::cout << "unable to open file\n";
        }
    };
    bool is_safe(const std::vector<int>& v) {
        if (v[1] == v[0]) return false;
        const bool ascending{ v[1] > v[0] };
        bool safe{ true };
        for (int j = 0; j < v.size() - 1; ++j) {
            const int diff{ v[j + 1] - v[j] };
            if (ascending) {
                if (diff < 1 || diff>3) {
                    safe = false;
                    break;
                }
            }
            else {
                if (diff < -3 || diff>-1) {
                    safe = false;
                    break;
                }
            }
        }
        return safe;
    }
    std::string solve_part1() {
        size_t count{ 0 };
        for (int i = 0; i < arr.size(); ++i) {
            count += (is_safe(arr[i]));
        }
        return std::to_string(count);
    };
    bool is_safe_without_index(const std::vector<int>& v, const size_t bad_index) {
        std::vector<int> v2{};
        for (size_t i = 0; i < v.size(); ++i) {
            if (i != bad_index) {
                v2.push_back(v[i]);
            }
        }
        return is_safe(v2);
    }
    bool is_safe2(const std::vector<int>& v) {
        if (is_safe(v)) return true;
        for (int i = 0; i < v.size(); ++i) {
            if (is_safe_without_index(v, i)) {
                return true;
            }
        }
        return false;
    }
    std::string solve_part2() {
        size_t count{ 0 };
        for (int i = 0; i < arr.size(); ++i) {
            count += (is_safe2(arr[i]));
        }
        return std::to_string(count);
    };
public:
	Day2() :Solution{ '2' } {}
};