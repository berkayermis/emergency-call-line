/*
----------------------------------------------------------------
	Names:Ilknur Akçay - Merve zehra Peru - Muhammed Berkay Ermis

	Course: Programming for Engineering Project 2021

	Purpose:The aim of this project is to reduce the emergency lines
			to a single line to prevent confusion and ease the situation.
			Notifications are saved when the necessary information
			is entered by the user into the program.
----------------------------------------------------------------
*/

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
----------------------------------------------------------------
	Information of denunciations struct
----------------------------------------------------------------
*/
struct information {
	string address, detail, name, type;
	int id;
};

vector<information> general;
vector<int> idStr;
string notifications[16] = { "Emergency Notification",
							"Traffic Accident Notification",
							"Home Accident Notification",
							"Work Accident Notification",
							"Others",
							"Fire Notification",
							"Emergency Fire Notificationotice",
							"Forest Fire Notification",
							"Veterinary Service Notification",
							"Pet Help",
							"Street Animals Help",
							"Police Department Notification",
							"Traffic Rule Violations",
							"Missing Person Reports",
							"Public Securities",
							"Anti-narcotics Crimes"
};

/*
----------------------------------------------------------------
	Prototype functions
----------------------------------------------------------------
*/
void addDenunction(fstream&, information);
int specifyDenunction(fstream&);
int idCreator();
void readData();
void display_data();
void deleteFunction(int, string);
void update(int, string);
void updateDenunction(fstream&, information);
bool check(istream&);

/*
-------------------------------------------------------------
	Main function consists all departments processes itself
----------------------------------------------------------------
*/
int main()
{
	/*
		Creation of data that is stored inside an excel file (comma-separated values)
	*/
	fstream data;
	data.open("data.csv", ios::out | ios::app);

	specifyDenunction(data);

	data.close();
	//display_data();

	return 0;
}

/*
------------------------------------------------------------------
This function checks whether people are entering numbers or letters
param :(input)
input(cin)
------------------------------------------------------------------
*/
bool check(istream& cin) {
	while (cin.fail()) {
		cout << "Invalid number" << endl << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return true;
	}
	return false;
}

/*
------------------------------------------------------------------
This function provide to add denunction.
param :(output,input)
------------------------------------------------------------------
*/
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

/*
------------------------------------------------------------------
This function allows to receive new information from the user when an update is requested.
param:(output,input)
------------------------------------------------------------------
*/
void updateDenunction(fstream& file, information prototype) {
	cout << "Address: ";
	getline(cin >> ws, prototype.address);
	cout << "Detail: ";
	getline(cin >> ws, prototype.detail);
	cout << "Denunction was updated" << endl;
	file << prototype.id << ';' << prototype.type << ';' << prototype.address << ';' << prototype.detail << ';' << prototype.name << endl;
}

