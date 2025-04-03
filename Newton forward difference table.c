#include <stdio.h>

// Function to calculate the forward difference table
void forwardDifferenceTable(float x[], float y[], int n) {
    float diffTable[n][n];  // 2D array to store differences
    int i, j;

    // Initialize first column with y values
    for(i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    // Calculate forward differences
    for(j = 1; j < n; j++) {
        for(i = 0; i < n-j; i++) {
            diffTable[i][j] = diffTable[i+1][j-1] - diffTable[i][j-1];
        }
    }

    // Print the forward difference table
    printf("\nForward Difference Table:\n");
    printf("x\t\ty\t\t");
    for(j = 1; j < n; j++) {
        printf("Δ^%dy\t", j);
    }
    printf("\n");

    // Print the table with x and difference values
    for(i = 0; i < n; i++) {
        printf("%.2f\t\t", x[i]);
        for(j = 0; j < n-i; j++) {
            printf("%.2f\t\t", diffTable[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;  // number of data points
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    float x[n], y[n];  // arrays for x and y values
    
    // Input x and y values
    printf("Enter the values of x and corresponding y:\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }
    
    // Call function to create and display forward difference table
    forwardDifferenceTable(x, y, n);
    
    return 0;
}