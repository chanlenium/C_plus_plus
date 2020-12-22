# Workshop #6: Class with a Resource

In this workshop, you will work with a class that holds dynamic resources as well as static ones. In addition to having regular member functions, this class will also permit copy copied. Copying their data members will involve the use of copy constructors and assignment operators. The class used in this workshop will be the `Basket` class for which we will produce different fruit baskets.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- implement a copy constructor and a copy assignment operator
- to manage a class with dynamic resources
- to use existing objects to create new ones or to assign values to existing objects based on other existing ones
- to implement custom input/output operators
- to describe to your instructor what you have learned in completing this workshop



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


## `Basket` Module

Design and code a class named `Basket` that holds information about a fruit basket. Place your class definition in a header file named `Basket.h` and your function definitions in an implementation file named `Basket.cpp`.

Include in your solution all of the statements necessary for your code to compile under a standard C++ compiler and within the `sdds` namespace.

Add to this module a custom type called `Fruit`:
```cpp
struct Fruit
{
  char m_name[30 + 1]; // the name of the fruit
  double m_qty;        // quantity in kilograms
};
```

### `Basket` Class

Design and code a class named `Basket` that holds information about a fruit basket.


#### `Basket` Private Members

The class should be able to store the following data:

- `m_fruits`: a dynamically allocated array of objects of type `Fruit`. This is the resource that you must manage.
- `m_cnt`: the size of the `m_fruits` array.
- `m_price`: the price of the basket.

You can add any other private members in the class, as required by your design.



#### `Basket` Public Members

- the default constructor
- a custom constructor that receives as parameters an array of objects of type `Fruit`, the size of the array received in the fist parameter, and the price of the basket (in this order); stores the parameters into the attributes if **all** the parameters are valid (the numbers are greater than 0, and the array is not null).
- the copy constructor (you must do a deep-copy for the resource, and a shallow copy for the other attributes)
- the copy assignment operator (you must do a deep-copy for the resource, and a shallow copy for the other attributes; note that the copy constructor and copy assignment operator have almost identical logic -- reuse the code)
- the destructor
- `void setPrice(double price)`: updates the `m_price` attribute to the value received as parameter
- the conversion to `bool` operator: returns `true` if the basket contains any fruits, `false` otherwise.
- an overload of the `+=` operator that receives as a parameter an object of type `Fruit` (by value) and adds it to the attribute `m_fruits` (resize the array-attribute; check previous workshops if you need a refresh on resizing a dynamic array)


#### Friend Helper Functions

- overload the insertion operator (`operator<<`) to insert into the stream (received as the first parameter) the content of an object of type `Basket` (received as the second parameter).

  If the basket doesn't contain any fruit, print the message `The basket is empty!<ENDL>`.

  If the basket contains fruits, print the content in the format:
  ```txt
  Basket Content:<ENDL>
  [FRUIT_1_NAME]: [FRUIT_1_QUANTITY]kg<ENDL>
  [FRUIT_2_NAME]: [FRUIT_2_QUANTITY]kg<ENDL>
  ...
  Price: [BASKET_PRICE]<ENDL>
  ```
  The fruit names should be printed on fields of size 10, aligned to the right; the fruit quantities and basket price should be printed with **two** significant digits.




## Submission

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w6/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.





# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Submission

Run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w6/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
