#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

int main()
{
	string userInput, action, object, concatenate;
	cout << "login: ";
	cin >> userInput;

	multimap<string, string> userRoleMap;
	multimap<string, string> permissionRoleMap;

	fstream infile;
	string info;
	infile.open("URA.txt");
	vector<string> myVector;
	vector<string> vec; 
	while (infile >> info) {
		auto it = myVector.insert(myVector.end(), info);
	}
	infile.close();

	for (int i = 0; i < myVector.size(); i += 2) {
		string data1 = myVector.at(i);
		string data2 = myVector.at(i + 1);
		userRoleMap.insert(pair<string, string>(data1, data2));
	}
	myVector.clear();

	if (userRoleMap.count(userInput) > 0) {
		cout << "Welcome " << userInput << "!" << endl;
		cout << "cmd>";
		cin >> action >> object;
	}
	else {
		cout << "ERROR: user " << userInput << " is not in the database!" << endl;
	}

	infile.open("PRA.txt");
	while (infile >> info) {
		auto it = myVector.insert(myVector.end(), info);
	}
	infile.close();

	for (int i = 0; i < myVector.size(); i += 2) {
		string data1 = myVector.at(i);
		i = i + 1; 
		string data2 = myVector.at(i) + " " + myVector.at(i + 1);
		permissionRoleMap.insert(pair<string, string>(data1, data2));
	}
	myVector.clear(); 
	concatenate = action + " " + object;

	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> iterPair = userRoleMap.equal_range(userInput);

	for (multimap<string, string>::iterator listIt = iterPair.first;
		listIt != iterPair.second; ++listIt){
		myVector.insert(myVector.begin(),listIt->second);
	}
	
	for (int i = 0; i < myVector.size(); i++) {
		pair<multimap<string, string>::iterator, multimap<string, string>::iterator> iterPair = permissionRoleMap.equal_range(myVector.at(i));
		for (multimap<string, string>::iterator listIt = iterPair.first;
			listIt != iterPair.second; ++listIt) {
			if (listIt->second == concatenate) {
				vec.insert(vec.begin(), listIt->first);
			}
		}
	}

	if (!vec.empty()) {

		cout << "Access granted by virtue of roles: ";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec.at(i) << " "; 
		}
		cout << endl; 
	}
	else {
		cout << "Access denied: you are not authorized to perform this action!" << endl;
	}
	

	system("pause");
	return 0;
}
