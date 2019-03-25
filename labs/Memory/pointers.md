# Lab 05: Pointers->get_excited()

## 1. Introduction

In today's lab you will use CS50's `debug50` to explore and understand how pointers work, and how they can be used when working with arrays.
Understanding pointers is extremely important to this class since nearly all of the data structures that we will be creating use pointers heavily.

This lab comes with two starter code files: `lab-05.cpp` and `secret-message.cpp`.
You will use the former for the majority of the lab, as the latter is just for the final section.
Also note that you will not need to write any code with this lab; you will need to follow through the starter code using the debugger as directed and answer questions about what you observe.

This is a guided lab, so you **need** to read everything.
Follow each instruction and answer each question as you go.

## 2. Starting Out With Pointers

**Before doing anything** set breakpoints at lines `14`, `35`, `45` and `72`.
Now compile the `lab-05.cpp` and run the debugger on the output file.
The program should stop at line `14`.

To start off your wonderful journey into the world of pointers, you will start by looking at instantiations of two variables, an `int` and an `int *` (a pointer to an `int`, or an `int` pointer).

```C++
// Declare an int variable, assign it the value 5
int number = 5;

// Declare a pointer to an int and set it to the address of number
int *numberPtr = &number;

```

The first line of the program in `main()` declares an `int` called `number` and sets it to the value `5`.
After setting a breakpoint at line `14` and running your program in `debug50` you should be paused at the first line of code in `main()`.

> **Question 1:** When you pause at line `14` you should be able to see the value of `number` listed in the debug menu on the right.
What is the value of `number` so far?
Why is it this value?

> **Question 2:** Step through line `14` only once using the step button located just next to the play button in the debug menu (reads "step over" when you hover your mouse over it) and inspect the value of `number` again.
What is the value of `number` now?  Why did it change?

Before discussing what happens on line `17`, it's important to know that every variable in a program has a memory address associated with it.
As it turns out, you as a programmer can do things with these memory addresses in your programs, and that's what pointers are all about.

Since you stepped through your code only once so far, you should be at line `17`, the second line of code in `main()`.
Line `17` declares an `int *` called `numberPtr`, ("ptr" being short for "pointer"), and sets it to the memory address of the variable `number` using the ***address-of operator:*** `&`.
This operator is used to get a variable's memory address.
It should then be clear that an `int *` is just a variable that holds the memory address associated with an `int`.

> **Question 3:** When you pause at line `17` inspect the value of `numberPtr`.
What is the value of `numberPtr` so far?  Why is it this value?

> **Question 4:** Step through line `17` only once using `step` and inspect the value of `numberPtr` again.
What is the value of `numberPtr` now?
Why did it change?

Now, getting the memory address of a variable wouldn't be very helpful if you couldn't use it to get back to the original variable.

```C++
// Change the value of number using the pointer
*numberPtr = 10;
```

The above code snippet uses the `*` operator for something much different than multiplication.
In this case, the `*` is called the ***Dereference*** operator.
*Dereferencing* a pointer directly accesses the element it *points* to.
This has the added benefit of allowing you to modify the value at that address without specifically needing a variable associated with it.

> **Question 5:** Step through the code using the command "step over" button until you reach line `24`.
Inspect the value of number, and step over once more.
What is the value of number now?
Was `numberPtr`'s value changed?

## 3. Passing Arguments by Value

You should now be on line `27`, which contains the call to the function `my_func`.
This function takes two arguments: the first an `int` and the second an `int *` passed by **value**.
Click the **step into** button, which is located to the right of the **step over** button.
This should take you to line `5`.

> **Question 6:** In the debugger you can now view the data stored in the variables belonging to both `main` and `my_func` by clicking between them in the Call Stack section (just as you did in Lab 3).
What are the values of x and y in `my_func`?
Where have you seen the address stored in y before?

Now step through to the next line, and look at `y` in the debugger.
The memory with the address stored in `y` now contains the value 15, and the same data can be accessed anywhere else, so long as the same address is used.
In other words, when a pointer is passed to a function, the memory location it points to can be directly modified by the function it was passed to.
Any changes made to variables *passed by value* will not be kept after the function returns.  When a variable is passed by value, the data stored in the variable (the value) is copied into the call stack when the function is called.

