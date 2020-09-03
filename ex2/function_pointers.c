/*************************************
* Lab 1 Exercise 2
* Name: Chee You
* Student No: A0188719J
* Lab Group: 01
*************************************/
#include "function_pointers.h"
#include "functions.h"

// write the necessary code to initialize the func_list
// array here, if needed

int (*func_list[5]) (int x);

void update_functions() 
{	
    func_list[0] = add_one;
    func_list[1] = add_two;
    func_list[2] = multiply_five;
    func_list[3] = square;
    func_list[4] = cube;
}
