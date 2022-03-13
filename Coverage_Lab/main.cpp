#include "Date.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream data("data");
    Date d;
    
    // Reads each line, test date conversion, throw error is failed.
    for (string s; getline(data, s); )
    {
    istringstream iss(s);       // Initialize stream with string
    if (iss >> d)               // Test for Date conversion
        cout << d << endl;
    else
        cerr << "ERROR! This date is invalid: " << s << endl;
    }

    const Date a(2015,6,8); // Monday June 8, 2015
    cout << a << endl;

    const Date b(a);
    cout << b << endl;

    Date c; c=a;
    cout << c << endl;

    c = c+1;
    cout << c << endl;
    c += 9;
    cout << c << endl;
    d = ++c;
    cout << c << endl;
    cout << d << endl;

    d = c++;
    cout << c << endl;
    cout << d << endl;

    Date e = d-1;
    cout << e << endl;
    d = e--;
    cout << d << endl;
    cout << e << endl;
    d = --e;
    cout << d << endl;
    cout << e << endl;
    e -= 5;
    cout << e << endl;
    e -= -2;
    cout << e << endl;
    cout << d-e << endl;
    cout << e-d << endl;

    Date f;
    f.setday(31);
    f.setmonth(12);
    f.setyear(1999);
    f = 1 + f;
    Date g(1999, 12, 31);
    // a==b, a<c
    cout << ((a==b) ? "== good" : "== bad") << endl;
    cout << ((a==c) ? "== bad"  : "== good") << endl;
    cout << ((a!=c) ? "!= good" : "!= bad") << endl;
    cout << ((a!=b) ? "!= bad"  : "!= good") << endl;
    cout << ((a<c)  ? "<  good" : "<  bad") << endl;
    cout << ((a<b)  ? "<  bad"  : "<  good") << endl;
    cout << ((c>a)  ? ">  good" : ">  bad") << endl;
    cout << ((b>a)  ? ">  bad"  : ">  good") << endl;
    cout << ((a<=b) ? "<= good" : "<= bad") << endl;
    cout << ((a<=c) ? "<= good" : "<= bad") << endl;
    cout << ((c<=a) ? "<= bad"  : "<= good") << endl;
    cout << ((a>=b) ? ">= good" : ">= bad") << endl;
    cout << ((c>=a) ? ">= good" : ">= bad") << endl;
    cout << ((a>=c) ? ">= bad"  : ">= good") << endl;
    cout << ((f==g) ? "== good" : "!= bad") << endl;

    return 0;
}
