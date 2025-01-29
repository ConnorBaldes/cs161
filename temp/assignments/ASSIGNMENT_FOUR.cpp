/*******************************
 *Program Filename: ASSIGNMENT_FOUR.cpp
 *
 * Author: Connor Baldes
 *
 * Date: 2-16-2019
 *
 * Description: This program allows a user to create a business trip expense report. The program will first prompt the user for the number of days spent on 
 * 		the trip, then will ask the departure time on the first day of the trip and departure time on the last day. Then will ask amount that the 
 * 		airfare was, then if there were any conference or seminar registration fees, then if they rented a car or took a taxi, the hotel expense
 * 		for each day, and finally the amount they spent on meals each day. The program will use that inforation to calculate the amount that the
 * 		person who went on the trip will be reimbursed for that trip. Also the total amount spent on the trip. 
 *
 * Input: Days spent on trip, departure time first day arrival time last day, airfare amount, car rented or taxi taken, hotel expense, meal expense
 *
 * Output: Total Reinbursement amount, Total amount spent 
 *
 * ******************************/


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;



/************************************************
 *  
 * Function: get_total_back()
 *    
 * Description: Add variable amount to total reinbursment amount
 *         
 * Parameters: float addition variable, float total reinbursment variable
 *    
 * Pre-Conditions: addition float
 *                 total reinbursment float
 *             
 * Post-Conditions: addition float added to total reinbursment float
 *                
*********************************************/


void get_total_back(float &addition, float &total_reinbursment ) { 

	total_reinbursment += addition;

}

/************************************************
 *  
 * Function: get_total_expense()
 *    
 * Description: Add variable amount to total  amount
 *         
 * Parameters: float addition variable, float expense variable
 *    
 * Pre-Conditions: addition float
 *                 total expense float
 *             
 * Post-Conditions: addition float added to total expense float
 *                
*********************************************/


void get_total_expense(float &addition, float &total_expense) {

	total_expense += addition;
}

/************************************************
 *  
 * Function: check_breakfast_back()
 *    
 * Description: Takes the value that user input for breakfast amount and checks if it is over 9.00 in which case it adds 9.00 to total reinbrusment amount. If it is 
 * 		not over 9.00 it adds the breakfast amount to total reinbursment amount. It then adds breakfast amount to total expense amount
 *         
 * Parameters: float breakfast expense, float total expense, float total reinbursment 
 *    
 * Pre-Conditions: breakfast expense float
 * 		   total expense float
 * 		   total reinbursment float
 *             
 * Post-Conditions: 9.00 or breakfast expense is added to total reinbursment, breakfast_expense is added to total expense 
 *                
*********************************************/


void get_breakfast_back( float &breakfast_expense, float &total_expense, float &total_reinbursment) {

	if(breakfast_expense > 9.00) {

		total_reinbursment += 9.00;
	}
	else {

		total_reinbursment += breakfast_expense;
	}
	
	total_expense += breakfast_expense;
}
	

/************************************************
 *  
 * Function: check_lunch_back()
 *    
 * Description: Takes the value that user input for lunch amount and checks if it is over 12.00 in which case it adds 12.00 to total reinbrusment amount. If it is 
 * 		not over 12.00 it adds the lunch amount to total reinbursment amount. It then adds lunch amount to total expense amount
 *         
 * Parameters: float lunch expense, float total expense, float total reinbursment 
 *    
 * Pre-Conditions: lunch expense float
 * 		   total expense float
 * 		   total reinbursment float
 *             
 * Post-Conditions: 12.00 or lunch expense is added to total reinbursment, lunch_expense is added to total expense 
 *                
*********************************************/


void get_lunch_back( float &lunch_expense, float &total_expense, float &total_reinbursment) {

	if(lunch_expense > 12.00) {

		total_reinbursment += 12.00;
	}
	else {

		total_reinbursment += lunch_expense;
	}
	
	total_expense += lunch_expense;
}

/************************************************
 *  
 * Function: check_dinner_back()
 *    
 * Description: Takes the value that user input for dinner amount and checks if it is over 16.00 in which case it adds 16.00 to total reinbrusment amount. If it is 
 * 		not over 16.00 it adds the dinner amount to total reinbursment amount. It then adds dinner amount to total expense amount
 *         
 * Parameters: float dinner expense, float total expense, float total reinbursment 
 *    
 * Pre-Conditions: dinner expense float
 * 		   total expense float
 * 		   total reinbursment float
 *             
 * Post-Conditions: 16.00 or dinner expense is added to total reinbursment, dinner_expense is added to total expense 
 *                
*********************************************/


