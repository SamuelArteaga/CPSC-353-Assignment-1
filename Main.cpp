#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

int main()
{
	// gets user input 
	string userInput;
	string command; 
	cout << "login: ";
	cin >> userInput;

	// create the maps for the URA and PRA file input
	multimap<string, string> userRoleMap; 
	multimap<string, string, string> permissionRoleMap; 

	fstream infile;
	string info; 
	infile.open("URA.txt");
	vector<string> myVector;

	while (infile >> info){
		int nElem = 0; 
		auto it = myVector.insert(myVector.end(), info);  
		nElem++; 
	}
	infile.close(); 
	
	for (int i = 0; i < myVector.size(); i += 2) {
		string data1 = myVector.at(i);
		string data2 = myVector.at(i + 1);
		userRoleMap.insert(pair<string, string>(data1, data2));
	}

	if (userRoleMap.count(userInput) > 0) {
		cout << "Welcome " << userInput << "!" << endl; 
		cout << "cmd>";
		cin >> command;
	}
	else {
		cout << "ERROR: user " << userInput << " is not in the database!" << endl; 
	}



	system("pause");
	return 0;
}
