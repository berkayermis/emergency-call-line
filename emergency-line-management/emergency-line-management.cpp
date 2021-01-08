#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdio>


using namespace std;

/*
	Information of denunciations struct
*/
struct information {
	string address, detail, name,type;
	int id;
};

vector<information> fireInfo;
vector<int> idStr;
/*
	Prototype functions
*/
void addFire(fstream&);
int selectDepartment(fstream&);
int idCreator();
void readData();
void display_data();
void deleteFunction(int);

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
	//readData();
	//display_data();
	//deleteFunction(5);
	//display_data();
	data.close();
	return 0;
}


// ADD function allows user to add a new denunciation to Emergency Call System
void addFire(fstream& file) {

f:
	int fireChoice;
	information tempFireInfo;
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
		getline(cin >> ws, tempFireInfo.address);
		cout << "Detail: ";
		getline(cin >> ws, tempFireInfo.detail);
		cout << "Name: ";
		getline(cin >> ws, tempFireInfo.name);
		tempFireInfo.id = idCreator();
		tempFireInfo.type = "Emergency Fire Notification";
		file << tempFireInfo.id << ';' << tempFireInfo.type << ';' << tempFireInfo.address << ';' << tempFireInfo.detail << ';' << tempFireInfo.name << endl;
		break;
	case 2:
		cout << "Forest Fire Notification:" << endl;
		cout << "Address: ";
		getline(cin >> ws, tempFireInfo.address);
		cout << "Detail: ";
		getline(cin >> ws, tempFireInfo.detail);
		cout << "Name: ";
		getline(cin >> ws, tempFireInfo.name);
		tempFireInfo.id = idCreator();
		file << tempFireInfo.id << ";" << "Forest Fire Notification" << ";" << tempFireInfo.address << ";" << tempFireInfo.detail << ";" << tempFireInfo.name << endl;
		break;
	default:
		goto f;
	}
}

int idCreator() {
	fstream file("ids.csv",ios::in);
	string line;
	int tempID;
	while (getline(file, line)) {
		stringstream geek(line);
		geek >> tempID;
		idStr.push_back(tempID);
	}
	int value = idStr.back();
	idStr.pop_back();
	file.clear();
	file.close();
	file.open("ids.csv",ios::out);
	for (int i = 0; i < idStr.size(); i++) {
		file << idStr.at(i) << endl;
	}
	file.close();
	return value;
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
	if (choice > 9 || choice < 1 || (choice > 4 && choice < 9)) {
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto main;
	}
	else if (choice == 1) { //addEmergency()
	}
	else if (choice == 2) { //addPolice()
	}
	else if (choice == 3) {
		addFire(data); //Fire department usage 
	}
	else if (choice == 4) { //addVeterinary()
	}
	else if (choice == 9) {
		return 0;
	}
	return 0;
}

void readData()
{

	fstream file;
	file.open("data.csv");
	if (!file)
	{
		cout << "File not open\n";
		return;
	}
	string line;
	const char delim = ';';
	string T;
	getline(file, line);
	while (getline(file, line))
	{
		istringstream ss(line);
		information person;
		string type;

		getline(ss, T, delim);
		stringstream geek(T);
		geek >> person.id;
		//cout << person.id << " ";
		getline(ss, T, delim);
		person.type = T;
		//cout << T << " ";
		getline(ss, T, delim);
		person.address = T;
		getline(ss, T, delim);
		person.detail = T;
		getline(ss, T, delim);
		person.name = T;

		/*
		cout << person.address << " ";
		cout << person.detail << " ";
		cout << person.name << " ";
		cout << endl;
		*/

		fireInfo.push_back(person);
	}
	
	file.close();
}


void display_data()
{
	readData();
	for (unsigned int i = 0; i < fireInfo.size(); i++)
		cout << setw(8) << fireInfo[i].id
			 << setw(5) << fireInfo[i].address
			 << setw(8) << fireInfo[i].name
			 << setw(8) << fireInfo[i].detail
			 << '\n';
}


void deleteFunction(int id) {
	readData();
	ofstream data;
	data.open("data.csv",ios::out);
	data << "ID"<< ";" <<"Type" << ";" << "Address" << ";" << "Detail" << ";" << "Name" << endl;
	for (unsigned int i = 0; i < fireInfo.size(); i++) {
		if (id == fireInfo[i].id) {
			continue;
		}
		data << fireInfo[i].id << ";" << fireInfo[i].type << ";" << fireInfo[i].address << ";" << fireInfo[i].detail << ";" << fireInfo[i].name << endl;
	}
	fstream ids("ids.csv", ios::out | ios::app);
	ids << id << endl;
	data.close();
}

