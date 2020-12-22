/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

//#ifndef NAMESPACE_HEADERFILENAME_H // replace with relevant names
//#define NAMESPACE_HEADERFILENAME_H
// Your header file content goes here

#ifndef SDDS_UTILS_H	// header guards
#define SDDS_UTILS_H
namespace sdds{
	char ToLower(char);
	int StrCmp(const char*, const char*);
	void StrCpy(char*, const char*);
	int StrLen(const char*);
	bool isAlpha(char);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif