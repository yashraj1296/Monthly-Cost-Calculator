#include <bits/stdc++.h>
using namespace std;

void storeDate(string fileName)
{
    string date;
    cout << "Please enter the date in the format 'dd/mm/yyyy':" << endl;
    cin >> date;

    ofstream budgetFile(fileName, ios::app);

    if (budgetFile.is_open())
    {
        budgetFile << "Date: " << date << endl;
        budgetFile.close();
    }
    else
    {
        cout << "Error: Could not open budget file" << endl;
    }
}

double income()
{
    double Loan, grantsETC, job, savings, anyOther, totalIncome;

    cout << endl;
    cout << "*---------------------------------------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*---------------INCOME------------------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*---------------------------------------*" << endl;
    cout << endl;
    cout << "Please enter your  loan amount, if any." << endl;
    cin >> Loan;

    cout << "Please enter the amount you expect to receive by sponsorship" << endl;
    cin >> grantsETC;

    cout << "Please enter the of income you receive from your job, if you have one" << endl;
    cin >> job;

    cout << "Please enter the amount of savings you wish to spend, if any" << endl;
    cin >> savings;

    cout << "Please enter any other income you may have" << endl;
    cin >> anyOther;

    // totalling up the income
    totalIncome = Loan + grantsETC + job + savings + anyOther;

    return totalIncome;
}

double essentialOutgoing()
{
    double totalEssentialOutgoing, rent, travel, carBills, utilityBills, mobilePhone, food;

    cout << endl;
    cout << "*---------------------------------------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*------------ESSENTIAL COSTS------------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*---------------------------------------*" << endl;
    cout << endl;

    cout << "Please enter the amount of rent you have paid " << endl;
    cin >> rent;

    cout << "Please enter the amount of travel costs " << endl;
    cin >> travel;

    cout << "If a car, please enter the cost for fuel, repairs etc," << endl;
    cin >> carBills;

    cout << "Please enter the amount you have spend on utility bills " << endl;
    cin >> utilityBills;

    cout << "Please enter the amount you have spend on you mobile phone" << endl;
    cin >> mobilePhone;

    cout << "Please enter how much money you have spend on groceries" << endl;
    cin >> food;

    // calculation
    totalEssentialOutgoing = rent + travel + food + utilityBills + mobilePhone + carBills;

    return totalEssentialOutgoing;

} // essentialOutgoing()

double otherCosts()
{
    double totalOtherCosts, conline_shoping, clothing, socialActivities;
    cout << endl;
    cout << "*---------------------------------------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*------------OTHER COSTS------------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*---------------------------------------*" << endl;
    cout << endl;

    cout << "Please enter how much you have spend on online shoping" << endl;
    cin >> conline_shoping;

    cout << "Please enter how much money you have spend on clothing " << endl;
    cin >> clothing;

    cout << "Please enter how much money you have spend on social activities" << endl;
    cin >> socialActivities;

    totalOtherCosts = socialActivities + conline_shoping + clothing;

    return totalOtherCosts;
} // otherCosts()

double unnecessarycost()
{
    double totalunnecessarycost, unnessary, unnessary2;
    cout << endl;
    cout << "*---------------------------------------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*------------UNNECESSARY COST-----------*" << endl;
    cout << "*                                       *" << endl;
    cout << "*---------------------------------------*" << endl;
    cout << endl;

    cout << "Enter the Unessary cost" << endl;
    cin >> unnessary;

    cout << "Enter the Unessary cost-2" << endl;
    cin >> unnessary2;

    totalunnecessarycost = unnessary + unnessary2;

    return totalunnecessarycost;
} // otherCosts()

void storeData(double DailyExpense, double essential, double other, double unessary)
{
    ofstream budgetFile("budget.txt", ios::app);
    if (budgetFile.is_open())
    {
        cout << endl;
        budgetFile << "Essential Expenses: " << essential << endl;
        budgetFile << "Other Expenses: " << other << endl;
        budgetFile << "Unnecessary Expenses: " << unessary << endl;
        budgetFile << "Daily_Expenses: " << DailyExpense << endl;
        cout << endl;
        budgetFile.close();
    }
    else
    {
        cout << "Error: Could not open budget file" << endl;
    }
}

void printData()
{

    ifstream budgetFile("budget.txt", ios::in);

    if (budgetFile.is_open())
    {
        string line;
        while (getline(budgetFile, line))
        {
            cout << line << endl;
        }
        budgetFile.close();
    }
    else
    {
        cout << "Error: Could not open budget file" << endl;
    }
}

void clearFile(string fileName)
{
    // truncate mode
    ofstream budgetFile(fileName, ios::trunc);

    if (budgetFile.is_open())
    {
        budgetFile.close();
    }
    else
    {
        cout << "Error: Could not open budget file" << endl;
    }
}

// string user_name()
// {
//     string nm;
//     cout<<"Enter the Name"<<endl;
//     getline(cin,nm);
//     return nm;
// }

string getName()
{
    string name;
    cout << "Please enter a name: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    return name;
}

