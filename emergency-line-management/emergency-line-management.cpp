#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <Windows.h>


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
string notifications[6] = { "Emergency Notification","Police Department Notification","Fire Notification",
						"Emergency Fire Notificationotice","Forest Fire Notification", "Veterinary Service Notification"};

/*
	Prototype functions
*/
void addDenunction(fstream&,information);
int specifyDenunction(fstream&);
int idCreator();
void readData();
void display_data();
void deleteFunction(int);
void update(int);

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

	specifyDenunction(data);
	//update(3);
	//readData();
	//display_data();
	//deleteFunction(5);
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
	cout << "9 >> Exit Program" << endl << endl;
	cout << "Enter your choice: ";

	cin >> choice;
	information prototype;

	switch (choice) {
		case 1:
			prototype.type = notifications[0];
			addDenunction(file, prototype);
			break;
		case 2:
			prototype.type = notifications[1];
			addDenunction(file, prototype);
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
						prototype.type = notifications[3];
						addDenunction(file, prototype);
						break;
					case 2:
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
		case 4:
			prototype.type = notifications[5];
			addDenunction(file, prototype);
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
	ids.close();
	data.close();
}

void update(int id) {
	readData();
	ofstream data;
	data.open("data.csv", ios::out);
	data << "ID" << ";" << "Type" << ";" << "Address" << ";" << "Detail" << ";" << "Name" << endl;
	for (unsigned int i = 0; i < fireInfo.size(); i++) {
		if (id == fireInfo[i].id) {
			f:
				int fireChoice;
				cout << "1 >> Emergency fire notice " << endl;
				cout << "2 >> Forest fire notice" << endl;
				cout << "Enter your choice: ";
				cin >> fireChoice;

				if (fireChoice > 2 || fireChoice < 1) {
					cout << "Invalid Choice\n";
					cout << "Try again...........\n\n";
					goto f;
				}
				else if (fireChoice == 1) { fireInfo[i].type = "Emergency fire notice"; }
				else fireInfo[i].type = "Forest fire notice";

			cout << "Address: ";
			getline(cin >> ws, fireInfo[i].address);
			cout << "Detail: ";
			getline(cin >> ws, fireInfo[i].detail);
			cout << "Name: ";
			getline(cin >> ws, fireInfo[i].name);
			data << fireInfo[i].id << ";" << fireInfo[i].type << ";" << fireInfo[i].address << ";" << fireInfo[i].detail << ";" << fireInfo[i].name << endl;
		}
		else
			data << fireInfo[i].id << ";" << fireInfo[i].type << ";" << fireInfo[i].address << ";" << fireInfo[i].detail << ";" << fireInfo[i].name << endl;

	}
}
