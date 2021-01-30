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
	string address, detail, name, type;
	int id;
};
vector<information> general;
vector<int> idStr;
string notifications[12] = { "Emergency Notification",
							"Traffic Accident Notification",
							"Home Accident Notification",
							"Work Accident Notification",
							"Others",
							"Police Department Notification",
							"Fire Notification",
							"Emergency Fire Notificationotice",
							"Forest Fire Notification",
							"Veterinary Service Notification",
							"Pet Help",
							"Street Animals Help" };

/*
	Prototype functions
*/
void addDenunction(fstream&, information);
int specifyDenunction(fstream&);
int idCreator();
void readData();
void display_data();
void deleteFunction(int);
int update(int);
void updateDenunction(fstream&, information);

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
	//display_data();
	specifyDenunction(data);

	//readData();

	//deleteFunction(1);
	//display_data();

	data.close();
	return 0;
}

void addDenunction(fstream& file, information prototype) {
	cout << prototype.type << endl;
	cout << "Address: ";
	getline(cin >> ws, prototype.address);
	cout << "Detail: ";
	getline(cin >> ws, prototype.detail);
	cout << "Name: ";
	getline(cin >> ws, prototype.name);
	prototype.id = idCreator();
	cout << "Your ID is " << prototype.id;
	file << prototype.id << ';' << prototype.type << ';' << prototype.address << ';' << prototype.detail << ';' << prototype.name << endl;
}

void updateDenunction(fstream& file, information prototype) {
	cout << "Address: ";
	getline(cin >> ws, prototype.address);
	cout << "Detail: ";
	getline(cin >> ws, prototype.detail);
	cout << "Name: ";
	getline(cin >> ws, prototype.name);
	file << prototype.id << ';' << prototype.type << ';' << prototype.address << ';' << prototype.detail << ';' << prototype.name << endl;
}


// ADD function allows user to add a new denunciation to Emergency Call System
int specifyDenunction(fstream& file) {

main:
	int choice;
	cout << "Welcome to Emergency Call Lines" << endl;
	cout << "1 >> Emergency Department" << endl;
	cout << "2 >> Police Department" << endl;
	cout << "3 >> Fire Department" << endl;
	cout << "4 >> Veterinary Service" << endl;
	cout << "5 >> Update Denunction" << endl;
	cout << "6 >>  Delete Denunction " << endl;
	cout << "9 >> Exit Program" << endl << endl;
	cout << "Enter your choice: ";

	cin >> choice;
	while (cin.fail()) {
		cout << "Please enter number" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> choice;
	}
	information prototype;

	switch (choice) {
	case 1:
		prototype.type = notifications[0];
	e:
		int Choice1;
		cout << "1 >> Traffic Accident Notification " << endl;
		cout << "2 >> Home Accident Notification" << endl;
		cout << "3 >> Work Accident Notification" << endl;
		cout << "4 >> Others" << endl;
		cout << "9 >> Back" << endl;
		cout << "Enter your choice: ";
		cin >> Choice1;
		switch (Choice1) {
		case 1:
			prototype.type = notifications[1];
			addDenunction(file, prototype);
			break;
		case 2:
			prototype.type = notifications[2];
			addDenunction(file, prototype);
			break;
		case 3:
			prototype.type = notifications[3];
			addDenunction(file, prototype);
			break;
		case 4:
			prototype.type = notifications[4];
			addDenunction(file, prototype);
			break;
		case 9:
			goto main;
			break;
		default:
			cout << "Invalid Choice\n";
			cout << "Try again...........\n\n";
			goto f;
		}
		break;
		addDenunction(file, prototype);
		break;
	case 2:
		prototype.type = notifications[5];
		addDenunction(file, prototype);
		break;
	case 3:
		prototype.type = notifications[6];
	f:
		int Choice;
		cout << "1 >> Emergency Fire Notification " << endl;
		cout << "2 >> Forest Fire Notification" << endl;
		cout << "9 >> Back" << endl;
		cout << "Enter your choice: ";
		cin >> Choice;

		switch (Choice) {
		case 1:
			prototype.type = notifications[7];
			addDenunction(file, prototype);
			break;
		case 2:
			prototype.type = notifications[8];
			addDenunction(file, prototype);
			break;

		case 9:
			goto main;
			break;
		default:
			cout << "Invalid Choice\n";
			cout << "Try again...........\n\n";
			goto f;
		}
		break;
	case 4:
		prototype.type = notifications[9];
	v:
		int Choice2;
		cout << "1 >> Pet Help " << endl;
		cout << "2 >> Street Animals Help" << endl;
		cout << "9 >> Back" << endl;
		cout << "Enter your choice: ";
		cin >> Choice2;

		switch (Choice2) {
		case 1:
			prototype.type = notifications[10];
			addDenunction(file, prototype);
			break;
		case 2:
			prototype.type = notifications[11];
			addDenunction(file, prototype);
			break;
		case 9:
			goto main;
			break;
		default:
			cout << "Invalid Choice\n";
			cout << "Try again...........\n\n";
			goto v;
		}
		break;
	case 5:
		int id;
		cout << "Enter ID : ";
		cin >> id;
		update(id);
		break;
	case 6:
		cout << "Enter ID : ";
		cin >> id;
		deleteFunction(id);
		cout << "Denunction is deleted.";
		break;
	case 9:
		return 0;
	default:
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto main;
	}
}

