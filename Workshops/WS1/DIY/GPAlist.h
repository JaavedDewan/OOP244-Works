#ifndef SDDS_GPSLIST_H
#define SDDS_GPALIST_H



namespace sdds {


	void displayGPA(char op, double gpa);
	void sortStudentID();
	bool gpaQuery(const char* filename);
	bool loadGPA(const char* filename);
	
}
#endif // !SDDS_GPALIST_H