//
//  Exercise-7.cpp
//  Chapter-07
//
//  Created by huangwei on 2019/5/12.
//  Copyright © 2019 huangwei. All rights reserved.
//


#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main1() {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    } else {
        cerr << "No Data?!" << std::endl;
        return -1;
    }
    return 0;
}
