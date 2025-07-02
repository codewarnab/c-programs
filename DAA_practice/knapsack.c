#include <stdio.h>

#define MAX 100

int n;
float weight[MAX], profit[MAX], ratio[MAX], x[MAX];
float capacity;

// Function to read input values
void read()
{
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of %d items:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &weight[i]);
    }

    printf("Enter profits of %d items:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);
}

// Function to sort items by profit/weight ratio (descending)
void itemsort()
{
    for (int i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swap profit
                float temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
            }
        }
    }
}

// Function to perform fractional knapsack using greedy method
float knapsack()
{
    float totalProfit = 0.0;
    float remaining = capacity;

    for (int i = 0; i < n; i++)
    {
        if (weight[i] <= remaining)
        {
            x[i] = 1.0;
            totalProfit += profit[i];
            remaining -= weight[i];
        }
        else
        {
            x[i] = remaining / weight[i];
            totalProfit += x[i] * profit[i];
            break; // knapsack is full
        }
    }

    return totalProfit;
}

// Function to display result
void optimal(float maxProfit)
{
    printf("\nSelected fractions of items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: %.2f\n", i + 1, x[i]);
    }
    printf("\nMaximum Profit: %.2f\n", maxProfit);
}

// Main function
int main()
{
    read();
    itemsort();
    float maxProfit = knapsack();
    optimal(maxProfit);
    return 0;
}
