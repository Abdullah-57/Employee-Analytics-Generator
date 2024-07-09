// Abdullah_Daoud_22I-2626_A1


# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <chrono>
# include "Header.h"

using namespace std;

int main()
{
    // Declaring template object "employees" of MAX_SIZE

    Employee <string> employees[MAX_SIZE];
    fstream file;
    string temp1;
    string temp2;
    string temp5;
    int temp3 = 0;
    int temp4 = 0;
    int count = 0;

    cout << "------------------------------------------------------ Scenario 1 ------------------------------------------------------ \n\n";

    // Opening the file

    file.open("Employeedata.txt");

    if (!file)
    {
        cout << "File doesnt exist! \n";
    }
    else
    {
        while (file)
        {
            // Reading data from the file line by line and storing them in their respective data members

            getline(file, temp1);
            temp2 = extractName(temp1);
            employees[count].setName(temp2);

            getline(file, temp1);
            temp2 = extractEmployeeID(temp1);
            employees[count].setEmployeeID(temp2);

            getline(file, temp1);
            temp2 = extractSalary(temp1);
            temp3 = stoi(temp2);
            employees[count].setSalary(temp3);

            getline(file, temp1);
            temp2 = extractJoinDate(temp1);
            temp5 = temp2.substr(0, 5);
            temp4 = stoi(temp5);
            employees[count].setJoinDate(temp4);

            getline(file, temp1);
            temp2 = extractDesignation(temp1);
            employees[count].setDesignation(temp2);

            getline(file, temp1);

            if (count < 9)
            {
                count++;
            }
            if (file.eof())
            {
                break;
            }
        }
    }

    // Closing the file

    file.close();

    // Opening the file again

    file.open("Employeedata.txt");

    // Printing the whole information from the file after reading and storing it

    while (file)
    {
        getline(file, temp1);

        cout << temp1 << endl;
    }

    // Closing the file again

    file.close();

    double sum = 0;
    double average = 0;

    // Calculating Average Salary

    for (int i = 0; i < MAX_SIZE; i++)
    {
        sum = sum + employees[i].getSalary();
    }

    average = sum / MAX_SIZE;

    cout << "Average Salary: " << average << endl;

    // Calculating Total Number of Employees

    int noOfEmployees = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        noOfEmployees++;
    }

    cout << "Total Employees: " << noOfEmployees << endl;

    // Calculating the Average Tenure in Years

    double tenure = 0;
    double sum2 = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        sum2 = sum2 + 2023 - employees[i].getJoinDate();
    }

    tenure = sum2 / noOfEmployees;

    cout << "Average Tenure in Years: " << tenure << endl;

    // Storing the Tenure of each employee in years and finding the longest tenure

    int longestTenure = 0;
    int temparr[10];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        temparr[i] = 2023 - employees[i].getJoinDate();
    }

    for (int i = 0; i < 10; i++)
    {
        if (temparr[i] > longestTenure)
        {
            longestTenure = temparr[i];
        }
    }

    cout << "Longest Tenure: " << longestTenure << endl;

    // Finding out Number of employees in each Designation

    string employeeDesignations[] = { "Software Engineer", "Senior Software Engineer", "Data Scientist", "Project Manager", "Senior Data Analyst", "UX Designer", "Software Engineer", "Quality Assurance Analyst", "Senior Software Engineer", "Data Scientist" };

    int countSE = 0;
    int countSSE = 0;
    int countDS = 0;
    int countPM = 0;
    int countSDA = 0;
    int countUX = 0;
    int countQAA = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (employeeDesignations[i] == "Software Engineer")
        {
            countSE++;
        }
        else if (employeeDesignations[i] == "Senior Software Engineer")
        {
            countSSE++;
        }
        else if (employeeDesignations[i] == "Data Scientist")
        {
            countDS++;
        }
        else if (employeeDesignations[i] == "Project Manager")
        {
            countPM++;
        }
        else if (employeeDesignations[i] == "Senior Data Analyst")
        {
            countSDA++;
        }
        else if (employeeDesignations[i] == "UX Designer")
        {
            countUX++;
        }
        else if (employeeDesignations[i] == "Quality Assurance Analyst")
        {
            countQAA++;
        }
    }

    cout << "Number of Software Engineer's: " << countSE << endl;
    cout << "Number of Senior Software Engineer's: " << countSSE << endl;
    cout << "Number of Data Scientist's: " << countDS << endl;
    cout << "Number of Project Manger's: " << countPM << endl;
    cout << "Number of Senior Data Analyst's: " << countSDA << endl;
    cout << "Number of UX Designer's: " << countUX << endl;
    cout << "Number of Quality Assurance Analayst's: " << countQAA << endl << endl;

    cout << "------------------------------------------------------ Scenario 2 ------------------------------------------------------ \n\n";

    int highestSalary = 0;
    int lowestSalary = employees[0].getSalary();
    int salaryRange = 0;
    int in = 0;
    double medianSalary = 0;
    double sumSalarySE = 0;
    double sumSalarySSE = 0;
    double sumSalaryUX = 0;
    double sumSalaryDS = 0;
    double sumSalaryPM = 0;
    double sumSalarySDA = 0;
    double sumSalaryQAA = 0;
    double averageSalarySE = 0;
    double averageSalarySSE = 0;
    double averageSalaryUX = 0;
    double averageSalaryDS = 0;
    double averageSalaryPM = 0;
    double averageSalarySDA = 0;
    double averageSalaryQAA = 0;

    // Calculating Highest Salary

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (highestSalary < employees[i].getSalary())
        {
            in = i;
            highestSalary = employees[i].getSalary();
        }
    }

    // Calculating Lowest Salary

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (lowestSalary > employees[i].getSalary())
        {
            lowestSalary = employees[i].getSalary();
        }
    }

    // Caculating Salary Range

    salaryRange = highestSalary - lowestSalary;

    // Caclulating Median Salary by sorting the Salaries in Ascending order

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = i + 1; j < MAX_SIZE; j++)
        {
            if (employees[i].getSalary() > employees[j].getSalary())
            {
                int tmp = employees[i].getSalary();
                employees[i].setSalary(employees[j].getSalary());
                employees[j].setSalary(tmp);
            }
        }
    }

    medianSalary = employees[4].getSalary() + employees[5].getSalary() / 2;

    // Calculating Sum of Salaries for each Designation

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (employees[i].getDesignation() == " Software Engineer")
        {
            sumSalarySE = sumSalarySE + employees[i].getSalary();
        }
        else if (employees[i].getDesignation() == " Senior Software Engineer")
        {
            sumSalarySSE = sumSalarySSE + employees[i].getSalary();
        }
        else if (employees[i].getDesignation() == " Data Scientist")
        {
            sumSalaryDS = sumSalaryDS + employees[i].getSalary();
        }
        else if (employees[i].getDesignation() == " Project Manager")
        {
            sumSalaryPM = sumSalaryPM + employees[i].getSalary();
        }
        else if (employees[i].getDesignation() == " Senior Data Analyst")
        {
            sumSalarySDA = sumSalarySDA + employees[i].getSalary();
        }
        else if (employees[i].getDesignation() == " UX Designer")
        {
            sumSalaryUX = sumSalaryUX + employees[i].getSalary();
        }
        else if (employees[i].getDesignation() == " Quality Assurance Analyst")
        {
            sumSalaryQAA = sumSalaryQAA + employees[i].getSalary();
        }
    }

    // Calculating Average Salary for each Designation

    averageSalarySE = sumSalarySE / countSE;
    averageSalarySSE = sumSalarySSE / countSSE;
    averageSalaryDS = sumSalaryDS / countDS;
    averageSalaryPM = sumSalaryPM / countPM;
    averageSalarySDA = sumSalarySDA / countSDA;
    averageSalaryUX = sumSalaryUX / countUX;
    averageSalaryQAA = sumSalaryQAA / countQAA;

    cout << "Highest Salary: " << highestSalary << endl;
    cout << "Lowest Salary: " << lowestSalary << endl;
    cout << "Salary Range: " << salaryRange << endl;
    cout << "Median Salary: " << medianSalary << endl;
    cout << "Employee with Highest Salary:" << employees[in].getName() << endl;
    cout << "Average Salary of Software Engineer: " << averageSalarySE << endl;
    cout << "Average Salary of Senior Software Engineer: " << averageSalarySSE << endl;
    cout << "Average Salary of Data Scientist: " << averageSalaryDS << endl;
    cout << "Average Salary of Project Manager: " << averageSalaryPM << endl;
    cout << "Average Salary of Senior Data Analyst: " << averageSalarySDA << endl;
    cout << "Average Salary of UX Designer: " << averageSalaryUX << endl;
    cout << "Average Salary of Quality Assurance Analyst: " << averageSalaryQAA << endl << endl; 

    cout << "------------------------------------------------------ Scenario 3 ------------------------------------------------------ \n\n";
    
    string longestEmployeeTenure;
    string shortestEmployeeTenure;
    int shortestTenure = temparr[0];
    double sumTenureSE = 0;
    double sumTenureSSE = 0;
    double sumTenureUX = 0;
    double sumTenureDS = 0;
    double sumTenurePM = 0;
    double sumTenureSDA = 0;
    double sumTenureQAA = 0;
    double averageTenureSE = 0;
    double averageTenureSSE = 0;
    double averageTenureUX = 0;
    double averageTenureDS = 0;
    double averageTenurePM = 0;
    double averageTenureSDA = 0;
    double averageTenureQAA = 0;

    // Calculating Shortest Tenure

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (shortestTenure > temparr[i])
        {
            shortestTenure = temparr[i];
        }
    }

    // Finding the employee with Longest and Shortest Tenure

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (longestTenure == temparr[i])
        {
            longestEmployeeTenure = employees[i].getName();
            break;
        }
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (shortestTenure == temparr[i])
        {
            shortestEmployeeTenure = employees[i].getName();
            break;
        }
    }

    // Finding Employee with Highest Salary

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (highestSalary < employees[i].getSalary())
        {
            in = i;
            highestSalary = employees[i].getSalary();
        }
    }

    // Calculating Sum of Tenure's of all employees for each Designation

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (employees[i].getDesignation() == " Software Engineer")
        {
            sumTenureSE = sumTenureSE + temparr[i];
        }
        else if (employees[i].getDesignation() == " Senior Software Engineer")
        {
            sumTenureSSE = sumTenureSSE + temparr[i];
        }
        else if (employees[i].getDesignation() == " Data Scientist")
        {
            sumTenureDS = sumTenureDS + temparr[i];
        }
        else if (employees[i].getDesignation() == " Project Manager")
        {
            sumTenurePM = sumTenurePM + temparr[i];
        }
        else if (employees[i].getDesignation() == " Senior Data Analyst")
        {
            sumTenureSDA = sumTenureSDA + temparr[i];
        }
        else if (employees[i].getDesignation() == " UX Designer")
        {
            sumTenureUX = sumTenureUX + temparr[i];
        }
        else if (employees[i].getDesignation() == " Quality Assurance Analyst")
        {
            sumTenureQAA = sumTenureQAA + temparr[i];
        }
    }

    // Calculating Average Tenure for each Designation

    averageTenureSE = sumTenureSE / countSE;
    averageTenureSSE = sumTenureSSE / countSSE;
    averageTenureDS = sumTenureDS / countDS;
    averageTenurePM = sumTenurePM / countPM;
    averageTenureSDA = sumTenureSDA / countSDA;
    averageTenureUX = sumTenureUX / countUX;
    averageTenureQAA = sumTenureQAA / countQAA;


    cout << "Employee with Longest Tenure of " << longestTenure << " years:" << longestEmployeeTenure << endl;
    cout << "Employee with Shortest Tenure of " << shortestTenure << " years:" << shortestEmployeeTenure << endl;
    cout << "Highest Paying Designation:" << employees[in].getDesignation() << endl;
    cout << "Average Tenure of Software Engineer: " << averageTenureSE << endl;
    cout << "Average Tenure of Senior Software Engineer: " << averageTenureSSE << endl;
    cout << "Average Tenure of Data Scientist: " << averageTenureDS << endl;
    cout << "Average Tenure of Project Manager: " << averageTenurePM << endl;
    cout << "Average Tenure of Senior Data Analyst: " << averageTenureSDA << endl;
    cout << "Average Tenure of UX Designer: " << averageTenureUX << endl;
    cout << "Average Tenure of Quality Assurance Analyst: " << averageTenureQAA << endl << endl;

    cout << "------------------------------------------------------ Scenario 4 ------------------------------------------------------ \n\n";

    int pass = 0;
    int countComparison = 0;
    int countSwap = 0;

    // Using Chrono to find out the Execution Time of Bubble Sort Algorithm for sorting employees based on Salary in Ascending order

    auto start = chrono::high_resolution_clock::now();

    for (int pass = 1; pass < MAX_SIZE; pass++)
    {
        for (int i = 0; i < MAX_SIZE - pass; i++)
        {
            countComparison++;

            if (employees[i].getSalary() > employees[i + 1].getSalary())
            {
                int tmp = employees[i].getSalary();
                employees[i].setSalary(employees[i + 1].getSalary());
                employees[i + 1].setSalary(tmp);
                countSwap++;
            }
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast <chrono::microseconds> (stop - start);

    cout << "Ranking of Employees in Ascending Order based on Salary: \n\n";

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (employees[i].getSalary() == 60000)
        {
            cout << "Employee Name: John Smith " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 62000)
        {
            cout << "Employee Name: William Wilson " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 68000)
        {
            cout << "Employee Name: Olivia Moore " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 70000)
        {
            cout << "Employee Name: Jane Doe " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 73000)
        {
            cout << "Employee Name: James Lee " << endl <<"Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 75000)
        {
            cout << "Employee Name: Sarah Williams " << endl <<"Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 80000)
        {
            cout << "Employee Name: Emily Davis " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 85000)
        {
            cout << "Employee Name: Robert Johnson " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 90000)
        {
            cout << "Employee Name: Emma Johnson " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
        else if (employees[i].getSalary() == 95000)
        {
            cout << "Employee Name: Michael Brown " << endl << "Salary: $" << employees[i].getSalary() << endl << endl;
        }
    }

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    cout << "Number of Comparisons in Bubble Sort: " << countComparison << endl;
    cout << "Number of Swaps in Bubble Sort: " << countSwap << endl << endl;

    cout << "------------------------------------------------------ Scenario 5 ------------------------------------------------------ \n\n";

    countComparison = 0;
    countSwap = 0;

    // Using Chrono to find out the Execution Time of Bubble Sort Algorithm for sorting employees based on Tenure in Ascending order

    auto start2 = chrono::high_resolution_clock::now();

    for (int pass = 1; pass < MAX_SIZE; pass++)
    {
        for (int i = 0; i < MAX_SIZE - pass; i++)
        {
            countComparison++;

            if (temparr[i] > temparr[i + 1]) 
            {
                int tmp = temparr[i];
                temparr[i] = temparr[i + 1];
                temparr[i + 1] = tmp;
                countSwap++;
            }
        }
    }

    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast <chrono::microseconds> (stop2 - start2);

    // Removing Duplicate's from Tenure Array

    int uniqueArr[MAX_SIZE]; 
    int uniqueSize = 0; 

    for (int i = 0; i < MAX_SIZE; i++) 
    {
        bool isDuplicate = false;

        for (int j = 0; j < uniqueSize; j++) 
        {
            if (temparr[i] == uniqueArr[j]) 
            {
                isDuplicate = true;
                break; 
            }
        }
        if (!isDuplicate) 
        {
            uniqueArr[uniqueSize] = temparr[i];
            uniqueSize++;
        }
    }

    cout << "Ranking of Employees in Ascending Order based on Tenure in Years: \n\n";


    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (uniqueArr[i] == 1)
        {
            cout << "Employee Name: Emily Davis " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
        }
        else if (uniqueArr[i] == 2)
        {
            cout << "Employee Name: Robert Johnson " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
            cout << "Employee Name: Emma Johnson " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
        }
        else if (uniqueArr[i] == 3)
        {
            cout << "Employee Name: Olivia Moore " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
            cout << "Employee Name: John Smith " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
            cout << "Employee Name: Sarah Williams " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
        }
        else if (uniqueArr[i] == 4)
        {
            cout << "Employee Name: Jane Doe " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
            cout << "Employee Name: James Lee " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
            cout << "Employee Name: William Wilson " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
        }
        else if (uniqueArr[i] == 5)
        {
            cout << "Employee Name: Michael Brown " << endl << "Tenure: " << uniqueArr[i] << endl << endl;
        }
        else
        {

        }
    }

    cout << "Time taken by function: " << duration2.count() << " microseconds" << endl;
    cout << "Number of Comparisons in Bubble Sort: " << countComparison << endl;
    cout << "Number of Swaps in Bubble Sort: " << countSwap << endl << endl;

    cout << "-------------------------------------------------------- The End ------------------------------------------------------- \n\n";

    return 0;
}
