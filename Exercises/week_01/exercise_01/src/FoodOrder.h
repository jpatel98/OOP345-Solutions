#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

namespace seneca {
    class FoodOrder {
        char m_customerName[10]{};
        char m_orderDescription[25]{};
        double m_price{};
        bool m_dailySpecial{};
    public:
        FoodOrder();
        void read(std::istream& is);
        void display() const;
    };
}

#endif // SENECA_FOODORDER_H