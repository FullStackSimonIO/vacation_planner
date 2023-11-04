#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<Employee> employees;


class Program {
    
    private:
        string Version;    
    public:


        Program(string version) {
            Version = version;
        }


        void setVersion(string version) {
            Version = version;
        }
        string getVersion() {
            return Version;
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
        }

        void showEmployees() {
            cout << "ALLE MITARBEITER:" << endl;

        }
};

class Employee {
    
    // Class Attributes
    private:
        string FirstName;
        string LastName;
        string Birthday;
        int DegreeOfDisability;
        int UsedVacation;
        
    public:
        // Constructor Method for Employee Class
        Employee(const string& firstName, const string& lastName, const string& birthday, const int& degreeOfDisability, const int& usedVacation) {
            FirstName = firstName;
            LastName = lastName;
            Birthday = birthday;
            DegreeOfDisability = degreeOfDisability;
            UsedVacation = usedVacation;
        }

        // Getter & Setter Methods for private Class Attributes
        void setFirstName(string firstName) {
            FirstName = firstName;
        }
        const string& getFirstName() {
            return FirstName;
        }


        void setLastName(string lastName) {
            LastName = lastName;
        }
        string getLastName() {
            return LastName;
        }
        

        void setBirthday(string birthday) {
            Birthday = birthday;
        }
        string getBirthday() {
            return Birthday;
        }


        void setDegreeOfDisability(int degreeOfDisability) {
            DegreeOfDisability = degreeOfDisability;
        }
        int getDegreeOfDisability() {
            return DegreeOfDisability;
        }


        void setUsedVacation(int usedVacation) {
            UsedVacation = usedVacation;
        }
        int getUsedVacation() {
            return UsedVacation;
        }

        void removeEmployee() {
            delete this;
        };


};

void addEmployee(vector<Employee>& employees) {
        string empFirstName, empLastName, empBirthDay;
        int degree, usedVacation;

        cout << "Mitarbeiter anlegen...\n\n" << endl;
        cout << "Geben Sie den Vornamen ein\n";
        cin >> empFirstName;
        cout << "Geben Sie den Nachnamen ein\n";
        cin >> empLastName;
        cout << "Geben Sie das Geburtsdatum ein\n";
        cin >> empBirthDay;
        cout << "Geben Sie den Grad der Behinderung ein ein\n";
        cin >> degree;
        cout << "Geben Sie den verbrauchten Urlaub ein\n";
        cin >> usedVacation;   

        cout << "Lege Mitarbeiter an...\n\n\n";
        cout << "Mitarbeiter erfolgreich angelegt...\nHier sind die von Ihnen eingegebenen Informationen:\n\n";
        cout << "Vorname: "<< empFirstName << endl;
        cout << "Nachname: " << empLastName << endl;
        cout << "Geburtsdatum: " << empBirthDay << endl;
        cout << "Grad der Behinderung: " << degree << endl;
        cout << "Verbuchter Urlaub: " << usedVacation << endl;

        employees.push_back(Employee(empFirstName, empLastName, empBirthDay, degree, usedVacation));
    };
    

int main() {
    int input;

    Program version1("1.0.0");

    version1.showHomescreen();

    cin >> input;
    if (input == 1) 
    {
        cout << "Mitarbeiter zeigen...\n" << endl;
        for (Employee& employee : employees) {
            cout << "Mitarbeiter: " << employee.getFirstName() << endl;
        }


    } 
    else if (input == 2)
    {
        addEmployee(employees);
    }
    else if (input == 3)
    {
        cout << "Mitarbeiter löschen..." << endl;
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
    }
    else 
    {
        cout << "Error\n";
    }
}