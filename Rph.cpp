#include "Rph.h"

void Rps_board::playround(std::string in) {
	if (in == "Rock" || in == "Paper" || in == "Scissor") {
		int ga = std::rand();
		std::cout << ga;
	} else {
		std::cout << "Sorry I didnt understand that could you try again ? \n";
	}
}