/*
------------------------------------------------------------------
This function is where functions such as adding, deleting, updating notification are selected.
param:(output)
------------------------------------------------------------------
*/
int specifyDenunction(fstream& file) {

main:
	int choice;
	cout << "Welcome to Emergency Call Lines" << endl;
	cout << "1 >> Emergency Department" << endl;
	cout << "2 >> Police Department" << endl;
	cout << "3 >> Fire Department" << endl;
	cout << "4 >> Veterinary Service" << endl;
	cout << "5 >> Update Denunction" << endl;
	cout << "6 >> Delete Denunction " << endl;
	cout << "9 >> Exit Program" << endl << endl;
	cout << "Enter your choice: ";

	cin >> choice;
	//If the value received from the user is not a number, the code returns to the main part
	if (check(cin)) goto main;
	information prototype;

	/*
		If the value received from the user matches the numbers in the menu,
		it is directed to the relevant section with the help of the "switch case"
	*/
	switch (choice) {
	case 1:
		//Emergency Department
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
		if (check(cin)) goto e;
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
			goto e;
		}
		break;
	case 2:
		//Police Department
		prototype.type = notifications[11];
	a:
		int Choice3;
		cout << "1 >> Traffic Rule Violations " << endl;
		cout << "2 >> Missing Person Reports" << endl;
		cout << "3 >> Public Securities" << endl;
		cout << "4 >> Anti-narcotics Crimes" << endl;
		cout << "9 >> Back" << endl;
		cout << "Enter your choice: ";
		cin >> Choice3;
		if (check(cin)) goto a;
		switch (Choice3) {
		case 1:
			prototype.type = notifications[12];
			addDenunction(file, prototype);
			break;
		case 2:
			prototype.type = notifications[13];
			addDenunction(file, prototype);
			break;
		case 3:
			prototype.type = notifications[14];
			addDenunction(file, prototype);
			break;
		case 4:
			prototype.type = notifications[15];
			addDenunction(file, prototype);
			break;
		case 9:
			goto main;
			break;
		default:
			cout << "Invalid Choice\n";
			cout << "Try again...........\n\n";
			goto a;
		}
		break;
	case 3:
		//Fire Department
		prototype.type = notifications[5];
	f:
		int Choice;
		cout << "1 >> Emergency Fire Notification " << endl;
		cout << "2 >> Forest Fire Notification" << endl;
		cout << "9 >> Back" << endl;
		cout << "Enter your choice: ";
		cin >> Choice;
		if (check(cin)) goto f;
		switch (Choice) {
		case 1:
			prototype.type = notifications[6];
			addDenunction(file, prototype);
			break;
		case 2:
			prototype.type = notifications[7];
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
		//Veterinary Department
		prototype.type = notifications[8];
	v:
		int Choice2;
		cout << "1 >> Pet Help " << endl;
		cout << "2 >> Street Animals Help" << endl;
		cout << "9 >> Back" << endl;
		cout << "Enter your choice: ";
		cin >> Choice2;
		if (check(cin)) goto v;
		switch (Choice2) {
		case 1:
			prototype.type = notifications[9];
			addDenunction(file, prototype);
			break;
		case 2:
			prototype.type = notifications[10];
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
	case 5: {
		//Update denunction
		int id;
		string testName;
	upd:
		cout << "Enter ID : ";
		cin >> id;
		if (check(cin)) goto upd;
		cout << "Enter name : ";
		cin >> testName;
		update(id, testName);
		break;
	}
	case 6: {
		//Delete denunction
		int id;
		string testName;
	deleteOpr:
		cout << "Enter ID : ";
		cin >> id;
		if (check(cin)) goto deleteOpr;
		cout << "Enter name : ";
		cin >> testName;
		deleteFunction(id, testName);
		break;
	}
	case 9:
		//Back
		return 0;
	default:
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto main;
	}
}

/*
------------------------------------------------------------------
This function allows to generate personalized id numbers.
param:()
------------------------------------------------------------------
*/
int idCreator() {
	fstream file("ids.csv", ios::in);
	string line;
	int tempID;
	while (getline(file, line)) {
		stringstream geek(line);
		geek >> tempID;

		idStr.push_back(tempID);
	}
	//The last number in the idStr vector is assigned to value.
	int value = idStr.back();
	//The last number assigned to value is removed from the vector.
	idStr.pop_back();
	//Numbers in id.svc is deleted.
	file.clear();
	file.close();
	file.open("ids.csv", ios::out);
	//Remaining values in vector are added to id file
	for (int i = 0; i < idStr.size(); i++) {

		file << idStr.at(i) << endl;
	}
	file.close();
	return value;
}

/*
------------------------------------------------------------------
This method allows the information to be kept update inside an temporary information struct object
and add those object’s datas into a general vector to use later by another functions itself
param:()
------------------------------------------------------------------
*/
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
	//Each information types are sepeared by semicolon “;” because data.csv file is an excel file.
	const char delim = ';';
	//In each line, program creates an temporary denunction object as a name of tempDenunction
	string T;
	getline(file, line);
	while (getline(file, line))
	{
		//Each line keeps itself inside istringstream feature as ssand this feature keeps those lines
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

/*
------------------------------------------------------------------
The function allows you to print data inside the file to console
param:()
------------------------------------------------------------------
*/
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

/*
------------------------------------------------------------------
This function enables deletion of wrong notices.
This process is performed by controlling the ID number and name.
param:(input)
------------------------------------------------------------------
*/
void deleteFunction(int id, string name) {
	readData();
	ofstream data;
	int count = 0;
	data.open("data.csv", ios::out);
	data << "ID" << ";" << "Type" << ";" << "Address" << ";" << "Detail" << ";" << "Name" << endl;
	for (unsigned int i = 0; i < general.size(); i++) {
		if (id == general[i].id && name == general[i].name) {
			fstream ids("ids.csv", ios::out | ios::app);
			ids << id << endl;
			ids.close();
			cout << "Denunction was deleted.";
			continue;
		}
		else {
			data << general[i].id << ";" << general[i].type << ";" << general[i].address << ";" << general[i].detail << ";" << general[i].name << endl;
			count++;
			if (count == general.size()) {
				cout << "There is no such denunction" << endl;
			}
		}
	}
	data.close();
}

/*
------------------------------------------------------------------
This function allows the user to change their information by checking their personal IDs.
After the ID and name are verified, the person is directed to the menu
param:(input,input)
------------------------------------------------------------------
*/
void update(int id, string name) {
	readData();
	fstream data;
	int count = 0;
	data.open("data.csv", ios::out);
	data << "ID" << ";" << "Type" << ";" << "Address" << ";" << "Detail" << ";" << "Name" << endl;
	for (unsigned int i = 0; i < general.size(); i++) {

		/*
			It is checked whether the entered id is in data.csv or not and
			the name is also checked as the second control mechanism.
		*/
		if (id == general[i].id && name == general[i].name) {
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
			if (check(cin)) goto main;

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

				if (check(cin)) goto e;
				switch (Choice1) {
					//Emergency Department
				case 1:
					prototype.type = notifications[1];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 2:
					prototype.type = notifications[2];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 3:
					prototype.type = notifications[3];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 4:
					prototype.type = notifications[4];
					prototype.id = id;
					prototype.name = name;
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
				//Police Department
				prototype.type = notifications[11];
			h:
				int Choice3;
				cout << "1 >> Traffic Rule Violations " << endl;
				cout << "2 >> Missing Person Reports" << endl;
				cout << "3 >> Public Securities" << endl;
				cout << "4 >> Anti-narcotics Crimes" << endl;
				cout << "9 >> Back" << endl;
				cout << "Enter your choice: ";
				cin >> Choice3;
				if (check(cin)) goto h;

				switch (Choice3) {
				case 1:
					prototype.type = notifications[12];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 2:
					prototype.type = notifications[13];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 3:
					prototype.type = notifications[14];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 4:
					prototype.type = notifications[15];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 9:
					goto main;
					break;
				default:
					cout << "Invalid Choice\n";
					cout << "Try again...........\n\n";
					goto h;
				}
				break;


				break;
			case 3:
				//Fire Department
				prototype.type = notifications[5];
			f:
				int Choice;
				cout << "1 >> Emergency Fire Notification " << endl;
				cout << "2 >> Forest Fire Notification" << endl;
				cout << "9 >> Back" << endl;
				cout << "Enter your choice: ";
				cin >> Choice;
				if (check(cin)) goto f;

				switch (Choice) {
				case 1:
					prototype.type = notifications[6];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 2:
					prototype.type = notifications[7];
					prototype.id = id;
					prototype.name = name;
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
				//Veterinary Department
				prototype.type = notifications[9];
			v:
				int Choice2;
				cout << "1 >> Pet Help " << endl;
				cout << "2 >> Street Animals Help" << endl;
				cout << "9 >> Back" << endl;
				cout << "Enter your choice: ";
				cin >> Choice2;
				if (check(cin)) goto v;
				switch (Choice2) {
				case 1:
					prototype.type = notifications[9];
					prototype.id = id;
					prototype.name = name;
					updateDenunction(data, prototype);
					break;
				case 2:
					prototype.type = notifications[10];
					prototype.id = id;
					prototype.name = name;
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
				data << general[i].id << ";" << general[i].type << ";" << general[i].address << ";" << general[i].detail << ";" << general[i].name << endl;
				break;
			default:
				cout << "Invalid Choice\n";
				cout << "Try again...........\n\n";
				goto main;
			}
		}
		else {
			data << general[i].id << ";" << general[i].type << ";" << general[i].address << ";" << general[i].detail << ";" << general[i].name << endl;
			count++;
			if (count == general.size()) {
				cout << "There is no such denunction" << endl;
			}
		}
	}
}