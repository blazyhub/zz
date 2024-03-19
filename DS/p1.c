#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char dayName[21]; // Use fixed-size character arrays to avoid dynamic memory allocation
    int date;
    char activity[101];
};

void create(struct Day *day) {
    printf("Enter the day name: ");
    fgets(day->dayName, sizeof(day->dayName), stdin);
    day->dayName[strcspn(day->dayName, "\n")] = '\0'; // Remove newline character

    printf("Enter the date: ");
    scanf("%d", &day->date);
    getchar(); // Consume newline character

    printf("Enter the activity for the day: ");
    fgets(day->activity, sizeof(day->activity), stdin);
    day->activity[strcspn(day->activity, "\n")] = '\0'; // Remove newline character
}

void read(struct Day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        create(&calendar[i]);
    }
}

void display(struct Day *calendar, int size) {
    printf("\nWeek's Activity Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Day %d:\n", i + 1);
        printf("Day Name: %s\n", calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
        printf("\n");
    }
}

void freeMemory(struct Day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        // No need to free memory as we are using fixed-size character arrays
    }
}

int main() {
    int size;
    printf("Enter the number of days in the week: ");
    scanf("%d", &size);
    getchar(); // Consume newline character

    struct Day *calendar = malloc(sizeof(struct Day) * size);
    if (calendar == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    read(calendar, size);
    display(calendar, size);
    freeMemory(calendar, size);
    free(calendar);

    return 0;
}