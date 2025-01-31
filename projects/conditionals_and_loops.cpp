
/**********************************************
 * 
 * Program Filename: ASSIGNMENT_THREE.cpp 
 *
 * Author: Connor Baldes
 *
 * Date: 2-1-2019
 *
 * Description: This program will create a standard game of 21 also know as "Black Jack". Ther user(s) first choose how much money they want to start with, that will be the
 * 		money that they are aloud to bet with. The starting amount will change once the user starts placing bets but once a users money reaches zero that player is out
 * 		of the game. Each player will be able to place bet each game, this amount cammot excede there current money amount. Based on if the player wins or loses the current 
 * 		game will decide whether they win their bet or lose it. If they win their bet they get their bet amount X2 if they lose they lose the amount that they bet. In the 
 * 		case of a tie the player will get the amount he bet back. The game will consist of a player first making a bet then getting random numbers. The goal is to get 
 * 		as close to the number 21 as possible without going over. The player can continue to get as many random numbers as they want but if those numbers added together 
 * 		excede 21 you bust and automatically lose your money. If you dont bust the turn then goes the the other players if there are some. After that the turn goes to the 
 * 		dealer who will play against each player, the dealer will get two cards automatically then based on your cards decide wether to get a third card. If the dealer busts 
 * 		the user automatically wins their bet. If the user does not bust whoever has the highest total amount between the current player and user wins. After dealer has 
 * 		played all of the players the players will get the opting to cash out or play again. Which will start another round.
 *
 * Input: Starting Amount, Bet Amount, Yes/No on Random Number, Yes/No on Play Again?
 *
 * Output: Randomly generated number for player, Randomly generated number for dealer, If player wins or loses their bet, Player money after each round 
 *
 * ********************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

/************************************************
 *
 * Function: check_input_int()
 *
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *		to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *		the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value 
 *		the user is told their input is bad and is re prompted		
 *
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *
 * Pre-Conditions: string message: telling what to input
 * 		   string input: empty variable that will get input value
 *
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is returned from function
 *
 * *********************************************/

int check_input_int(string message ) {

	string input;
	bool bad_input;	
	int int_input;
	do{
	
		bad_input = false;

		cout << message;
		
		cin >> input;
	
		for( int i = 0; i < input.size(); i++) {
		
			if( !(input.at(i) >= '0' && input.at(i) <= '9')) {

				cout << "You must input a postive integer" << endl;
				
				bad_input = true;
				break;	
			}
		}
	}while(bad_input);

	int_input = atoi(input.c_str());	

	return int_input;
}

/************************************************
 *
 * Function: check_input_go_again()
 *
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *		to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. After making
 *		sure the input is an int it checks that the int is withing the range 1-2  In the case that it is the loop is broken and the string is converted 
 *		into an int and the int value is returned from the function. If the string contains any non int value the user is told their input is bad and is 
 *		re prompted. 	
 *
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *
 * Pre-Conditions: string message: telling what to input
 * 		   string input: empty variable that will get input value
 *
 * Post-Conditions: int int_input: correctly input string that is withing the required 1-2 range that was converted to an int and is returned from function
 *
 * *********************************************/

int check_input_go_again(string message ) {
	string input;
	bool bad_input;	
	int int_input;
	do{
		int_input = 0;
		
		bad_input = false;

		cout << message;
		
		cin >> input;
	
		for( int i = 0; i < input.size(); i++) {
		
			if( !(input.at(i) >= '0' && input.at(i) <= '9')) {

				cout << "You must input a postive integer" << endl;
				
				bad_input = true;
				break;	
			}
		

			else if( !(input.at(i) == '1' || input.at(i) == '2'))  {

				cout << "You must input a 1 or a 2." << endl;

				bad_input = true; 
				break;	
			}
		}

	
	}while(bad_input);

	int_input = atoi(input.c_str());	

	return int_input;

}

/************************************************
 *
 * Function: check_bet()
 *
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *		to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *		the loop is broken and the string is converted into an int. If the string contains any non int value the user is told their input is bad and is re prompted.	
 *		The int value which is now considered the users "bet" is checked to see if it is greater than that users "money" value. If it is the user is re prompted for 
 *		a new bet. If the bet is less than the users total money the bet is accepted and returned from the function.
 *
 * Parameters: user money value, message saying what to input
 *
 * Pre-Conditions: user money: greater than 0
 *
 * Post-Conditions: user bet: user bet is valid int value smaller than total money
 *
 * *********************************************/

