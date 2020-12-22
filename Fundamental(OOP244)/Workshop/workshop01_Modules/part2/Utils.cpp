/**********************************************************
* Name: DONG CHAN OH
* Student ID: 128975190
* Seneca email: dcoh@myseneca.ca
* Section: NCC
**********************************************************/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include"Utils.h"
using namespace std;

// clearKeyboard
void clearKeyboard(void)
{
while (getchar() != '\n'); // empty execution code block on purpose
}

// getAssenmentName: accepts up to 40 characters and adds null byte
void getAssenmentName(char asName[])
{
cin.getline(asName, 41);
}

// getIntInRange: accepts an int between min and max
// returns the value of the int accepted
int getIntInRange(int min, int max)
{
int value, keeptrying = 1, rc;
char after;

    do
    {
        rc = scanf("%d%c", &value, &after);
        if (rc == 0) {
            printf("Invalid Number, try again: ");
            clearKeyboard();    // clear buffer
        }
        else if (after != '\n') {
            printf("Invalid trailing characters, try again: ");
            clearKeyboard();
        }
        else if (value < min || value > max) {
            printf("Invalid value (%d<=value<=%d), try again: ", min, max);
        }
        else {
            keeptrying = 0;
        }
    } while (keeptrying == 1);

    return value;
}

// sort()
void selectSort(int* a, int n)
{
    int i, j, m;
    int temp;

    for (i = 0; i < n; i++) {
        m = i;
        for (j = i + 1; j < n; j++)
            if (a[j] > a[m]) {
                m = j;
            }
        if (m != i) {
            temp = a[i];
            a[i] = a[m];
            a[m] = temp;
        }
    }
}

// display the results
void display(int* noMarks, int* marks) {
    double average = 0;
    int noPassingMark = 0;

    for (int i = 1; i <= *noMarks; i++) {
        if (i == 1) {
            cout << marks[i - 1];
        }
        else {
            cout << ", ";
            cout << marks[i - 1];
        }
        average += marks[i - 1];

        if (marks[i - 1] >= 50) {
            noPassingMark++;
        }
    }
    average /= *noMarks;

    cout.setf(ios::fixed);
    cout.precision(1);
    cout << endl << "Average: " << average << endl;

    cout << "Number of Passing Marks: " << noPassingMark << endl;
}



