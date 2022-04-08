I/O Lab                


Description                

In this lab, we’ll do some exercises with I/O streams. The files for this lab are available in ~cs253/Lab/IO. You will modify code in these files, and check them in for credit. The TAs will compile your files using the Makefile that we provided, and execute them to ensure that they work properly. Your code must not have any compilation warnings or errors. A video introduction is available.                 
Robust input operators                

Consider number.cc. It creates a class called Number that’s a wrapper around an int.                 
Consider how it is that << works for Number, even though operator<< wasn’t defined for this class.
Consider operator>>. It doesn’t check for failure. And, yet, it works properly for:
valid numeric input
end of input
incorrect input (in that it sets ios::failbit)
Understand why this is.
Now, improve operator>> so that it works properly for input of “one”, “two”, “three”, “four”, and “five”, as well as working for all traditional numeric input that worked before.
No other wordy numbers, just those.
Consider using ios::clear(). Remember that ios is a base class of istream, and an istream is-a ios, so ios methods are inherited by istream.
Turn your results in at the end.
Using fstream to modify a file in place.                

Consider modify.cc. It copies its input file to its output file, replacing all instances of “Trump” with “Biden”.                 
Note the use of getline(). There are two versions of this function:
The free function getline() reads into a C++ string.
The method istream::getline() reads into a C-style character array—much less frequently used.
Change modify.cc to modify a single file in place. That is, the program should only take a single filename argument.                 
Don’t just read the entire file into one giant string. Your code must work for colossal files that don’t fit into memory.
Open the file once, in read/write mode, in an fstream. Not an ifstream, not an ofstream—an fstream.
Use getline().
Use the istream::tellg() and ostream::seekp() methods to ask “what’s my current read offset” and to say “where I want to write to”.
Remember that for an fstream, the g (get, read) and p (put, write) offsets are merged into a single offset.
Make sure that your solution works for data files that don’t contain “Trump” on every line, or that contains several “Trump”s on a single line.
This approach only works if the replacement string is the same length as the original string. However, it sure is efficient.
If you’re rewriting the entire file, you’re not doing a good job. Just rewrite what is needed. Replacing ten “Trump” strings should only require writing fifty bytes.
Turn your results in at the end.


For extra fame & glory (but no points)                
Improve operator>> in number.cc even more:
If it encounters invalid input such as “zork”, it shouldn’t consume the bogus input. It should fail, and leave things such that the next read (assuming that the stream is put back into a good state) would see “zork” again.                 
