#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum number of jobs

// Structure to hold job details
typedef struct
{
    char id[5];   // Job identifier (string)
    int profit;   // Profit earned by doing the job
    int deadline; // Deadline by which job should be completed
} Job;

Job jobs[MAX]; // Array to store all jobs
int n;         // Number of jobs

// a) Read job details from user
void readJobs()
{
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Job ID: ");
        scanf("%4s", jobs[i].id);
        printf("Enter Profit: ");
        scanf("%d", &jobs[i].profit);
        printf("Enter Deadline: ");
        scanf("%d", &jobs[i].deadline);
    }
}

// b) Sort jobs array by descending profit using Bubble Sort
void sortJobs()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                // Swap jobs[j] and jobs[j+1]
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

// c) Schedule jobs to maximize total profit under deadlines
void jobSequencing()
{
    int maxDeadline = 0;
    // Find the maximum deadline among all jobs
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Arrays to hold the result and slot occupancy
    char result[maxDeadline + 1][5];
    int slot[maxDeadline + 1];

    // Initialize all time slots as free (0)
    for (int i = 1; i <= maxDeadline; i++)
        slot[i] = 0;

    int totalProfit = 0;

    // Iterate over all jobs sorted by descending profit
    for (int i = 0; i < n; i++)
    {
        // For the current job, try to schedule it in the latest possible slot
        // starting from its deadline and moving backwards to slot 1
        // We search for the latest free slot ≤ deadline so that each job
        // is scheduled as late as possible. This leaves earlier slots open
        // for jobs with tighter deadlines, maximizing the total number of jobs
        // (and profit) we can fit into the schedule.
        for (int t = jobs[i].deadline; t >= 1; t--)
        {
            // If this time slot is still free (0 means unused)
            if (slot[t] == 0)
            {
                slot[t] = 1;                   // Mark slot t as occupied
                strcpy(result[t], jobs[i].id); // Place job ID into result[t]
                totalProfit += jobs[i].profit; // Accumulate the job's profit
                break;                         // Stop searching and move to next job
            }
            // If slot t is already taken, the loop continues to check t-1, t-2, ...
        }
    }

    // d) Display the scheduled jobs and total profit
    printf("\nSelected Jobs in Sequence:\n");
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (slot[i])
            printf("Time Slot %d: Job %s\n", i, result[i]);
    }
    printf("Maximum Profit: %d\n", totalProfit);
}

int main()
{
    // Sample data initialization (can be replaced by readJobs())
    n = 5;
    strcpy(jobs[0].id, "I");
    jobs[0].profit = 50;
    jobs[0].deadline = 2;
    strcpy(jobs[1].id, "II");
    jobs[1].profit = 30;
    jobs[1].deadline = 1;
    strcpy(jobs[2].id, "III");
    jobs[2].profit = 10;
    jobs[2].deadline = 3;
    strcpy(jobs[3].id, "IV");
    jobs[3].profit = 20;
    jobs[3].deadline = 2;
    strcpy(jobs[4].id, "V");
    jobs[4].profit = 15;
    jobs[4].deadline = 4;

    // If you want to input jobs manually, uncomment the next line:
    // readJobs();

    sortJobs();      // Sort jobs by profit descending
    jobSequencing(); // Perform job sequencing to maximize profit

    return 0;
}
