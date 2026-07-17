#include<iostream>
#include<fstream>
using namespace std;

// Parent Class
class User {

protected:
    string username = "admin";
    string password = "1234";
};

// Child Class
class SafeVault : public User {

private:

    float income = 0;
    float expense = 0;
    float budget = 0;

public:

    // Constructor
    SafeVault() {

        loadData();

        cout << "Welcome to SafeVault System\n";
    }

    // Load Previous Data
    void loadData() {

        ifstream file("report.txt");

        if(file.is_open()) {

            file >> income;
            file >> expense;
            file >> budget;

            file.close();
        }
    }

    // Save Data Permanently
    void saveData() {

        ofstream file("report.txt");

        file << income << endl;
        file << expense << endl;
        file << budget << endl;

        file.close();
    }

    // Login Function
    bool login() {

        string user, pass;
        int attempt = 0;

        while(attempt < 3) {

            cout << "Username: ";
            cin >> user;

            cout << "Password: ";
            cin >> pass;

            if(user == username && pass == password) {

                cout << "\nLogin Successful!\n";
                return true;
            }

            else {

                cout << "\nWrong Password!\n";
                attempt++;
            }
        }

        cout << "\nAccess Denied!\n";
        return false;
    }

    // Add Income
    void addIncome() {

        float amount;

        cout << "Enter Income: ";
        cin >> amount;

        income += amount;

        saveData();

        cout << "Income Added Successfully!\n";
    }

    // Add Expense
    void addExpense() {

        float amount;

        cout << "Enter Expense: ";
        cin >> amount;

        expense += amount;

        saveData();

        cout << "Expense Added Successfully!\n";
    }

    // Show Balance
    void showBalance() {

        float balance = income - expense;

        cout << "\n===== FINANCIAL SUMMARY =====\n";

        cout << "Total Income : "
             << income
             << " Taka\n";

        cout << "Total Expense : "
             << expense
             << " Taka\n";

        cout << "Current Balance : "
             << balance
             << " Taka\n";

        if(expense >= budget && budget != 0) {

            cout << "\nWarning! Budget Limit Reached!\n";
        }
    }

    // Set Budget
    void setBudget() {

        cout << "Enter Budget Limit: ";
        cin >> budget;

        saveData();

        cout << "Budget Saved Successfully!\n";
    }

    // Split Bill
    void splitBill() {

        float bill;
        int people;

        cout << "Enter Total Bill: ";
        cin >> bill;

        cout << "Enter Number of People: ";
        cin >> people;

        cout << "\nEach Person Will Pay: "
             << bill / people
             << " Taka\n";
    }

    // Reminder System
    void reminder() {

        string name;
        string date;
        float amount;

        cin.ignore();

        cout << "\nEnter Bill or Debt Name: ";
        getline(cin, name);

        cout << "Enter Amount: ";
        cin >> amount;

        cout << "Enter Due Date: ";
        cin >> date;

        cout << "\n===== REMINDER SAVED =====\n";

        cout << "Pay "
             << amount
             << " Taka for "
             << name
             << " before "
             << date
             << endl;
    }

    // Export Report
    void exportReport() {

        ofstream file("finance_report.txt");

        file << "===== SafeVault Report =====\n";
        file << "Income : " << income << endl;
        file << "Expense : " << expense << endl;
        file << "Balance : " << income - expense << endl;

        file.close();

        cout << "\nReport Exported Successfully!\n";
    }
};

int main() {

    SafeVault obj;

    if(obj.login() == false) {

        return 0;
    }

    int choice;

    do {

        cout << "\n===== SafeVault MENU =====\n";

        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. Show Balance\n";
        cout << "4. Set Budget\n";
        cout << "5. Split Bill\n";
        cout << "6. Add Reminder\n";
        cout << "7. Export Report\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            obj.addIncome();
            break;

        case 2:
            obj.addExpense();
            break;

        case 3:
            obj.showBalance();
            break;

        case 4:
            obj.setBudget();
            break;

        case 5:
            obj.splitBill();
            break;

        case 6:
            obj.reminder();
            break;

        case 7:
            obj.exportReport();
            break;

        case 8:
            cout << "\nProgram Ended Successfully!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 8);

    return 0;
}
