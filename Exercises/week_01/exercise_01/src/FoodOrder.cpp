#include <iostream>
#include <iomanip>
#include "FoodOrder.h"
extern double g_taxrate;
extern double g_dailydiscount;
namespace seneca {
    // Default constructor - initializes all members to empty state
    FoodOrder::FoodOrder() {
        m_customerName[0] = '\0';
        m_orderDescription[0] = '\0';
        m_price = 0.0;
        m_dailySpecial = false;
    }

    // Reads the order information from the input stream
    void FoodOrder::read(std::istream& is) {
        // Clear any existing data
        m_customerName[0] = '\0';
        m_orderDescription[0] = '\0';
        
        // Read customer name until comma
        is.getline(m_customerName, 10, ',');
        
        // Read order description until comma
        is.getline(m_orderDescription, 25, ',');
        
        // Read price
        is >> m_price;
        is.ignore(); // skip comma
        
        // Read daily special status
        char special;
        is >> special;
        m_dailySpecial = (special == 'Y');
        
        is.ignore(1000, '\n'); // clear the remainder of the line
    }

    // Displays the order information
    void FoodOrder::display() const {
        static int counter = 1;  // Add back the counter for numbering
        
        if (m_customerName[0] != '\0') {
            std::cout << std::setw(2) << counter << ". " 
                     << std::left << std::setw(10) << m_customerName << "|"
                     << std::left << std::setw(25) << m_orderDescription << "|"
                     << std::right << std::fixed << std::setprecision(2) 
                     << std::setw(10) << m_price * (1 + g_taxrate) << "|";
            
            if (m_dailySpecial) {
                std::cout << std::right << std::setw(12) 
                         << (m_price * (1 + g_taxrate) - g_dailydiscount);
            }
            std::cout << std::endl;
            counter++;
        } else {
            std::cout << counter << ". No Order" << std::endl;
            counter++;
        }
    }
}