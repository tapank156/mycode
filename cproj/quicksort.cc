#include "include/error.h"
#include "include/first.h"
#include "include/template.h"
#include "unistd.h"
#include "utmp.h"
#include "fcntl.h"
#include "pwd.h"
#include <map>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>


void QuickSort(int a[], int lo0, int hi0) {
  int lo = lo0;
    int hi = hi0;
    int mid;

    if (hi0 > lo0) {
	cout << "begin#lo0=" << lo0 << " hi0=" << hi0 << "\n"; 

      /*
       * Arbitrarily establishing partition element as the midpoint of the
       * array.
       */
      mid = a[(lo0 + hi0) / 2];

      // loop through the array until indices cross
      while (lo <= hi) {
	cout << "loop lo=" << lo << " hi=" << hi << "\n"; 
        /*
         * find the first element that is greater than or equal to the
         * partition element starting from the left Index.
         */
        while ((lo < hi0) && (a[lo] < mid)){
          ++lo;
	  cout << "--a[" << lo << "]=" << a[lo] << " mid=" << mid << "\n"; 
        }

        /*
         * find an element that is smaller than or equal to the
         * partition element starting from the right Index.
         */
        while ((hi > lo0) && (a[hi] > mid)){
          --hi;
	  cout << "--a[" << hi << "]=" << a[hi] << " mid=" << mid << "\n"; 
        }
        // if the indexes have not crossed, swap
        if (lo <= hi) {
          int t = a[hi];
          a[hi] = a[lo];
          a[lo] = t;

          ++lo;
          --hi;
        }
      }

      /*
       * If the right index has not reached the left side of array must
       * now sort the left partition.
       */
      if (lo0 < hi)
        QuickSort(a, lo0, hi);

      /*
       * If the left index has not reached the right side of array must
       * now sort the right partition.
       */
      if (lo < hi0)
        QuickSort(a, lo, hi0);

    }
}


int main(int argc, char* args[])
{
       int* a;
        a = new int[10];
        a[0] = 10;
        a[1] = 15;
        a[2] = 22;
        a[3] = 13;
        a[4] = 6;
        a[5] = 5;
        a[6] = 9;
        a[7] = 42;
        a[8] = 32;
        a[9] = 2;


	for(int k = 0; k < 10; k++) {
		cout << a[k] << ", "; 
	}
	cout << "\n"; 
	QuickSort(a,0,9);
	for(int k = 0; k < 10; k++) {
		cout << a[k] << ", "; 
	}
	cout << "\n"; 
	return 0;
}
