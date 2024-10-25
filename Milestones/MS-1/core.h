/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Tejasvi Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// This function get the integer value followed by newline char
int inputInt(void);

//This function get the positive integer as a value
int  inputIntPositive(void);

//This function get the positive integer as a value within the boundaries of upper and lower limits
int inputIntRange(int lowerBound, int upperBound);

// This function get the input of a character out of a specific range
char inputCharOption(const char* charList);

// This function get the input of some string of a certain length 
void inputCString(char* cString, int minLength, int maxLength);

//This function display the array of ten digits as a formatted phone number
void displayFormattedPhone(const char* phoneNumber);
