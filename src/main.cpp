
#include "MyList.h"
#include <iostream>
#include <string>

using namespace std;

void print_schedule(MyList<string> &theList);
void add(MyList<string> &theList, const string &jobTitle, int timeSlot);
void fire(MyList<string> &theList, const string &jobTitle);
void sleepIn(MyList<string> &theList, int time);
void carCrash(MyList<string> &theList, int timeSlot);
void disease(MyList<string> &theList);

int main() {
  MyList<string> schedule;
  string startingJob;

  auto it = schedule.begin();

  for (int i = 0; i < 3; i++) {
    cin >> startingJob;
    schedule.insert(it, startingJob);
    it++;
  }

  string func = "";
  int total_days;
  cin >> total_days;

  for (int day = 0; day < total_days; day++) {
    cin >> func;
    // Finish Me!
    print_schedule(schedule);
  }

  return 0;
}

// "Recommended" functions below

void print_schedule(MyList<string> &theList) {
  int numJobs = theList.size();
  auto it = theList.begin();
  if (numJobs == 0)
    cout << "Unemployed" << endl;
  else {
    for (int i = 0; i < theList.size() - 1; i++) {
      cout << *it << " ";
      it++;
    }
    cout << *it << endl;
  }
}

// add function - Inserts job in the given time slot
// If timeslot >= len of MyList is passed,
// job is appended to the end.
void add(MyList<string> &theList, const string &jobTitle, int timeSlot) {}

// If he is fired from a specific job, it goes
// through his schedule from front to back,
// erasing each instance of that job from his schedule
void fire(MyList<string> &theList, const string &jobTitle) {}

void sleepIn(MyList<string> &theList, int time) {}

void carCrash(MyList<string> &theList, int timeSlot) {}

void disease(MyList<string> &theList) {}
