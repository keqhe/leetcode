#include<string>
#include<list>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*topics: list, string, queue, stack, recursion
*/

bool strCmp(string s1, string s2) {//if s1 "<" s2, return true
    while (s1.length() > 1) {
        if (s1.front() == '0') {
            s1.erase(s1.begin());
        }
        break;
    }
    while (s2.length() > 1) {
        if (s2.front() == '0') {
            s2.erase(s2.begin());
        }
        else
            break;
    }

    if (s1.length() < s2.length())
        return true;
    else if (s1.length() > s2.length())
        return false;
    else
        return s1 < s2;
}

int main() {
    string s;
    s = "abc";

    //how to iterate
    for (auto c : s)
        cout << c << " ";
    cout << endl;

    for (int i = 0; i < s.length(); i ++)//s.length() returns type of unsigned int
        cout << s[i] << " ";
    cout << endl;

    //how to add a char at the end of the string?
    s += 'd';
    s += "e";
    s.push_back('f');
    s.pop_back();

    for (auto c : s)
        cout << c << " ";
    cout << endl;

    //how to convert a char into a string?
    string tmp(1,'a');//tmp = "a"
    char c = 'b';
    string tmp2(1,'a');//tmp = "a"
    //how to reverse a string?
    reverse(s.begin(), s.end());
    //how to compare 2 string?
    string s1 = "123";
    string s2 = "234";
    cout << (s1 < s2) << endl; //should output 1
    string s3 = "99";
    cout << (s1 < s3) << endl; //should output 1


    //the maximal value an interger can represent is 2 billion
    //note, you can sort strings
    //vector<string> v {"def", "abc"};
    //sort(v.begin(), v.end());//"abd" < "bca"

    //how to get sub-string?
    string subway = "subway";
    string way = subway.substr(3, 3);//first parameter is position, second parameter is length of the substr
    string way2 = subway.substr(3); //still returns "way"

    //you can check whether a string is empty using s.empty(), i.e., ""
    //NULL is pointer, NULL, nullptr
    //you can check the length of a string using s.length() or s.size() (i prefer s.length())

    //to_string, number to string
    int a = 1918;
    float f = 3.1415926;
    string a_str = to_string(a);
    string f_str = to_string(f);

    cout << a_str << " " << f_str << endl;

    //string to number
    //most likely you just need to know how to convert int, unsigned int, long, unsigned long, long long into string
    //see, http://en.cppreference.com/w/cpp/language/types
    string test123 = "123";
    int test123_i = stoi(test123);

    return 0;
}


