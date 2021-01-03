#include <iostream>

using namespace std;

//Fire department menu
void fireMenu() {
	int fireChoose;
	cout << "1 >> Emergency fire notice " << endl;
	cout << "2 >> Forest fire notice" << endl;
f:
	cout << "Enter your choice: ";
	cin >> fireChoose;

	if (fireChoose > 2 || fireChoose < 1) {
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto f;
	}

}

int main()
{

	int choose;
	//Main menu
	cout << "Welcome to Emergency Call Lines" << endl;
	cout << "1 >> Emergency" << endl;
	cout << "2 >> Police" << endl;
	cout << "3 >> Fire Department" << endl;
	cout << "4 >> Veterinary service" << endl;
	cout << "5 >> Police" << endl;

	
a:
	cout << "Enter your choice: ";
	cin >> choose;
	if (choose > 5 || choose < 1) { 
		cout << "Invalid Choice\n";
		cout << "Try again...........\n\n";
		goto a; 
	} 
	if (choose == 3) {
		fireMenu();
	}


}