int check_bet(int player_money, string message) {

	string input;
	bool bad_input;	
	int int_input;

	if( player_money == 0) { 
	
		int_input = 0;
		return int_input;
		 
	}

	else {

		do{
			int_input = 0;
		
			bad_input = false;

			cout << message;
		
			cin >> input;
	
			for( int i = 0; i < input.size(); i++) {
		
				if( !(input.at(i) >= '0' && input.at(i) <= '9')) {

					cout << "You must input a postive integer" << endl;
				
					bad_input = true;
					break;	
				}
			}
	
			int_input = atoi(input.c_str());	

			if(int_input > player_money) {

				cout << "Sorry that is more than you have right now." << endl;
				bad_input = true; 	
			}
			else if(int_input == 0) {

				cout << "If you want to play you have to bet." << endl;
				bad_input = true;
			}
		}while(bad_input);

	}

	return int_input;

	
}

/************************************************
 *
 * Function: player_game() 
 *
 * Description: This fuction is used to get and return a players black jack number. It first checks to see if the players bet is equal to zero if it is the players black jack
 * 		number is set to 0 and the function returns the black jack number value. If the players bet is anything greater than 0 the player is given a randomly generarted 
 * 		number and the players black jack number is set as that value. The function prints the value to the screen and asks the player if they would like to get another
 * 		random number that will be added to the black jack number. This is done in a loop so the player can continue to add to their total until they choose to stop or 
 * 		they bust. A bust is when the users total numbet excedes 21, if that happens the function tell the player that they busted then sets their black jack number to 
 * 		0 and returns the balck jack number. If the player chooses to exit the loop their current black jack value will be returned from the function.
 *
 * Parameters: player black jack number, message telling user what to input, players already defined bet
 *
 * Pre-Conditions: -Player bet is greater than 0
 * 		   -Player black jack number
 * 		   -Message telling what to input 
 * 		   -Defined player bet 	
 *          
 * Post-Conditions: Player black jack number value is returned 
 *            
 **********************************************/

int player_game(int black_jack_num, string message, int player_bet)  {

	
	black_jack_num = 0;
	int result;

	if(player_bet == 0) {

		black_jack_num = 0;
		return black_jack_num;
	}

	else {
		do {
			int x = 0;
			x += ((rand()%11)+1); 
			black_jack_num += x;
				

			cout << "You get: "<< x << endl;
			cout << "Your total is: " << black_jack_num << endl;
			if(black_jack_num > 21) {


				cout << "Bust!" << endl;
				black_jack_num = 0;
			}

			if(black_jack_num == 0) {
				break;
			}

			else {

				message  = "\n Would you like to get another random number? Enter \"1\" for yes and \"2\" for no: ";
				result = check_input_go_again(message);
			}

		}while(result == 1);
	}
	return black_jack_num;
}

/************************************************
 *  
 * Function: dealer_game()
 *    
 * Description: This function generates a black jack number for the players opponent the "Dealer" the dealer. The function first checks to see if all the players 
 * 		black jack numbes are equal to 0 in which case the function returns 0. If any players values are greater than 0 the user first gets two random numbers
 * 		between 1-11 that are added together and are placed in the dealers black jack number if that number is greater than 21 the dealer busts and and the dealer 
 * 		black jack number is set to 0. If the dealer number is less than 21 the dealer then checks to see if any players blak jack numbers are greater than 21 
 * 		if they are then the deaeler gets another random number which is added to the dealers black jack number total. The total is checked again to see if it is 
 * 		over 21, if it is not the dealers black jack number is returned from the function.
 *      
 * Parameters: All players black jack numbers, dealers undefined black jack number
 *        
 * Pre-Conditions: Player black jack numbers are defined
 *          
 * Post-Conditions: Dealers black jack number is defined
 *            
 ***********************************************/

