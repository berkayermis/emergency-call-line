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
	Fire department and id creator prototype functions
*/
void fireMenu(fstream&);
int idCreator();

int main()
{
	/*
		Creation of data that is stored inside an excel file (comma-separated values)
	*/
	fstream data;
	data.open("data.csv", ios::out | ios::app);

	int choice;
	//Main menu
main:
	cout << "Welcome to Emergency Call Lines" << endl;
	cout << "1 >> Emergency" << endl;
	cout << "2 >> Police" << endl;
	cout << "3 >> Fire Department" << endl;
	cout << "4 >> Veterinary service" << endl;
	cout << "5 >> Police" << endl;
	cout << "6 >> Exit Program" << endl;

a:
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice > 6 || choice < 1) {
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto a;
	}
	if (choice == 3) {
		fireMenu(data); //Fire department usage
	}
	data.close();
	return 0; 
}


//Fire department menu
void fireMenu(fstream& file) {

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

