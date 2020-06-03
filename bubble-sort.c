#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Create an array to store the numbers to sort
    const int sizeOfNumbers = argc - 1;
    int numbers[sizeOfNumbers];

    // Populate the array with the arguments
    for (int i = 0; i < sizeOfNumbers; i++)
    {
        // Add the number to the array as an int
        numbers[i] = atoi(argv[i + 1]);
    }

    // This keeps track if there are still elements that may need sorting
    // It's how we track when to stop the bubble sort
    bool hasSwapped;

    // Bubble sort
    do
    {
        // No elements sorted until now in this iteration
        hasSwapped = false;

        // For each number we will try and swap it if it's out of order
        for (int i = 0; i < sizeOfNumbers - 1; i++)
        {
            // Store the value for swapping later
            const int swapValue = numbers [i + 1];

            // Check if elements are in the correct order
            if (numbers[i] > swapValue)
            {
                // Swap them
                numbers[i + 1] = numbers[i];
                numbers[i] = swapValue;
                hasSwapped = true;
            }
        }
    }
    // Keep sorting while the last iteration has swapped at least one value
    while (hasSwapped);

    // Print out the sorted array
    for (int i = 0; i < sizeOfNumbers; i++)
    {
        printf("%i ", numbers[i]);
    }

    printf("\n");
    return 0;
}
