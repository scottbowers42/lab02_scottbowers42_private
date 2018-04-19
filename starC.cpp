// starC.cpp   A demonstration of ASCII Art printing C characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starC(int width, int height);
void runTests(void);

// Write starC per specifictions in the lab writeup
// so that internal tests pass, and submit.cs system tests pass


string starC(int width, int height)
{
  string result="";
  if(height < 3 || width < 2)
	  return result;
  string fullLine = "";//Setup top and bottom lines
  string sideLine = "";
  for(int i = 0; i < width; i++)//Loop to create top and bottom lines
	  fullLine = fullLine + "*";
  sideLine = sideLine + "*";
  for(int i = 1; i < width; i++)//Loop to create middle lines
	  sideLine = sideLine + " ";
  fullLine = fullLine + "\n";
  sideLine = sideLine + "\n";
  result = result + fullLine;//Add top line
  for(int i = 1; i < height - 1; i++)
	  result = result + sideLine;//Add middle lines
  result = result + fullLine;//Add bottom line
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starC34Expected = 
    "***\n"
    "*  \n"
    "*  \n"
    "***\n";
  
  assertEquals(starC34Expected,starC(3,4),"starC(3,4)");

  string starC53Expected =     
    "*****\n"
    "*    \n"
    "*****\n";

  
  assertEquals(starC53Expected,starC(5,3),"starC(5,3)");

  assertEquals("",starC(2,1),"starC(2,1)");
  assertEquals("",starC(2,2),"starC(2,2)");

  string starC23Expected =     
    "**\n"
    "* \n"
    "**\n";
  
  assertEquals(starC23Expected,starC(2,3),"starC(2,3)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[])
{
if(argc != 3){//Prints error message if usage is incorrect.
                cerr << "Usage: " << argv[0] << " width height" << endl;
                exit(1);
        }

        if(atoi(argv[1]) == -1 && atoi(argv[2]) == -1){//Run the test if width and height are -1
                runTests();
                exit(1);
        }

        cout << starC(atoi(argv[1]),atoi(argv[2]));//Print starC function
  return 0;
}