void get_dinner_back( float &dinner_expense, float &total_expense, float &total_reinbursment) {

	if(dinner_expense > 16.00) {

		total_reinbursment += 16.00;
	}
	else {

		total_reinbursment += dinner_expense;
	}
	
	total_expense += dinner_expense;
}

/************************************************
 *  
 * Function: get_car_back()
 *    
 * Description: Using the type of car that the user input, and that cars correspinding rental fee, and gas fee the function adds the total of those two things to 
 * 		total expenses. The function then uses the type of car  the user chose to add rental fee and gas fee to reinbursment amount by using the information
 * 		the company gives for reinbursment. 
 *         
 * Parameters: trip days, car type, rental fee, gas fee, miles driven, total expense, total reinbursment
 *    
 * Pre-Conditions: trip days greater than 0
 * 		   car type between 1 and 4
 * 		   rental fee greater than 0
 * 		   gas fee greater than 0
 * 		   miles driven greater than 0
 *
 *             
 * Post-Conditions: rental fee and gas fee added to total expense
 * 		    calculation for amount to be reinbursed added to total reinbursment
 *                
*********************************************/


void get_car_back( int &trip_days, int &car_type, float &rental_fee, float &gas_fee, float &miles_driven, float &total_expense, float &total_reinbursment) {

	total_expense += (rental_fee + gas_fee);


	if(car_type == 1) {

		total_reinbursment += (( 20 * trip_days) + (.24 * miles_driven));
	}

	else if(car_type == 2) {

 		total_reinbursment += (( 25 * trip_days) + (.27 * miles_driven));

	}

	else if(car_type == 3) { 
		
		total_reinbursment += (( 30 * trip_days) + (.32 * miles_driven));
	}

	else {
	
		total_reinbursment += (( 50 * trip_days) + (.45 * miles_driven));

	}
}

/************************************************
 *  
 * Function:get_parking_back()
 *    
 * Description: takes the amount input for parking fees each day and first adds it to total expenses. Then if the amount if above 6.00, 6.00 is
 * 		added to total expenses. If it is less parking fees amount is added to totat expenses.
 *         
 * Parameters: parking fees, total expenses, total reinbursment
 *    
 * Pre-Conditions: parking fee amount is more than 0
 * 		   total expenses 
 * 		   total reinbursment	
 *             
 * Post-Conditions: total expense gets parking fees added to it and total reinbursment gets either 6.00 or parking fees added to it
 *                
*********************************************/


void get_parking_back(float &parking_fees, float &total_expense, float &total_reinbursment) {

	total_expense += parking_fees;

	if(parking_fees > 6.00) {

		total_reinbursment += 6.00;
	}
	
	else {

		total_reinbursment += parking_fees;

	}
}

/************************************************
 *  
 * Function:get_taxi_back()
 *    
 * Description: takes the amount input for taxi fees each day and first adds it to total expenses. Then if the amount if above 10.00, 10.00 is
 * 		added to total expenses. If it is less taxi fees amount is added to totat expenses.
 *         
 * Parameters: taxi fees, total expenses, total reinbursment
 *    
 * Pre-Conditions: taxi fee amount is more than 0
 * 		   total expenses 
 * 		   total reinbursment	
 *             
 * Post-Conditions: total expense gets taxi fees added to it and total reinbursment gets either 10.00 or taxi fees added to it
 *                
*********************************************/


void get_taxi_back(float &taxi_fees, float &total_expense, float &total_reinbursment) {

	total_expense += taxi_fees;

	if(taxi_fees > 10.00) {


		total_reinbursment += 10.00;
	}

	else {

		total_reinbursment += taxi_fees;

	}
}

/************************************************
 *  
 * Function:get_hotel_back()
 *    
 * Description: takes the amount input for hotel fees each day and first adds it to total expenses. Then if the amount if above 90.00, 90.00 is
 * 		added to total expenses. If it is less hotel fees amount is added to totat expenses.
 *         
 * Parameters: hotel fees, total expenses, total reinbursment
 *    
 * Pre-Conditions: hotel fee amount is more than 0
 * 		   total expenses 
 * 		   total reinbursment	
 *             
 * Post-Conditions: total expense gets hotel fees added to it and total reinbursment gets either 90.00 or hotel fees added to it
 *                
*********************************************/


