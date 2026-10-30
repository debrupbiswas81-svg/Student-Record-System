
#include <stdio.h>
#include <string.h>

struct Student {
    int roll, c, web, dv, dm, rdbms;
    char name[50];
};

struct Student s[50];
int count = 0;

int getMarks();
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void classAverage();
void topper();
void performanceAlert();

int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student Details\n");
        printf("5. Delete Student\n");
        printf("6. Class Average\n");
        printf("7. Class Topper\n");
        printf("8. Student Performance Alert\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: classAverage(); break;
            case 7: topper(); break;
            case 8: performanceAlert(); break;
            case 9: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}

int getMarks() {
    int marks;

    do {
        printf("Enter marks (0-100): ");
        scanf("%d", &marks);

        if (marks < 0 || marks > 100)
            printf("Invalid marks! Try again.\n");

    } while (marks < 0 || marks > 100);

    return marks;
}

void addStudent() {
    if (count >= 50) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &s[count].roll);

    printf("Enter full name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Problem Solving in C:\n");
    s[count].c = getMarks();

    printf("Web Technology:\n");
    s[count].web = getMarks();

    printf("Data Visualization:\n");
    s[count].dv = getMarks();

    printf("Discrete Mathematics:\n");
    s[count].dm = getMarks();

    printf("RDBMS:\n");
    s[count].rdbms = getMarks();

    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    int i, total;

    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        total = s[i].c + s[i].web + s[i].dv
              + s[i].dm + s[i].rdbms;

        printf("\nRoll: %d | Name: %s\n", s[i].roll, s[i].name);
        printf("C: %d, Web: %d, Data Visualization: %d\n",
               s[i].c, s[i].web, s[i].dv);
        printf("Discrete Math: %d, RDBMS: %d\n",
               s[i].dm, s[i].rdbms);
        printf("Total: %d/500 | Average: %.2f\n",
               total, total / 5.0);
    }
}

void searchStudent() {
    int choice, roll, i;
    char name[50];

    printf("\n1. Search by Roll Number\n");
    printf("2. Search by Full Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter roll number: ");
        scanf("%d", &roll);

        for (i = 0; i < count; i++) {
            if (s[i].roll == roll)
                break;
        }
    }
    else if (choice == 2) {
        printf("Enter full name: ");
        scanf(" %49[^\n]", name);

        for (i = 0; i < count; i++) {
            if (strcmp(s[i].name, name) == 0)
                break;
        }
    }
    else {
        printf("Invalid choice!\n");
        return;
    }

    if (i < count) {
        printf("\nStudent Found!\n");
        printf("Roll: %d | Name: %s\n", s[i].roll, s[i].name);
        printf("C: %d, Web: %d, Data Visualization: %d\n",
               s[i].c, s[i].web, s[i].dv);
        printf("Discrete Math: %d, RDBMS: %d\n",
               s[i].dm, s[i].rdbms);
    }
    else {
        printf("Student not found!\n");
    }
}

void updateStudent() {
    int roll, i, choice, subject;
    char name[50];

    printf("Enter current roll number of student: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll)
            break;
    }

    if (i == count) {
        printf("Student not found!\n");
        return;
    }

    printf("\nWhat do you want to update?\n");
    printf("1. Student Name\n");
    printf("2. Roll Number\n");
    printf("3. Marks\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new full name: ");
            scanf(" %49[^\n]", name);
            strcpy(s[i].name, name);
            printf("Name updated successfully!\n");
            break;

        case 2:
            printf("Enter new roll number: ");
            scanf("%d", &s[i].roll);
            printf("Roll number updated successfully!\n");
            break;

        case 3:
            printf("\nChoose subject to update:\n");
            printf("1. Problem Solving in C\n");
            printf("2. Web Technology\n");
            printf("3. Data Visualization\n");
            printf("4. Discrete Mathematics\n");
            printf("5. RDBMS\n");
            printf("Enter subject choice: ");
            scanf("%d", &subject);

            switch (subject) {
                case 1: s[i].c = getMarks(); break;
                case 2: s[i].web = getMarks(); break;
                case 3: s[i].dv = getMarks(); break;
                case 4: s[i].dm = getMarks(); break;
                case 5: s[i].rdbms = getMarks(); break;
                default:
                    printf("Invalid subject choice!\n");
                    return;
            }

            printf("Marks updated successfully!\n");
            break;

        default:
            printf("Invalid choice!\n");
    }
}

void deleteStudent() {
    int roll, i, j;

    printf("Enter roll number: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll)
            break;
    }

    if (i == count) {
        printf("Student not found!\n");
        return;
    }

    for (j = i; j < count - 1; j++)
        s[j] = s[j + 1];

    count--;
    printf("Student deleted successfully!\n");
}

void classAverage() {
    int i, total = 0;

    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    for (i = 0; i < count; i++)
        total += s[i].c + s[i].web + s[i].dv
               + s[i].dm + s[i].rdbms;

    printf("Class Average: %.2f\n",
           (float)total / (count * 5));
}

void topper() {
    int i, best = 0, total, max = -1;

    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        total = s[i].c + s[i].web + s[i].dv
              + s[i].dm + s[i].rdbms;

        if (total > max) {
            max = total;
            best = i;
        }
    }

    printf("Class Topper: %s\n", s[best].name);
    printf("Roll Number: %d\n", s[best].roll);
    printf("Total Marks: %d/500\n", max);
    printf("Percentage: %.2f%%\n", max / 5.0);
}

void performanceAlert() {
    int i, j, marks[5], min;

    char *subjects[] = {
        "Problem Solving in C",
        "Web Technology",
        "Data Visualization",
        "Discrete Mathematics",
        "RDBMS"
    };

    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        marks[0] = s[i].c;
        marks[1] = s[i].web;
        marks[2] = s[i].dv;
        marks[3] = s[i].dm;
        marks[4] = s[i].rdbms;

        min = 0;

        for (j = 1; j < 5; j++) {
            if (marks[j] < marks[min])
                min = j;
        }

        printf("\nStudent: %s (Roll %d)\n",
               s[i].name, s[i].roll);
        printf("Lowest Subject: %s (%d marks)\n",
               subjects[min], marks[min]);

        if (marks[min] < 40)
            printf("Alert: Needs improvement!\n");
        else
            printf("Performance is satisfactory.\n");
    }
}
