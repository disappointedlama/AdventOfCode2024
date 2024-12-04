#pragma once
#include<string>
#include <sstream>
#include<filesystem>
#include<string>
#include<fstream>
#include<iostream>
#include<array>
#include<vector>
#include<unordered_map>
#include"christmas.hpp"
class Solution {
protected:	
	char day;
	Solution(const char day) : day{day}{}
	virtual void parse_for_part1() = 0;
	virtual void prepare_for_part2() {};
	virtual std::string solve_part1() = 0;
	virtual std::string solve_part2() = 0;
public:
	void solve() {
		parse_for_part1();
		std::stringstream s{};
		s << "day" << day << " part1: "<<solve_part1();
		std::cout << '\n';
		print_framed(s.str());
		prepare_for_part2();
		s.str(std::string());
		s << "day" << day << " part2: " << solve_part2();
		std::cout << '\n';
		print_framed(s.str());
	}
	virtual ~Solution() {};
};