#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <thread>

using namespace std;


float player, playerTwo;
short int rounds;



random_device myEngine;
uniform_int_distribution<int> randomInt(1, 3);
uniform_int_distribution<int> randomInt2(1, 3);
int computer = randomInt(myEngine);
int computerTwo = randomInt2(myEngine);






void Clear_Console() {
	system("cls");
}

void Player_Vs_Machine() {
	Clear_Console();
	cout << "PLAYER VS MACHINE" << endl;


	
	cout << "How many rounds do you want to play? ";
	cin >> rounds;
	Clear_Console();

	int playerScore, machineScore, count;
	playerScore = machineScore = count = 0;
	while (rounds != count) {

		cout << "Input your number from 1-3 | 1-Rock, 2-Paper, 3-Scissors: ";
		cin >> player;

		if (computer == player) {
			Clear_Console();
			cout << "ITS A DRAW! NO SCORE FOR BOTH!" << endl;
			// count += 1;
		}
		else if (player == 1 && computer == 2 || player == 2 && computer == 3 || player == 3 && computer == 1) {
			Clear_Console();
			cout << "THE MACHINE WINS THIS ROUND!" << endl;
			machineScore += 1;
			count += 1;
		}
		else if (player == 1 && computer == 3 || player == 2 && computer == 1 || player == 3 && computer == 2 ) {
			Clear_Console();
			cout << "YOU WIN THIS ROUND!" << endl;
			playerScore += 1;
			count += 1;
		}
		else {
			Clear_Console();
			cout << "\aPLEASE ENTER YOUR NUMBER FROM 1-3 CONTENDER!" << endl;
			
		}
	}

	// TODO: See if you can add this part in the while statement and add a play again option for the player. 
	// FINAL SCORE
	Clear_Console();
	cout << "FINAL SCORE!" << endl;
	cout << "\nPlayer = " << playerScore << endl;
	cout << "Machine = " << machineScore << endl;

	if (playerScore > machineScore) {
		cout << "YOU ARE THE CHAMPION!" << endl;
	}
	else if (playerScore < machineScore) {
		cout << "THE MACHINE RULES THE WORLD!" << endl;
	}
	else if (playerScore == machineScore) {
		cout << "ITS A TIE! NO ONE IS A WINNER HERE!" << endl;
	}
	else;
}

void Machine_Vs_Machine() {

	
	int short count = 0;
	int short computer_Score =  0;
	int short computerTwo_Score = 0;
	

	Clear_Console();
	cout << "In this game mode, both players are going to place their bets on their champions" << endl;
	cout << "Player one, place your bet for your champion: $"; 
	cin >> player;
	cout << "Player One's Bet: $" << player << endl;
	
	// TODO: MAKE SURE THE PLAYERS PLACES THEIR BET FROM THE RANGE 1 TO 100. ANY NUBMER IS OUTSIDE OF THE RANGE, MAKE SURE THE NUMBER NOFITY THE USER!
	// TODO: SET THE BET AMOUNT FORMAT TO TWO DECIMAL PLACES.
	// TODO the round setting must be converted to a function to make the code cleaner.
	
	cout << "Player two, place your bet for your champion: $";
	cin >> playerTwo;
	cout << "Player Two's Bet: $" << playerTwo << endl;

	cout << "How many rounds: "; 
	cin >> rounds;

	this_thread::sleep_for(chrono::milliseconds(2000));
	Clear_Console();
	cout << "THE BET IS SETTLED!" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "LET THE GAMES BEGIN!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2900));
	Clear_Console();


	while (count != rounds) {

		computer = randomInt(myEngine);
		computerTwo = randomInt2(myEngine);

		cout << "Computer 1 Number: " << computer << endl;
		cout << "Computer 2 Number: " << computerTwo << endl;

		if (computer == computerTwo) {
			cout << "ITS A TIE! NO POINTS FOR THIS ROUND!" << endl;
			++count;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << '\n';
		}
		else if ((computer == 1 && computerTwo == 2) || (computer == 2 && computerTwo == 3) || (computer == 3 && computerTwo == 1)) {
			cout << "COMPUTER 1 WINS!" << endl;
			++count;
			++computer_Score;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << '\n';
		}
		else if ((computer == 1 && computerTwo == 3) || (computer == 2 && computerTwo == 1) || (computer == 3 && computerTwo == 2)) {
			cout << "COMPUTER 2 WINS!" << endl;
			++count;
			++computerTwo_Score;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << '\n';
		}
		else if ((computer == 1 && computerTwo == 1) || (computer == 2 && computerTwo == 2) || (computer == 3 && computerTwo == 3)) {
			cout << "THIS MATCH IS A STALEMATE!!!" << endl;
		}
	}

	
	cout << "The Game is over!\nTime to see who will gain it all and lose it all!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	Clear_Console();
	cout << "Computer One Score: " << computer_Score << endl;
	cout << "Computer Two Score: " << computerTwo_Score << endl;

	if (computer_Score > computerTwo_Score) {
		cout << "\nBETTER 1 HAS ITS CHAMPION! CLAIM YOUR PRICE FROM YOUR FOE!" << endl;
		cout << "BETTER 1 YOU HAVE EARNED " << player + playerTwo << " DOLLARS!" << endl;
		cout << "BETTER 2 YOU HAVE NOTHING! BETTER LUCK NEXT TIME!" << endl;
	}
	else {
		cout << "\nBETTER 2 HAS ITS CHAMPION! CLAIM YOUR PRICE FROM YOUR FOE!" << endl;
		cout << "BETTER 2 YOU HAVE EARNED " << player + playerTwo << " DOLLARS!" << endl;
		cout << "BETTER 1 YOU HAVE NOTHING! BETTER LUCK NEXT TIME!" << endl;
	} 


	


}

void Main_Menu() {

	cout << "ROCK PAPERS SCISSORS C++ EDITION" << endl;
	cout << "Type Either 1 or 2 To Select Your Game Mode" << endl;
	cout << "[1] Player VS Machine\n[2] Machine VS Machine Betting Game\n" << endl;
	cin >> player;
	bool isValid = false;




	while (isValid == false) {
		if (player == 1) {
			Player_Vs_Machine();
			isValid = true;
		}
		else if (player == 2) {
			Machine_Vs_Machine();
			isValid = true;
		}
		else {
			cout << "Type 1 for Player vs Machine\nType 2 for Machine vs Machine" << endl;
			cin >> player;
			isValid = false;
		}
	}

}

int main() {


	Main_Menu();



}



