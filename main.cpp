#include"christmas.hpp"
#include"day1.hpp"
#include"day2.hpp"
#include"day3.hpp"
#include"day4.hpp"

void print_head() {
	print_christmas_tree();
	std::cout << '\n';
	using namespace ansi_colors;
	print_framed("Welcome to my entry to AOC",5,40);
}

int main() {
	print_head();
	std::vector<Solution*> solutions{ 
		new Day1{}, 
		new Day2{}, 
		new Day3{}, 
		new Day4{},
	};
	for (Solution* p : solutions) {
		p->solve();
		delete p;
	}
}