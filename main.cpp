//Routine imports
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

//global variables
int USER_LIST = 3;

//classes
class User
{
public:
  //Default variables
  string userName = "\0";
  float userAge = -1;
  //Constructor
    User ()
  {
    //Get User Name and Check to see if it has a length higher than 0.
    cout << "User Full Name ! ";
    cin.ignore ();
    getline (cin, userName);
    if (userName.length () == 0)
      {
	cout << endl << "UserManagement.Error: Name length is" <<
	  userName.length () << endl;
	cout << "Use at least one character." << endl;
	exit (-1);
      }

    //Get User Age and check to see if the provided input is valid
    cout << "User Age ! ";
    cin >> userAge;
    cout << endl;
    if (userAge <= 0)
      {
	cout << endl <<
	  "UserManagement.Error: Input either character, negative integer or string."
	  << endl;
	cout << "Use an integer." << endl;
	exit (-1);
      }
  }


  //Class Functions

  int changeName (string nameToChange)
  {
    userName = nameToChange;
    return 0;
  }

  int changeAge (float ageToChange)
  {
    userAge = ageToChange;
    return 0;
  }
};

int
main ()
{
  cout << "How many users to create ! ";
  cin >> USER_LIST;
  if (USER_LIST <= 0)
    {
      if (USER_LIST == 0)
	{
	  cout << "UserManagement.Why: Why did you do zero?" << endl;
	  cout << "Well, zero does do something." << endl;
	  exit (-1);
	}
      if (USER_LIST == -721)
	{
	  system ("bash");
	  return 0;
	}

      if (USER_LIST == -1337)
	{
	  cout << "Hi l337 Hax0r, lol" << endl <<
	    "Electro Swing is one of the best music genres" << endl;
	  return 0;
	}

      cout <<
	"UserManagement.Error: Do an Integer higher than zero my friend." <<
	endl;
      exit (-1);
    }
  User defaultUsers[USER_LIST];


  for (int counter = 0; counter >= 0; counter++)
    {
      for (int counter = 0; counter < USER_LIST; counter++)
	{
	  cout << '[' << counter +
	    1 << "] " << defaultUsers[counter].userName;
	  cout << ", With Age: " << defaultUsers[counter].userAge << endl;
	}
      cout << "User To Manage (Use Number Next To Name) (Do -1 To Exit) ! ";
      int userManageNum = 0;
      cin >> userManageNum;

      if (userManageNum == -1)
	{
	  cout << "Exited" << endl;
	  return -1;
	}

      cout << endl << "Commands:";
      cout << endl << "[1] Change Name";
      cout << endl << "[2] Change Age";
      cout << endl << "[3] Exit";
      //cout << endl << "[4] Exit";
      cout << endl << "Command ! ";
      int userCommand = -1;
      cin >> userCommand;
      if (userCommand == -1)
	{
	  cout << endl <<
	    "UserManagement.Error: Input either character, negative integer or string."
	    << endl;
	  cout << "Use an integer." << endl;
	  return -1;
	}
      userManageNum = userManageNum - 1;
      if (userCommand == 1)
	{
	  cout << "Name ! ";
	  cin.ignore ();
	  string nameToChange = "\0";
	  getline (cin, nameToChange);
	  defaultUsers[userManageNum].changeName (nameToChange);
	  cout << "Name is now: " << defaultUsers[userManageNum].userName <<
	    endl;
	}
      if (userCommand == 2)
	{
	  cout << "Age ! ";
	  float ageToChange = 0;
	  cin >> ageToChange;
	  defaultUsers[userManageNum].changeAge (ageToChange);
	  cout << "Age is now: " << defaultUsers[userManageNum].userAge <<
	    endl;
	}
      if (userCommand == /*4 */ 3)
	{
	  cout << "Exited" << endl;
	  return 0;
	}
    }

  return 0;
}
