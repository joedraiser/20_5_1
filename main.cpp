#include <iostream>
#include <fstream>
#include <vector>


struct manNsalary
{
    std::string name;
    int salary;
    std::string date;
};

bool date_verif(std::string date)
{
    if(std::stoi(date.substr(0, 2))>=1&&std::stoi(date.substr(0, 2))<=31&&std::stoi(date.substr(3, 2))>=1&&std::stoi(date.substr(3, 2))<=12&&std::stoi(date.substr(6, 4))>=1900&&std::stoi(date.substr(6, 4))<=2070)
        return true;
    else
        return false;
}

int main()
{
    std::ofstream payroll;
    payroll.open("payroll.txt", std::ios::app);

    if(!payroll.is_open())
    {
        std::cout << "File is not opened.";
        exit(EXIT_FAILURE);
    }

    manNsalary temp;

    std::cout << "Input name and surname: ";
    std::getline(std::cin, temp.name);
    std::cout << "Input date of issue: ";
    std::cin >> temp.date;

    if(!date_verif(temp.date))
    {
        std::cout << "Date is invalid";
        return 1;
    }

    std::cout << "Input salary value: ";
    std::cin >> temp.salary;

    payroll << temp.name << ' ' << temp.date << ' ' << temp.salary << ' ' << std::endl;

    payroll.close();

    return 0;
}
