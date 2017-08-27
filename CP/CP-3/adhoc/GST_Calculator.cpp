#include <algorithm>
#include <iostream>
#include <iomanip>

int main() {
    
    int tc;
    
    std::cin >> tc;
    std::setw(0);
    std::setprecision(2);
    
    for (int c = 1; c <= tc; ++c) {
        int n;
        std::cin >> n;
        std::string name, rate;
        int quantity;
        double price;
        double totalBill = 0.0, totalGstTax = 0.0;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> quantity >> price >> rate;
            double temp = quantity * price;
            totalBill += temp;
            if (rate == "SR") {
                double tax = (temp * 6.0)/100.0;
                totalBill += tax;
                totalGstTax += tax;
            }  
        }
        std::cout << "Case #" << c << ":" << std::endl;
        std::cout << "Total Amount Include GST: " << totalBill << std::endl;
        std::cout << "Total Amount GST Paid: "  << totalGstTax << std::endl;
    }
    return 0;
}

