//This file includes the implementation for the function gpaQuery, sortStudentID, loadGPA, and displayGPA
//that are used to query and display student GPAs from a file

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "GPAlist.h"
#include "GPA.h"
//#include "UI.h"
//#include "File.h"
using namespace std;

//Global array of structure GPA
GPA averages[87];


bool sdds::gpaQuery(const char* filename) 
{
	//Load the GPAs from the given file
	bool readable = loadGPA(filename);
	bool loading = true;
	double  gpa;
	char op;
	char exit;
	if (readable == false) {
	
		return false;
	}
	//Sort the student GPAs by student ID
	sortStudentID();

	//Prompts the user to enter a GPA query

	cout << "Enter GPA query..." << endl;

	//Keeps looping until the user decides to exit

	while (loading) {
		
		cout << "? ";
		
		cin >> op;

		//If the user enters '!' then the program will ask if the user wants to exit

		if (op == '!') {

			cout << "Exit the Program? (Y)es/(N)o: ";
			cin >> exit;

			//If the user enters 'y' then the program will exit

			if (exit == 'y') {
				break;
			}

			//If the user enters 'n' then the program will continue

			else if (exit == 'n') {

				cout << "Query resumed.";
			}

			//If the user enters anything else then the program will give an error message

			else {

				cout << "Error: Please enter y or n.";
			}
		}

		cin >> gpa;

		//If the user enters a valid operation then the program will call the displayGPA function

		if (op == '>' || op == '<' || op == '~') {
			
			displayGPA(op, gpa);

		}
		//If the user enters an invalid operation then the program will give an error message

		else {

			cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
			cout << "Op: [>, <, ~, !]" << endl;
			cout << "value : GPA value" << endl << endl;
		}
	}
	return true;
}


void sdds::sortStudentID() {

	// Initialize a variable to keep track of whether the list is still sorting

	bool sorting = true;
	int i = 0, j = 0;

	// Use a while loop to continue sorting the list until it is fully sorted

	while (sorting) {

		sorting = false;

		// Use nested for loop to compare each element in the list

		for (j = 0; j < (86 - 1 - i); j++) {

			// Compare the student ID of the current element with the next element

			if (averages[j].stno > averages[j + 1].stno) {

				// If the current element has a larger student ID, swap the elements

				GPA sorted = averages[j];
				averages[j] = averages[j + 1];
				averages[j + 1] = sorted;
				sorting = true;
			}
		}

		i++;
	}
}

bool sdds::loadGPA(const char* filename) {
	GPA records;  // variable to store the records from the file
	int numbers = 0;

	FILE* fp = nullptr;
	fp = fopen(filename, "r"); // open the file in read mode
	if (fp != NULL) // if the file is not null
	{ 
		rewind(fp);  // rewind the file pointer to the beginning of the file
		while (fscanf(fp, "%[^,],%d,%lf", records.name, &records.stno, &records.gpa) != EOF)

		{
			averages[numbers] = records; // store the records in the averages array
			++numbers; // increase the number of records loaded
		}

		fclose(fp); // close the file

	}
	return fp != nullptr; // return true if file is not null, false otherwise
}

void sdds::displayGPA(char op, double gpa) {

	int count = 0; // variable to keep track of number of students with matching GPA

	for (int i = 0; i < 86; i++) {

		std::string Names = averages[i].name;

		// Removing newline character from name string

		Names.erase(remove_if(Names.begin(), Names.end(),
			[](char remove)
			{
				return (remove == '\n');
			}),
			Names.end());

		// If operator is greater than

		if (op == '>') {

			// check if student's gpa is greater than the given gp

			if (averages[i].gpa > gpa) {

				count++; // increment count

				cout << "[" << count << "] " << averages[i].stno << ": ";
				cout << averages[i].gpa;
				cout << " (" << Names << ") " << endl;

			}
		}

		// If operator is less than

		else if (op == '<') {

			// check if student's gpa is less than the given gpa

			if (averages[i].gpa < gpa) {

				count++; // increment count

				cout << "[" << count << "] " << averages[i].stno << ": ";
				cout << averages[i].gpa;
				cout << " (" << Names << ") " << endl;

			}
		}

		// check if the student's gpa is within a certain range of +-0.05

		else if (op == '~') {

			if (((gpa + 0.05) > averages[i].gpa) && ((gpa - 0.05) < averages[i].gpa)) {

				count++; // increment count

				cout << "[" << count << "] " << averages[i].stno << ": ";
				cout << averages[i].gpa;
				cout << " (" << Names << ") " << endl;
			}
		}
	}
}