//Bibliotecas:
#include <iostream>
#include <string>
#include <ctime>
#include "Functions.hpp"



//main
int main(int argc, char const *argv[]) {

	int PlayerWill = 5, LevelDifficulty = 1;
	const unsigned int MaxDifficulty = 10;
	srand(time(NULL));


	while (PlayerWill != 0){ // Loop the game until you lose.
		bool bLevelComplete = PlayGame(&PlayerWill, LevelDifficulty);
		
		std::cin.clear();	//clear any errors
		std::cin.ignore();	//clear any errors

		if (bLevelComplete){
			++LevelDifficulty;
		}
		if (LevelDifficulty > MaxDifficulty)
		{
			LevelDifficulty = PrintEndGame();
			
		}
		
	}
	

	return 0;
}
