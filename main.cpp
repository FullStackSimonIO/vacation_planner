#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

///////////////////
// EMPLOYEE CLASS//
///////////////////
class Employee {
    private:
        string empFirstName, empLastName, empBirthday;
        int yearlyEmpVacation;
        int empDegreeOfDisability, empUsedVacation, empIndex;


    public:
        // Constructor Method for Employee Class
        Employee(string firstName, string lastName, string birthday, int degreeOfDisability, int usedVacation, int vacation, int index) : empFirstName(firstName), empLastName(lastName), empBirthday(birthday), empDegreeOfDisability(degreeOfDisability), empUsedVacation(usedVacation), yearlyEmpVacation(vacation), empIndex(index) {};
        vector<string> vacationDays;


        // Getter & Setter Methods for private Class Attributes
        string getFirstName() {
            return empFirstName;
        }

        string getLastName() {
            return empLastName;
        }

        string getBirthday() {
            return empBirthday;
        }

        int getDegreeOfDisability() {
            return empDegreeOfDisability;
        }
        
        int getVacation() {
            return yearlyEmpVacation;
        }

        int getUsedVacation() {
            return empUsedVacation;
        }

        int getEmployeeIndex() {
            return empIndex;
        }
        
        void setEmployeeIndex(int index) {
            empIndex = index;
        }

        void setYearlyVacationDays(int vacationDays) {
            yearlyEmpVacation = vacationDays;
        }

        void setUsedVacation(int vacationDays) {
            empUsedVacation += vacationDays;
        }


        ////////////////////////////
        //ADD VACATION DAYS METHOD//
        ////////////////////////////

        void getVacationDays() {
            for (int i = 0; i <= vacationDays.size(); i++) {
                cout << vacationDays[i] << endl;
            }
        }

};




/////////////////
//PROGRAM CLASS//
/////////////////
class Program {
    
    private:
        string Version;    
    
    public:
        vector<Employee> employeeList = {Employee("Max", "Mustermann", "01.01.2000", 0, 0, 0, 0)};
        int input;

        Program(string version) {
            Version = version;
        };

        string getVersion() {
            return Version;
        };

        ////////////////////////
        //ADD EMPLOYEE METHOD//
        ////////////////////////

        void addEmployee() {
            string firstName, lastName, birthday;
            int vacation = 30;
            int degreeOfDisability, usedVacation, age, index;

            cout << "Geben Sie den Vornamen des Mitarbeiters ein...\n";
            cin >> firstName;
            cout << "Geben Sie den Nachnamen des Mitarbeiters ein...\n";
            cin >> lastName;
            cout << "Geben Sie das Geburtsdatum des Mitarbeiters ein... (Format: 01.01.2000)\n";
            cin >> birthday;
            cout << "Geben Sie den Grad der Behinderung ein...\n";
            cin >> degreeOfDisability;
            cout << "Geben Sie die bereits verbuchten Urlaubstage ein...\n";
            cin >> usedVacation;
            cout << "Berechne jährliche Urlaubstage..\n";
            vacation = calculateVacationDays(birthday, degreeOfDisability);


            Employee newEmp(firstName, lastName, birthday, degreeOfDisability, usedVacation, vacation, index);
            employeeList.push_back(newEmp);

            cout << "Mitarbeiternummer wird zugewiesen...\n";
            for (int i = 0; i < employeeList.size(); i++) {
                employeeList[i].setEmployeeIndex(i);
            }
        };


        /////////////////////////
        //SHOW EMPLOYEES METHOD//
        /////////////////////////

        void showEmployees() {
            if (employeeList.size() > 0) {
                for (int i = 1; i < employeeList.size(); i++) {
                    cout << "Mitarbeiternummer: " << employeeList[i].getEmployeeIndex() << endl;
                    cout << "Vorname: " << employeeList[i].getFirstName() << endl;
                    cout << "Nachname: " << employeeList[i].getLastName() << endl;
                    cout << "Geburtsdatum: " << employeeList[i].getBirthday() << endl;
                    cout << "Grad der Behinderung: " << employeeList[i].getDegreeOfDisability() << endl;
                    cout << "Jährlicher Urlaub: " << employeeList[i].getVacation() << endl;
                    cout << "Verbuchter Urlaub: " << employeeList[i].getUsedVacation() << endl << endl << endl;
                }
            }
            else {
                cout << "Keine Mitarbeiter in der Datenbank!!\n\n\n";
            }
        };


        //////////////////////////
        //SEARCH EMPLOYEE METHOD//
        //////////////////////////

        void searchEmployee() {
            int searchInput, index, employeeIndex;
            string lastname, employeeLastname;
            cout << "Möchten Sie den Mitarbeiter anhand seines Nachnamens oder anhand seiner Mitarbeiternummer in der Datenbank suchen?\n";
            cout << "1. Mitarbeiternummer\n2. Nachname\n";
            cin >> searchInput;
            if (searchInput == 1) {
                cout << "Bitte geben Sie die Mitarbeiternummer ein...\n";
                cin >> index;
                for (Employee emp : employeeList) {
                    if (emp.getEmployeeIndex() == index) {
                        cout << "Mitarbeiternummer: " << emp.getEmployeeIndex() << endl;
                        cout << "Vorname: " << emp.getFirstName() << endl;
                        cout << "Nachname: " << emp.getLastName() << endl;
                        cout << "Geburtsdatum: " << emp.getBirthday() << endl;
                        cout << "Grad der Behinderung: " << emp.getDegreeOfDisability() << endl;
                        cout << "Verbuchter Urlaub: " << emp.getUsedVacation() << endl << endl << endl;
                    }
                }
            } 
            else if (searchInput == 2) {
                cout << "Bitte geben Sie den Nachnamen des Mitarbeiters an...\n";
                cin >> lastname;
                for (Employee emp : employeeList) {
                    if (emp.getLastName() == lastname) {
                        cout << "Mitarbeiternummer: " << emp.getEmployeeIndex() << endl;
                        cout << "Vorname: " << emp.getFirstName() << endl;
                        cout << "Nachname: " << emp.getLastName() << endl;
                        cout << "Geburtsdatum: " << emp.getBirthday() << endl;
                        cout << "Grad der Behinderung: " << emp.getDegreeOfDisability() << endl;
                        cout << "Verbuchter Urlaub: " << emp.getUsedVacation() << endl << endl << endl;
                    }
                }   
            }
        }


        //////////////////////////
        //DELETE EMPLOYEE METHOD//
        //////////////////////////

        void deleteEmployee() {
            int index, input;
            string lastname;

            cout << "Möchten Sie den Mitarbeiter anhand seiner Mitarbeiternummer oder anhand seines Nachnamen aus der Datenbank löschen?\n";
            cout << "1. Mitarbeiternummer\n2. Nachname\n";
            cin >> input;

            if (input == 1) {
                cout << "Geben Sie die Mitarbeiternummer an...\n";
                cin >> index;
                for (auto emp = employeeList.begin(); emp != employeeList.end(); emp++) {
                if (emp->getEmployeeIndex() == index) {
                    employeeList.erase(emp);
                    showHomescreen();
                    }
                }
            }
            else if (input == 2) {
                cout << "Bitte geben Sie den Nachnamen des Mitarbeiters an...\n";
                cin >> lastname;
                for (auto emp = employeeList.begin(); emp !=employeeList.end(); emp++) {
                    if (emp->getLastName() == lastname) {
                        employeeList.erase(emp);
                        showHomescreen();
                    }
                }

            }
        
        }


        ///////////////////////////
        //CALCULATE VACATION DAYS//
        ///////////////////////////

        int calculateVacationDays() {
            int searchInput, index, employeeIndex;
            string lastname, employeeLastname;

            cout << "Möchten Sie den Mitarbeiter anhand seines Nachnamens oder anhand seiner Mitarbeiternummer in der Datenbank suchen?\n";
            cout << "1. Mitarbeiternummer\n2. Nachname\n";
            cin >> searchInput;
            if (searchInput == 1) {
                cout << "Bitte geben Sie die Mitarbeiternummer ein...\n";
                cin >> index;
                // Loop through employee vector and search for Index
                for (Employee emp : employeeList) {
                    if (emp.getEmployeeIndex() == index) {
                        string birthday = emp.getBirthday();
                        int degreeOfDisability = emp.getDegreeOfDisability();

                        // Calculate age function
                        string year = birthday.substr(birthday.length() -4,4);
                        int birthyear = stoi(year);
                        string month = birthday.substr(birthday.length() -7,2);
                        int birthmonth = stoi(month);
                        string day = birthday.substr(birthday.length() -10,2);
                        int dayOfBirth = stoi(day);
                        time_t now = time(0);
                        tm* localdate = localtime(&now);
                        int currentYear = localdate->tm_year + 1900;
                        int age = currentYear - birthyear;
                        if (birthmonth > localdate->tm_mon + 1 || (birthmonth == localdate->tm_mon + 1 && dayOfBirth > localdate->tm_mday)) {
                            age--;
                        }
                        
                        // Checking degree of disability and current age to calculate vacation days
                        if (age < 50 && degreeOfDisability < 50) {
                            emp.setYearlyVacationDays(30);
                        }
                        else if (age > 50 && degreeOfDisability < 50) {
                           emp.setYearlyVacationDays(32);
                        }
                        else if (age < 50 && degreeOfDisability > 50) {
                            emp.setYearlyVacationDays(35);
                        }
                        else if (age > 50 && degreeOfDisability > 50) {
                            emp.setYearlyVacationDays(37);
                        }
                    }
                }
            } 
            else if (searchInput == 2) {
                cout << "Bitte geben Sie den Nachnamen des Mitarbeiters an...\n";
                cin >> lastname;
                    // Loop through employee vector and search for lastname
                    for (Employee emp : employeeList) {
                        if (emp.getEmployeeIndex() == index) {
                        string birthday = emp.getBirthday();
                        int degreeOfDisability = emp.getDegreeOfDisability();
                        string year = birthday.substr(birthday.length() -4,4);
                        int birthyear = stoi(year);
                        string month = birthday.substr(birthday.length() -7,2);
                        int birthmonth = stoi(month);
                        string day = birthday.substr(birthday.length() -10,2);
                        int dayOfBirth = stoi(day);

                        time_t now = time(0);
                        tm* localdate = localtime(&now);

                        int currentYear = localdate->tm_year + 1900;
                        int age = currentYear - birthyear;

                        if (birthmonth > localdate->tm_mon + 1 || (birthmonth == localdate->tm_mon + 1 && dayOfBirth > localdate->tm_mday)) {
                            age--;
                        }

                        if (age < 50 && degreeOfDisability < 50) {
                            emp.setYearlyVacationDays(30);
                        }
                        else if (age > 50 && degreeOfDisability < 50) {
                           emp.setYearlyVacationDays(32);
                        }
                        else if (age < 50 && degreeOfDisability > 50) {
                            emp.setYearlyVacationDays(35);
                        }
                        else if (age > 50 && degreeOfDisability > 50) {
                            emp.setYearlyVacationDays(37);
                        }
                    }
                }
            }   
        }
        

