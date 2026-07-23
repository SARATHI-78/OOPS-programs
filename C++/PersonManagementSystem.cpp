#include <iostream>
#include <string>
using namespace std;

class Address
{
	private:
		string city;
		string state;
		int pincode;

	public:
		Address(string city, string state, int pincode)
		{
			setCity(city);
			setState(state);
			setPincode(pincode);
		}

		void setCity(string city)
		{
			this->city = city;
		}

		void setState(string state)
		{
			this->state = state;
		}

		void setPincode(int pincode)
		{
			this->pincode = pincode;
		}

		void displayAddress()
		{
			cout << "City: " << city << endl;
			cout << "State: " << state << endl;
			cout << "Pincode: " << pincode << endl;
		}
};

class Person
{
	protected:
		string name;
		int age;
		Address address;

	public:
		Person(string name, int age, string city, string state, int pincode) : address(city, state, pincode)
		{
			setName(name);
			setAge(age);
		}

		void setName(string name)
		{
			this->name = name;
		}

		void setAge(int age)
		{
			this->age = age;
		}

		void displayPerson()
		{
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			address.displayAddress();
		}
};

class Student : public Person
{
	private:
		int rollNo;
		string department;

	public:
		Student(string name, int age, string city, string state, int pincode,int rollNo, string department): Person(name, age, city, state, pincode)   // calling Person constructor
		{
			setRollNo(rollNo);
			setDepartment(department);
		}

		void setRollNo(int rollNo)
		{
			this->rollNo = rollNo;
		}

		void setDepartment(string department)
		{
			this->department = department;
		}

		void displayStudent()
		{
			cout << "\nStudent Details" << endl;
			displayPerson();
			cout << "Roll No: " << rollNo << endl;
			cout << "Department: " << department << endl;
		}
};

class Employee : public Person
{
	private:
		int employeeId;
		double salary;

	public:
		Employee(string name, int age, string city, string state, int pincode,int employeeId, double salary): Person(name, age, city, state, pincode)   // calling Person constructor
		{
			setEmployeeId(employeeId);
			setSalary(salary);
		}

		void setEmployeeId(int employeeId)
		{
			this->employeeId = employeeId;
		}

		void setSalary(double salary)
		{
			this->salary = salary;
		}

		void displayEmployee()
		{
			cout << "\n\tEmployee Details\n" << endl;
			displayPerson();
			cout << "Employee ID: " << employeeId << endl;
			cout << "Salary: " << salary << endl;
		}
};

int main()
{
	int choice;

    do {
        cout << "\n\tSelect Catogory\n";
        cout << "1. Student\n";
        cout << "2. Employee\n";
        cout << "3. Exit\n";
        
		cout << "Enter your choice: ";
        cin >> choice;

		if(choice == 3)
		{
			break;
		}

        switch (choice)
		{
			case 1: 
			{
				string name, city, state, department;
				int age, rollNo, pincode;

				cout << "\nEnter Student details\n";
				
				cout << "Name: ";
				cin >> name;

				cout << "Enter Age: ";
				cin >> age;
			
				cout << "Enter City: ";
				cin >> city;

				cout << "Enter State: ";
				cin >> state;

				cout << "Enter Pincode: ";
				cin >> pincode;

				cout << "Enter Roll No: ";
				cin >> rollNo;

				cout << "Enter Department: ";
				cin >> department;

				Student student(name, age, city, state, pincode, rollNo, department);

				student.displayStudent();
				
				break;
			}
			
			case 2:
			{			
				string name, city, state;
				int age, pincode, employeeId;
				double salary;

				cout << "\nEnter Employee details\n";

				cout << "Name: ";
				cin >> name;

				cout << "Enter Age: ";
				cin >> age;

				cout << "Enter City: ";
				cin >> city;

				cout << "Enter State: ";
				cin >> state;

				cout << "Enter Pincode: ";
				cin >> pincode;

				cout << "Enter Employee ID: ";
				cin >> employeeId;

				cout << "Enter Salary: Rs ";
				cin >> salary;

				Employee employee(name, age, city, state, pincode, employeeId, salary);

				employee.displayEmployee();
				
				break;
			}
			default:
				cout << "\nInvalid choice!" << endl;
		}

	} while (true);
	
	cout << "\n\n\tThank You\n";

    return 0;
}
