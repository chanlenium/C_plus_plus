/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include "Displayable.h"
namespace sict {   
    template <typename  T>
    bool validate(const T& minimum, const T* arrayOfTest, const int numOfElement, bool* boolArray) {
        bool returnVal = true;
        for (int i = 0; i < numOfElement; i++) {
            if (arrayOfTest[i] >= minimum) {
                boolArray[i] = true;
            }
            else {
                boolArray[i] = false;
                returnVal = false;
            }
        }
        return returnVal;
    }

    //bool validate(const Student& minimum, const Student* arrayOfTest, const int numOfElement, bool* boolArray) {
    //    bool returnVal = true;
    //    for (int i = 0; i < numOfElement; i++) {
    //        if (arrayOfTest[i] >= minimum) {
    //            boolArray[i] = true;
    //        }
    //        else {
    //            boolArray[i] = false;
    //            returnVal = false;
    //        }
    //    }
    //    return returnVal;
    //}

    //bool validate(const Employee& minimum, const Employee* arrayOfTest, int numOfElement, bool* boolArray) {
    //    bool returnVal = true;
    //    for (int i = 0; i < numOfElement; i++) {
    //        if (arrayOfTest[i] >= minimum) {
    //            boolArray[i] = true;
    //        }
    //        else {
    //            boolArray[i] = false;
    //            returnVal = false;
    //        }
    //    }
    //    return returnVal;
    //}

    //bool validate(const int& minimum, const int* arrayOfTest, int numOfElement, bool* boolArray) {
    //    bool returnVal = true;
    //    for (int i = 0; i < numOfElement; i++) {
    //        if (arrayOfTest[i] >= minimum) {
    //            boolArray[i] = true;
    //        }
    //        else {
    //            boolArray[i] = false;
    //            returnVal = false;
    //        }
    //    }
    //    return returnVal;
    //}

    //bool validate(const char& minimum, const char* arrayOfTest, int numOfElement, bool* boolArray) {
    //    bool returnVal = true;
    //    for (int i = 0; i < numOfElement; i++) {
    //        if (arrayOfTest[i] >= minimum) {
    //            boolArray[i] = true;
    //        }
    //        else {
    //            boolArray[i] = false;
    //            returnVal = false;
    //        }
    //    }
    //    return returnVal;
    //}
}
#endif 