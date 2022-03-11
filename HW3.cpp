#include<iostream>
#include<string>
#include <fstream>
using namespace std;

ifstream myfile;


int len(string str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}


void replaceString(string str,string old_word,string censor = "CENSORED")
{
     
    bool status = false;
    int startIndex = 0, endIndex = len(old_word);
    for (int i = 0; i < len(str); i++) {
        if (str[i] == old_word[0])
        {
            startIndex = i;
            for (int j = 0; j < len(old_word); j++, i++) {
                if (str[i] != old_word[j]) {
                    status = false;
                    break;
                }
                else
                {
                    status = true;
                }
            }
            if (status) {
                str.replace(startIndex, endIndex, "CENSORED");
                cout << str << endl;
                return;
            }
        }
    }
    cout << "Old word is not found";
}


int main()
{
    ifstream myfile;
    string str = "", old_word = "", censor = "";
    
    if ( myfile.is_open() )
    {
        char mychar;
        while ( myfile )
        {
            mychar = myfile.get();
            std::cout << mychar;
        }
    }
    else
        cout << "Enter string : ";
        getline(cin, str);
    
    
    cout << "Enter Old_word : ";
    cin >> old_word;
    cout << "String before replacement : " << str << endl;
    replaceString(str, old_word, "CENSORED");
    return 0;
}
