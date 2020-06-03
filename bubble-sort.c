#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void alert(char *message)
{
    printf("%s", message);
    printf("Usage: bubbleSort firstNum secondNum [...] \n");
}

int main(int argc, char *argv[])
{
    // Program entrypoint without arguments
    if (argc == 1)
    {
        alert("This applicattion uses bubble sort to sort an array of numbers \n");
        printf("\nCode is MIT licensed, source at github.com/DoodlesEpic/Bubble-Sort \n");
        return 0;
    }

    // Handle missing arguments in the input
    if (argc < 3)
    {
        alert("Error: Provide at least 2 numbers to sort \n");
        return 1;
    }

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
