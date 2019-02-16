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
	string action, object; 
	cout << "login: ";
	cin >> userInput; 

	vector<string> myVector;
	multimap<string, string> userRoleMap;
	multimap<string, string, string> permissionRoleMap;
	fstream infile;
	string info;

	for (int i = 0; i < 2; i++) {
		string filename; 
		if (i == 0) {
			filename = "URA.txt";
		}
		else if (i == 1) {
			filename = "PRA.txt"; 
		}
		
		infile.open(filename);
		while (infile >> info) {
			int nElem = 0;
			auto it = myVector.insert(myVector.end(), info);
			nElem++;
		}
		infile.close();
	}

	for (int i = 0; i < myVector.size(); i += 2) {
		string key = myVector.at(i);
		string data = myVector.at(i + 1);
		userRoleMap.insert(pair<string, string>(key, data));
	}

	for (int i = 0; i < myVector.size(); i += 2) {
		string key = myVector.at(i);
		string data1 = myVector.at(i + 1);
		string data2 = myVector.at(i + 2); 
		//string concat = data1 + " " + data2; 
		permissionRoleMap.insert(pair<string, string>(key, concat));
	}
	
	if (userRoleMap.count(userInput) > 0) {
		cout << "Welcome " << userInput << "!" << endl; 
		cout << "cmd>";
		cin >> action >> object; 
		
	}
	else {
		cout << "ERROR: user " << userInput << " is not in the database!" << endl; 
	}
	 








	system("pause");
	return 0;
}
