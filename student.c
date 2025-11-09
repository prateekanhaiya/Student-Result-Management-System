#include <stdio.h>

int main() {
    int n, i, j, sub;
    float classTotal = 0, classAverage;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    printf("Enter number of subjects: ");
    scanf("%d", &sub);
    
    int marks[n][sub];
    float total[n], percentage[n];
    char grade[n];
    char names[n][50];
    
    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", names[i]);
        total[i] = 0;
        
        printf("Enter marks for %d subjects (out of 100):\n", sub);
        for (j = 0; j < sub; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            total[i] += marks[i][j];
        }
        
        percentage[i] = total[i] / sub;
        classTotal += percentage[i];
        
        // Calculate grade
        if (percentage[i] >= 90)
            grade[i] = 'A';
        else if (percentage[i] >= 75)
            grade[i] = 'B';
        else if (percentage[i] >= 60)
            grade[i] = 'C';
        else if (percentage[i] >= 45)
            grade[i] = 'D';
        else
            grade[i] = 'F';
    }
    
    // Display results
    printf("\n\n===== STUDENT RESULT RECORD =====\n");
    printf("%-15s %-10s %-10s %-10s\n", "Name", "Total", "Percent", "Grade");
    printf("-------------------------------------------------\n");
    
    for (i = 0; i < n; i++) {
        printf("%-15s %-10.2f %-10.2f %-10c\n", names[i], total[i], percentage[i], grade[i]);
    }
    
    // Class average
    classAverage = classTotal / n;
    printf("\nClass Average Percentage = %.2f%%\n", classAverage);
    
    return 0;
}