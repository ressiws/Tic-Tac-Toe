#include "../common.h"

int main( )
{
	tic_tac_toe game;
	std::string start;

	std::cout << "Who starts?" << std::endl << "1. Player" << std::endl << "2. A.I" << std::endl << std::endl;
	std::cin >> start;

	game.player1_turn = start != "2";
	game.start_game( );

	return 0;
}