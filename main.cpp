// main.cpp
// Purpose: Test 2x2 Matrix ADT

/* ******************************************
 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: June 23, 2023
 ******************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Matrix2x2.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
   Mat2x2 m1(2, -1, 1, 2); // test constructor
   cout << "m1\n" << m1 << endl;    // operator<<, the output operator

   Mat2x2  m1Inv = m1.inverse();    // inverse
   cout << "m1.invers()\n" << m1Inv << endl;
   
   Mat2x2 m1Inv_times_m1 = m1Inv * m1;   
   cout << "m1 * m1.invers()\n" << m1Inv_times_m1  << endl;
      
   // the inverse of any 2x2 mutiplied by the 2x2 itself must give the identity 2x2 
   assert(m1Inv_times_m1 == Mat2x2(1, 0, 0, 1)); 

   Mat2x2 m1_times_m1Inv = m1 * m1Inv;
   cout << "m1.invers() * m1\n" << m1_times_m1Inv << endl;
   // any 2x2 mutiplied by its inverse must give the identity 2x2 
   assert(m1_times_m1Inv == Mat2x2(1,0,0,1)); 

   cout << "det(m1) =   " << m1.determinant() << "\n";
   cout << "trace(m1) = " << m1.trace() << "\n\n";

   if (m1.isInvertible())
   {
      cout << "m1 is invertible\n" << m1 << endl;
   }
   else
   {
      cout << "m1 is not invertible\n" << m1 << endl;
   }

   if (!m1)
   {
      cout << "m1 is not invertible\n" << m1 << endl;
   }
   else
   {
      cout << "m1 is invertible\n" << m1 << endl;
   }

   Mat2x2 m2 = m1 + 1;  // Mat + int, and assignment op=
   assert(m2 == Mat2x2(3, 0, 2, 3));
   cout << "m2\n" << m2 << endl;
   
   m2 = 1 + m1;  // op=, int + Mat
   assert(m2 == Mat2x2(3, 0, 2, 3));

   Mat2x2 m3 = m2 - 1;  // Mat -int
   assert(m3 == m1);
   cout << "m3\n" << m3 << endl;

   Mat2x2 m4 = 1 - m3; // int - Mat 
   cout << "m4\n" << m4 << endl;
   assert(m4 == Mat2x2(-1, 2, 0, -1));

   Mat2x2 m5 =  m4 * 5 ; // Mat * int
   cout << "m5\n" << m5 << endl;
   assert(m5 == Mat2x2(-5, 10, 0, -5));
   
   Mat2x2 m6 = 10 *  m5; // int * Mat
   cout << "m6\n" << m6 << endl;
   assert(m6 == Mat2x2(-50, 100, 0, -50));
   
   assert(m6 / 10 == m5);  // Mat / int
   assert(10 / m6 == 10 * m6.inverse());  // int / Mat, inverse
   assert(5 * m4 * 10 == m6);  // int * Mat * int == Mat
   
   Mat2x2 m7 = m1++;
   cout << "m1\n" << m1 << endl;
   cout << "m7\n" << m7 << endl;
   assert(m7 == m1 - Mat2x2(1, 1, 1, 1));
   
   Mat2x2 m8 = --m1;  // --Mat
   cout << "m1\n" << m1 << endl;
   cout << "m8\n" << m8 << endl;
   assert(m8 == m1 );
   m8--;  // Mat--
   cout << "m8\n" << m8 << endl;
   assert(m1 == 1 + m8);
   assert(m1 - 1 == m8);
   assert(-m1 + 1 == -m8);
   assert(2 * m1 == m8 + m1 + 1);
   assert(m1 * m1 == m1 *(1 + m8));
   cout << "m8 is " << (m8.isSymmetric() ? "" : "not") << " symmetric\n";
   Mat2x2 m9(123, 6, 6, 4567.89);
   cout << "m9\n" << m9 << endl;
   cout << "m9 is " << (m9.isSymmetric() ? "" : "not") << " symmetric\n";

   // subscripts (non-const)
   m9[0] = 3;
   m9[10] = 1;
   m9[2] = 7;
   m9[3] = 4;
   cout << "m9\n" << m9 << endl;
   assert(m9 == Mat2x2(3, 1, 7, 4));
   cout << "det(m1) =   " << m1() << "\ntrace(m1) = " << m1.trace() << "\n\n";
   cout << "det(m9) =   " << m9() << "\ntrace(m9) = " << m9.trace() << "\n\n";
   cout << "m9 is " << (m9.isSimilar(m1) ? "" : "not") << " similar to m1\n";

   // subscripts (const version)
   const Mat2x2 cm9{ m9 };
   cout << "cm9\n" << cm9 << endl;

   m9 += m9;
   cout << "m9\n" << m9 << endl;
   assert(m9 == 2 * Mat2x2(3, 1, 7, 4));

   Mat2x2 m10;
   m10 += (m9 / 2);
   cout << "m10\n" << m10 << endl;
   assert(m10 == Mat2x2(3, 1, 7, 4));
 
   m10 *= 2;
   cout << "m10\n" << m10 << endl;
   assert(m10 == m9);

   m10 /= 2;
   cout << "m10\n" << m10 << endl;
   assert(m10 == m9/2);

   m10 += 10;
   cout << "m10\n" << m10 << endl;
   assert(m10 == (m9 +20) / 2);

   m10 -= 10;
   cout << "m10\n" << m10 << endl;
   assert(m10 == 0.5 * m9);

   // testing transpose()
   Mat2x2 m11 = m10.transpose();
   cout << "m11\n" << m11 << endl;
   assert(m10 == m11.transpose());
   
   //testing operator>>
   Mat2x2 m12;

   cout << "In response to the following prompt, \n";
   cout << "enter the numbers 10, 20, 30, 40, in that order\n\n";

   cin >> m12;
   cout << "\nm12\n" << m12 << endl;
   if (m11)  // show off converting a martrix m11 to a bool
   {
      cout << "m12 is invertible" << '\n';
   }
  assert(m12 == Mat2x2(10, 20, 30, 40));

   // testing unary operators + and -
   Mat2x2 m13 = -m11;
   cout << "m13\n" << m13 << endl;
   assert(+m11 == -m13);

 
   cout << "Test completed successfully!" << endl;
       return 0;
}