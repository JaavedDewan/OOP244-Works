/*
*****************************************************************************
<assessment name example: Workshop - #2 (Part-2)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 02/01/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    
    // complete
   
        // EmptyRecord for Customer
    void EmptyRecord(Customers& rec) {
        rec.user_name[0] = '\0';
        rec.likes_count = 0;
        rec.retweets_count = 0;
        rec.replies_count = 0;
        rec.share_videos = '\0';
    }

    // EmptyRecord for CustomersRecord
    void EmptyRecord(CustomersRecord& t_rec) {
        t_rec.ptr_rec = nullptr;
        t_rec.noOfRecords = 0;
    }

    // read function for Customers
    bool read(Customers& rec) {
        std::cout << " Enter User name: ";
        read(rec.user_name, 21);
        if (rec.user_name[0] == '\0') {
            return false;
        }
        std::cout << " Enter likes_count: ";
        std::cin >> rec.likes_count;
        std::cout << " Enter retweets_count: ";
        std::cin >> rec.retweets_count;
        std::cout << " Enter replies_count: ";
        std::cin >> rec.replies_count;
        std::cout << " Enter share videos (y/n): ";
        std::cin >> rec.share_videos;
        return true;
    }

    // addCustomer function
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        Customers* temp = new Customers[t_rec.noOfRecords + 1];
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            temp[i] = t_rec.ptr_rec[i];
        }
        temp[t_rec.noOfRecords] = c_rec;
        delete[] t_rec.ptr_rec;
        t_rec.ptr_rec = temp;
        t_rec.noOfRecords++;
    }

    // display function for Customers
    void display(const Customers& c_rec) {
        std::cout << c_rec.user_name << ", "
            << c_rec.likes_count << ", "
            << c_rec.retweets_count << ", "
            << c_rec.replies_count << ", "
            << c_rec.share_videos << '\n' << endl;
    }

    // display function for CustomersRecord
    void display(const CustomersRecord& t_rec) {
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            std::cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
        }
    }
  }

