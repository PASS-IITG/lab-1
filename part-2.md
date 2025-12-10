# **Part 2: Makefile Basics and String Utilities**

## **1. Introduction**

This lab introduces two important components of systems programming:

1. Makefile-based build automation
2. Implementation of a small String Utilities Library in C/C++, organized across header and source files

You will learn how multi-file C/C++ projects are compiled, how Makefiles automate the build process, and how to implement and test a utility library. You will also use **Git** and **GitHub Classroom** to manage and submit your work.

# **2. Makefile Basics**

## **2.1 What Is a Makefile?**

A Makefile is a configuration file used by the `make` build automation tool.
It describes:

* How to compile each part of a program
* How different files depend on one another
* How to link everything into an executable

Makefiles eliminate repetitive manual compilation steps.

### **Without a Makefile**

```bash
g++ -c src/string_utils.cpp -o build/string_utils.o
g++ -c tests/test.cpp -o build/test.o
g++ build/string_utils.o build/test.o -o stringlab
```

### **With a Makefile**

```bash
make
```

## **2.2 How Makefile Rules Work**

Each rule has the following structure:

```
target: dependencies
<TAB> command
```

### Example Rule

```make
stringlab: build/string_utils.o build/test.o
    g++ build/string_utils.o build/test.o -o test_lab1
```

Make uses timestamps:

* If a dependency changed, the target is rebuilt.
* If nothing changed, Make skips rebuilding.

Before writing Makefile, you first need to implement the following: 

# **3. String Utilities  (Implementation Guide)**

You will implement three utility functions:

1. `reverseString`
2. `toUpper`
3. `resizeArray`

These are declared in a header file and implemented in a source file.


## **3.1 File Structure (Provided in Template)**

```
include/
    string_utils.h
src/
    string_utils.cpp
tests/
    test.cpp
build/
Makefile
```


## **3.2 Header File — string_utils.h**

```cpp
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <cstddef>

void reverseString(char* s);
void toUpper(char* s);
int* resizeArray(int* arr, size_t oldSize, size_t newSize);

#endif
```

Do not modify function signatures.


## **3.3 Implementing `reverseString`** in `src/string_utils.cpp`

**Goal:** Reverse the characters in a null-terminated C string.

### Example

Input:
`hello`

Output:
`olleh`

### Notes

* Modify the string **in place**.
* Use two indices: start and end.
* Swap characters until reaching the midpoint.


## **3.4 Implementing `toUpper` in `src/string_utils.cpp`

**Goal:** Convert every character in the string to uppercase.

### Example

Input:
`HeLLo`

Output:
`HELLO`

### Notes

* Use the `toupper` function.
* Move through the string sequentially using a pointer.


## **3.5 Implementing `resizeArray` in `src/string_utils.cpp`**

**Goal:** Create a new integer array of size `newSize`, copy elements from the old array, and return the new array.

### Notes

* Allocate a new array of size `newSize`.
* Copy `min(oldSize, newSize)` elements.
* Free the old array.
* Return the new array.

### Example

Original array (size 3):

```
[10, 20, 30]
```

Resize to 5:

```
[10, 20, 30, ?, ?]
```


## **3.6 Test Program — tests/test.cpp**

This program will:

* Read a string from the user
* Call your string utility functions
* Print outputs
* Demonstrate array resizing

You do **not** need to modify this file unless instructed.

## **3.7 Makefile for the String Utilities**

A complete Makefile for this lab:

```make
CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude

TARGET = test_lab1
OBJ = build/string_utils.o build/test.o

all: $(TARGET)

build/string_utils.o: src/string_utils.cpp include/string_utils.h
	$(CXX) $(CXXFLAGS) -c src/string_utils.cpp -o build/string_utils.o

build/test.o: tests/test.cpp include/string_utils.h
	$(CXX) $(CXXFLAGS) -c tests/test.cpp -o build/test.o

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -rf build/*.o $(TARGET)
run:
	./$(TARGET)
```

# **4. Building and Running**

Compile:

```bash
make
```

Run:

```bash
./test_lab1
or
make run
```

Clean:

```bash
make clean
```

Ensure your output is correct for multiple test cases.


# **5. Submitting to GitHub Classroom**

When finished (All tests passed):

### Step 1: Stage your changes

```bash
git add Makefile
git add src/string_utils.cpp
```

### Step 2: Commit your work

```bash
git commit -m "Complete String Utilities and Makefile"
```

### Step 3: Push your submission

```bash
git push
```

Your **latest push** becomes your submission.
Verify by checking your GitHub repository.


