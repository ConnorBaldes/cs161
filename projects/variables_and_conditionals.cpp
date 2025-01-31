/**************************
 *
 * Program Filename: ASSIGNMENT_TWO.cpp
 *
 * Author: Connor Baldes
 *
 * Date: 1-17-2019
 *
 * Description: This program is a text adventure that uses "if" and "else" statements that provide the user of the program with different 
 * paths in the adventure. The user will be prompted to enter a number which will be used to determine the path the user has chosen to take.
 * several of the paths will have nested statements that will allow the user to continue to choose different paths that lead to different outcomes 
 * as they move throught the adventure.
 *
 * Input: The user will input numbers either "1" or "2" to decide different paths they would like to take in an adventure game that lead to different outcomes.
 *
 * Output: Depending on the input given by the user different text will be output to the screen telling the user the results of the decison the user is making in game.
 *
 * ************************/

#include <iostream> //library for input (cin) and output (cout)
#include <ctime>	//include to allow time() to be used 
#include <cstdlib>	//include to allow rand() and srand() to be used 


using namespace std;

int main() {
	
	int x = 1;
	while(x == 1) {
	int coin;        //variable to hold our random integer
	srand(time(NULL));      //seeds random number generator. Done only once.
	coin = rand()%2; // chooses a number between 0 and 1 that will we used to determine a path in the adventure.
	//cout << num << endl; used to make sure rand function was producing proper numbers
	// showing the user what this program is so they know what to input
	cout << "\n" <<  "Hello this is an adventure game. You get to choose your own adventure by" << endl;
	cout << "choosing from different path options that have different outcomes." <<"\n"<< endl;
	char num;
	int loop;		//the loop variable will be used at the end to determine if the user wants to replay the game via a loop
	int path;		// path will be used as the variable to determine what path the user will take
			// The while loop is used to ask the user if they want to go through
				// the adventure again 
		cout << "You are an explorer and you are searching for an Incan temple in south america." << endl;
		cout << "You must first decide if you are going to take a boat down the";
		cout << "river or treck through the jungle. \nIf you would like to treck through the jungle enter \"1\" if you would like to go down the river enter \"2\"" << "\n" << endl;
		cout << "Enter choice: ";
		cin >> path; // First user input for adventure game should be "1' or "2"

		if(path == 1) {
			cout << "\n" << "You chose to enter the jungle. As you are making your way through the trees you come across a cave " << endl;
			cout << "and think that if the cave has an exit you may be able to move faster throught it but the cave could also end " << endl;
			cout << "in a dead end or worse... To decide what to do you flip a coin, heads means go into the cave and tails means " << endl;
			cout << "continue through the jungle." << "\n" << endl;
			cout << "Enter any number to flip the coin: ";
			cin >> num;

			// the coin will be decided by a random generator and the executed if statement will be decided by the num that is between 0 and 1
			if(coin == 0) { 
				cout << "\n" << "The coin landed on heads! Looks like you are headed into the cave. As you make your way through the cave " << endl;
				cout << "you start to lose your way and eventually get completley lost. After several weeks of being stuck in the cave " << endl;
				cout << "you die of starvation." << endl;
			}
		
			else if(coin == 1) {
				cout << "\n" << "The coin landed on tails! Looks like you are continuing through the jungle. After continuing towalking through the jungle for " << endl;
				cout << "some time you come across a ravine with a river below. You think that you may be able to jump over the ravine to the other side " << endl;
				cout << "but it is a long jump and a long way down. If you want to try and jump across the ravine enter \"1\" if you want to try and find " <<endl;
				cout << "another way down enter \"2\": ";
				cin >> path;
				
				if(path == 1) {
					cout <<"\n" << "When you tried to jump the ravine you tripped on a rock and plummeted to your death. " << endl;
				}
			
				else if(path == 2) {
					cout << "\n" << "You chose to find another way. As you were looking you found a bridge and on the other side of that " << endl;
					cout << "bridge was the Incan temple! You see though that the bridge does not look sturdy, you must choose whether" << endl;
					cout << "you want to cross the bridge to the temple or continue to look for another way. If you would like to cross" << endl;
					cout << "bridge press \"1\" if you want to look for another way press \"2\": ";
					cin >> path;
					
					if(path == 1) {
						cout << "\n" << "You made it across the bridge and into the Incan temple, Congratulations you win!" << endl;
					}
			
					else if(path == 2) {
						cout << "\n" << "While you were searching for a new way you got bitten by a snake and died." << endl;
					}

					//Else statements are incase at any point user gives bad input, if they do they will be told their input is bad and the program will end
					else {
						cout << "\n" << "You must input a \"1\" or a \"2\"." << endl;
						return 0; // return 0 will end the program if bad input is given. Prevents crashes
					}
				}

				else {
					cout << "\n" << "You must input a \"1\" or a \"2\"." << endl;
					return 0;
				}
 
			}
		

			else {
				cout << "\n" << "You must input a \"1\" or \"2\"." << endl;
				return 0;
			}


		}
		// This is the start of the second initial path that the user can take in the story
		else if(path == 2) { 
			cout << "\n" << "You chose to take a boat down the river. Afte awhile you see that you are approaching a fork in the river, you must choose " << endl;
			cout << "wether you want to go left at the fork or right. If you want to go left enter \"1\" if you want to go right enter \"2\": ";
			cin >> path;

			if(path == 1) {
				cout << "\n" << "You chose to go left at the fork. As you continue you see that you are about to go over some rapids. The rapids look dangerous" << endl;
				cout << "but you think you might be able to manage them. If you would like to try and make it through the rapids press \"1\" if you want" << endl;
				cout << "to steer the boat to shore and continue on foot press \"2\": ";
				cin >> path;
					
				if(path == 1) {
					cout << "\n" << "You made it through the rapids but in the distance you here a weird noise. It may be nothing but then again" << endl;
					cout << "who knows? If you would like to keep going and take your chances enter \"1\" if you want to turn back enter \"2\": ";
					cin >> path;
								
					if(path == 1) {
						cout << "\n" <<  "The noise was a waterfall and you plummeted to your death." << endl;
					}

					else if(path == 2) {
						cout << "\n" <<  "The current was to strong for you to turn baxk. You were pulled over a waterfall and fell plummeted to your death" << endl;
					}
				
					else {
						cout << "\n" << "You must input a \"1\" or a \"2\"." << endl;
						return 0;
					}

				 } 

				else if(path == 2) { 
					cout << "\n" << "You chose to go ashore, when you got there you were mauled by a tiger and eaten. " << endl;
				}

				else {
					cout << "\n" << "You must enter a \"1\" or a \"2\"." << endl;
					return 0;
				}			
			}	
		
			else if(path == 2) {
				cout << "\n" << "You chose to go right. As you were floating you were attacked by a crocodile and eaten. " << endl;
			} 

			else {
				cout << "\n" << "You must input a \"1\" or a \"2\"." << endl;
				return 0;
			}
		}

		else { 
			cout << "\n" << "You must input a \"1\" or a \"2\"." << endl;
			return 0;
		}
		
		cout << "\n" << "Would you like to play again? Enter \"1\" if yes and \"2\" if no: ";
		cin >> loop;	/* I could have just used the actual variable used for the loop which is "x" but I was afraid this 
				could cause an issue so I just created a second variable */
		if(loop == 1) {
			cout << "\n" << endl;
			x = 1;
		}

		else if(loop == 2) {
			cout << "\n" << "Game over." << endl;
			x = 0;
		}

		else {	
			cout << "\n" << "Invalid input. Game over." << endl;
		}
	}


	return 0;
} 



