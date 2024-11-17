#include <stdio.h>
#include <stdlib.h>

int maxArea(int* heights, int heightSize) {
    int water = 0, *i = heights, *j = i + heightSize - 1;
    while (i < j) {
        int h = *i < *j ? *i : *j;
        int w = (j - i) * h;
        if (w > water) water = w;
        while (*i <= h && i < j) i++;
        while (*j <= h && i < j) j--;
    }
    return water;
}

// Function to run test cases
void runTest(int* heights, int size, int expectedOutput) {
    printf("Input: [");
    for (int i = 0; i < size; i++) {
        printf("%d", heights[i]);
        if (i < size - 1) printf(",");
    }
    printf("]\n");
    
    int result = maxArea(heights, size);
    printf("Output: %d\n", result);
    printf("Expected: %d\n", expectedOutput);
    printf("%s\n\n", (result == expectedOutput) ? "PASSED" : "FAILED");
}

int main() {
    // Test Case 1
    int heights1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size1 = sizeof(heights1) / sizeof(heights1[0]);
    runTest(heights1, size1, 49);

    // Test Case 2
    int heights2[] = {1, 1};
    int size2 = sizeof(heights2) / sizeof(heights2[0]);
    runTest(heights2, size2, 1);

    // Test Case 3
    int heights3[] = {4, 3, 2, 1, 4};
    int size3 = sizeof(heights3) / sizeof(heights3[0]);
    runTest(heights3, size3, 16);

    // Test Case 4
    int heights4[] = {1, 2, 1};
    int size4 = sizeof(heights4) / sizeof(heights4[0]);
    runTest(heights4, size4, 2);

    return 0;
}