        ////////////////////////////
        //ADD VACATION DAYS METHOD//
        ////////////////////////////

        void addVacationDay() {
            int days, remainingVacationDays;
            string date;
            cout << "Wie viele Urlaubstage möchten Sie eingeben?\n";
            cin >> days;
            cout << "Sie können jetzt " << days << " Tag(e) verplanen.\nBitte geben Sie einen Tag nach dem anderen ein und bestätigen Sie mit Enter\n";
            for (Employee emp : employeeList){
                cout << "Bitte geben Sie den Urlaubstag ein.\n";
                cin >> date;
                emp.vacationDays.push_back(date);
                emp.setUsedVacation(days);
                remainingVacationDays = emp.getVacation() - emp.getUsedVacation();
                cout << "Sie haben " << emp.getUsedVacation() << " Tage Urlaub bereits verbucht.\nSie haben noch " << remainingVacationDays << " Tag(e) zum verplanen übrig.\n";
            }
        }

        //////////////////////////
        //SHOW HOMESCREEN METHOD//
        //////////////////////////

        void showHomescreen() {
            cout << "#####################" << endl;
            cout << "###URLAUBSPLANUNG:###" << endl;
            cout << "#####################" << endl << endl;

            cout << "1: Mitarbeiter zeigen" << endl;
            cout << "2: Mitarbeiter anlegen" << endl;
            cout << "3: Mitarbeiter löschen" << endl;
            cout << "4: Eingabe von Urlaubstag" << endl;
            cout << "5: Resturlaub überprüfen" << endl;
            cout << "6: Mitarbeiterdaten abfragen" << endl << endl;

            cout << "Bitte wählen Sie Ihre Funktion aus..." << endl;

            cin >> input;
            if (input == 1) 
            {
                cout << "Mitarbeiter zeigen...\n" << endl;
                showEmployees();
                showHomescreen();
                cin >> input;
            } 
            else if (input == 2)
            {
                cout << "Mitarbeiter hinzufügen...\n" << endl;
                addEmployee();
                showHomescreen();
                cin >> input;
            }
            else if (input == 3)
            {
                cout << "Mitarbeiter löschen..." << endl;
                deleteEmployee();
                showHomescreen();
            }
            else if (input == 4)
            {
                int empNum;
                cout << "Eingabe von Urlaubstagen..." << endl;
                cout << "Bitte wählen Sie den Mitarbeiter anhand seiner Mitarbeiternummer\n";
                cin >> empNum;
                employeeList[empNum].addVacationDay();
                employeeList[empNum].getVacationDays();
                showHomescreen();
            }
            else if (input == 5)
            {
                cout << "Resturlaub abfragen..." << endl;
                cout <<  << endl;
            }
            else if (input == 6)
            {
                cout << "Mitarbeiterdaten abfragen..." << endl;
                searchEmployee();
                showHomescreen();
            }
            else 
            {
                cout << "Error\n";
            }
        }
};


int main() {
    Program version1("1.0.0");
    version1.showHomescreen();
}