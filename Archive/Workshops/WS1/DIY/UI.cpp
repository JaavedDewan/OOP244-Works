/*
*****************************************************************************
<assessment name example: Workshop - #1 (Part-2)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

//#include <iostream>
//#include <algorithm>
//#include "UI.h"
//#include "GPAlist.h"
//#include "GPA.h"
//using namespace std;
//
//GPA averages[87];
//
//void sdds::sortStudentID() {
//
//	bool sorting = true;
//	int i = 0, j = 0;
//
//	while (sorting) {
//
//		sorting = false;
//
//		for (j = 0; j < (86 - 1 - i); j++) {
//
//			if (averages[j].stno > averages[j + 1].stno) {
//
//				GPA sorted = averages[j];
//				averages[j] = averages[j + 1];
//				averages[j + 1] = sorted;
//				sorting = true;
//			}
//		}
//
//		i++;
//	}
//}
//
//void sdds::displayGPA(char op, double gpa) {
//
//	int count = 0;
//
//	for (int i = 0; i < 86; i++) {
//
//		std::string Names = averages[i].name;
//
//		Names.erase(remove_if(Names.begin(), Names.end(),
//			[](char remove)
//			{
//				return (remove == '\n');
//			}),
//			Names.end());
//
//		if (op == '>') {
//			if (averages[i].gpa > gpa) {
//
//				count++;
//
//				cout << "[" << count << "] " << averages[i].stno << ": ";
//				cout << averages[i].gpa;
//				cout << " (" << Names << ") " << endl;
//
//			}
//		}
//		else if (op == '<') {
//
//			if (averages[i].gpa < gpa) {
//
//				count++;
//
//				cout << "[" << count << "] " << averages[i].stno << ": ";
//				cout << averages[i].gpa;
//				cout << " (" << Names << ") " << endl;
//
//			}
//		}
//		else if (op == '~') {
//
//			if (((gpa + 0.05) > averages[i].gpa) && ((gpa - 0.05) < averages[i].gpa)) {
//
//				count++;
//
//				cout << "[" << count << "] " << averages[i].stno << ": ";
//				cout << averages[i].gpa;
//				cout << " (" << Names << ") " << endl;
//			}
//		}
//	}
//}
