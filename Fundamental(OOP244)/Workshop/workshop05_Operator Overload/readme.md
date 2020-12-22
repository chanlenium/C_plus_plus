# Workshop #5: Operator Overload

In this workshop, you will write codes to practice operator overloading to implement Ships and Engine classes.

## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- code a compositional relationship across multiple classes
- manage dynamic memory within a class
- overload an operator as a member of a class
- overload an operator as a helper function of a class 
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


## `Engine` Module

Design and code a class named `Engine` that holds information about a type of simulated vehicle’s engine. Place your class definition in a header file named `Engine.h` and your function definitions in an implementation file named `Engine.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

### Global Constants

- `TYPE_MAX_SIZE`: the maximum length of the type attribute in `Engine` class (not including the null terminator). Set it to 30.

### `Engine` Class

Design and code a class named `Engine` that holds information about a vehicle's engine.

The class should be able to store the following data:
- `m_size`: the size of an engine, as a floating point number in double precision
- `m_type`: the engine model type, as an array of characters of size `TYPE_MAX_SIZE` (not including the null terminator).


#### `Engine` Public Members

- a default constructor
- a custom constructor that receives as parameters the engine type and the size (in this order); stores the parameters into the attributes.
- `double get() const`: a query that returns the size of the engine
- `void display() const`: a query that prints to the screen the content of an object in the format `[SIZE] liters - [TYPE]<ENDL>`

You can add any private members in the class, as required by your design.





## `Ship` Module

Create a module called `Ship` that contains a class named `Ship`.  This module contains the header file and an implementation file.  All code you add in this module should be in a namespace called `sdds`.  Use your previous knowledge regarding designing a module (header guard, utilization of constants instead of magic numbers, code duplication, etc.)


### Global Constants

- `MIN_STD_POWER`: the minimum power of a ship, according to the regulation. Set it to 90.111
- `MAX_STD_POWER`: the maximum power of a ship, according to the regulation. Set it to 99.999

### `Ship` Class

Design and code a class named `Ship` that holds information about a single ship. 

The class should be able to store the following data:
- `m_engines`: a statically allocated array of engines, of size 10. We say the ship has a capacity of maximum, 10 engines; we can have installed less than that.
- `m_type`: the ship model type, as a statically allocated array of characters of size `TYPE_MAX_SIZE` (not including the null terminator).
- `m_engCnt`: the number of engines that are actually installed on the ship.


#### Class Public Members

In order to interact with the private data members of the `Ship` class, public member functions are needed. The following function prototypes should be placed in the `Ship` header and their definitions in the implementation file (`.cpp`).

- default constructor: set the current instance into a safe empty state. Remember, an empty state signal the absence of data in an object; it is a special value for an attribute, or a combination of values for multiple attributes **that can be recognized at any moment and cannot be confused with valid data**.  Choose any empty state that makes sense for your design.

- a custom constructor that receives as parameters the type of the ship, the address of an array of engines, and the size of the array passed in (in this order).  If **all** parameters are valid, store them in the current instance; if any parameter is invalid, set the current instance into an empty state.  Remember, that in order to copy the array of engines into the attribute, you must iterate over the array received as a parameter and copy each element.



- `explicit operator bool() const`: a conversion to `bool` operator that returns `true` if the object is valid, and `false` otherwise. A valid object contains valid data (check for your chosen empty state).

  Explain in the reflection what happens if the keyword `explicit` is removed, and why is it necessary.

- `Ship& operator+=(Engine engine)`: a member operator that adds an engine to the array of engines. Make sure the number of engines is less than the maximum number of engines allowed.

  If the ship is not valid, print the message `The object is not valid! Engine cannot be added!<ENDL>` and do not add the engine.

- `bool operator<(double power) const`: a query that returns `true` if the total output power of the ship is less than the number provided as parameter; `false` otherwise. This overload enables syntaxes like `if (aShip < 22.22) { ... }`, where `aShip` is an instance of class `Ship`.

  The total output power of a ship is the size of all engines installed on the ship, multiplied by 5. You must iterate over the array of engines to calculate it (**Hint:** since the total output power of the ship will be used in other places too, create a private function to calculate it, to avoid code duplication in case a change is the formula is required in a future version of the program).

- `void display() const`: a query that print to the screen the content of the current instance in the following format:
  ```txt
  [TYPE] - [TOTAL_OUTPUT_POWER]<ENDL>
  [ENGINE_1_SIZE] liters - [ENGINE_1_TYPE]<ENDL>
  [ENGINE_2_SIZE] liters - [ENGINE_2_TYPE]<ENDL>
  ...
  ```

  Use the `Engine::display()` function to print the content of a single engine.




#### `Ship` Friend Helpers

- `bool operator<(double power, const Ship& theShip)`: a global function that returns `true` if the first parameter is smaller than the total output power of the ship received in the second parameter; `false` otherwise.   This overload enables syntaxes like `if (22.22 < aShip) { ... }`, where `aShip` is an instance of class `Ship`.

  Explain in the reflection why this operator cannot be a member of the class.





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
~profname.proflastname/submit 244/w5/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.





# Part 2 (50%)

In this part, update the `Ship` class to use dynamic memory for `m_engines` and `m_type` attributes, allowing you to use arrays of any size.

Update your implementation of the `+=` operator to resize the array of engines when a new engine is added to the ship.

Also, update the `display()` function to print the numbers with 2 significant digits.  The total output power of the ship should be printed on a field of size 6.  Use input/output formatters to achieve this.




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
~profname.proflastname/submit 244/w5/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
