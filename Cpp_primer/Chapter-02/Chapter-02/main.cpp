#include <string>
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

void ex1_20() {
    Sales_data item;
    double price = 0;
    while (std::cin >> item.bookNo >> item.units_sold >> price) {
        item.revenue = item.units_sold * price;
        std::cout << item.bookNo << " " << item.units_sold << " " << item.revenue << std::endl;
    }
}

int ex1_21() {
    Sales_data d1, d2;
    double price = 0;
    if (std::cin >> d1.bookNo >> d1.units_sold >> price) {
        d1.revenue = d1.units_sold * price;
        if (std::cin >> d2.bookNo >> d2.units_sold >> price) {
            d2.revenue = d2.units_sold * price;
            if (d1.bookNo == d2.bookNo) {
                unsigned totalSold = d1.units_sold + d2.units_sold;
                double totalRevenue = d1.revenue + d2.revenue;
                std::cout << d1.bookNo << " " << totalSold << " " << totalRevenue << " ";
                if (totalSold != 0) {
                    std::cout << totalRevenue / totalSold << std::endl;
                } else {
                    std::cout << "(no sales)" << std::endl;
                }
            } else {
                std::cerr << "Data must reer eto same ISBN" << std::endl;
                return -1;
            }
        } else {
            std::cerr << "No data for item two!" << std::endl;
            return -1;
        }
    } else {
        std::cerr << "No data for item one!" << std::endl;
        return -1;
    }
    return 0;
}

int main() {
    ex1_21();
    return 0;
}
