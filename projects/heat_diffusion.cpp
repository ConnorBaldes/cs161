/****************************************
 *Program Filename: ASSIGNMENT_SIX.cpp
 *
 * Author: Connor Baldes
 *
 * Date: 3-17-2019
 *
 * Description: This program allows a user to simulate the heat diffusion of a 1 or 2 dimensional objject over a set period of time intervals. The user inputs vaules
 * 		such as density, heat capacity of the object, thermal conductivity, and initial temp that are all used to calcuate the heat diffusion 
 * 		over the object. The user will be shown the resulst after entering in the values listed and will then be asked if they want to go again  
 *
 * Input:1-d: 
 * 	 wire, thermal conductivity, heat capacity, density, width, width sections, left constant temp, right constant temp, initial temp, time
 * 	 time intervals
 *
 * 	 2-d:
 *	plate, thermal conductivity, heat capacity, density, width, height, width section, height sections, top row const temp, bottom row cost temp, 
 *	left col const temp, right col const temp, time, time intervals, initial temp
 *
 * Output: table of values showing heat diffusion throughout time intervals. 
 *
 * ************************************/


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string> 
#include <iomanip>
#include <cmath>

using namespace std;

/************************************************
 *  
 * Function: check_wire_plate()
 *    
 * Description: Checks to see wether the user input said they wanted to simulated using a wire or a plate by using the strcmp function to 
				see which one they chose and places a value corresponding to the results in wire_plate
 *         
 * Parameters: place holder array storing wire or plate, refrence to wire_plate int  
 *    
 * Pre-Conditions: - phold must contain array of characters
 *                 
 *             
 * Post-Conditions: wire_array will hold variable corrsponding to wire of plate
 *                
*********************************************/
void  check_wire_plate(char *phold, int &wire_plate) {

	char wire[] = "wire";
	char plate[] = "plate";

	if( strcmp(wire,phold) == 0) {

		wire_plate = 1;
	}
	else if( strcmp(plate,phold) == 0) {

		wire_plate = 2;
	}
	else {
		wire_plate = 0;
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

		if( input.at(0) == 0) {

			bad_input = true;
			cout << "You must input a number greater than 0. " << endl;
		}

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
* Function: check_input_go_again()
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
* Post-Conditions: int int_input_go_again: correctly input string that was converted to an int and is input in variable
*
*********************************************/
void check_input_go_again(int &int_input) {
 
	string input;
	bool bad_input;
	int count;
	do{
		count = 0;
		
		bad_input = false;
		
		cout <<"Woud you like to go again? You will be able to change lenght, sections, time, andd temperatures. But not  u,k, r,  or c as those are command line arguments." << endl;
			cout << "To go again enter 1 to end enter 2: ";
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
 * Function: check_input_float_command()
 *    
 * Description: Checks to see if an input in command line argument is string is a valid integer, it does this by looping through all the characters in the string and 
				checks the ascii valueto see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer.
				In that case thethe loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non
				int value the user is told their input is bad and is re prompted
 *         
 * Parameters: phold, float val
 *    
 * Pre-Conditions: phold contains array of characters
 *                 
 *             
 * Post-Conditions: command line arguments are placed int float variables
 *                
*********************************************/
void check_input_float_command(char *phold, float &float_val) {

	bool bad_input = false;

	int count = 0;

	for( int i = 0; i < strlen(phold); i++) {

		if( !((phold[i] >= '0' && phold[i] <= '9') || phold[i] == '.')) {

			bad_input = true;
			break;
		}
		if(phold[i] == '.') {

			count += 1;
		}

		if(count > 1) {

			bad_input = true;
			break;
		}
	}

	if(bad_input == true) {
		
		float_val = 0;
	}

	else {
		float_val = atof(phold);
	}
}

/************************************************
 *  
 * Function: command_check()
 *    
 * Description: Checks to see if all command line arguments are valid and if so returns a value of true. If any command like argumentws are 
				invalid a value of false is returned. 
 *         
 * Parameters: argc, argv, phold, wire_plate, rho, thermal conductivity, heat capacity, check
 *    
 * Pre-Conditions: all values are entered into function
 *             
 * Post-Conditions: int int_input: true or false is returned based on if command line arguments were valid. 
 *                
*********************************************/
bool command_check(int argc, char **argv, char *phold, int &wire_plate, float &rho, float &therm_cond, float &heat_cap, bool &check) {
	

	for(int i = 0; i < argc; i++) {

		for(int j = 0; j < strlen(argv[i]); j++) {

			if(argv[i][j] == '-') {
			
				if(argv[i][j+1] == 'u') {

					 phold = argv[i +1];
					 check_wire_plate(phold, wire_plate);
				}				
	
				if(argv[i][j+1] == 'r') {

					 phold = argv[i +1];
					 check_input_float_command(phold, rho);
				}	
				if(argv[i][j+1] == 'k') {

					 phold = argv[i +1];
					 check_input_float_command(phold, therm_cond);
				}

				if(argv[i][j+1] == 'c') {

					 phold = argv[i +1];
					 check_input_float_command(phold, heat_cap);
				}
			}
		}
	}

	if( wire_plate == 0 || rho == 0 || therm_cond == 0 || heat_cap == 0) {

		cout << "You did not enter the program correctly, the format is: ASSIGNMENT_SIX -u \"wire\" or \"plate\" -r (Value for density) " << endl;
	       	cout << " -k (Value for thermal conductivity) -c (Heat capacity of material) " << endl;
		check = false;
	}

	else { 

		check = true;


	}
	return check;
}
	
/**************************************

deletes 2 d arrays

***************************************/

void delete_2_d( float **&two_d_array, int a) {
	
	for(int i = 0; i < a; i++) {
		
		delete [] two_d_array[i];
	}
	
	delete [] two_d_array;
}

/**************************************

deletes 3 d arrays

***************************************/


void delete_3_d( float ***&three_d_array, int a, int b) {
	
	for(int i = 0; i < a; i++) {
		
		for( int j = 0; j < b; j++) {
			
			delete [] three_d_array[i][j];
		}
	}
	for(int i = 0; i < a; i++) {
		
		delete [] three_d_array[i];
	}
	delete [] three_d_array;
}


/************************************************************************************************************************
 * Wire Functions
*************************************************************************************************************************/
/************************************************
 *  
 * Function: get_values_wire()
 *    
 * Description: Gets all the required values for the simulation to be run 1 dimensionally
 *         
 * Parameters: widht, width sections, change in width, change in time, time intervals, time, right temp, left temp, initial temp
 
 * Pre-Conditions: all the variables must already exist 
 *             
 * Post-Conditions: variables are filled with values 
 *                
*********************************************/
void get_values_wire(float &width, int &width_sections, float &delta_width, float &delta_time, int &time_intervals, float &time, float &right_temp, float &left_temp, float &initial_temp) {

	cout << endl;
	
	check_input_float("Please input the lenght of the wire you are testing: ", width);

	check_input_int("Please input the number sections you want to use: ", width_sections);

	check_input_int("Please input the number of time intervals you want to use: ",time_intervals);		
	
	check_input_float("Please input the time of the simulation: ", time);

	check_input_float("Please enter the right constant temperature: ", right_temp);

	check_input_float("Please enter the left constant temperature: ", left_temp);

	check_input_float("Please enter the initial temperature: ",initial_temp);

	delta_width = (width / width_sections);

	delta_time = (time / time_intervals);

	cout << endl;


}

/************************************************
 *  
 * Function: wire_stability()
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
bool wire_stability(float therm_cond, float time, int time_intervals, float width, int width_sections, float heat_cap, float rho)  {


	float stability = 0;

	stability = (((therm_cond) * (time / time_intervals)) / ( pow((width / width_sections), 2) * heat_cap * rho));

	if(stability < .5) {

		return true;
	}
	
	return false;
	

}

/************************************************
 *  
 * Function: time_array_setup()
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
void time_array_setup( float * &time_array, float &width, int &width_sections, int &time_intervals, float &time, float &initial_temp, float &right_temp, float &left_temp, float &rho, float &therm_cond, float &heat_cap, float &delta_width, float &delta_time) {

	time_array = new float[time_intervals + 1];
	
	for(int i = 0; i < time_intervals; i++) {
		
		if( i == 0) {
			
			time_array[i] = 0;
		}
	
		else {
			
		time_array[i] = 0 + (delta_time * i);
		
		}
	}
}
/************************************************
 *  
 * Function: wire_array_setup()
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
void wire_array_setup( float ** &wire_array, float &width, int &width_sections, int &time_intervals, float &time, float &initial_temp, float &right_temp, float &left_temp, float &rho, float &therm_cond, float &heat_cap, float &delta_width, float &delta_time) {
	
	wire_array = new float*[time_intervals + 1];

	for( int i = 0; i < time_intervals; i ++) {
		
		wire_array[i] = new float[width_sections];

	}
	
	for(int i = 0; i < time_intervals; i++) {
		for( int j = 0; j < width_sections; j++) {
			
			if( j == 0) {
				
				wire_array[i][j] = 0;
			}
			else {
				
				wire_array[i][j] = (wire_array[i][j-1] + delta_width);
			}
		}
	}
}
/************************************************
 *  
 * Function: wire_heat_array_setup()
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
void wire_heat_array_setup( float ** &wire_heat_array, float &width, int &width_sections, int &time_intervals, float &time, float &initial_temp, float &right_temp, float &left_temp, float &rho, float &therm_cond, float &heat_cap, float &delta_width, float &delta_time) {
	
	wire_heat_array = new float*[time_intervals + 1];

	for( int i = 0; i < time_intervals; i ++) {
		
		wire_heat_array[i] = new float[width_sections];

	}
	
	for(int i = 0; i < time_intervals; i++) {
		for( int j = 0; j < width_sections; j++) {
			
			if( j == 0) {
				
				wire_heat_array[i][j] = left_temp;
			}
			else if( j == (width_sections - 1)) {
				
				wire_heat_array[i][j] = right_temp;
			}
				
			else {
				
				wire_heat_array[i][j] = initial_temp;
			}
		}
	}

}
/************************************************
 *  
 * Function: get_wire_array()
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
void get_wire_array( float ** &wire_array, float ** &wire_heat_array, float * &time_array, float &width, int &width_sections, int &time_intervals, float &time, float &initial_temp, float &right_temp, float &left_temp, float &rho, float &therm_cond, float &heat_cap, float &delta_width, float &delta_time) {


	wire_array_setup(wire_array, width, width_sections, time_intervals, time, initial_temp, right_temp, left_temp, rho, therm_cond, heat_cap, delta_width, delta_time);
	
	wire_heat_array_setup(wire_heat_array, width, width_sections, time_intervals, time, initial_temp, right_temp, left_temp, rho, therm_cond, heat_cap, delta_width, delta_time);

	time_array_setup(time_array, width, width_sections, time_intervals, time, initial_temp, right_temp, left_temp, rho, therm_cond, heat_cap, delta_width, delta_time);


	for(int i = 0; i < time_intervals; i++) {
		
		
		for(int j = 0; j < width_sections - 1; j++) {
			
			
			 wire_heat_array[i][j] =  ((((therm_cond * delta_time) / ((heat_cap * rho) * (delta_width * delta_width))) * (((wire_array[i][j+1]) - (2 * wire_array[i][j]) + (wire_array[i][j])) + wire_array[i][j])));
		
		}
		
		wire_heat_array[i][0] = left_temp;
		
		wire_heat_array[i][width_sections - 1] = right_temp;
		
	}


}
/************************************************
 *  
 * Function: print_wire_heat_array()
 *    
 * Description: Checks to see if  valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the  int and the int value is returned from the function. 
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. 
 *    
 * Pre-Conditions: 
 *                 int_float: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/
void print_wire_heat_array( float **wire_heat_array, int time_intervals, int width_sections) {
	
	for( int i = 0; i < time_intervals; i++) {
		
		for( int j = 0; j < width_sections; j++) {
			
			cout << setprecision(6);
			
			cout << setw(4) << wire_heat_array[i][j] << "  ";
		}
		cout << endl;
	}
}
/************************************************
 *  
 * Function: run_wire()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping  the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In 
 *              the loop is broken and the string is int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/
int run_wire(float &width, int &width_sections,int &time_intervals, float &time,float initial_temp, float &right_temp, float &left_temp, float &rho, float &therm_cond, float &heat_cap, float &delta_width, float &delta_time ) {
	//cout << "go beavs";
	
	float **wire_array = NULL;
	
	float **wire_heat_array = NULL;
	
	float *time_array = NULL;

	bool check_stability;
	
	get_values_wire(width, width_sections, delta_width, delta_time, time_intervals, time, right_temp, left_temp, initial_temp); 

	check_stability = wire_stability( therm_cond, time, time_intervals, width, width_sections, heat_cap, rho); 
	//cout << "go beavs" << endl;
	
	if(check_stability == false) {
		cout << "The data you entered was unstable. " << endl;
		return 0;
	}
	//cout << "go beavs" << endl;
	get_wire_array( wire_array, wire_heat_array, time_array, width, width_sections, time_intervals, time, initial_temp, right_temp, left_temp, rho, therm_cond, heat_cap, delta_width, delta_time);
	
	print_wire_heat_array(wire_heat_array, time_intervals, width_sections);
	
	delete_2_d(wire_array, (time_intervals + 1));
	
	delete_2_d(wire_heat_array, (time_intervals + 1));
	
	delete [] time_array;

	return 0;
	
}

/********************************************************************************************************************
 * End of Wire functions
*********************************************************************************************************************/





/********************************************************************************************************************
 * Plate Functions 
 ********************************************************************************************************************/
 /************************************************
 *  
 * Function: get_values_plate()
 *    
 * Description: Gets the values required to run the simulation of a 2 dimendional object
 *         
 * Parameters: int wire_plate, float &width, float &height, int &height_sections, int &width_sections, int &time_intervals, float &rho, float &therm_cond, float &heat_cap, float &time, float &initial_temp, float &left_temp, float &right_temp,  float &left_const_col, float &right_const_col, float &top_const_row, float &bottom_const_row, float &delta_height, float &delta_width, float &delta_time
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_float: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/
void get_values_plate(int wire_plate, float &width, float &height, int &height_sections, int &width_sections, int &time_intervals, float &rho, float &therm_cond, float &heat_cap, float &time, float &initial_temp, float &left_temp, float &right_temp,  float &left_const_col, float &right_const_col, float &top_const_row, float &bottom_const_row, float &delta_height, float &delta_width, float &delta_time) {

	cout << endl;
	
	check_input_float("Please input the width of the plate you are testing: ", width);

	check_input_float("Please input the height of the plate you are testing: ", height);

	check_input_int("Please input the number sections you want to use across the width: ", width_sections);
	
	check_input_int("Please input the number sections you want to use across the height: ", height_sections);

	check_input_int("Please input the number of time intervals you want to use: ",time_intervals);		
	
	check_input_float("Please input the time of the simulation: ", time);

	check_input_float("Please enter the right column constant temperature: ", right_const_col);

	check_input_float("Please enter the left column constant temperature: ", left_const_col);
	
	check_input_float("Please enter the top row constant temperature: ", top_const_row);

	check_input_float("Please enter the bottom row constant temperature: ", bottom_const_row);

	check_input_float("Please enter the initial temperature: ",initial_temp);

	delta_width = (width / width_sections);
	
	delta_height = (height / height_sections);

	delta_time = (time / time_intervals);

	cout << endl;
}

/************************************************
 *  
 * Function: plate_stability()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string 
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: float therm_cond, float delta_width, float delta_height, float delta_time, float heat_cap, float rho
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_float: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/
bool plate_stability(float therm_cond, float delta_width, float delta_height, float delta_time, float heat_cap, float rho)  {
	


	float stability = 0;

	stability = ((delta_width * delta_height * rho * heat_cap) / (4 * therm_cond));

	if( delta_time <= stability) {

		return true;
	}
	
	return false;
	

}

/************************************************
 *  
 * Function: plate_heat_array_setup()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. In that case the
 *              the loop is broken and the string is converted into an int and the int value is returned from the function. If the string contains any non int value
 *              the user is told their input is bad and is re prompted
 *         
 * Parameters: float *** &plate_heat_array, int &width_sections, int &height_sections,  int &time_intervals, float &initial_temp, float &right_const_col, float &left_const_col, float &top_const_row, float &bottom_const_row
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_float: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/
void plate_heat_array_setup( float *** &plate_heat_array, int &width_sections, int &height_sections,  int &time_intervals, float &initial_temp, float &right_const_col, float &left_const_col, float &top_const_row, float &bottom_const_row) {
	
	plate_heat_array = new float**[time_intervals + 1];

	for( int i = 0; i < time_intervals; i ++) {
		
		plate_heat_array[i] = new float*[width_sections + 1];
		
		for(int j = 0; j < width_sections; j++) {
				
			plate_heat_array[i][j] = new float[height_sections + 1];
		}
	}

	for(int i = 0; i < time_intervals; i++) {
		
		for( int j = 0; j < width_sections; j++) {
			
				for(int z = 0; z < height_sections; z++) {
					
				if( j == 0) {
				
					plate_heat_array[i][j][z] = top_const_row;
				}
				else if( j == width_sections-1) {

					plate_heat_array[i][j][z] = bottom_const_row;
				}
				
				else if( j != 0 && j != (width_sections - 1)) {
					
					plate_heat_array[i][j][0] = left_const_col;
					
					plate_heat_array[i][j][height_sections - 1] = right_const_col;
				
				}
				else {
					
					plate_heat_array[i][j][z] = initial_temp;
				}
			}
		}
	}
}

/************************************************
 *  
 * Function: get_plate_array()
 *    
 * Description: Checks to see if an input string is a valid integer, it does this by looping through all the characters in the string and checks the ascii value
 *              to see if it is between the value '0' and '9'. If all the characters in the string are in that range the string is a valid integer. 
 *             
 *         
 * Parameters: float *** &plate_heat_array, int &width_sections, int &height_sections,  int &time_intervals, float &initial_temp, float &right_const_col, float &left_const_col, float &top_const_row, float &bottom_const_row
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_float: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/
void get_plate_array(float *** &plate_heat_array, float * &time_array, float &width, float &height, int &height_sections, int &width_sections, int &time_intervals, float &rho, float &therm_cond, float &heat_cap, float &time, float &initial_temp, float &left_const_col, float &right_const_col, float &top_const_row, float &bottom_const_row, float &delta_height, float &delta_width, float &delta_time) {

	plate_heat_array_setup( plate_heat_array, width_sections, height_sections, time_intervals, initial_temp, right_const_col, left_const_col, top_const_row, bottom_const_row);
		
	//time_array_setup( time_array, width, width_sections, time_intervals, time, initial_temp, right_temp, left_temp, rho, herm_cond, heat_cap, delta_width, delta_time);

	for( int i = 0; i < time_intervals; i++) {
		
		for( int j = 1; j < width_sections - 2; j++) {
			
			for( int z = 1; z < height_sections - 2; z++) {
				
				plate_heat_array[i][j][z] = ((((therm_cond * delta_time) / (heat_cap * rho)) * ((plate_heat_array[i][j][z+1] - (2 * plate_heat_array[i][j][z]) + plate_heat_array[i][j][z-1] + plate_heat_array[i][j+1][z] - (2 * plate_heat_array[i][j][z]) + plate_heat_array[i][j+1][z]) / (pow(delta_width, 2)))) + plate_heat_array[i][j][z]);
			}
		}
	}
}

/************************************************
 *  
 * Function: print_plate_heat_array()
 *    
 * Description: Prints the heat array 
 *         
 * Parameters: wire heat array, time intervals, width sections, height sections 
 *    
 * Pre-Conditions: all variables are valid
 *             
 * Post-Conditions: printed array
 *                
*********************************************/
void print_plate_heat_array( float ***wire_heat_array, int time_intervals, int width_sections, int height_sections) {
	
	for( int i = 0; i < time_intervals; i++) {
		
		for( int j = 0; j < width_sections; j++) {
			
			for( int z = 0; z < height_sections; z++) {
				
				cout << setprecision(6);
			
				cout << setw(4) << wire_heat_array[i][j][z] << "  ";
			}
			cout << endl;
		}
		cout << "\n" << endl;
	}
}

/************************************************
 *  
 * Function: run_plate()
 *    
 * Description: Runs all the functions required to print the plate diffusion to the screem 
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: string message: telling what to input
 *                 int_float: the integer that the input will be placed in
 *             
 * Post-Conditions: int int_input: correctly input string that was converted to an int and is input in variable
 *                
*********************************************/
int run_plate(int wire_plate, float &width, float &height, int &height_sections, int &width_sections, int &time_intervals, float &rho, float &therm_cond, float &heat_cap, float &time, float &initial_temp, float &left_temp, float &right_temp,  float &left_const_col, float &right_const_col, float &top_const_row, float &bottom_const_row, float &delta_height, float &delta_width, float &delta_time) {

	float ***plate_heat_array = NULL;
	
	float *time_array = NULL;

	bool check_stability;

	get_values_plate( wire_plate, width, height, height_sections, width_sections, time_intervals, rho, therm_cond, heat_cap, time, initial_temp, left_temp, right_temp, left_const_col, right_const_col, top_const_row, bottom_const_row, delta_height, delta_width, delta_time);
	
	check_stability = plate_stability(therm_cond, delta_width, delta_height, delta_time, heat_cap, rho);
	
	if( check_stability == false) {
		
		cout << endl << "The data you entered was not stable. " << endl;
		return 0;
	}
	get_plate_array(plate_heat_array, time_array,  width, height, height_sections, width_sections, time_intervals, rho, therm_cond, heat_cap, time, initial_temp, left_const_col, right_const_col, top_const_row, bottom_const_row, delta_height, delta_width, delta_time);
	
	print_plate_heat_array( plate_heat_array, time_intervals, width_sections, height_sections);
	
	delete_3_d(plate_heat_array, (time_intervals), (width_sections));

	delete [] time_array;
	
	return 0;
}

/********************************************************************************************************************
 * End of Plate functions
*********************************************************************************************************************/

/************************************************
 *  
 * Function: sire_wire_plare()
 *    
 * Description: runs simulation for wire or plate. calls all other functions pertaining to either wire or plate 
 *         
 * Parameters: string message: a message that is strored in a string. The message will tell the user what it is they are inputing
 *    
 * Pre-Conditions: all variables have been declared in main 
 *             
 * Post-Conditions: 1 or 2 d array is printed to the screen 
 *                
*********************************************/
void sim_wire_plate(int wire_plate, float &width, float &height, int &height_sections, int &width_sections, int &time_intervals, float &rho, float &therm_cond, float &heat_cap, float &time, float &initial_temp, float &left_temp, float &right_temp,  float &left_const_col, float &right_const_col, float &top_const_row, float &bottom_const_row, float &delta_height, float &delta_width, float &delta_time) {

	if(wire_plate == 1) {

		//run_wire();
		run_wire(width, width_sections, time_intervals, time, initial_temp, right_temp, left_temp, rho, therm_cond, heat_cap, delta_width, delta_time );
	}	
	else{
		//run_plate();
		run_plate(wire_plate, width, height, height_sections, width_sections, time_intervals, rho, therm_cond, heat_cap, time, initial_temp, left_temp, right_temp,  left_const_col, right_const_col, top_const_row, bottom_const_row, delta_height, delta_width, delta_time);
	}
}


int main(int argc, char *argv[]) {

	int go_beavs;
	
	do{

		bool check;

		char *phold;

		int wire_plate;

		float width = 0;

		float height = 0;

		int height_sections = 0;

		int width_sections = 0;
	
		int time_intervals = 0;

		float rho = 0;
	
		float therm_cond = 0;
	
		float heat_cap = 0;	

		float time = 0;

		float initial_temp = 0;

		float left_temp =  0;

		float right_temp = 0;

		float left_const_col = 0;

		float right_const_col = 0;
	
		float top_const_row = 0;

		float bottom_const_row = 0;

		float delta_height = 0;

		float delta_width = 0;

		float delta_time = 0;
	
	
		string message;

		command_check(argc, argv, phold, wire_plate, rho, therm_cond, heat_cap, check);

		if(check == false) {
			return 0;
		}
	
	
		sim_wire_plate(wire_plate, width, height, height_sections, width_sections, time_intervals, rho, therm_cond, heat_cap, time, initial_temp, left_temp, right_temp,  left_const_col, right_const_col, top_const_row, bottom_const_row, delta_height, delta_width, delta_time);

		check_input_go_again(go_beavs);

	}while(go_beavs == 1);

	return 0;
}
