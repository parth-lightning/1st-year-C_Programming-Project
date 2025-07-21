#include <stdio.h>
#include <string.h>

// Structure to store student data
typedef struct {  // if we have to declare a variable we have to write struct student and the variable name here if we only write student and that variable name no need to write struct 
    char name[50];
    int prn;
    int rollNo;
    char teacherremarks[100];  // Stores remarks by parents
    char subjectNames[10][50];
    int marks[10];
    int numSubjects;
    char parentremarks[100];
    char studentsremarks[100];
} Student;

Student students[100];  // Array to store students//if we dont use typedef we have to write struct student students[100]//
int studentCount = 0;   // Number of students in the system//whenever we add a student it increases

// Function prototypes//this are all the functions
void saveData();//to write the data 
void loadData();// to fetch the data
void teacherSection();
void studentSection(int prn);
void parentSection();
void verifyRole(int prn);
void login();

// Save data to file
void saveData() {
    FILE *file = fopen("students.txt", "wb");
    if (file) {
        fwrite(&studentCount, sizeof(int), 1, file);// here we will store student count data 
        fwrite(students, sizeof(Student), studentCount, file);
        fclose(file);
    }// here yoou will notice not use for loop 
}

// Load data from file
void loadData() {
    FILE *file = fopen("students.txt", "rb");
    if (file) {
        fread(&studentCount, sizeof(int), 1, file);
        fread(students, sizeof(Student), studentCount, file);
        fclose(file);
    }
}

// Teacher Section
void  teacherSection() {
    while (1) {
        printf("\n--- Teacher Section ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. View All Students & Remarks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (studentCount < 100) {
                printf("Enter Student Name: ");
                getchar();
                scanf("%[^\n]s", students[studentCount].name);

                printf("Enter PRN (8-digit): ");
                scanf("%d", &students[studentCount].prn);

                printf("Enter Roll Number: ");
                scanf("%d", &students[studentCount].rollNo);

                printf("Enter Number of Subjects: ");
                scanf("%d", &students[studentCount].numSubjects);

                for (int i = 0; i < students[studentCount].numSubjects; i++) {
                    printf("Enter Subject %d Name: ", i + 1);
                    getchar();
                    scanf("%[^\n]s", students[studentCount].subjectNames[i]);

                    printf("Enter Marks for %s: ", students[studentCount].subjectNames[i]);
                    scanf("%d", &students[studentCount].marks[i]);
                }

                printf("Enter Remark:-");
                scanf("%s",students[studentCount].teacherremarks);

                studentCount++;
                saveData();
                printf("Student added successfully!\n");
            } else {
                printf("Student limit reached!\n");
            }
        } else if (choice == 2) {
            int prn;
            printf("Enter PRN of the student to delete: ");
            scanf("%d", &prn);

            int found = 0;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].prn == prn) {
                    found = 1;
                    for (int j = i; j < studentCount - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    studentCount--;
                    saveData();
                    printf("Student deleted successfully!\n");
                    break;
                }
            }
            if (!found) {
                printf("Student with PRN %d not found!\n", prn);
            }
        } else if (choice == 3) {
            printf("\n--- List of Students & Remarks ---\n");
            for (int i = 0; i < studentCount; i++) {
                printf("Name: %s, PRN: %d, Roll No: %d\n", students[i].name, students[i].prn, students[i].rollNo);
                printf("Remarks by student: %s\n", students[i].studentsremarks);
                printf("Remarks by parents:-%s\n",students[i].parentremarks);
            }
        } else if (choice == 4) {
            return ;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

// Student Section
void studentSection(int prn) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].prn == prn) {
            found = 1;
            printf("\n--- Student Section ---\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Subjects and Marks:\n");
            for (int j = 0; j < students[i].numSubjects; j++) {
                printf("%s: %d\n", students[i].subjectNames[j], students[i].marks[j]);
            }
            printf("Remarks: %s\n", students[i].teacherremarks);
            printf("Enter remark for teacher:-");
             getchar();
            scanf("%[^\n]s", students[i].studentsremarks);
            return;
        }
    }
    if (found==0) {
        printf("Student with PRN %d not found!\n", prn);
    }
}

// Parent Section (Now asks for their ward's PRN)
void parentSection() {
    int wardPRN;
    printf("Enter your ward's PRN: ");
    scanf("%d", &wardPRN);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].prn == wardPRN) {
            found = 1;
            printf("\n--- Parent Section ---\n");
            printf("Student Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Subjects and Marks:\n");
            for (int j = 0; j < students[i].numSubjects; j++) {
                printf("%s: %d\n", students[i].subjectNames[j], students[i].marks[j]);
            }
            printf("Current Remarks: %s\n", students[i].teacherremarks);
            
            printf("\nEnter Remarks for teacher: ");
            getchar();
            scanf("%[^\n]s", students[i].parentremarks);
            saveData();
            printf("Remarks added successfully!\n");
            return;
        }
    }
    if (found==0) {
        printf("Student with PRN %d not found! Cannot add remarks.\n", wardPRN);
    }
}

// Verify user role
void verifyRole(int prn) {
    int firstDigit = prn / 10000000;
    if (firstDigit == 1) {
        studentSection(prn);
    } else if (firstDigit == 2) {
        teacherSection();
    } else if (firstDigit == 3) {
        parentSection();
    } else {
        printf("Invalid PRN! The first digit should be 1 (Student), 2 (Teacher), or 3 (Parent).\n");
    }
}

// Login function
void login() {
    while (1) {
        int prn, password;

        printf("\n*********************** WELCOME TO STUDENT MANAGEMENT SYSTEM ***********************\n");
        printf("Enter your PRN (8-digit): ");
        scanf("%d", &prn);

        if (prn < 10000000 || prn > 99999999) {
            printf("Invalid PRN! It must be 8 digits.\n");
            continue;
        }

        printf("Enter Password (First 6 digits of PRN): ");
        scanf("%d", &password);

        int correctPassword = prn / 100;

        if (password == correctPassword) {
            printf("\n Login Successful!\n");
            verifyRole(prn);
        } else {
            printf("\n Incorrect Password! Try again.\n");
            continue;
        }

        printf("\nDo you want to log out? (1: Yes, 2: No): ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nLogging out...\n");
            continue;
        }
    }
}

// Main function
int main() {
    loadData();
    login();
    return 0;
}
