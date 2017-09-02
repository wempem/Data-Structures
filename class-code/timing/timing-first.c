#include <iostream>
#include <time.h>

void simple(int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += i;
        }
    }
}

int main(int argc, char *argv[]) { // Standard main heading.
    /* clock_t is the data type for storing timing information.
     * We must make two variables, one for the start and the other to capture
     * the difference.
     */
    clock_t start, diff;

    // timeAmount is used to print out the time in seconds.
    double timeAmount;

    // We want to run our algorithm over varying sizes.
    for (int i = 1000; i < 1000000; i += 1000) {
        // Capture the start clock
        start = clock();

        // This is were your algorithm should be called.
        simple(i);

        // Capture the clock and subtract the start to get the total time elapsed.
        diff = clock() - start;

        // Convert clock_t into seconds as a floating point number.
        timeAmount = diff * 1.0 / CLOCKS_PER_SEC;

        // Print out first the size (i) and then the elapsed time.
        std::cout << i << " " << timeAmount << "\n";

        // We flush to ensure the timings is printed out.
        std::cout << std::flush;
    }
    return 0;
}

