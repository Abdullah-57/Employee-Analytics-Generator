# Employee Analytics Generator System

---

## 📝 Introduction

This project is a simple Employee Management System implemented in C++. It reads employee data from a file, processes it, and provides various statistics and insights. The program uses templates and basic file handling in C++ to achieve these functionalities.

---

## ✨ Features

**Extract and Process Employee Data**: Reads employee data from a file and stores it in an array of Employee objects.

- **Calculate Statistics**:
  - Average Salary
  - Total Number of Employees
  - Average Tenure in Years
  - Longest Tenure
  - Number of Employees in Each Designation
- **Scenario Analysis**:
  - Highest and Lowest Salary
  - Salary Range
  - Median Salary
  - Employee with Highest Salary
  - Average Salary for Each Designation
  - Longest and Shortest Employee Tenure
  - Highest Paying Designation
  - Average Tenure for Each Designation
- **Sorting and Execution Time Measurement**: Uses the Bubble Sort algorithm to sort employees based on salary and measures the execution time.

---

## 📂 File Structure

🔹 `main.cpp`: Contains the main logic of the program, reads data from the file, and performs various operations.

🔹 `Header.h`: Contains the Employee class and template functions for extracting data.

🔹 `Employeedata.txt`: The data file containing employee information.

---

## 📄 File Format

The `Employeedata.txt` file should have the following format for each employee:

```
Name: John Doe
ID: 12345
Salary: $50000
Joining Date: 2015
Designation: Software Engineer
```

---

## 📊 Example Output

```
------------------------------------------------------ Scenario 1 ------------------------------------------------------ 

Employee Data:
Name: John Doe
ID: 12345
Salary: $50000
Joining Date: 2015
Designation: Software Engineer

Average Salary: 55000
Total Employees: 10
Average Tenure in Years: 8
Longest Tenure: 10

Number of Software Engineers: 2
Number of Senior Software Engineers: 2
Number of Data Scientists: 2
Number of Project Managers: 1
Number of Senior Data Analysts: 1
Number of UX Designers: 1
Number of Quality Assurance Analysts: 1

------------------------------------------------------ Scenario 2 ------------------------------------------------------ 

Highest Salary: 70000
Lowest Salary: 40000
Salary Range: 30000
Median Salary: 52500
Employee with Highest Salary: Jane Smith

Average Salary of Software Engineer: 50000
Average Salary of Senior Software Engineer: 65000
Average Salary of Data Scientist: 60000
Average Salary of Project Manager: 70000
Average Salary of Senior Data Analyst: 60000
Average Salary of UX Designer: 45000
Average Salary of Quality Assurance Analyst: 40000

------------------------------------------------------ Scenario 3 ------------------------------------------------------ 

Employee with Longest Tenure of 10 years: Jane Smith
Employee with Shortest Tenure of 5 years: John Doe
Highest Paying Designation: Project Manager

Average Tenure of Software Engineer: 8
Average Tenure of Senior Software Engineer: 9
Average Tenure of Data Scientist: 7
Average Tenure of Project Manager: 10
Average Tenure of Senior Data Analyst: 6
Average Tenure of UX Designer: 8
Average Tenure of Quality Assurance Analyst: 5

------------------------------------------------------ Scenario 4 ------------------------------------------------------ 

Bubble Sort Execution Time: 0.000123 seconds
Total Comparisons: 45
Total Swaps: 15
```

---

## 📋 Notes

- 🔹 The program uses templates for data extraction functions, making it versatile for different data types.
- 🔹 Ensure the data file (`Employeedata.txt`) is in the correct format to avoid errors during execution.
- 🔹 The maximum number of employees is set to 10 (`MAX_SIZE`), but this can be adjusted if needed.

---

## ⚖️ License
This project is for **academic and personal skill development purposes only**.  
Reuse is allowed for **learning and research** with proper credit.

---