int dealer_game(int player_1_bjack_num, int player_2_bjack_num, int player_3_bjack_num, int player_4_bjack_num, int dealer_bjack_num) {

	if(player_1_bjack_num == 0 && player_2_bjack_num == 0 && player_3_bjack_num == 0 && player_4_bjack_num == 0) {

		return 0; //  no need for dealer to play if all players busted or didnt bet
	}

	else {

		dealer_bjack_num = 0;

		dealer_bjack_num += ((rand()%11)+1);

		dealer_bjack_num += ((rand()%11)+1);
	

		cout << "Dealer gets: " << dealer_bjack_num << endl;

		if(dealer_bjack_num > 21) {

			cout << "Dealer busts!" << endl;

			dealer_bjack_num = 0;
		
		}

		else {
			// This is a standard black jack strategy for the dealer if any players have above a 17 the dealer chooses another number
			if(player_1_bjack_num >= 17 || player_2_bjack_num >= 17 || player_3_bjack_num >= 17 || player_4_bjack_num >= 17) {

				cout << "Dealer takes another number." << endl;

				dealer_bjack_num += ((rand()%11)+1);
			
				if(dealer_bjack_num > 21) {
				
					cout << "Dealer busts!" << endl;

					dealer_bjack_num  = 0;
				}
				else {
			
					cout << "Dealer gets: " << dealer_bjack_num << endl;
				}
			}



		}
	}
	cout << "\n" << "\n" << endl;
	return dealer_bjack_num;
}	

/************************************************
 *
 * Function: player_round()
 *    
 * Description: Function checks to see if player has money, if not the player does not get a black jack number, if player has money play_game funcion is run to 
 * 		to get a black jack number the black jack number is returned 
 *      
 * Parameters: player money, black jack number, string message, player bet, current player playing "x"
 *        
 * Pre-Conditions: player has money, player bet is undefined, current players turn
 *          
 * Post-Conditions: Player assinged black jack number value
 *            
 ************************************************/

int player_round ( int player_money, int black_jack_num, string message, int player_bet, int x) {

	if (player_money == 0) {
	// Player cannot play if they have no money to bet, this checks they have money before giving them turn
		return 0;
	}

	else {
		cout << "Player " << x << "'s turn." << endl;
		black_jack_num = player_game(black_jack_num, message, player_bet);

		
	}

	
	return black_jack_num;
}

/************************************************
 *
 * Function: check_player_round() 
 *
 * Description: Function checks to see if during a players turn they bust and if so their bet is subtracted from their total money and their adjusted total money is resturned
 *
 * Parameters: player black jack num, player bet, player money
 *
 * Pre-Conditions: Defined player black jack num, Defined player bet, Defined player money
 *
 * Post-Conditions: Adjusted player money if player black jack number equaled 0
 *
 * *********************************************/

int check_player_round(int player_bjack_num, int player_bet, int player_money) {

	if(player_bjack_num == 0) {

		player_money = (player_money - player_bet);
		//cout << player_money << endl;
	}
	
	return player_money;

}

/************************************************
 *
 * Function: change_bet()
 *
 * Description: If players black jack number is equal to zero their bet is given a value of zero and is then returned
 *
 * Parameters: player black jack number, player bet
 *
 * Pre-Conditions: defined player black jack number, defined player bet
 *
 * Post-Conditions: player bet has value of 0
 *
 * *********************************************/

int change_bet(int player_bjack_num, int player_bet) {

	if(player_bjack_num == 0) { 

		player_bet = 0;
	}
	
	return player_bet;
}

/************************************************
 *
 * Function: dealear_round() 
 *
 * Description: This function takes the dealers black jack number and a plaers black jack number and compares them. If the players number is greater than the dealers 
 * 		number the player wins their bet and their bet amount is added to their total money amount. If the players black jack number is less than the dealer 
 * 		the player loses their bet and their bet amount is subtracted from their total money. If the players number is the same the player keeps their bet. 
 * 		the players adjusted total money is returned from the function
 *
 * Parameters: player bet player black jack number, player money, dealer black jack number
 *
 * Pre-Conditions:defined player bet, defined player black jack number, defined player money, defined dealer black jack number, current player "x"
 *
 * Post-Conditions: Current player adjusted money
 *
 * *********************************************/