void get_hotel_back(float &hotel_expense, float &total_expense, float &total_reinbursment) {

	total_expense += hotel_expense;

	if(hotel_expense > 90.00) {
	
		total_reinbursment += 90.00;
	}

	else {

		total_reinbursment += hotel_expense;

	}

} 
/************************************************
 *  
 * Function: check_input_int()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void check_input_int(string message, int &int_input) {

	string input;
	bool bad_input;
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

}

/************************************************
 *  
 * Function: check_input_float()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_float: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void check_input_float(string message, float &float_input) {

	string input;
	bool bad_input;
	int count;

	do{
	
		count = 0;
		
		bad_input = false;

		cout << message;

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !((input.at(i) >= '0' && input.at(i) <= '9') || input.at(i) =='.')) {

				cout << "You must input a positive float value Ex: 4.5" << endl;

				bad_input = true;				

				break;
			}

			if( input.at(i) == '.') {

				count += 1;
			}

			if(count > 1) {

				cout << "You must input a postive float value" << endl;

				bad_input = true;
				break;
			}
		
		}

	}while(bad_input);

	float_input = atof(input.c_str());

}

/************************************************
 *  
 * Function: check_input_flaot_return()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


float check_input_float_return( int &trip_nights) {

	string input;
	bool bad_input;
	int count;
	float float_input;

	do{
	
		count = 0;
		
		bad_input = false;

		cout << "Enter hotel fee for night " << trip_nights << " in $: ";

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !((input.at(i) >= '0' && input.at(i) <= '9') || input.at(i) =='.')) {

				cout << "You must input a positive float value Ex: 4.5" << endl;

				bad_input = true;

				break;
			}

			if( input.at(i) == '.') {

				count += 1;
			}

			if(count > 1) {

				cout << "You must input a postive float value" << endl;

				bad_input = true;
				break;
			}
		
		}

	}while(bad_input);

	float_input = atof(input.c_str());

	return float_input;
}


/************************************************
 *  
 * Function: check_input_days()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void check_input_days(string message, int &trip_days) {

	string input;
	bool bad_input;
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
	

			trip_days = atoi(input.c_str());

			if( trip_days < 1) {
			
				cout << "You must input a number greater than zero" << endl;

				bad_input = true;
			}

		}
		
	}while(bad_input);

}
/************************************************
 *  
 * Function: check_input_depart_arrival()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void check_input_depart_arrival(string message, float &depart_arrival) {

	
	string input;
	bool bad_input;
	int count;

	do{

		count = 0;		

		bad_input = false;

		cout << message;

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !((input.at(i) >= '0' && input.at(i) <= '9') || input.at(i) =='.')) {

				cout << "You must input a positive float value Ex: 4.6" << endl;

				bad_input = true;
				break;
			}
			
			

			if( input.at(i) == '.') {

				count += 1;
			}

			if(count > 1) {

				cout << "You must input a postive float value Ex: 4.5" << endl;

				bad_input = true;
				break;
			}

		}

		depart_arrival = atof(input.c_str());

		if(!( depart_arrival >= 0.00 && depart_arrival < 23.60)) {
			
			cout << "You must input a time betwwen 0.00 (12 am) and 23.59 (11:59 pm)" << endl;

			bad_input = true;
		}


	}while(bad_input);

}
/************************************************
 *  
 * Function: check_input_car_taxi()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/



void check_input_car_taxi(string message, int &int_input) {

	string input;
	bool bad_input;
	int count;
	do{
		count = 0;
			
		bad_input = false;

		cout << message;

		cin >> input;

		for( int i = 0; i < input.size(); i++) {
		
			count += 1;

			if( !(input.at(i) >= '1' && input.at(i) <= '2')) {

				cout << "You must input either a 1 or a 2." << endl;

				bad_input = true;
				break;
			}

			if(count > 1 )  {

				cout << "You must input either a 1 or a 2." << endl;

				bad_input = true;
				break;
			}
		
		}
	}while(bad_input);

	int_input = atoi(input.c_str());

}

/************************************************
 *  
 * Function: check_input_car_type()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/

void check_input_car_type(int &int_input) {

	string input;
	bool bad_input;
	int count = 0;

	do{

		bad_input = false;

		cout << "1. Sedan " << "\n" << "2. SUV " << "\n" << "3. Van " << "\n" << "4. Convertible " << "\n" << "Enter your car type: ";

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !(input.at(i) >= '1' && input.at(i) <= '4')) {

				cout << "You must input a number 1-4." << endl;

				bad_input = true;
				break;
			}

			if(count > 1 )  {

				cout << "You must input a single number." << endl;

				bad_input = true;
				break;
			}
		}
	
	}while(bad_input);

	int_input = atoi(input.c_str());

}

/************************************************
 *  
 * Function: check_input_parking_fees()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


float check_input_parking_fees( int trip_day) {

	string input;
	bool bad_input;
	int count;
	float float_input = 0;
	
	do{
		count = 0;
		
		bad_input = false;

		cout << "Enter parking fee for day " <<  trip_day << " in $: ";

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !((input.at(i) >= '0' && input.at(i) <= '9') || input.at(i) =='.')) {

				cout << "You must input a positive float value Ex: 4.5" << endl;
				
				bad_input = true;
				break;
			}

			if( input.at(i) == '.') {

				count += 1;
			}

			if(count > 1) {

				cout << "You must input a postive float value" << endl;

				bad_input = true;
				break;
			}
		}
	

	}while(bad_input);

	float_input = atof(input.c_str());

	return float_input;
}

/************************************************
 *  
 * Function: ccheck_input_taxi_fees()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


float check_input_taxi_fees( int trip_day) {

	string input;
	bool bad_input;
	int count;
	float float_input = 0;
	
	do{
		count = 0;

		bad_input = false;

		cout << "Enter taxi fee for day " <<  trip_day << " in $: ";

		cin >> input;

		for( int i = 0; i < input.size(); i++) {

			if( !((input.at(i) >= '0' && input.at(i) <= '9') || input.at(i) =='.')) {

				cout << "You must input a positive float value Ex: 4.5" << endl;

				
				bad_input = true;
				break;
			}


			if( input.at(i) == '.') {

				count += 1;
			}

			if(count > 1) {

				cout << "You must input a postive float value" << endl;

				bad_input = true;
				break;
			}
		}
		

	}while(bad_input);

	float_input = atof(input.c_str());

	return float_input;
}


/************************************************
 *  
 * Function: breakfast()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/

void breakfast( float &breakfast_expense, float &total_expense, float &total_reinbursment) {

	check_input_float("Enter breakfast fee in, $: ", breakfast_expense); 
	get_breakfast_back(breakfast_expense, total_expense, total_reinbursment );
				
	cout << "Lunch is not allowed as an expense. " << endl;

	cout << "Dinner is not allowed as an expense. " << endl;

}

/************************************************
 *  
 * Function: breakfast_lunch()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void breakfast_lunch( float &breakfast_expense, float &lunch_expense, float &total_expense, float &total_reinbursment) {
					
	check_input_float("Enter breakfast fee, in $: ", breakfast_expense);
	get_breakfast_back( breakfast_expense, total_expense, total_reinbursment);
				
	check_input_float("Enter lunch fee in, $: ", lunch_expense); 
	get_lunch_back( lunch_expense, total_expense, total_reinbursment);
				
	cout << "Dinner is not allowed as an expense. " << endl;


}

/************************************************
 *  
 * Function: breakfast_lunch_dinner()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: Donald trump is a fucking idiot who is going to destroy our country.
 *                
*********************************************/


