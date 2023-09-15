//Bibliotecas:
#include <iostream>
#include <string>
#include "Functions.hpp"


//PlayGame
bool PlayGame(int *PlayerWill, int Difficulty){

	//Variables declarations and initialization
	const unsigned int TalismanA = Difficulty + rand() % Difficulty, TalismanB = Difficulty + rand() % Difficulty, TalismanC = Difficulty + rand() % Difficulty;
	const unsigned int NumberOfTasliman = 3;
	const unsigned int TalismanSum = TalismanA + TalismanB + TalismanC;
	const unsigned int TalismanProduct = TalismanA * TalismanB * TalismanC;
	unsigned int GuessA, GuessB, GuessC;
	unsigned int SumGuess, ProductGuess;
    char Continue = 0;
	
	//Initial massage to the player (Intro)
	PrintIntroduction(Difficulty);
	
	//Player objective
	std::cout << "# Insert the right combination of Talismans to bypass the mage's defenses. Each Talisman is represented by a number between " << Difficulty << " and " << Difficulty*2-1 << ".\n";
	std::cout << "# The " << NumberOfTasliman << " talismans add up to: " << TalismanSum;
	std::cout << "\n# The " << NumberOfTasliman << " talismans multiply to: " << TalismanProduct << std::endl;
	//Player guesses
    std::cout << "Enter your " << NumberOfTasliman << " talisman number guesses: ";
	std::cin >> GuessA >> GuessB >> GuessC;
	std::cout << "\nYou entered: " << GuessA << " " << GuessB << " " << GuessC << std::endl;

	SumGuess = GuessA + GuessB + GuessC;
	ProductGuess = GuessA * GuessB * GuessC;

	if (SumGuess == TalismanSum && ProductGuess == TalismanProduct){	//Win condition
		std::cout << "\nThe " << NumberOfTasliman << " talismans numbers are correct! You broke the mage's barrier.\n";
        std::cout << "Enter any character to continue or ctrl+C to exit\n";
        std::cin >> Continue;

        return true;
	}
	else{	//Retry
		--*PlayerWill;
		std::cout << "You have guessed the wrong talisman numbers, the enemy mage's defenses took a toll on your will." << " You can try " << *PlayerWill << " more times.\n";
        
        if (*PlayerWill == 0){	//Game over (possible replay function defending from an ai)
		    std::cout << "Your will has been exausted, the enemy has the upper hand. Protect yourself.\n";
	    }
        std::cout << "Enter any character to continue or ctrl+C to exit\n";
        std::cin >> Continue;

        return false;
	}
}

void PrintIntroduction(int Difficulty){

	//Initial massage to the player (Intro)
	if (Difficulty == 1){
            
        std::cout << "You are a Mattatron, a powerfull mage seeking endless knowledge.\n";
	    std::cout << R"(
		            .

                   .
        	 /^\     .
	    /\   "V" 
   	   /__\   I      O  o
  	  //..\\  I     .
  	  \].`[/  I
  	  /l\/j\  (]    .  O
 	 /. ~~ ,\/I          .
 	 \\L__j^\/I       o
	  \/--v}  I     o   .
  	  |    |  I   _________
  	  |    |  I c(`       ')o
  	  |    l  I   \.     ,/
	_/j  L l\_!  _//^---^\\_
	
	    )";
	std::cout << "\nThis is one of many mind battles you have engaged. You seek your enemy's secrets, but they are buried beneath their defenses.\n";
	std::cout << "Break the mages' 10 mind barriers, steal his knowledge and destroy his very own identity.\n\n";
    }
    else
    {
        std::cout << "You encounter another mind barrier. You broke " << Difficulty-1 << " so far.\n\n";
    }
    

}

int PrintEndGame(){
    
    char PlayAgain;

    std::cout << "\nCongratulations! You broke your enemy's will! You amassed more knowledge and left another husk walking this plane.\n";
    std::cout << "\nDo you want to play again? Y or N: ";
    std::cin >> PlayAgain;
    std::cout << std::endl;
    
    if (PlayAgain == 'Y')
    {
        int Difficulty = 1;
        
        return Difficulty;
    } else
    {
        exit(1);
    }
    
    

}