int dealer_round(int player_bet, int player_bjack_num, int player_money,  int dealer_bjack_num, int x) {

	if (player_bet == 0) {

		return player_money;
	}

	else {
		
		if(player_bjack_num > dealer_bjack_num) {

				cout << "Player " << x << " wins their bet!" << endl;

				player_money += player_bet;

				cout << "Player " << x << " now has: " << player_money << endl;

				cout << "\n" << "\n" << endl;	
		}

		else if(player_bjack_num < dealer_bjack_num) {

				cout << "Player " << x << " loses their bet!" << endl;

				player_money -= player_bet;

				cout << "Player " << x << " now has: " << player_money << endl;

				cout << "\n" << "\n" << endl;	

		}
		
		else { 

			cout << "Player " << x << " ties with dealer." << endl;

			cout << "Player " << x << " keeps their bet." << endl;

			cout << "\n" << "\n" << endl;

		}

	}

	return player_money;	
}

/************************************************
 *
 * Function: play_again()
 *
 * Description: This function asks players if they want to play another round of black jack. It first checks to see if a players money is 0 if it is the player is 
 * 		already out and does not need to be asked. If the players money is more than 0 the game prints their money amount and then asks if they want to play 
 * 		again if they enter yes nothing happens, if they enter 2 they "cash out" and that players money is set to 0. The players money is then returned from 
 * 		the function.
 *
 * Parameters: player money, current player "x"
 *
 * Pre-Conditions: player money is defined, current player is defined 
 *
 * Post-Conditions: adjusted player money is returned
 *
 * *********************************************/

