#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
    private:
        string empFirstName, empLastName, empBirthday;
        int vacation = 30;
        int empDegreeOfDisability, empUsedVacation;

    public:
        // Constructor Method for Employee Class
        Employee(string firstName, string lastName, string birthday, int degreeOfDisability, int usedVacation, int vacation) : empFirstName(firstName), empLastName(lastName), empBirthday(birthday), empDegreeOfDisability(degreeOfDisability), empUsedVacation(usedVacation) {};

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
            return vacation;
        }

        int getUsedVacation() {
            return empUsedVacation;
        }
};


class Program {
    
    private:
        string Version;    
        vector<Employee> employeeList;

    public:
        int input;

        Program(string version) {
            Version = version;
        };

        string getVersion() {
            return Version;
        };

        void addEmployee() {
            string firstName, lastName, birthday;
            int vacation = 30;
            int degreeOfDisability, usedVacation, age;

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

       
            switch(age) {
                case age > 50:
                    Employee newEmp(firstName, lastName, birthday, degreeOfDisability, usedVacation, vacation = 30);
                    employeeList.push_back(newEmp);
            }
            Employee newEmp(firstName, lastName, birthday, degreeOfDisability, usedVacation, vacation = 30);
            employeeList.push_back(newEmp);
        };

        void showEmployees() {
            if (employeeList.size() > 0) {
                for (int i = 0; i < employeeList.size(); i++) {
                    cout << "Vorname: " << employeeList[i].getFirstName() << endl;
                    cout << "Nachname: " << employeeList[i].getLastName() << endl;
                    cout << "Geburtsdatum: " << employeeList[i].getBirthday() << endl;
                    cout << "Grad der Behinderung: " << employeeList[i].getDegreeOfDisability() << endl;
                    cout << "Verbuchter Urlaub: " << employeeList[i].getUsedVacation() << endl << endl << endl;
                }
            }
            else {
                cout << "Keine Mitarbeiter in der Datenbank!!\n\n\n";
            }
        };

        void searchEmployee() {
            string inputLastName;
            cout << "Geben Sie den Nachnamen des Mitarbeiters ein, um ihn in der Datenbank zu suchen...\n";
            cin >> inputLastName;
            for (Employee& emp : employeeList) {
                if (emp.getLastName() == inputLastName) {
                    cout << "Vorname: " << emp.getFirstName() << endl;
                    cout << "Nachname: " << emp.getLastName() << endl;
                    cout << "Geburtsdatum: " << emp.getBirthday() << endl;
                    cout << "Grad der Behinderung: " << emp.getDegreeOfDisability() << endl;
                    cout << "Verbuchter Urlaub: " << emp.getUsedVacation() << endl << endl << endl;
                }
                else {
                    cout << "Der eingegebene Mitarbeiter existiert nicht!\n";
                }
            }
        }

        void deleteEmployee() {
            string inputLastName;
            cout << "Geben Sie den Nachnamen des Mitarbeiters an, den Sie aus der Datenbank löschen wollen.\n";
            cin >> inputLastName;
            for (auto emp = employeeList.begin(); emp != employeeList.end(); emp++) {
                if (emp->getLastName() == inputLastName) {
                    emp = employeeList.erase(emp);
                }
            }
        }

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
                cout << "Eingabe von Urlaubstagen..." << endl;
            }
            else if (input == 5)
            {
                cout << "Resturlaub abfragen..." << endl;
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