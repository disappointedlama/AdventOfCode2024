#include"christmas.hpp"
#include"day1.hpp"
#include"day2.hpp"
#include"day3.hpp"

void print_head() {
	print_christmas_tree();
	std::cout << '\n';
	using namespace ansi_colors;
	print_framed("Welcome to my entry to AOC",5,40);
}

int main() {
	print_head();
	Day1 d1{};
	d1.solve();
	Day2 d2{};
	d2.solve();
	Day3 d3{};
	d3.solve();
}