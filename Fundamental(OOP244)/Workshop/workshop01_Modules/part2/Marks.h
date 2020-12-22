/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef DCOH_MARKS_H
#define DCOH_MARKS_H

#define MIN_NO_MARKS 5
#define MAX_NO_MARKS 50

#define MIN_MARK 0
#define MAX_MARK 100

struct Assesent
{
	char name[41];
	int noMarks;
	int marks[50];
};
void markstat();

#endif



/*
namespace dcoh
{
	struct Assesent
	{
		char name[41];
		int noMarks;
		int mark;
	};
	void markstat();
}
#endif
*/