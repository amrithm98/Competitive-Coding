/*
 * Reference:
 * http://www.quora.com/Computer-Programming/What-are-some-cool-bit-manipulation-tricks-hacks
 * http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/
 */

#include <iostream>
#include <string.h>

using namespace std;

// print binary representation of an integer
void int_to_bin(int num)
{
  char str[9] = {0};
  int i;
  for (i=7; i>=0; i--)
  {
    str[i] = (num&1) ? '1' : '0';
    num >>= 1;
  }
  cout << str << endl;
}
// (n & 1) test if the first bit is set
bool even(int n)
{
  return ((n & 1) == 0);
}

// Test if the n-th bit is set(0th, 1th, .. nth)
bool nth(int x, int n)
{
  return (x & (1 << n)) != 0;
}

// set the nth bit
int set_nth(int x, int n)
{
  return (x | (1 << n));
}

// unset the n-th bit
int unset_nth(int x, int n)
{
  return (x & ~(1 << n));
}
// Toggle the n-th bit.
int toggle(int x, int n)
{
  return (x ^ (1 << n));
}

// Turn off the rightmost 1-bit
int off_rightmost(int x)
{
  return (x & (x - 1));
}

/*
 * Find out the number of binary 1s in an integer number. native solution below, more efficient using
 * turn off the rightmost 1-bit trick.
 * int count=0;
 * while (n)
 * {
 *   n = n&(n-1);
 *   count +=1;
 * }
 * return count;
 */

int findOnes(int n)
{
  int count = 0;
  while(n)
  {
    count += n&1;
    n >>= 1;
  }
  return count;
}

/*
 * test whether an integer is a power of two.
 */

bool ispower2(int n)
{
  return !(n & (n-1));
}

// isolate the rightmost 1-bit, two possible cases(there is a rightmost 1-bit, and the value is 0)

int isolate(int x)
{
  return (x & (-x));
}

// right propagate the rightmost 1-bit, 01010000=>01011111
int propagate(int x)
{
  return (x | (x-1));
}

// isolate the rightmost 0-bit, 10101011 => 00000100
int isolate0(int x)
{
  return (~x & (x+1));
}

// Turn on the rightmost 0-bit. 10100011 => 10100111
int turn0(int x)
{
  return (x | (x+1));
}

int main()
{
  int_to_bin(10);
  cout << "test even(n): even(-43) = "  << even(-43) << endl;  // 0
  cout << "test nth(x, n): nth(122, 3) = " << nth(122, 3) << endl; // 1
  cout << "test set_nth(x, n), set_nth(16,1) = " << set_nth(16, 1) << endl; // 18
  cout << "test unset_nth(x, n), unset_nth(127, 4) = " << unset_nth(127, 4) << endl; // 111
  cout << "test toggle(x, n), toggle(16, 3) = " << toggle(16,3) << endl; // 10000 => 11000
  cout << "test turn off rightmost 1-bit off_rightmost(x), off_rightmost(00010000) = " << off_rightmost(16) << endl; // 0
  cout << "test Isolate the rightmost 1-bit, isolate(9) = " << isolate(9) << endl; // 1001 => 0001 
  cout << "test power two, 4 is power 2? : " << ispower2(4) << endl;
  cout << "test right propagate the rightmost 1-bit, propagate(12)= " << propagate(12) << endl;
  cout << "test Isolate the rightmost 0-bit, isolate0(3) = " << isolate0(3) << endl; // 0011 => 0100
  cout << "test turn on the rightmost 0-bit, turn0(3)=" << turn0(3) << endl; // 0011 => 0111
  return 0;
}