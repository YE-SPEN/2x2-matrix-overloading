COMP5421 Assignment #3
Submitted by: Eric Spensieri (ID #26997252)
==================

The Matrix2x2 project is a fully self-sufficient ADT which provides stnadard operations on 2x2 Matrices implemented as a std::array<std::array<double, 2>, 2> along with all necessary overload operations to manipulate and compare Mat2x2 objects. 


Features
========

The Matrix2x2 ADT comes with the below built-in functionalities & operator overload capabilities:
 
1.	Standard Matrix operations including inverse(), transpose()
2. 	Matrix value calculation for trace() and determinant()
3. 	Matrix boolean evaluators for isSimilar(), isInvertible(), isSymmetric()
4.	Input & Output overload 
5.	Relational equality overload ==, !=
6.	Boolean & conversion overloads
7.	Subscript overload [] and const [] and function overload ()
8.	Unary operator overloads +, -, ++, --
9.	Compound operator overloads +=, -=, *=, /=
10.	Binary operator overloads +, -, *, /


Requirements
============

To run the Dictionary project, you need:

C++ compiler that supports C++11 or higher.


Usage
=====

Run the project from your chosen IDE, ensuring to have all header & implementation files along with the main.cpp executable in the same directory. 

Run the main.cpp from your IDE & enter the numbers 10 20 30 40 when prompted. Test will be output directly to the terminal. 


File Structure
==============

The Matrix project consists of the following files:

Matrix2x2.h: 		Header file for the Word class.
Matrix2x2.cpp: 		Implementation of the Word class.
main.cpp:	 	Main program execution file with menu interface to facilitate dictionary generation.

