#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<random>
namespace ansi_colors {
	enum StandardColor :int {
		BLACK,
		DARK_RED,
		DARK_GREEN,
		DARK_YELLOW,
		DARK_BLUE,
		DARK_PURPLE,
		DARK_CYAN,
		DARK_WHITE,
		LIGHT_BLACK,
		LIGHT_RED,
		LIGHT_GREEN,
		LIGHT_YELLOW,
		BLUE,
		PURPLE,
		CYAN,
		WHITE
	};
	static constexpr auto RESET_COLOR{ "\033[m" };
	static constexpr auto ANSI_START{ "\033[38;5;" };
	template<typename T>
	void print_colored(const T& t, const int color) {
		std::cout << ANSI_START << color << 'm' << t << RESET_COLOR;
	}
	std::string set_color(const int color) {
		std::stringstream s{  };
		s << ANSI_START << color << 'm';
		return s.str();
	}
}
void print_christmas_tree() {
	using namespace ansi_colors;
	std::string red_at{ "\033[38;5;9m@\033[38;5;2m" };
	std::string green_o{ "\033[38;5;10mO\033[38;5;2m" };
	std::string yellow_star{ "\033[38;5;3m*\033[38;5;2m" };
	std::cout << "                  "<<yellow_star
	    << '\n' << set_color(DARK_GREEN)
		<< "                 ***\n"
		<< "                *****\n"
		<< "               *"
		<<red_at
		<<                  "*****\n"
		<< "              ******"
		<<green_o
        <<                      "**\n"
		<< "             *******"
		<< yellow_star
		<<                      "***\n"
		<< "            ****"
		<< green_o
		<<                  "********\n"
		<< "           ***"
		<< red_at
		<<                "******"
		<< yellow_star
		<<                       "****\n"
		<< "          ***"
		<<yellow_star
		<<               "*************\n"
		<< "         *********"
		<< yellow_star
		<<                    "*****"
		<< red_at
		<<	                        "***\n"
		<< "        *********************\n"<<set_color(52)
		<< "                ####\n"
		<< "                ####\n";
	std::cout << RESET_COLOR;
}
void print_framed(const std::string& s, const int padding=2, const int decoration_percentage=40) {
	using namespace ansi_colors;
	static constexpr const char* decorations{ "#*O@$%&" };
	static constexpr size_t decoration_count{ 7 };
	static constexpr const int colors[]{ LIGHT_RED,DARK_YELLOW, LIGHT_GREEN,52, DARK_PURPLE, 202 };
	static constexpr size_t color_count{ 6 };
	for (int i = 0; i < 2 + 2 * padding + s.size(); ++i) {
		if (rand() % 100 < decoration_percentage) {
			const char c{ decorations[rand() % decoration_count] };
			const int color{ colors[rand() % color_count] };
			print_colored(c, color);
		}
		else {
			print_colored('#', DARK_GREEN);
		}
	}
	std::cout << '\n' << set_color(DARK_GREEN);
	std::cout << '#';
	for (int i = 0; i < padding; ++i) {
		std::cout << ' ';
	}
	std::cout << s;
	for (int i = 0; i < padding; ++i) {
		std::cout << ' ';
	}
	std::cout << "#\n";
	for (int i = 0; i < 2 + 2 * padding + s.size(); ++i) {
		if (rand() % 100 < decoration_percentage) {
			const char c{ decorations[rand() % decoration_count] };
			const int color{ colors[rand() % color_count] };
			print_colored(c, color);
		}
		else {
			print_colored('#', DARK_GREEN);
		}
	}
	std::cout <<'\n' << RESET_COLOR;
}