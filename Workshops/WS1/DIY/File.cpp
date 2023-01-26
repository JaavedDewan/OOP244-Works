//#define _CRT_SECURE_NO_WARNINGS
//#include  <iostream>
//#include "File.h"
//#include "GPA.h"
//#include "GPAlist.h"
//
//
//
//bool sdds::loadGPA(const char* filename) {
//	GPA records;
//	int numbers = 0;
//
//	FILE* fp = nullptr;
//	fp = fopen(filename, "r");
//	if (fp != NULL)
//	{
//		rewind(fp);
//		while (fscanf(fp, "%[^,],%d,%lf", records.name, &records.stno, &records.gpa) != EOF)
//
//		{
//			averages[numbers] = records;
//			++numbers;
//		}
//
//		fclose(fp);
//
//	}
//	return fp != nullptr;
//}