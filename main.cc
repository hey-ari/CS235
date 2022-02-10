// 1. replace nope-words w./ Censored
// 2. spaces and lines matter: user should be able to type in new line
// 3. replace only nope-word but nothing else


#include <iostream>
#include <string>

using namespace std;

void findAndReplaceAll(string & data, string toSearch, string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + replaceStr.size());
        
    }
}

    
int main()
{
    string data;
    string holder;
    string replacement = " CENSORED ";
    //string bigBoy;
    int i;

        
    for (int f=0; f<3; f++)
    {
       getline(cin, data);
        holder += data; // + "\n";

        while ((i = data.find(" alpha ")) != string::npos)
        {
        findAndReplaceAll(data, " alpha ", replacement);
            holder = data;
       }
        while ((i = data.find(" beta ")) != string::npos)
        {
            findAndReplaceAll(data, " beta ", replacement);
            holder = data;
        }
        while ((i = data.find(" gamma ")) != string::npos)
        {
           findAndReplaceAll(data, " gamma ", replacement);
            holder = data;
        }
        while ((i = data.find(" delta ")) != string::npos)
        {
            findAndReplaceAll(data, " delta ", replacement);
            holder = data;
        }
        cout << holder << "\n";
  }

    return 0;
}




//__________________________________________
//#include <iostream>
//using namespace std;

//int main (int argc, char *argv[])
//{
//    int c;
//    while ( (c = cin.get()) != EOF )
//    {
//       cout.put(c);
//    }
//    return 0;
//}


//void display(string c)
//{
//    string replacement = " CENSORED ";

//    int i;
//    while ((i = c.find(" alpha ")) != string::npos || (i = c.find(" beta ")) != string::npos || (i = c.find(" gamma ")) != string::npos || (i = c.find(" delta ")) != string::npos )
//    {
//        c.replace(i, replacement.length(), replacement);
//    }
//    cout << "You entered: " << c << endl;
//}

//_______________________________________________
//  main.cpp
//  test1
//
//  Created by Ariadna on 2/9/22.
//

//#include <iostream>
//#include <string>

//using namespace std;
//using std::string;


//void display (string);

//int main()
//{
//  string str;
    
//    cout << "Enter a string: ";
//    getline(cin, str);
    
//    display(str);
    
//    return 0;
//}
//
//
//void display(string s)
//{
//    string replacement = " CENSORED ";
//
//    int i;
//    while ((i = s.find(" alpha ")) != string::npos)
//    {
//        s.replace(i, replacement.length(), replacement);
//    }
//    cout << "You entered: " << s << endl;
//}

