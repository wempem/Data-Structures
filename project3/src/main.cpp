#include <stdio.h>
#include <iostream>
#include <binarytree.hpp>
#include <scapetree.hpp>
#include <time.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	 BinaryTree<double> bt;
	srand(1000);
	//std::cout << bt.getHeight();
	//std::cout << bt.inorderString();
	ScapeTree<double> st;	
	//std::cout << st.inorderString();
	//std::cout << st.contains(2);
   clock_t start, diff;

   // timeAmount is used to print out the time in seconds.
   double timeAmount;
	double insert;
	
   // We want to run our algorithm over varying sizes.
   for (double i = 1000; i < 100000000; i += 100) {
       // Capture the start clock
       start = clock();

       // This is were your algorithm should be called.
       bt.put(rand());

       // Capture the clock and subtract the start to get the total time elapsed.
       diff = clock() - start;

       // Convert clock_t into seconds as a floating point number.
       timeAmount = diff * 1.0 / CLOCKS_PER_SEC;

       // Print out first the size (i) and then the elapsed time.
      // std::cout << i << " " << timeAmount << "\n";

       // We flush to ensure the timings is printed out.
      // std::cout << std::flush;
   }
	return 0;
}