void breakfast_lunch_dinner( float &breakfast_expense, float &lunch_expense, float &dinner_expense, float &total_expense, float &total_reinbursment) {

	check_input_float("Enter breakfast fee in, $: ", breakfast_expense); 
	get_breakfast_back(breakfast_expense, total_expense, total_reinbursment );
				
	check_input_float("Enter lunch fee in, $: ", lunch_expense); 
	get_lunch_back( lunch_expense, total_expense, total_reinbursment);
			
	check_input_float("Enter dinner fee in, $: ", dinner_expense); 
	get_dinner_back(dinner_expense, total_expense, total_reinbursment );

}

/************************************************
 *  
 * Function: dinner()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void dinner( float &dinner_expense, float &total_expense, float &total_reinbursment) {

	cout << "Breakfast is not allowed as an expense. " << endl;

	cout << "Lunch is not allowed as an expense. " << endl;

	check_input_float("Enter dinner fee, in $: ", dinner_expense);
	get_dinner_back( dinner_expense, total_expense, total_reinbursment);

}

/************************************************
 *  
 * Function: lunch_dinner()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void lunch_dinner( float &lunch_expense, float &dinner_expense, float &total_expense, float &total_reinbursment) {

	cout << "Breakfast is not allowed as an expense. " << endl;

	check_input_float("Enter Lunch fee, in $: ", lunch_expense);
	get_lunch_back( lunch_expense, total_expense, total_reinbursment);
	
	check_input_float("Enter dinner fee in, $: ", dinner_expense); 
	get_dinner_back( dinner_expense, total_expense, total_reinbursment);

}

/************************************************
 *  
 * Function: meal_day_one()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void meal_day_one(float &breakfast_expense, float &lunch_expense, float &dinner_expense, float &departure_time, float &total_expense, float &total_reinbursment) {

	cout << "Day 1, " << endl;

	if( departure_time > 18.00) {

		cout << "No meals are allowed as an expense." << endl;
	} 
			
	else if( departure_time > 12.00) {
		
		dinner(dinner_expense, total_expense, total_reinbursment);
	}

	else if( departure_time > 7.00) {
				
		lunch_dinner(lunch_expense, dinner_expense, total_expense, total_reinbursment);
	}
			
	else if( departure_time < 7.00) {

		breakfast_lunch_dinner(breakfast_expense, lunch_expense, dinner_expense, total_expense, total_reinbursment);
	}

}

/************************************************
 *  
 * Function: meal_last_day()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void meal_last_day(float &breakfast_expense, float &lunch_expense, float &dinner_expense, float &arrival_time, int &i, float &total_expense, float &total_reinbursment) {

	cout << "Day " << i << ", " << endl;

	if( arrival_time > 19.00) {

		breakfast_lunch_dinner(breakfast_expense, lunch_expense, dinner_expense, total_expense, total_reinbursment);
				
	} 
			
	else if( arrival_time > 12.00) {
		
					
		breakfast_lunch(breakfast_expense, lunch_expense, total_expense, total_reinbursment);

	}

	else if( arrival_time > 8.00) {
				
		breakfast(breakfast_expense, total_expense, total_reinbursment);
	}
			
	else if( arrival_time < 8.00) {

		cout << "No meals are allowed as an expense. " << endl;
	}			

}

/************************************************
 *  
 * Function: check_input_meal_expense()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void check_input_meal_expense(int &trip_days, float &departure_time, float &arrival_time,  float &breakfast_expense, float &lunch_expense, float &dinner_expense, float &total_expense, float &total_reinbursment) { 
	

	for(int i = 1; i <= trip_days; i++) {

		breakfast_expense = 0;
		lunch_expense = 0;
		dinner_expense = 0;
		
		cout << "\n";
	
		if( i == 1) {
		
			meal_day_one(breakfast_expense, lunch_expense, dinner_expense, departure_time, total_expense, total_reinbursment);	

		}

		else if( i == trip_days) { 
		
			meal_last_day(breakfast_expense, lunch_expense, dinner_expense, arrival_time, i, total_expense, total_reinbursment);	
	
		}

		else { 
			cout << "Day " << i << ", " << endl;

			breakfast_lunch_dinner(breakfast_expense, lunch_expense, dinner_expense, total_expense, total_reinbursment);
				
		}	
			
	
	}

}

/************************************************
 *  
 * Function: get_trip_info()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/

void get_trip_info(int &trip_days, float &depart_time, float &arrival_time, float &airfare_amount, float &conf_amount, float &total_reinbursment, float &total_expense) {

	
	check_input_days("Enter the number of days on your trip: ", trip_days);

	check_input_depart_arrival("Enter the time you departed for your trip: ", depart_time);

	check_input_depart_arrival("Enter the time you arrived after your trip: ", arrival_time);

	check_input_float("Enter total airfare cost, in $: ", airfare_amount);

	get_total_back(airfare_amount, total_reinbursment);
	get_total_expense(airfare_amount, total_expense);

	check_input_float("Enter total conference or seminar registration fees, in $: ", conf_amount);

	get_total_back(conf_amount, total_reinbursment);
	get_total_expense(conf_amount, total_expense);


	
}


/************************************************
 *  
 * Function: get_car_info()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/



void get_car_info(int &trip_days, int &car_type, float &rental_fee, float &gas_fee, float &miles_driven, float &parking_fees, float &total_expense, float &total_reinbursment) {

	check_input_float("Enter total spent on the rental car in $: ", rental_fee);

	check_input_float("Enter your total gas fee spent in $: ", gas_fee);

	check_input_car_type(car_type);
	
	check_input_float("Enter your total miles driven: ", miles_driven);

	for(int i =1; i <= trip_days; i++) {
		
		parking_fees = 0;
		parking_fees = check_input_parking_fees(i);  
		get_parking_back(parking_fees, total_expense, total_reinbursment);

		// for each day add amount aloud for parking
	}
	get_car_back(trip_days, car_type, rental_fee, gas_fee, miles_driven, total_expense, total_reinbursment);
}

/************************************************
 *  
 * Function: get_taxi_info()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void get_taxi_info( int &trip_days, float &taxi_fees, float &total_expense, float &total_reinbursment) {

	for(int i = 1; i <= trip_days; i++) {
		// add variable and change so that it recieves returned amount so that daily amount can be cheched and totalled before added to total amount	
		taxi_fees = 0;
		taxi_fees = check_input_taxi_fees(i);
		get_taxi_back(taxi_fees, total_expense, total_reinbursment);
	}

}


/************************************************
 *  
 * Function: get_hotel_info()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/


void get_hotel_info( int &trip_days, float &hotel_expense, float &total_expense, float &total_reinbursment) {

	for(int i = 1; i <= (trip_days - 1); i++) {
		// add variable and change so that it recieves returned amount so that daily amount can be cheched and totalled before added to total amount	
		hotel_expense = 0;
		hotel_expense = check_input_float_return(i);
		get_hotel_back(hotel_expense, total_expense, total_reinbursment);
	}

}

/*void get_food_info( int &trip_days, float &meal_expense, float &departure_time, float &arrival_time) {

	for(int i = 1; i <= (trip_days); i++) {
		// add variable and change so that it recieves returned amount so that daily amount can be cheched and totalled before added to total amount	
		meal_expense += check_input_float_return(i);
	}

}
*/


