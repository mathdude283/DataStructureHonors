

# LinkedList Implementation (forward_list)

![](workful-willy.png)

_He’s baaack?_


## Assignment Description

_It’s Workful Willy again... that’s it. Workful Willy with a LinkedList_

Your task will be to replicate the functionality of a std::forward_list as closely as possible in your own class (MyList).

The class you’ll be building along with function definitions can be found in MyList.h, read this file carefully as the operations may not be exactly the same as those discussed in class. (**DO NOT MODIFY THIS FILE**) You can also refer to [cppreference](https://en.cppreference.com/w/cpp/container/forward_list) for more info on the operations.

Place your code for each of the required functions in MyList.hpp, as always it is recommended that you follow the unit tests as a guide and code each function one-by-one after passing each test.

**Important Note:**
To bring this implementation more in line with std::forward_list and prepare you for working with the standard library implementations directly, some functions have shifted to use an **LinkedListIterator** in place of a normal _pointer_.

The **LinkedListIterator** class provided is designed to act similar to a _ListNode_ pointer.
* It returns a reference to the data element inside the underlying node when de-referenced
* It can be advanced forward _i_ nodes with addition **(iter+1 ; iter+i)**
* It can be used to access member variables **(iter->data ; iter->next)**


**Input:**

_If you did well on the previous assignment, then congrats! Simply adapt your main program to use a LinkedList instead of an ArrayList._

Input will be a stream of lines that will give specific information about an event for William and how it will affect his schedule. 
The first line of input will be a list of jobs that William will start his schedule with. **William will always start with 3 jobs**. The positions of the job in the list should match the position in William’s schedule, for example the first job that appears in input should be at index 0 in William’s schedule. 

The second line will the number of days William has until eviction.

The rest of the lines of input will be events that affect William’s schedule. There will be one event for every day until eviction, and they will follow this format:

---

ADD **job** **timeslot** 
William gets a new job and adds it to his schedule. 
**timeslot** is an integer relating to the position within William’s schedule arraylist, and **job** is a string beginning and ending with quotation marks.  For ADD specifically, the range of **timeslot** is from 0 to the amount of elements in William’s schedule, inclusively. **timeslot** for FIRE and CAR_CRASH have a range from 0 to the amount of element’s in William’s schedule minus 1, inclusively.

---

FIRE (**job**) 
William gets fired from one of his jobs. 
All instances of that job should be removed from William’s schedule.

---

SLEPT_IN **time** 
William accidentally sleeps in one morning and gets fired from the jobs he missed.
**time** is an integer relating to how many shifts William slept through. All slept through shifts should be removed from William’s schedule. Removed shifts should start at index 0, going upwards.

---

CAR_CRASH **timeslot**
William crashes his car and can’t make it to any jobs in his schedule for the rest of the day.
**timeslot** is the position in William’s schedule where he crashes his car. Everything at and after the car crash should be removed from William’s schedule, e.g. CAR_CRASH 0 would remove everything from William’s schedule.

---

DISEASE
William gets struck down with a terrible illness and can’t make it to work at all today.
Remove everything in William’s schedule.

---

**Example input:**

```
Dentist Garbageman Lawyer
13
ADD Janitor 1
FIRE Dentist
FIRE Lawyer
ADD Cheesemonger 0
SLEPT_IN 2
ADD Pilot 1
ADD Baker 1
CAR_CRASH 2
DISEASE
ADD Coal-Miner 0
ADD Magician 0
ADD Fireman 1
FIRE Magician
```

**Output:**
After each event, print William’s current schedule for the day on its own line. If an event leaves William with nothing in his schedule, print the word _Unemployed_. You do not need to print William’s initial schedule

Example output:

```
Dentist Janitor Garbageman Lawyer
Janitor Garbageman Lawyer
Janitor Garbageman
Cheesemonger Janitor Garbageman
Garbageman
Garbageman Pilot
Garbageman Baker Pilot
Garbageman Baker
Unemployed
Coal-Miner
Magician Coal-Miner
Magician Fireman Coal-Miner
Fireman Coal-Miner
```

## Scoring:

To get full points on the assignment...
* Implement each function in the _MyList_ class **(unit_tests)**
* Fix any memory leaks or invalid memory operations **(mem_tests)**
* Address any warnings given by cppcheck **(static analysis)**
* Format your code using the clang-format utility **(style check)**

