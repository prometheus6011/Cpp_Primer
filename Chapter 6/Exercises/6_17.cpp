#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

bool has_capitals(const string& s)
{
  for (const char& c : s) {
    if (std::isupper(c)) {
      return true;
    }
  }
  return false;
}

void to_lower(string& s)
{
  for (char& c : s) {
    c = std::tolower(c);
  }
}

int main()
{
  cout << has_capitals("Hello World") << endl;
  string s = "HELLO";
  to_lower(s);
  cout << s << endl;

  return 0;
}