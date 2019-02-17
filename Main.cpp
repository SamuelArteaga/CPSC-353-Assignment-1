#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

int main()
{
	// get user input and declaration of variables
	string userInput, action, object, concatenate; 
	cout << "login: ";
	cin >> userInput;

	// declaration of multimaps for user roles and permissions
	multimap<string, string> userRoleMap;	
	multimap<string, string> permissionRoleMap;

	// read from URA file and input into vector
	fstream infile;				
	string info;
	infile.open("URA.txt");
	vector<string> myVector;
	vector<string> vec; 
	while (infile >> info) {
		auto it = myVector.insert(myVector.end(), info);
	}
	infile.close();

	// insert vector elements from URA file into map in their associated order
	for (int i = 0; i < myVector.size(); i += 2) {
		string data1 = myVector.at(i);
		string data2 = myVector.at(i + 1);
		userRoleMap.insert(pair<string, string>(data1, data2));
	}
	myVector.clear(); 

	// count the amount of times username is in user role map, if less than zero, user is not in the URA file
	if (userRoleMap.count(userInput) > 0) {
		cout << "Welcome " << userInput << "!" << endl;
		cout << "cmd>";
		cin >> action >> object;
	}
	else {
		cout << "ERROR: user " << userInput << " is not in the database!" << endl;
	}

	// read from PRA file and insert into vector
	infile.open("PRA.txt");
	while (infile >> info) {
		auto it = myVector.insert(myVector.end(), info);
	}
	infile.close();

	// insert vector elements from PRA file into map
	for (int i = 0; i < myVector.size(); i += 2) {
		string data1 = myVector.at(i);
		i = i + 1; 
		string data2 = myVector.at(i) + " " + myVector.at(i + 1); // concatenate action & object and input into map as command associated with the role
		permissionRoleMap.insert(pair<string, string>(data1, data2));
	}
	myVector.clear(); 

	// iterate through the map to find the roles associated with username and insert roles into a vector
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> iterPair = userRoleMap.equal_range(userInput);
	for (multimap<string, string>::iterator listIt = iterPair.first;
		listIt != iterPair.second; ++listIt){
		myVector.insert(myVector.begin(),listIt->second);
	}

	// concatenate user input, loop through the elements of the vector and create a pair of iterators to view the commands corresponding to their roles. Compare commands to the concatenated variable; if they are equal to each other
	// insert their key into a vector (in this case key = role) 
	concatenate = action + " " + object;
	for (int i = 0; i < myVector.size(); i++) {
		pair<multimap<string, string>::iterator, multimap<string, string>::iterator> iterPair = permissionRoleMap.equal_range(myVector.at(i));
		for (multimap<string, string>::iterator listIt = iterPair.first;
			listIt != iterPair.second; ++listIt) {
			if (listIt->second == concatenate) {
				vec.insert(vec.begin(), listIt->first);
			}
		}
	}
	// if the new vector isn't empty, output the elements of the vector to view which roles granted access, else deny access
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
