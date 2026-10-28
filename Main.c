#include <stdio.h>
#include <string.h>

// Defining the structure
struct student {
    char name[50];
    float grade;
};

// Function to partition the array of students (in descending order: highest grade first)
int particionar(struct student vetor[], int inicio, int fim) {
    float pivo = vetor[fim].grade;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        // Changed the sign to '>=' to sort from highest to lowest (ranking)
        if (vetor[j].grade >= pivo) {
            i++;
            struct student temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    struct student temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    return i + 1;
}

// Quick Sort function adapted for the student struct
void quicksort(struct student vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, p - 1);
        quicksort(vetor, p + 1, fim);
    }
}

int main() {
    int n = 5;
    struct student students[n];

    printf("=== STUDENTS AND GRADES REGISTRATION ===\n");
    for (int i = 0; i < n; i++) {
        printf("\n[%d] Enter the student's name: ", i + 1);
        scanf(" %[^\n]", students[i].name); // Reads string with spaces
        printf("[%d] Enter %s's grade: ", i + 1, students[i].name);
        scanf("%f", &students[i].grade);
    }

    // Sorting students from highest to lowest using Quick Sort
    quicksort(students, 0, n - 1);

    // Displaying the Final Ranking
    printf("\n\n========================================\n");
    printf("                GRADES RANKING           \n");
    printf("========================================\n");

    for (int i = 0; i < n; i++) {
        printf("%do Place: %-15s | grade: %.2f", i + 1, students[i].name, students[i].grade);
        
        // Checking who got a grade higher than 6
        if (students[i].grade > 6.0) {
            printf(" -> [grade > 6: Approved/Highlighted!]");
        }
        printf("\n");
    }
    printf("========================================\n");

    return 0;
}