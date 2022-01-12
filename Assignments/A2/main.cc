/*
  Program creator: Felix Cardinal Tremblay
  Student number: 101141593

  The purpose of this program is to emulate a telephone company, and
  keep track of the calls that the the subscribers execute and receive.

  Usage: run the makefile, then run ./a2 in the command line. Once that is done,
  simply enter whatever the program prompts you to input.

  Revisions: none.
*/


#include <iostream>
using namespace std;
#include <string>
#include "Control.h"


int main()
{
  Control c = Control("Felix's Telephone Company");
  c.launch();
  return 0;
}