void storeMonthlyIncome(string fileName)
{
    string filName = getName();
    double monthlyIncome = income();
    ofstream budgetFile(fileName, ios::app);
    if (budgetFile.is_open())
    {
        budgetFile << "Name : " << filName << endl;
        budgetFile << "Monthly Income: " << monthlyIncome << endl;

        budgetFile.close();
    }
    else
    {

        cout << "Error: Could not open budget file" << endl;
    }
}

double DailyExpense(double otherCost, double essentialOutgoing, double unnessarycst)
{
    double dailyExpense = essentialOutgoing + otherCost + unnessarycst;
    return dailyExpense;
}

int countLines(string fileName)
{
    int lineCount = 0;
    string line;
    ifstream budgetFile(fileName);
    if (budgetFile.is_open())
    {
        while (getline(budgetFile, line))
        {
            lineCount++;
        }
        budgetFile.close();
    }
    else
    {
        cout << "Error: Could not open budget file" << endl;
    }
    return lineCount;
}

double totalmonthlyexpenses(string fileName)
{
    ifstream budgetFile(fileName);
    double expense = 0, totalExpense = 0;
    string expenseLine;
    bool expenseFound = false;
    int lineCounter = 0, totalLines;
    if (budgetFile.is_open())
    {
        totalLines = countLines(fileName); 
        while (getline(budgetFile, expenseLine))
        {
            lineCounter++;
            if (lineCounter <= totalLines)
            {
                if (expenseLine.substr(0, 15) == "Daily_Expenses:")
                {
                    try
                    {
                        expenseLine = expenseLine.substr(15);
                        expense = stod(expenseLine);
                        expenseFound = true;
                        totalExpense += expense;
                    }
                    catch (const std::invalid_argument &ia)
                    {
                        cout << "Invalid argument, skipping line" << endl;
                    }
                }
            }
        }
        budgetFile.close();
    }
    else
    {
        cout << "Error: Could not open budget file" << endl;
    }
    if (!expenseFound)
    {
        cout << "No expenses data found in file" << endl;
    }
    return totalExpense;
}


int main()
{
    int choice;
    double theTotalIncome = 0, theTotalEssentialOutgoing, theTotalOtherCosts, remainingMoney, dailyexpense, totalUnnessaryCost;

    cout << "*----------------------------------------------------------------*" << endl;
    cout << "|                                                                |" << endl;
    cout << "|                                                                |" << endl;
    cout << "|                                                                |" << endl;
    cout << "|             Welcome to Monthly Cost calculator!                |" << endl;
    cout << "|                                                                |" << endl;
    cout << "|                                                                |" << endl;
    cout << "|                                                                |" << endl;
    cout << "|           Created By -:                                        |" << endl;
    cout << "|                         1) Yashraj Nigade                      |" << endl;
    cout << "|                         2) Rohit Kumar                         |" << endl;
    cout << "|                                                                |" << endl;
    cout << "*----------------------------------------------------------------*" << endl;

    do
    {
        cout << "**********************************************************************" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*                 **Enter the Choice**                               *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*         0) Exit                                                    *" << endl;
        cout << "*         1) Enter the Monthly Income                                *" << endl;
        cout << "*         2) Enter the Data                                          *" << endl;
        cout << "*         3) Clear the previous Records from file                    *" << endl;
        cout << "*         4) View Data From File                                     *" << endl;
        cout << "*         5) Total Expense                                           *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "*                                                                    *" << endl;
        cout << "**********************************************************************" << endl;
        cin >> choice;
        if (choice == 1)
        {
            storeMonthlyIncome("budget.txt");
        }
        else if (choice==0)
        {
            exit;
        }
        else if (choice == 2)
        {
            int noOfLines = countLines("budget.txt");

            // for storing Date
            storeDate("budget.txt");

            // theTotalIncome = income();

            // calling ess outgoing method
            theTotalEssentialOutgoing = essentialOutgoing();

            theTotalOtherCosts = otherCosts();

            totalUnnessaryCost = unnecessarycost();

            dailyexpense = DailyExpense(theTotalOtherCosts, theTotalEssentialOutgoing, totalUnnessaryCost);

            // storing the data into files
            storeData(dailyexpense, theTotalEssentialOutgoing, theTotalOtherCosts, totalUnnessaryCost);
        }
        else if (choice == 3)
        {
            cout << endl;
            int chz;
            cout << "1) See data in file" << endl;
            cout << "2) Clear Data" << endl;
            cout << "3) Abbort Clearing" << endl;
            cin >> chz;
            if (chz == 1)
            {
                cout << "Data in the FIle is " << endl;
                printData();
            }
            else if (chz == 2)
            {
                clearFile("budget.txt");
            }
            else
            {
                exit;
            }
        }

        else if (choice == 4)
        {
            cout << "Data in the FIle is " << endl;
            printData();
        }

        else if (choice == 5)
        {
            double total_exp = totalmonthlyexpenses("budget.txt");
            cout << "Total Expense of Month = " << total_exp << endl;
        }
        else
        {
            cout << "Opps!!! You Have Enterd Wrong Choice" << endl;
        }
    } while (choice != 0);

    return 0;
}
