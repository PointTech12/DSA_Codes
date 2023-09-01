/* Joshua Bara
    IT - 03 */
/*Define a structure data type called time_struct containing 3 members int hour, int minute and int second. Write functions that accept the structure to perform the following operations:1. Input new time2. Display the time3. Update the time such that the function accepts the time_struct and increments the time by one second.(If the increment results in 60 seconds, the then second member is set to 0 and the minute is incremented by 1. Then, if the result is 60 minutes, the minute member is set to 0 and the hour member is incremented by 1. Finally when the hour becomes 24, it is set to zero.)*/


#include <stdio.h>

// Define the structure
struct time_struct {
    int hour;
    int minute;
    int second;
};

// Function to input new time
void inputTime(struct time_struct *time) {
    printf("Enter hour: ");
    scanf("%d", &time->hour);
    printf("Enter minute: ");
    scanf("%d", &time->minute);
    printf("Enter second: ");
    scanf("%d", &time->second);
}

// Function to display the time
void displayTime(const struct time_struct *time) {
    printf("%02d:%02d:%02d\n", time->hour, time->minute, time->second);
}

// Function to update time by one second
void updateTime(struct time_struct *time) {
    time->second++;

    if (time->second == 60) {
        time->second = 0;
        time->minute++;

        if (time->minute == 60) {
            time->minute = 0;
            time->hour++;

            if (time->hour == 24) {
                time->hour = 0;
            }
        }
    }
}

int main() {
    struct time_struct myTime;

    printf("Input new time:\n");
    inputTime(&myTime);

    printf("\nDisplaying the time:\n");
    displayTime(&myTime);

    printf("\nUpdating the time by one second:\n");
    updateTime(&myTime);
    displayTime(&myTime);

    return 0;
}

