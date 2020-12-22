# Workshop #9: Function Templates

In this workshop, you are to code a function template for validating if a value is greater than a minimum value.


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

-	code a function template
-	implement a call to a function template
-	describe the syntax of a constrained cast and its purpose
-	describe what you have learned in completing this workshop




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


Create a function called validate in a file called `validate.h` that accepts four arguments (a minimum, an array of test-values, number of elements in the array, an array of Boolean for validation results) and returns a bool that is true only if ALL the test-value elements are greater than the minimum, and false otherwise. That is:
Return true, if testValue[i] >= minimum (for “i” being the index of the elements in testValue) and return false otherwise.
Also, as the validation test is being done on each element, the result of validation is saved for each element in the Boolean array. So, the caller program can determine exactly which element of the testValue array is valid or invalid. 
Make sure the function is designed in a way that all test objects (min, and test elements) are not copied or modified in the function. 



## `Car` Module, `Employee` Module, `Student` Module, `main` Module (supplied)

**Do not modify these modules!**  Look at the code and make sure you understand it.



### Sample Output

The output should look like the one from the `expected_output.txt` file.


















## Submission

To test and demonstrate execution of your program use the same data as shown in the output example.

Upload your source code to your `matrix` account. Compile and run your code using the `g++` compiler as shown above and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w9/p1
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.





# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


## Submission

Run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 244/w9/p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
