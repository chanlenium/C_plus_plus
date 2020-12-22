/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include<iostream>
#include"Utils.h"
#include"Marks.h"
using namespace std;

void markstat() {
	struct Assesent as;	// declare Assesent type variable "as"

	cout << "Mark Stats Program." << endl << endl;
	cout << "Please enter the assessment name: ";
	getAssenmentName(as.name);	// call function to get assement name
		
	cout << "Please enter the number of marks: ";
	as.noMarks = getIntInRange(MIN_NO_MARKS, MAX_NO_MARKS);	// call function to get number between min and max

	cout << "Please enter " << as.noMarks << " marks (" << MIN_MARK << "<=Mark<=" << MAX_MARK << "):" << endl;
	for (int i = 1; i <= as.noMarks; i++) {
		cout << i << "> ";
		as.marks[i - 1] = getIntInRange(MIN_MARK, MAX_MARK);	// call function to get number between min and max
	}
	cout << "Thank you..." << endl;
	cout << "Assessment Name: " << as.name << endl;
	cout << "----------------" << endl;

	//sort()
	selectSort(as.marks, as.noMarks);	// call function to sort the marks from user prompt

	//display();
	display(&as.noMarks, as.marks);	// call function to display results
}