int play_again(int player_money, int x) {
	
	int input;	
	
	if(player_money == 0) {
		//cout << player_money << endl;
		return 0;
	}

	else {
		cout << "Player " << x << " you have: " << player_money << endl;
		// checks for 1 or 2
		input = check_input_go_again("If you would like to play again enter \"1\" if you would like to cash out enter \"2\": ");
		
		if(!(input == 1)) { // 1 is go again so anything else is cash out

		cout << "Player " << x << " cashs out." << endl;
		
		player_money= 0; //this is done so that the program knows how many players are still playing and how many cashed out
		
		}
	}
	cout << "\n" << endl;
	return player_money;
}

	
int main () {
	
	string message; // This will be used if the check_input_int function as the message that will be printed telling the user what to input.
	
	srand(time(NULL)); // Used for seeding random number generator	
	int player_amount; // will be used to determine length of for loops
	//used as numbers players get in black jack game
	int player_1_bjack_num = 0;			

	int player_2_bjack_num = 0;

	int player_3_bjack_num = 0;

	int player_4_bjack_num = 0;
	//used to store amount of money each player wants to start with/has
	int player_1_money = 0;
	
	int player_2_money = 0;
													//All variables are inialized at 0 because they may be called without
													//being given a new value so better to know what is in them and work
													//around that then having garbage			
	int player_3_money = 0;
	
	int player_4_money = 0;
	//bet each player makes
	int player_1_bet = 0;
	
	int player_2_bet = 0;
														
	int player_3_bet = 0;				

	int player_4_bet = 0;				
	//general variable to get black jack number
	int black_jack_num = 0;

	int dealer_bjack_num = 0;

	//bool x;

	player_amount = check_input_int("Please input the number of players playing (1-4): "); // how many player are playing
	
	for(int x = 1; x <= player_amount; x++) { // loop to get each players starting amount, this is only asked once not in loop
		
		if( x == 1){
			player_1_money = check_input_int("Player 1, input how much would you like to start with: ");

		}

		else if (x == 2){
			player_2_money = check_input_int("Player 2, input how much would you like to start with: ");

		}

		else if( x == 3){
			player_3_money = check_input_int("Player 3, input how much would you like to start with: ");

		}

		else if( x == 4){
			player_4_money = check_input_int("Player 4, input how much would you like to start with: ");

		}
	}

	do {
	/*
  	Use do while loop here because if you dont players would be asked if they want to play without even playing
	once and the game should always run once that is why do while is used. Players are asked if they want to play 
	after first game
	*/
		for(int x =1; x <= player_amount; x++) { // loop to get each players bet
		
			cout << "\n" << endl;		

			if( x == 1){
				player_1_bet = check_bet(player_1_money, "Player 1, input how much would you like to bet: ");
				
			}

			else if (x == 2){
				player_2_bet = check_bet(player_2_money, "Player 2, input how much would you like to bet: ");
	
			}
	
			else if( x == 3){
				player_3_bet = check_bet(player_3_money, "Player 3, input how much would you like to bet: ");

			}

			else if( x == 4){
				player_4_bet = check_bet(player_4_money, "Player 4, input how much would you like to bet: ");

	
			}
		}

		for(int x = 1; x <= player_amount; x++) { 
		/* This is where the player gets there black jack number the game also checks
 		   to see if the player busts in which case the players bet is set to 0 and 
		   player money is subtracted
		*/
			if( x == 1) {

				cout << "\n" << endl;
				//player one gets black jack number				
				player_1_bjack_num = player_round(player_1_money, black_jack_num, message, player_1_bet, x);
				// game checks if player black jack number is 0 if yes player bet is subtracted from player money
				player_1_money = check_player_round(player_1_bjack_num, player_1_bet, player_1_money);
				// player bet is set to 0 if player black jack number equals 0
				player_1_bet = change_bet(player_1_bjack_num, player_1_bet);
			}

			else if(x ==2) {

				cout << "\n" << endl;
	
				player_2_bjack_num = player_round(player_2_money, black_jack_num, message, player_2_bet, x);

				player_2_money = check_player_round(player_2_bjack_num, player_2_bet, player_2_money);

				player_2_bet = change_bet(player_2_bjack_num, player_2_bet);
			
			
			}

			else if(x == 3) {

				cout << "\n" << endl;
	
				player_3_bjack_num = player_round(player_3_money, black_jack_num, message, player_3_bet, x);

				player_3_money = check_player_round(player_3_bjack_num, player_3_bet, player_3_money);

				player_3_bet = change_bet(player_3_bjack_num, player_3_bet);
		
				
			}

			else {
	
				cout << "\n" << endl;
			
				player_4_bjack_num = player_round(player_4_money, black_jack_num, message, player_4_bet, x);
	
				player_4_money = check_player_round(player_4_bjack_num, player_4_bet, player_4_money);

				player_4_bet = change_bet(player_4_bjack_num, player_4_bet);
			
			}
		

			cout <<  "\n" << "\n" << endl;
				
		}

		
		//Dealer gets their black jack number

		dealer_bjack_num = dealer_game(player_1_bjack_num, player_2_bjack_num, player_3_bjack_num, player_4_bjack_num, dealer_bjack_num);
		
		for(int x = 1; x <=player_amount; x++) { 
		
			if( x == 1) {
				// the dealer and players black jack numbers are compared and based on who wins the players money is adjusted
				player_1_money = dealer_round(player_1_bet, player_1_bjack_num, player_1_money, dealer_bjack_num, x);

			}

			else if( x == 2) {

				player_2_money = dealer_round(player_2_bet, player_2_bjack_num, player_2_money, dealer_bjack_num, x);

			}

			else if( x == 3) {

				player_3_money = dealer_round(player_3_bet, player_3_bjack_num, player_3_money, dealer_bjack_num, x);

			}

			else {

				player_4_money = dealer_round(player_4_bet, player_4_bjack_num, player_4_money, dealer_bjack_num, x);

			}

		}
		for( int i = 1; i <= player_amount; i++) { //each player is asked if they want to play again or not

			if(i == 1) {

				//cout << "Player " << i << endl;

				player_1_money = play_again(player_1_money, i);

			}

			else if(i == 2) {

				//cout << "Player " << i << endl;

				player_2_money = play_again(player_2_money, i);

			}

			else if(i == 3) {

				//cout << "Player " << i << endl;

				player_3_money = play_again(player_3_money, i);

			}

			else if(i == 4) {

				//cout << "Player " << i << endl;

				player_4_money = play_again(player_4_money, i);

			}
		}

	}while(player_1_money > 0 || player_2_money > 0 || player_3_money > 0 || player_4_money > 0); // game checks if any players wanted to go agaoin by
												     // seing if their money is greater than 0

	return 0; // go beavs!
}






