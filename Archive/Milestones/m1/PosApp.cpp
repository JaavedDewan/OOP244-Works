/*
*****************************************************************************
<assessment name example: Project - Milestone 1>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 03/10/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include <limits>
#include "PosApp.h"

namespace sdds {
    PosApp::PosApp(const char* filename) {
        m_filename[0] = '\0';
        if (filename != nullptr && filename[0] != '\0') {
            strncpy(m_filename, filename, MAX_FILE_LENGTH - 1);
            m_filename[MAX_FILE_LENGTH - 1] = '\0';
        }
        memset(m_items, 0, sizeof(Item*) * MAX_NO_ITEMS);
    }

    int PosApp::menu() {
        int selection = -1;
        std::cout << "The Sene-Store" << std::endl;
        std::cout << "1- List items" << std::endl;
        std::cout << "2- Add item" << std::endl;
        std::cout << "3- Remove item" << std::endl;
        std::cout << "4- Stock item" << std::endl;
        std::cout << "5- Point of Sale" << std::endl;
        std::cout << "0- exit program" << std::endl;
        std::cout << "> ";
        std::cin >> selection;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            selection = -1;
        }
        if (selection < -1 || selection > 5) {
            selection = -1;
        }
        return selection;
    }

    void PosApp::loadRecs() {
        std::cout << "Loading data from " << m_filename << std::endl;
        std::ifstream file(m_filename);
        if (!file) {
            std::cerr << "Could not open file: " << m_filename << std::endl;
            return;
        }
        char record[2000];
        int count = 0;
        while (file.getline(record, 2000)) {
            count++;
            if (count > MAX_NO_ITEMS) {
                std::cerr << "Too many items, only loading first " << MAX_NO_ITEMS << std::endl;
                break;
            }
            char type = record[0];
            if (type == 'P') {
                m_items[count - 1] = new Perishable(record);
            }
            else if (type == 'N') {
                m_items[count - 1] = new NonPerishable(record);
            }
            else {
                std::cerr << "Unrecognized record type: " << type << std::endl;
            }
        }
        m_noOfItems = count;
        file.close();
    }

    void PosApp::saveRecs() {
        std::cout << "Saving data in " << m_filename << std::endl;
        std::ofstream file(m_filename);
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i]->save(file);
        }
        file.close();
    }

    int PosApp::searchItems(const char* sku)const {
        int index = -1;
        for (int i = 0; i < m_noOfItems; i++) {
            if (*m_items[i] == sku) {
                index = i;
                break;
            }
        }
        return index;
    }

    void PosApp::updateQty() {
        std::cin.ignore();
        std::cout << "
