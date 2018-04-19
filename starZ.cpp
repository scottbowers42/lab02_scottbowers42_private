// starZ.cpp   A demonstration of ASCII Art printing C characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);

// Write starZ per specifictions at 
// https://foo.cs.ucsb.edu/16wiki/index.php/F14:Labs:lab04
// and so that internal tests pass, and submit.cs system tests pass


string starZ(int width)
{
  string result="";
  if(width < 3)
	  return result;
  for(int i = 0; i < width; i++)//Create top line
	  result = result + "*";
  result = result + "\n";
  for(int i = width - 1; i > 1; i--){//Create diagonal lines
	for(int j = 0; j < width; j++){
		if(j + 1 == i)//Add * if at the correct position in the diagonal
			result = result + "*";
		else//Add " " otherwise
			result = result + " ";
	}
	result = result + "\n";//Move to the next line
  }
  for(int i = 0; i < width; i++)
	  result = result + "*";
  result = result + "\n";
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starZ3Expected = 
    "***\n"
    " * \n"
    "***\n";
  
  assertEquals(starZ3Expected,starZ(3),"starZ(3)");

  string starZ4Expected = 
    "****\n"
    "  * \n"
    " *  \n"
    "****\n";
  
  assertEquals(starZ4Expected,starZ(4),"starZ(4)");

  assertEquals("",starZ(0),"starZ(0)");
  assertEquals("",starZ(2),"starZ(2)");
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
if(argc != 2){//Prints error message if usage is incorrect.
                cerr << "Usage: " << argv[0] << " width" << endl;
                exit(1);
        }

        if(atoi(argv[1]) == -1){//Run the test if width is -1
                runTests();
                exit(1);
        }

        cout << starZ(atoi(argv[1]));//Print starZ function
  return 0;

}
