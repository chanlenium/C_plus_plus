# Workshop #8: Virtual Functions

In this workshop, you are to implement an abstract definition of behavior for a specific type.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define a pure virtual function
- code an abstract base class
- implement behavior declared in a pure virtual function
- explain the difference between an abstract base class and a concrete class
- describe what you have learned in completing this workshop




## Submission Policy

The workshop is divided into one coding part and one non-coding part:

- *Part 1*: worth 100% of the workshop's total mark, is due on **Wednesday at 23:59:59** of the week of your scheduled lab.
- *reflection*: non-coding part, is due on **Sunday at 23:59:59** of the week of your scheduled lab. Te reflection doesn't have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

**The code that is submitted late receives 0%.**  On Sunday at midnight the submission closes; if the workshop is incomplete when the submission closes (missing at least one of the coding or non-coding parts), **the mark for the entire workshop is 0%**.

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





# Part 1 (100%)


## `Employee` Module

Design and code a class named `Employee` that holds information about an employee. Place your class definition in a header file named `Employee.h` and your function definitions in an implementation file named `Employee.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `Employee` Class

Design and code a class named `Employee` that holds information about an employee.

Assume all parameters are valid.


#### `Employee` Private Members

The class should be able to store the following data:

- a **constant** integer representing the minimum number of hours an employee must work in a week. ***Very Important***: **this must be a member constant.**
- a number representing the hourly salary of the employee, as a floating point number in double precision.

**:warning:Important:** Constant and referene attributes cannot be initialized in the body of a constructor like regular attributes (explain in the reflection why is that). You must use an **initializer list**. For more information read https://en.cppreference.com/w/cpp/language/constructor

You can add any other **private** members in the class, as required by your design.



#### `Employee` Protected Members

- two queries to retrieve the values of the two attributes (minimum working hours and hourly salary).



#### `Employee` Public Members

This class will **NOT** have a default constructor!

- a custom constructor that receives as parameters the hourly salary and the minimum number of hours the employee must work in a week.

- `double getSalary(int workedHours)`: a **pure virtual query** that calculates the salary earned by the employee during a week in which she worked the number of hours specified in the parameter.  Each type of employee will use a different formula to calculate salary.

- `ostream& display(ostream& out)`: a **pure virtual query** that inserts into the stream the representation of the current instance. Each type of employee has different data to print.
  The parameter will have `std::cout` as a default value.

- a **virtual**, empty-body, destructor.
  Explain in reflection why is it necessary to add the destructor to the class, considering that the implementation contains no statements.



#### Free Helper Functions

- overload the insertion operators to insert an `Employee` into a stream. This operator should call the `display` member function of the class `Employee`.
  In the previous workshop you had to overload this operator for each class on the hierarchy, but in this workshop you only overload it here.  Why is working properly in this workshop but not in the previous one?  Note that the function `display` has no implementation in this class. **Explain in the reflection.**










## `Doctor` Module

Design and code a class named `Doctor` that holds information about a doctor. Place your class definition in a header file named `Doctor.h` and your function definitions in an implementation file named `Doctor.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `Doctor` Class

Design and code a class named `Doctor` that holds information about a doctor.  **This class should inherit from `Employee` class.**

Assume all parameters are valid.


#### `Doctor` Private Members

The class should be able to store the following data (on top of data coming from the parent class):

- the type of doctor (surgeon, general medicine, family medicine, etc.) as an array of characters of size 32.
- a boolean value that is `true` if the doctor is a specialist.

You can add any other private members in the class, as required by your design.  **Do not duplicate members from the base class!**



#### `Doctor` Public Members

- a custom constructor that receives as parameters the type of doctor, the hourly salary, minimum numbers of hours the doctor must work in a week, and a value signaling if the doctor is a specialist. The last parameter should have a default value of `false`.
- `double getSalary(int workedHours)`: overrides the base class function. Calculates the salary according to the following rules:
  - if the doctor worked minimum number of hours or less, multiply the parameter by the hourly rate
  - if the doctor worked overtime, the minimum number of hours are paid at hourly rate, and anything extra is paid at 150% hourly rate.
  - if the doctor is a specialist, she receives extra 2000 regardless of the numbers of hours worked.
- `ostream& display(ostream& out)`: overrides the base class function. Inserts into the stream the content of the object in the format
  ```txt
  Doctor<ENDL>
  Type: [TYPE]<ENDL>
  Pay Rate: [HOURLY_RATE]<ENDL>
  Min Hours: [MIN_HOURS]<ENDL>
  ```

  If the doctor is a specialist, use the format:

  ```txt
  Doctor<ENDL>
  Type: [TYPE] (specialist)<ENDL>
  Pay Rate: [HOURLY_RATE]<ENDL>
  Min Hours: [MIN_HOURS]<ENDL>
  ```

  The labels should be printed on a field of size 16, aligned to the right.










## `Engineer` Module

Design and code a class named `Engineer` that holds information about an engineer. Place your class definition in a header file named `Engineer.h` and your function definitions in an implementation file named `Engineer.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### `Engineer` Class

Design and code a class named `Engineer` that holds information about an engineer.  **This class should inherit from `Employee` class.**

Assume all parameters are valid.


#### `Engineer` Private Members

The class should be able to store the following data (on top of data coming from the parent class):

- an integer representing the level of an engineer. This value is used in calculating the salary.

You can add any other private members in the class, as required by your design.  **Do not duplicate members from the base class!**



#### `Engineer` Public Members


- a custom constructor that receives as parameters the hourly salary and the level. The engineer must work minimum 30 hours per week.

- `double getSalary(int workedHours)`: overrides the base class function. Calculates the salary according to the following rules:
  - multiply the parameter by the hourly rate (the engineer is paid the same amount for all worked hours)
  - add an extra 40 dollars for each level the engineer has
  - if the engineer worked less than the minimum number of hours, cut 20% of her salary.
- `ostream& display(ostream& out)`: overrides the base class function. Inserts into the stream the content of the object in the format
  ```txt
  Engineer<ENDL>
  Level: [LEVEL]<ENDL>
  Pay Rate: [HOURLY_RATE]<ENDL>
  Min Hours: [MIN_HOURS]<ENDL>
  ```

  The labels should be printed on a field of size 20, aligned to the right.







## `main` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### Sample Output

The output should look like the one from the `expected_output.txt` file.


















## Submission

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w8/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.





# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.

## Submission

Run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w8/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
