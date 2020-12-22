# Workshop #4: Constructors and Destructors

In this workshop, you are to code a class that represents a Saiyan (a race of aliens inspired from DBZ anime show) and control their powers and fate through various member functions.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a default constructor that sets an object to a safe empty state
- define a custom constructor that initializes an object’s data at creation time
- describe to your instructor what you have learned in completing this workshop


## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 50% of the workshop's total mark, is due on **Wednesday at 23:59:59** of the week of your scheduled lab.
- *Part 2*: worth 50% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. Te reflection doesn't have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

If at the deadline the workshop is not complete, there is an extension of **one day** when you can submit the missing parts.  **The code parts that are submitted late receive 0%.**  After this extra day, the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.


## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.





# Part 1 (50%)


## Saiyan Module

Create a module called `Saiyan` that contains a class named `Saiyan`.  This module contains the header file and an implementation file.  All code you add in this module should be in a namespace called `sdds`.  Use your previous knowledge regarding designing a module (header guard, utilization of constants instead of magic numbers, code duplication, etc.)


### Saiyan Class

Design and code a class named `Saiyan` that holds information about an alien race of warriors known as *The Mighty Saiyans*. 

The class should be able to store the following data:
- `m_name`: A C-style string holding the name of the Saiyan. You may assume that the string is no longer than 32 characters, including the null terminator.
- `m_dob`: An integer indicating the year in which the Saiyan was born (<= 2020).
- `m_power`: An integer indicating the strength of the Saiyan (>= 0).
- `m_super`: A Boolean value to indicate whether the Saiyan has the ability to evolve into a Super Saiyan (a value of `false` indicates that the Saiyan has not achieved this ability yet).



***Valid Name***: a string that contains at least one character, but less than 32.

***Valid Year of Birth***: an integer within the interval [0, 2020].

***Valid Power***: an integer that is greater than 0.


#### Class Public Members

In order to interact with the private data members of the `Saiyan` class, public member functions are needed. The following function prototypes should be placed in the `Saiyan` header and their definitions in the implementation file (`.cpp`).

- default constructor: set the current instance into a safe empty state. Remember, an empty state signal the absence of data in an object; it is a special value for an attribute, or a combination of values for multiple attributes **that can be recognized at any moment and cannot be confused with valid data**.  Choose any empty state that makes sense for your design.

- a custom constructor that receives as parameters the name, date of birth and power of the Saiyan (in that order).  If **all** parameters are valid, store them in the current instance; if any parameter is invalid, set the current instance into an empty state.  You should reuse the `set()` function to handle the data.

- `void set(const char* name, int dob, int power, bool super = false)`: a modifier that stores the data it receives into the attributes. If any of the parameter is invalid, set the current object into an empty state.

  Note that the last parameter has a default value: if the client doesn't provide a value, the default one will be used.  You should put the default value only in the header (when you declare the function), and not in the implementation file.

- `bool isValid() const`: a query that return true if the object is **not** in an empty state (contains valid data).

- `void display() const`: a query that prints to the screen the content of an object. Use the following format:

  If the object is invalid, print `Invalid Saiyan!<ENDL>`

  If the object is valid, print
  ```txt
  [NAME]<ENDL>
  DOB: [DOB]<ENDL>
  Power: [POWER]<ENDL>
  Super: [YES/NO]<ENDL>
  ```

- `fight(const Saiyan& other) const`: a query that simulates a fight between two Saiyans.  This function should return true if the current instance will win the fight, `false` otherwise.
  
  The current object would win the fight only if **the two Saiyans are valid** and the power of the current Saiyan is greater than the power of the `other`


#### Class Private Members

You can add any private members in the class, as required by your design.




## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### Sample Output

The output should look like the one from the `sample_output.txt` file.



## Submission

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w4/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.





# Part 2 (50%)

In this part you must update the Saiyan module according to the specs below.


## Saiyan Class

Add a new attribute to the class:
- `m_level`: an integer indicating the level of a Super Saiyan.

***Valid Level***: an integer that is at least 0.

**In this part you need to transform the `m_name` attribute into a dynamically allocated array of characters.  In other words allocate the memory in the constructor and free the memory in the destructor and make sure your `set()` function does not cause memory leak.**



### Class Public Members

The functions below are either new to this part of the workshop, or require an update from the version you had in **Part 1**.

- add a destructor to the class

- `void display() const`: update this query to also print the level of a Super Saiyan and beautify the output. Use the following format:

  If the object is invalid, print `Invalid Saiyan!<ENDL>`

  If the object is valid, and we have a regular Saiyan, print
  ```txt
  [NAME]<ENDL>
  DOB: [DOB]<ENDL>
  Power: [POWER]<ENDL>
  Super: no<ENDL>
  ```

  If the object is valid, and we have a Super Saiyan, print
  ```txt
  [NAME]<ENDL>
  DOB: [DOB]<ENDL>
  Power: [POWER]<ENDL>
  Super: yes<ENDL>
  Level: [LEVEL]<ENDL>
  ```

  The labels (including the `: `) should be printed on fields of size 10, aligned to the right.

- `void set(const char* name, int dob, int power, int level = 0, bool super = false)`: update the function to accept one more parameter: `super`. Add appropriate code to manage the resource that doesn't cause a memory leak.

- `bool fight(Saiyan& other)`: update this function to allow the two Saiyans fighting to power-up (only valid objects can fight).

  Powering-up means to **permanently** update the power of the Super Saiyan, increasing it with 10% for every level the Super Saiyan has. Regular Saiyans do not change their power.

  Explain in the reflection why the prototype has been updated to remove `const`.





## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### Sample Output

The output should look like the one from the `sample_output.txt` file.



## Reflection

Study your final solutions for each deliverable of the workshop, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and mention any issues that caused you difficulty.


## Submission

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w4/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
