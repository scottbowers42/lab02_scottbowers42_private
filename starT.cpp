// starT.cpp   A demonstration of ASCII Art printing T characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starT(int width, int height);
void runTests(void);

// Write starT per specifictions in the lab writeup
// so that internal tests pass, and submit.cs system tests pass

string starT(int width, int height)
{
  string result="";
  if(width % 2 == 0 || height == 1 || width == 1)
	  return result;
  for(int i = 0; i < width; i++)//Draw the first line.
  	result = result + "*";
  result = result + "\n";
  int spaces = (width - 1)/2;
  string spaceText = "";
  for(int i = 0; i < spaces; i++)//Set up the spacing on each side.
	spaceText = spaceText + " ";
  for(int i = 1; i < height; i++)
	result = result + spaceText + "*" + spaceText + "\n";//Draw a new line
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starT34Expected = 
    "***\n"
    " * \n"
    " * \n"
    " * \n" ;
  
  assertEquals(starT34Expected,starT(3,4),"starT(3,4)");

  string starT53Expected =     
    "*****\n"
    "  *  \n"
    "  *  \n" ;
  
  assertEquals(starT53Expected,starT(5,3),"starT(5,3)");

  string starT72Expected =     
    "*******\n"
    "   *   \n";
  
  assertEquals(starT72Expected,starT(7,2),"starT(7,2)");

  assertEquals("",starT(1,2),"starT(1,2)");
  assertEquals("",starT(5,1),"starT(5,1)");
  assertEquals("",starT(4,2),"starT(4,2)");
  assertEquals("",starT(6,2),"starT(6,2)");
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

	cout << starT(atoi(argv[1]),atoi(argv[2]));//Print starT function
  return 0;
}
