#pragma once
#include<filesystem>
#include<string>
#include<fstream>
#include<iostream>
#include<unordered_map>
#include<sstream>
#include"christmas.hpp"
using std::string, std::cout;
void day1() {
    //parsing
    std::vector<int> list1{};
    std::vector<int> list2{};
    std::ifstream infile(std::filesystem::current_path() / "inputs" / "day1.txt");
    if (infile.is_open()) {
        string line;
        int sum{ 0 };
        while (std::getline(infile, line)) {
            string first{ line.substr(0, 5) };
            string second{ line.substr(8,5) };
            list1.push_back(stoi(first));
            list2.push_back(stoi(second));
        }
    }
    else {
        cout << "unable to open file\n";
    }
    //part1
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    size_t sum{ 0 };
    for (int i = 0; i < list1.size(); ++i) {
        sum += std::abs(list1[i] - list2[i]);
    }
    std::stringstream s{};
    s << "day1 part1: " << sum;
    cout << '\n';
    print_framed(s.str(), 5);
    cout << '\n';

    //part2
    std::unordered_map<int, size_t> occurence_count{};
    for (int i = 0; i < list1.size(); ++i) {
        occurence_count[list1[i]] = 0;
    }
    for (int i = 0; i < list2.size(); ++i) {
        if (occurence_count.find(list2[i]) != occurence_count.end()) {
            ++occurence_count[list2[i]];
        }
    }
    size_t score{ 0 };
    for (int i = 0; i < list1.size(); ++i) {
        score += list1[i] * occurence_count[list1[i]];
    }
    s = std::stringstream{};
    s << "day1 part2: " << score;
    print_framed(s.str(), 5);
    cout << '\n';
}