> **Question 7:** Now step over until you exit the function.
Name all the variables in `main` that have been affected by the call to `my_func`.
What would have happened if the function call had been `my_func(number, 10)` instead, and why?
(If something seems wrong about this, you're on the right track).

**You may now press the "run" button in the debugger to advance to the next breakpoint.**
You should now be paused at line `35`.

## 4. Arrays on the Stack and Heap

By this point you should be fairly familiar with data stored on the stack (we did a whole lab about it), but there is another major location in which memory can be stored: *the heap*.

In contrast to the stack, the heap is not managed automatically by the program, rather, it is a special location in memory where programmers can store larger, and longer term variables.
While the stack is literally a stack of frames, one per function called, the heap is a large pile where data can be thrown at any point in time.
Functions can share heap memory by passing around pointers, significantly speeding up operations on large matrices and vectors.
By it's nature, memory on the heap must be both specifically declared, and specifically freed, again unlike the stack, where frames are destroyed automatically upon completion.

> Note: You can read [this pdf](http://cslibrary.stanford.edu/102/PointersAndMemory.pdf) if you would like to learn more about pointers and memory in C++

```C++
// Declare an int array on the stack
int array_on_stack[number];
std::cout << "The address of array_on_stack is: " << array_on_stack << std::endl;

// Declare an int array on the heap
int *array_on_heap = new int[number];
std::cout << "The address of array_on_heap is: " << array_on_heap << std::endl;

// Set each element of array_on_heap
for (int i = 0; i < number; i++)
{
	array_on_heap[i] = i;
}
```

As noted in the above sample, the first declaration allocates space on the stack (within the current frame), for the array `array_on_stack`.
Beneath this, lies a potentially new operator: `new`.
Whenever you need to put memory on the heap, you must use this `new` operator, which signifies that the variable should be placed on the heap, not the stack.
Since `new` always returns a pointer, we set the variable type to a pointer as well, `int *array_on_heap` will be the address of the heap memory allocated for the array.

Step through the code until you are paused on line `45`.

> **Question 8:** What are the values of `array_on_stack` and `array_on_heap`?
`debug50` will not show the value of `array_on_stack` by default, so you should type `array_on_stack` into "Watch Expressions" to get the value.
Now plug these values into [this hexadecimal to decimal converter](http://www.binaryhexconverter.com/hex-to-decimal-converter).
What do these values represent?
What is the obvious difference between these two numbers (*Hint*: think magnitude)?
Why might they differ in this way?

Notice that we printed the memory addresses of the start of both arrays just like when we printed the value of `numberPtr`, which was pointing to `number`.
This is because an array is accessed the same way that an integer is accessed when using a pointer.
In other words `array_on_stack` and `array_on_heap` are pointers too.
The difference is that memory is reserved to store more than one element when instantiating an array.
In fact, `numberPtr` is actually more similar to `array_on_stack` since it also points to memory on the stack.
If you want to allocate a *single integer* on the heap, you will use `new int;` on the right side of the equals sign (notice the lack of square brackets).

Let's prove to ourselves that `array_on_heap` is a pointer, and that its elements can be accessed using a different pointer.
In the code snippet below we set `numberPtr = array_on_heap`.
We should now be able to access the elements of `array_on_heap` using both pointers.

```C++
// Make numberPtr point to array_on_heap
numberPtr = array_on_heap;
```

> **Question 9:** You should be paused at line `45`.
Step through the code once and inspect the values of `array_on_heap` and `numberPtr`.
Ware the values and what do they represent?
How do they compare?

> **Question 10:** Now, in "Watch Expressions" type `array_on_heap[3]` and `numberPtr[3]`.
What are the values and what do they represent?
How do they compare?

Despite being allocated in two different places, and in two different ways, arrays on the stack and on the heap are (for the most part) functionally the same.
We could set `numberPtr = array_on_stack` and achieve the same results (assuming we added elements to `array_on_stack` first).
The major difference between the two allocation types is how the memory is handled.
When a variable is declared on the stack, the program knows exactly how much memory is needed to store that variable and so will allocate it automatically when the function is called, and deallocate it when it completes.
On the other hand, memory on the heap (sometimes referred to as *dynamic memory*) is allocated without a specific known size at compilation.
Responsibility lies with the programmer for making sure any memory that is allocated on the heap is deallocated (or freed) before it is inaccessible (or the program ends).

## 5. Working With Arrays Via Pointers

With the new knowledge that arrays are essentially pointers to memory allocated for more than one element, you will likely want to know how you can use this to your advantage.
Well it turns out there is a lot you can do when you start thinking about arrays in terms of pointers.

```C++
// Access the first element of the array
number = numberPtr[0];

// Dereference the first element of the array
number = *numberPtr
```

The above code accomplishes the same thing twice.
It sets `number` to the first element of our array by dereferencing the array pointer at its first position.
The syntax to dereference the array is `[]` in the case of the first example, and `*` in the case of the second.

> **Question 11:** Step through the code once, pausing at line `48` and inspect the value of `number`. What is its value?
To get the memory address of `number` type `&number` in "Watch Expressions".
What is the address of `number`?
Step through the code once again, pausing at line `51`.
Inspect the value of `number` again, what is its value?
Did the value of `number` change?  Why or why not?
Get the memory address of `number` again?  Did the value change?

Now that we know that an array pointer simply points to the first element in the array, let's examine how we traverse the array to access its elements.
Let's print out the memory address of the first two elements in `numberPtr`.
To do this we will simultaneously dereference the array element and get its memory address using the `&` operator as shown in the next question.

> **Question 12:** Enter the expressions `&numberPtr[0]` and `&numberPtr[1]` in "Watch Expressions".
You should get two different addresses.
What is the numerical difference between the two values you just printed (use the hexadecimal to decimal converter if you need to).
Type `sizeof(int)` in "Watch Expressions".
What do you notice about the result?

> **Question 13:** If the difference in memory addresses for an integer array is equal to `sizeof(int)`, what does this tell you about how a program knows where to find the next element in an array when provided with a pointer to some element in the array?
How might the program know where the array stops?

> **Question 14:** How many bytes does it take to represent a single memory address?  How many bits?

The next two lines of code are again, equivalent, except now we are getting the third element in our array.
The first line is self explanatory, using the `[]` syntax to dereference the array pointer (as that's what indexing an array really is).
The second example, however, uses pointer arithmetic to accomplish the same thing.
The syntax `numberPtr+2` tells the program to start at the first element of `numberPtr` and advance two more elements.
Step through these next two lines of code (you should pause at line `60`) and watch `number` each time to prove this to yourself.

```C++
// Dereference the third element of the array
number = numberPtr[2];

// Dereference the third element of the array
number = *(numberPtr+2)
```

> **Question 15:** If `*numberPtr` gets the first element in the array, what element does `*(numberPtr+1)` return?  What about `*(numberPtr+5)`?
Using the `[]` syntax, what is the equivalent of `*(numberPtr+9)`?  Using the `*` syntax, what is the equivalent of `numberPtr[7]`?
What is the numerical difference between the memory addresses `numberPtr+2` and `numberPtr+5`?

```C++
// Advance numberPtr by three
numberPtr = numberPtr+3;

// Dereference numberPtr at its new location
number = *numberPtr;
```

So far we have seen how to dereference elements of `numberPtr` without changing the memory location that `numberPtr` points to.
It is possible, however, to update `numberPtr` using pointer arithmetic so that it points to a new memory address going forward.
This is a very important concept in the implementations of many data structures and algorithms in C++, especially so for recursive algorithms.
The above code snippet advances the pointer by three elements.

> **Question 16:** What element number in `array_on_heap` does `numberPtr` point to now?
Using the `array_on_heap[]` syntax, what is the equivalent of `*numberPtr`?

**You may now press the "run" button in the debugger to advance to the next breakpoint.**
You should now be paused at line `72`.

```C++
// Make numberPtr point to array_on_stack
numberPtr = array_on_stack;

// Set number to 10
number = 10;

// Set each element of array_on_stack
for (int i = 0; i < number; i++)
{
	*numberPtr++ = i;
}
```

Now that we have seen that arithmetic operations can be applied to pointers, let's iterate through an array by incrementing the pointer one memory address at a time using the unary increment operator `++`.
In the above example `numberPtr = array_on_stack`, so now `numberPtr` can be used to access the elements in `array_on_stack` by setting these pointers equal to each other.
In the `for` loop, `numberPtr` is incremented by one for each pass of the loop.  However, the dereference operator `*`, and the assignment operator `=`, take precedence over the unary postfix operator `++`.
This means that the current value of `numberPtr` gets dereferenced and updated before we increment the memory address.

> **Question 17:** Step through each iteration of the `for` loop beginning at line `72`.
Type `numberPtr` in "Watch Expressions" and inspect its value until the loop terminates and you are paused at line `78`.
Write down the value of `numberPtr` for each iteration.

> **Question 18:** When we increment `numberPtr` by one, what is the numerical difference between the value of `numberPtr` before and after incrementing.  Why?

> **Question 19:**  Type `array_on_stack[5]` in "Watch Expressions".  What value is shown?
Did the process of incrementing through `numberPtr` succeed in updating `array_on_stack`?

## 6. Decoding a Secret Message

You have now finished with `lab-05.cpp` and will be looking into `secret-message.cpp`, so make sure you have the file in your IDE.
Compile and run the program, and take a look at the code. Is it clear what is going on?
Try to parse as much as you can before moving forward.

In this last code snippet we are doing something tricky.  We declare an integer array `secret_message` and assign each element in the array some number.
We then pass each element of this array to the function `printMessage()`.
The odd thing is that `printMessage()` expects a `char *` to be passed as an argument, not an `int` or an `int *`.
So how did we make this happen without the compiler complaining?
The trick is to cast the pointer to each element in `secret_message` as a `char *` so that the function thinks the pointer is pointing to a `char` and not an `int`.
The program doesn't know any better, all it knows is that we are passing some memory address, and that we told it that the memory address points to some character or string of characters.


```C++
// The size of our array
int arraySize = 5;

// Declare the array
long secret_message[arraySize];

// The size of our number type
int typeSize = sizeof(long);

// Why choose these numbers?
secret_message[0] = 478560413032;
secret_message[1] = 431316168567;
secret_message[2] = 7827304;
secret_message[3] = 6648417;
secret_message[4] = 7696249;

// Call our method to print secret message
for (int i = 0; i < arraySize; i++)
{
	printMessage((char*)&secret_message[i],typeSize);
}

std::cout << std::endl;
```

> **Question 20:** In your own words describe how to create a secret message of your own.
What is the process to create an integer that encodes a word?
How many letters can an `int` hold?
How many letters can a `long` hold?

## 7. Submission

For this lab you are to submit a text file containing all the answers you were able to attain during the lab.
The file should be formatted as follows:

```
Names of Group Members
1. Answer
2. Answer
etc.
```
