// Abdullah_Daoud_22I-2626_A1


#pragma once

# include <iostream>
# include <fstream>
# include <string>

using namespace std;

// Declaring Max Number of Employees based on Employeedata.txt file

const int MAX_SIZE = 10;

// Template Class

template <typename T>
class Employee 
{
private:
    T employeeID;
    T name;
    int salary;
    int joinDate;
    T designation;

public:

    // Default/Parameterized Constructors

    Employee()
    {
        name = "";
        employeeID = "";
        salary = 0;
        joinDate = 0;
        designation = "";
    }
    Employee(const T& name, const T& employeeID, const int& salary, const int& joinDate, const T& designation)
    {
        this->name = name;
        this->employeeID = employeeID;
        this->salary = salary;
        this->joinDate = joinDate;
        this->designation = designation;
    }

    // Getter/Setter Functions

    void setEmployeeID(T employeeID)
    {
        this->employeeID = employeeID;
    }
    void setName(T name)
    {
        this->name = name;
    }
    void setSalary(int salary)
    {
        this->salary = salary;
    }
    void setJoinDate(int joinDate)
    {
        this->joinDate = joinDate;
    }
    void setDesignation(T designation)
    {
        this->designation = designation;
    }

    T getEmployeeID()
    {
        return employeeID;
    }
    T getName()
    {
        return name;
    }
    int getSalary()
    {
        return salary;
    }
    int getJoinDate()
    {
        return joinDate;
    }
    T getDesignation()
    {
        return designation;
    }
};

Employee <string> employees[MAX_SIZE];

// Template Function to Extract Names from Employeedata.txt

template <typename T1>
T1 extractName(T1 temp1)
{
    T1 temp2;

    for (int i = 0; i < temp1.length(); i++)
    {
        if (temp1[i] == 'e' && temp1[i + 1] == ':')
        {
            for (int j = i + 2; j < temp1.length(); j++)
            {
                temp2 = temp2 + temp1[j];
            }
            return temp2; 
        }
    }
    return "";
}

// Template Function to Extract Employee ID's from Employeedata.txt

template <typename T2>
T2 extractEmployeeID(T2 temp1)
{
    T2 temp2;

    for (int i = 0; i < temp1.length(); i++)
    {
        if (temp1[i] == 'D' && temp1[i + 1] == ':')
        {
            for (int j = i + 2; j < temp1.length(); j++)
            {
                temp2 = temp2 + temp1[j];
            }
            return temp2;
        }
    }
    return " ";
}

// Template Function to Extract Salaries from Employeedata.txt

template <typename T3>
T3 extractSalary(T3 temp1)
{
    T3 temp2;

    for (int i = 0; i < temp1.length(); i++)
    {
        if (temp1[i] == '$')
        {
            for (int j = i + 1; j < temp1.length(); j++)
            {
                if (temp1[j] == ',')
                {
                    j++;
                }
                temp2 = temp2 + temp1[j];
            }
            return temp2;
        }
    }

    return "";
}

// Template Function to Extract Joining Date's from Employeedata.txt

template <typename T4>
T4 extractJoinDate(T4 temp1)
{
    string temp2;

    for (int i = 0; i < temp1.length(); i++)
    {
        if (temp1[i] == 'g' && temp1[i + 1] == ':')
        {
            for (int j = i + 2; j < temp1.length(); j++)
            {
                temp2 = temp2 + temp1[j];
            }
            return temp2;
        }
    }

    return "";
}

// Template Function to Extract Designations from Employeedata.txt

template <typename T5>
T5 extractDesignation(T5 temp1)
{
    string temp2;

    for (int i = 0; i < temp1.length(); i++)
    {
        if (temp1[i] == 'n' && temp1[i + 1] == ':')
        {
            for (int j = i + 2; j < temp1.length(); j++)
            {
                temp2 = temp2 + temp1[j];
            }
            return temp2;
        }
    }
    return " ";
}

