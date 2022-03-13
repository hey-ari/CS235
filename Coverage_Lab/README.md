DISCLAIMER:
The information provided and lab contents are ONLY for my personal job searching purposes. One MAY NOT use any files to submit as their own, this will be consideed as cheating and punished as such.

<b>Description</b>

gcov is a code coverage tool. It tells you how many times each line in your code has been executed. This tells you:                 

1. which lines of the code were tested
2. where the code is spending time


#1 is frequently used, in industry, as a requirement before releasing code. For example, the code might not be considered finished until automated tests execute 90% of the code. It’s difficult to persuade the author to test their own code—we have an unconscious aversion to testing the parts of the code that are dubious. That’s why, in industry, somebody else tests your code—they have no protective feelings toward it.                 

#2 is just an approximation, since not all lines of code take the same amount of time—consider the assignment of an integer, as opposed to calculating a cosine. However, it’s often a sufficient approximation.                 

In this lab, we will use gcov to:

1. see if we’ve tested some code adequately
2. make the code more efficient


<b>Tasks</b>                
1. Copy the directory ~cs253/Lab/Coverage to a convenient location in your home directory. It contains a class Date in Date.h and Date.cc, and a test program in main.cc.
2. You will modify Date.cc and main.cc, wrap them up in a tar file, and turn them in for credit. Take a minute or two to look at the code, including the test cases in main().
3.Build the code; note the interesting g++ options used:
<i>make</i>
4. Run the code:
./prog
5. Create coverage data:
gcov -r Date.cc
6. Look at the coverage data:
more Date.cc.gcov
Each line contains the number of times that it was executed (or ##### for never executed, or - for a non-executable line), a line number, and the source code for that line.
7. Find the lines that contain #####. Those lines weren’t tested.
8. Add test cases to main() for those untested lines.
9. Recompile (make), rerun (./prog), and recreate the coverage data (gcov -r Date.cc).
10. Look at the coverage data, and verify that all code is now tested.
11. It’s time to look for inefficient code. Look at Date.cc.gcov, and find the lines that start with the largest number. It should be the routine days_per_month(). Resist the urge to optimize that code. Instead, find out who’s calling it hundreds of millions of times. The culprit should be line 82 or so.
12. Observe the code above line 82 that’s commented out with #if 0. Try making that code active (change #if 0 to #if 1), recompile, rerun, recreate coverage data, and see if it helped.
13 Look at the coverage data for the function leap(). Observe how it almost always calculates the modulus (%) three times for each year. Since most years are not leap years, this is silly. Assume that the % operator, which has to perform division, is slow.
Make this code more efficient, without sacrificing clarity or correctness, and prove it using gcov data. By “more efficient”, I mean that, for boring years like 2021, which is clearly not a leap year, modulus (%) should only be executed once, not three times. Before you do that, however, run ./prog and save the output. After you make your improvements to leap(), run ./prog again and diff the output, so you’ll know if you broke it or not.

Look at the branch coverage for leap() and see if it makes sense.
Look at the branch coverage for operator>>. Some branches are taken 0% of the time. Why? What still isn’t being tested?
Add tests to cover those cases.
