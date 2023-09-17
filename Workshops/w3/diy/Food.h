/*
*****************************************************************************
Workshop - #3 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/04/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_foodName[31]; //name
        int m_calories; //calories between 0 to 3000
        int m_mealCode; //meal code between 1 to 4
        void setName(const char* name); //set name
    public:
        Food();
        Food(const char* foodName, int mealCode);
        void setEmpty(); //empty
        void set(const char* name, int calories, int when); //set variables name calories and meal code
        void display()const; //display
        bool isValid()const; //check if the item is valid based on name.
        int calorie() const; //returns calorie
        int mealCode() const; //returns meal code
    };
}

#endif // !SDDS_FOOD_H