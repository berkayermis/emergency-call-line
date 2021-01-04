#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
	Information of denunciations struct
*/
struct information {
	string address,detail,name;
};

/*
	Prototype functions
*/
void addFire(fstream&);
int selectDepartment(fstream&);
int idCreator();

/*
	Main function consists all departments processes itself
*/
int main()
{
	/*
		Creation of data that is stored inside an excel file (comma-separated values)
	*/
	fstream data;
	data.open("data.csv", ios::out | ios::app);

	selectDepartment(data); //this function allows user to select department

	data.close();
	return 0; 
}


// ADD function allows user to add a new denunciation to Emergency Call System
void addFire(fstream& file) {

f:
	int fireChoice,id;
	information fireInfo;
	cout << "1 >> Emergency fire notice " << endl;
	cout << "2 >> Forest fire notice" << endl;

	cout << "Enter your choice: ";
	cin >> fireChoice;
	
	if (fireChoice > 2 || fireChoice < 1) {
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto f;
	}

	switch (fireChoice) {
		case 1:
			cout << "Emergency Fire Notification:" << endl;
			cout << "Address: ";
			getline(cin >> ws, fireInfo.address);
			cout << "Detail: "; 
			getline(cin >> ws, fireInfo.detail);
			cout << "Name: ";
			getline(cin >> ws, fireInfo.name);
			id = idCreator();
			file << id << ";" <<"Emergency Fire Notification"<< ";" << fireInfo.address << ";" << fireInfo.detail <<";"<< fireInfo.name << endl;
			break;
		case 2:
			cout << "Forest Fire Notification:" << endl;
			cout << "Address: ";
			getline(cin >> ws, fireInfo.address);
			cout << "Detail: ";
			getline(cin >> ws, fireInfo.detail);
			cout << "Name: ";
			getline(cin >> ws, fireInfo.name);
			id = idCreator();
			file << id << ";" << "Forest Fire Notification" << ";" << fireInfo.address << ";" << fireInfo.detail << ";" << fireInfo.name << endl;
			break;

		default:
			goto f;
	}
}

/*
	idCreator function provides to create ID of denunciations with respect to number of line in excel file.
*/
int idCreator()
{
	int lineNo = 0;
	string line;
	fstream data("data.csv", ios::in);
	if (data.is_open()) {
		while (getline(data, line)) {
			lineNo++;
		}
	}
	return lineNo;
}

/*
	SELECT function allows user to select department
*/
int selectDepartment(fstream& data) {
	int choice;

	//Main menu of program
main:
	cout << "Welcome to Emergency Call Lines" << endl;
	cout << "1 >> Emergency" << endl;
	cout << "2 >> Police" << endl;
	cout << "3 >> Fire Department" << endl;
	cout << "4 >> Veterinary Service" << endl;
	cout << "9 >> Exit Program" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice > 9 || choice < 1 || (choice>4 && choice <9)) {
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto main;
	}
	else if (choice == 1) { //addEmergency()
	}
	else if (choice == 2) { //addPolice()
	}	
	else if (choice == 3) { addFire(data); //Fire department usage 
	}
	else if (choice == 4) { //addVeterinary()
	}
	else if (choice == 9) { return 0; 
	}
}