int idCreator() {
	fstream file("ids.csv", ios::in);
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
	file.open("ids.csv", ios::out);
	for (int i = 0; i < idStr.size(); i++) {

		file << idStr.at(i) << endl;
	}
	file.close();
	return value;
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
		getline(ss, T, delim);
		person.type = T;
		getline(ss, T, delim);
		person.address = T;
		getline(ss, T, delim);
		person.detail = T;
		getline(ss, T, delim);
		person.name = T;

		general.push_back(person);
	}

	file.close();
}


void display_data()
{
	readData();
	for (unsigned int i = 0; i < general.size(); i++)
		cout << setw(8) << general[i].id
		<< setw(5) << general[i].address
		<< setw(8) << general[i].name
		<< setw(8) << general[i].detail
		<< '\n';
}


void deleteFunction(int id) {
	readData();
	ofstream data;
	data.open("data.csv", ios::out);
	data << "ID" << ";" << "Type" << ";" << "Address" << ";" << "Detail" << ";" << "Name" << endl;
	for (unsigned int i = 0; i < general.size(); i++) {
		if (id == general[i].id) {
			continue;
		}
		data << general[i].id << ";" << general[i].type << ";" << general[i].address << ";" << general[i].detail << ";" << general[i].name << endl;
	}
	fstream ids("ids.csv", ios::out | ios::app);
	ids << id << endl;
	ids.close();
	data.close();
}

int update(int id) {
	readData();
	fstream data;
	data.open("data.csv", ios::out);
	data << "ID" << ";" << "Type" << ";" << "Address" << ";" << "Detail" << ";" << "Name" << endl;
	for (unsigned int i = 0; i < general.size(); i++) {
		if (id == general[i].id) {

		main:
			int choice;
			cout << "Change denunction type" << endl;
			cout << "1 >> Emergency Department" << endl;
			cout << "2 >> Police Department" << endl;
			cout << "3 >> Fire Department" << endl;
			cout << "4 >> Veterinary Service" << endl;
			cout << "9 >> Exit Program" << endl << endl;
			cout << "Enter your choice: ";

			cin >> choice;

			information prototype;

			switch (choice) {
			case 1:
			e:
				prototype.type = notifications[0];
				int Choice1;
				cout << "1 >> Traffic Accident Notification " << endl;
				cout << "2 >> Home Accident Notification" << endl;
				cout << "3 >> Work Accident Notification" << endl;
				cout << "4 >> Others " << endl;
				cout << "9 >> Back" << endl;
				cout << "Enter your choice: ";
				cin >> Choice1;
				switch (Choice1) {
				case 1:
					prototype.type = notifications[1];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 2:
					prototype.type = notifications[2];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 3:
					prototype.type = notifications[3];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 4:
					prototype.type = notifications[4];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 9:
					goto main;
				default:
					cout << "Invalid Choice\n";
					cout << "Try again...........\n\n";
					goto e;
				}
				break;
			case 2:
				prototype.type = notifications[5];
				prototype.id = id;
				updateDenunction(data, prototype);
				break;
			case 3:
				prototype.type = notifications[2];
			f:
				int Choice;
				cout << "1 >> Emergency Fire Notification " << endl;
				cout << "2 >> Forest Fire Notification" << endl;
				cout << "9 >> Back" << endl;
				cout << "Enter your choice: ";
				cin >> Choice;

				switch (Choice) {
				case 1:
					prototype.type = notifications[7];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 2:
					prototype.type = notifications[8];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 9:
					goto main;
					break;
				default:
					cout << "Invalid Choice\n";
					cout << "Try again...........\n\n";
					goto f;
				}
				break;
			case 4:
				prototype.type = notifications[9];
			v:
				int Choice2;
				cout << "1 >> Pet Help " << endl;
				cout << "2 >> Street Animals Help" << endl;
				cout << "9 >> Back" << endl;
				cout << "Enter your choice: ";
				cin >> Choice2;
				switch (Choice2) {
				case 1:
					prototype.type = notifications[10];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 2:
					prototype.type = notifications[11];
					prototype.id = id;
					updateDenunction(data, prototype);
					break;
				case 9:
					goto main;
				default:
					cout << "Invalid Choice\n";
					cout << "Try again...........\n\n";
					goto v;
				}
				break;
			case 9:
				return 0;
			default:
				cout << "Invalid Choice\n";
				cout << "Try again...........\n\n";
				goto main;
			}
		}

		else
			data << general[i].id << ";" << general[i].type << ";" << general[i].address << ";" << general[i].detail << ";" << general[i].name << endl;
	}
}