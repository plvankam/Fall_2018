#include <fstream>
#include <string>
#include<iostream>

using namespace std;

int main()
{

string s1= "pine";
string s2= "apple";
cout << "length of s1 is " << s1.length() << endl;
string s3= s1+s2;
cout << "s1 + s2 = " << s3 << endl;
string s4= s3.substr(2,4);
cout << "s3.substr(2,4)=" << s4 << endl;
cout << "s3.find(\"neap\")=" << s3.find("neap") << endl;
cout << "s3.rfind(’p’)=" << s3.rfind("p") << endl;

return 0;
}
