# Student Management System

A comprehensive C-based Student Management System developed as a first semester project for the course **'Problem Solving and Programming in C'**.

## 📚 Project Overview

This project implements a multi-user Student Management System with role-based access control. The system allows teachers, students, and parents to interact with student records through a console-based interface.

## 🎯 Features

### 🔐 Authentication System
- **PRN-based Login**: 8-digit PRN (Permanent Registration Number) authentication
- **Role-based Access**: Different interfaces for different user types
- **Password Protection**: First 6 digits of PRN as password

### 👨‍🏫 Teacher Section
- **Add Students**: Register new students with personal and academic details
- **Delete Students**: Remove student records from the system
- **View All Students**: Access complete student database with remarks
- **Manage Academic Records**: Input subject names, marks, and teacher remarks

### 👨‍🎓 Student Section
- **View Personal Information**: Access name, roll number, and academic details
- **Check Academic Performance**: View subjects and corresponding marks
- **Read Teacher Remarks**: Access feedback from teachers
- **Submit Remarks**: Provide feedback to teachers

### 👨‍👩‍👧‍👦 Parent Section
- **Monitor Ward's Progress**: View child's academic performance
- **Access Teacher Feedback**: Read teacher remarks about their ward
- **Provide Parental Feedback**: Submit remarks for teachers

## 🏗️ System Architecture

### Data Structure
```c
typedef struct {
    char name[50];
    int prn;
    int rollNo;
    char teacherremarks[100];
    char subjectNames[10][50];
    int marks[10];
    int numSubjects;
    char parentremarks[100];
    char studentsremarks[100];
} Student;
```

### File Management
- **Text File**: `students.txt` - Stores data in text format
- **Binary File**: `students.dat` - Stores data in binary format
- **Automatic Data Persistence**: Data is saved automatically after each operation

## 🚀 Installation & Usage

### Prerequisites
- GCC Compiler (GNU Compiler Collection)
- Any C development environment

### Compilation
```bash
# Compile the main program
gcc course.c -o course.exe

# Compile the alternative version
gcc boysc.c -o boysc.exe
```

### Running the Application
```bash
# Run the main program
./course.exe

# Run the alternative version
./boysc.exe
```

## 🔑 User Access Guide

### PRN Format
The system uses 8-digit PRN with role identification:
- **Students**: PRN starting with '1' (e.g., 12345678)
- **Teachers**: PRN starting with '2' (e.g., 22345678)
- **Parents**: PRN starting with '3' (e.g., 32345678)

### Login Process
1. Enter your 8-digit PRN
2. Enter password (first 6 digits of your PRN)
3. System automatically directs to appropriate section based on PRN

### Example Usage
```
PRN: 22345678
Password: 223456
→ Redirects to Teacher Section

PRN: 12345678
Password: 123456
→ Redirects to Student Section

PRN: 32345678
Password: 323456
→ Redirects to Parent Section
```

## 📁 Project Structure

```
├── course.c          # Main program with text file storage
├── boysc.c           # Alternative version with binary file storage
├── course.exe        # Compiled executable (course.c)
├── boysc.exe         # Compiled executable (boysc.c)
├── students.txt      # Data file (text format)
├── students.dat      # Data file (binary format)
└── README.md         # This file
```

## 🛠️ Technical Implementation

### Key Functions
- `saveData()`: Persists data to file
- `loadData()`: Retrieves data from file
- `teacherSection()`: Teacher interface
- `studentSection()`: Student interface
- `parentSection()`: Parent interface
- `verifyRole()`: Role-based routing
- `login()`: Authentication system

### Data Management
- **Array-based Storage**: Supports up to 100 students
- **File I/O Operations**: Binary and text file handling
- **Dynamic Data Loading**: Automatic data retrieval on startup

## 🎓 Course Information

**Course**: Problem Solving and Programming in C  
**Semester**: First Semester  
**Project Type**: Console Application  
**Programming Language**: C  
**Concepts Demonstrated**:
- Structures and Arrays
- File Handling (Text & Binary)
- Functions and Modular Programming
- User Input/Output
- Control Structures
- Data Persistence

## 🔧 Development Details

### Compiler Used
- GCC (GNU Compiler Collection)

### Platform Compatibility
- Windows (tested)
- Linux (compatible)
- macOS (compatible)

### Memory Management
- Static array allocation for student records
- Automatic file handling with proper cleanup

## 📝 Notes

- The system supports a maximum of 100 students
- Data is automatically saved after each operation
- Two versions are provided: text-based (`course.c`) and binary-based (`boysc.c`) storage
- The system includes comprehensive error handling for invalid inputs

## 🤝 Contributing

This is an academic project developed for learning purposes. Feel free to explore the code and understand the implementation of basic C programming concepts.

---

**Developed as part of the Problem Solving and Programming in C course curriculum.** 