/************************************************
 *  
 * Function: car_or_taxi()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_input: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/



void car_or_taxi(int &car_taxi, int &trip_days, int &car_type, float &rental_fee, float &gas_fee, float &miles_driven, float &parking_fees, float &taxi_fees, float &total_expense, float &total_reinbursment) {

	check_input_car_taxi("Did you 1: rent a car or 2: use a taxi for your trip? Enter a 1 or 2: ", car_taxi);

	if( car_taxi == 1) {

		get_car_info( trip_days, car_type, rental_fee, gas_fee, miles_driven, parking_fees, total_expense, total_reinbursment);
	}

	else  {

		get_taxi_info(trip_days, taxi_fees, total_expense, total_reinbursment);
	}

}


int main() {
	//this assignment was ass but its all good because go beavs. 
	int go_beavs;

	do{
		//all variables declared inside of loop so if user goes again numbers reset
		string message;

		int trip_days = 0;

		float depart_time = 0;

		float arrival_time = 0;

		float airfare_amount = 0;

		float conf_fees = 0;

		int car_taxi;

		int car_type = 0;

		float rental_fee = 0;

		float gas_fee = 0;

		float miles_driven = 0;

		float parking_fees = 0;

		float taxi_fees= 0;

		float hotel_expense = 0;

		float meal_expense = 0;

		float total_reinbursment = 0;

		float total_expense = 0;
	
		float breakfast_expense;

		float lunch_expense;

		float dinner_expense;	

		cout << "\n";	
		//gets info on trip such as trip days, departure and arrival time, and conference fees and calculates the amount put into totals for those variables
		get_trip_info(trip_days, depart_time, arrival_time, airfare_amount, conf_fees, total_reinbursment, total_expense);
	
		cout << "\n";	
		//checks if car or taxi then depending on which one will calculate totals for either car fees or taxi fees to be added to totals
		car_or_taxi(car_taxi, trip_days, car_type, rental_fee, gas_fee, miles_driven, parking_fees, taxi_fees, total_expense, total_reinbursment);
	
		cout << "\n";
		// gets hotel expenses and adds them to totals 
		get_hotel_info(trip_days, hotel_expense, total_expense, total_reinbursment);

		cout << "\n";	
		//get meal expenses and adds them to totals
		check_input_meal_expense(trip_days, depart_time, arrival_time, breakfast_expense, lunch_expense, dinner_expense, total_expense, total_reinbursment); 
	
		cout << "\n";
		//total of all expenses entered
		cout << "Total expense: " << total_expense << endl;

		cout << "\n";		
		// total amount reinbursed to person who went on trip 
		cout << "Total Reinbursment: " << total_reinbursment << endl;

		cout << "\n" << "\n" << endl;
		//checks to see if user wants to go again. Re used car or taxi function with different message because the same task that was needed is performed
		check_input_car_taxi("Would you like make another expense report? If yes enter 1 if no enter 2: ", go_beavs);

		}while(go_beavs == 1); 
		

		return 0;
}
