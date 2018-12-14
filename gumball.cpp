#include <iostream>

const int NO_QUARTER = 0;
const int HAS_QUARTER = 1;
const int GUMBALLSOLD = 2;
const int EJECTQUARTER =3;
int input;
/* The section above is assigns which state the gumball machine is at as well as
setting the variable for the user's input. */
class gumballMachine {
  public:
    int  getstate() {
      return state;
    }
/* this section of code is an if statement inside a void which will check what state the machine is at.
this section will check the machine once the user has inserted a quarter, it will check if there is already
a quarter in the machine or if it’s free.*/
    void insertQuarter () {
      if (state == NO_QUARTER) {
        std::cout << "Quarter inserted\n";
        setState (HAS_QUARTER);
        User_input();
      } else {
        std::cout <<"Quarter could not be inserted\n";
        User_input();
      }
    }
/* This section of code is like the one above however it checks if there is a quarter in the machine when the
user wants to eject it.*/
    void ejectQuarter () {
     if(state == HAS_QUARTER ) {
       std::cout << "Quarter ejected\n";
      setState (NO_QUARTER);
      User_input();
     } else {
       std::cout << "no Quarter to eject\n";
       User_input();
    }
  }
/* this section of code checks if the machine has a quarter in it so that when the user
 cranks the handle is can dispense a gumball */
    void gumballsold () {
      if (state == HAS_QUARTER) {
        std::cout << "Crank turned. Gumball sold.\n";
        setState (GUMBALLSOLD);
        User_input();
      } else {
        std::cout << "No Quarter incerted\n";
        User_input();
      }
    }

protected:
/* this section of code changes the state of the machine to a new state which the machine is currently at. */
private:
  int state;

  void setState (int newstate) {
      state=newstate;
  }
  
/* This section of code will check the users input against the list of commands that are available to the user */
public:
void check () {
  gumballMachine gumball;
  if (input == 1) {
    gumball.insertQuarter();
  } else if (input == 2) {
    gumball.ejectQuarter();
  } else if (input == 3) {
    gumball.gumballsold();
  } else {
  }
}

// this section of code will present the user will the list of commands with the corresponding numbers.
void User_input () {
  std::cout << "Plase enter your next command: (1:insert)(2:eject)(3:crank)\n";
  std::cin >> input;
  check();
}

};

int main() {
  gumballMachine gumball;
  std::cout << "Welcome to Gumball State Machine!\n";
  std::cout << "Please enter the number that corresponds with the command\n";
  gumball.check();

    std:: cout << "Current State: " << gumball.getstate() <<std::endl;
    gumball.gumballsold();
}
