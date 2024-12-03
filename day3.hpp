#pragma once
#include"solution.hpp"

class Day3 :public Solution {
    std::vector<std::string> v;
protected:
	void parse_for_part1() {
        std::ifstream infile(std::filesystem::current_path() / "inputs" / "day3.txt");
        if (infile.is_open()) {
            std::string line;
            while (std::getline(infile, line)) {
                v.push_back(line);
            }
        }
        else {
            std::cout << "unable to open file\n";
        }
	}
	void prepare_for_part2() {};
	std::string solve_part1() {
        size_t sum{ 0 };
        for (std::string l : v) {
            size_t idx;
            while ((idx = l.find("mul(")) !=std::string::npos) {
                int first_number{ 0 };
                bool first_started{ false };
                int second_number{ 0 };
                bool second_started{ false };
                bool first_ended{ false };
                bool second_ended{ false };
                for (char* p = l.data() + idx+4; *p; ++p) {
                    const char c{ *p };
                    if (c >= '0' && c <= '9') {
                        if (!first_ended) {
                            first_started = true;
                            first_number *= 10;
                            first_number += c - '0';
                        }
                        else {
                            second_started = true;
                            second_number *= 10;
                            second_number += c - '0';
                        }
                    }
                    else if (c == ',') {
                        if (first_started) {
                            first_ended = true;
                        }
                        else {
                            break;
                        }
                    }
                    else if (c == ')') {
                        if (second_started) {
                            second_ended = true;
                        }
                        break;
                    }
                    else {
                        break;
                    }
                }
                if (second_ended) {
                    sum += first_number * second_number;
                }
                l = l.substr(idx + 4);
            }
        }
        return std::to_string(sum);
	}
	std::string solve_part2(){
        size_t sum{ 0 };
        bool do_mult{ true };
        std::string text{};
        for (std::string l : v) {
            size_t idx;
            while ((idx = l.find("mul(")) != std::string::npos) {
                const size_t do_idx{ l.find("do()") };
                const size_t dont_idx{ l.find("don't()") };
                if (!do_mult) {
                    if (l.find("do()") != std::string::npos) {
                        l = l.substr(l.find("do()")+4);
                        do_mult = true;
                        continue;
                    }
                    else {
                        l = "";
                        break;
                    }
                }

                if (do_idx < idx) {
                    if (dont_idx < do_idx) {
                        do_mult = false;
                        l = l.substr(dont_idx + 7);
                        continue;
                    }
                    do_mult = true;
                    l = l.substr(do_idx + 4);
                    continue;
                }
                if (dont_idx < idx) {
                    l = l.substr(dont_idx + 7);
                    do_mult = false;
                    continue;
                }                int first_number{ 0 };
                bool first_started{ false };
                int second_number{ 0 };
                bool second_started{ false };
                bool first_ended{ false };
                bool second_ended{ false };
                for (char* p = l.data() + idx + 4; *p; ++p) {
                    const char c{ *p };
                    if (c >= '0' && c <= '9') {
                        if (!first_ended) {
                            first_started = true;
                            first_number *= 10;
                            first_number += c - '0';
                        }
                        else {
                            second_started = true;
                            second_number *= 10;
                            second_number += c - '0';
                        }
                    }
                    else if (c == ',') {
                        if (first_started) {
                            first_ended = true;
                        }
                        else {
                            break;
                        }
                    }
                    else if (c == ')') {
                        if (second_started) {
                            second_ended = true;
                        }
                        break;
                    }
                    else {
                        break;
                    }
                }
                if (do_mult && second_ended) {
                    sum += first_number * second_number;
                }
                l = l.substr(idx + 4);
            }
            size_t do_idx;
            size_t dont_idx;

            while ((do_idx = l.find("do()") != std::string::npos) || (dont_idx = l.find("don't()") != std::string::npos)) {
                if (do_idx < dont_idx) {
                    l = l.substr(do_idx + 4);
                    do_mult = true;
                }
                else {
                    do_mult = false;
                    l = l.substr(dont_idx + 7);
                }
            }
        }
        return std::to_string(sum);
	}
public:
	Day3():Solution{'3'}{}
};