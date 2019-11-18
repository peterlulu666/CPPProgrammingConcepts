#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // The first line gives the price of an individual Sprocket.
    // The second line gives the sales tax percentage to be applied.
    // The next three lines list three shipping rates.
    // The first value is the minimum price and the second value is the corresponding shipping fee.
    // The last line gives the minimum amount to qualify for free shipping.
    double price_per_individual_unit;
    double sales_tax_percentage_rate;
    double shipping_min_1;
    double flat_shipping_rate1;
    double shipping_min_2;
    double flat_shipping_rate2;
    double shipping_min_3;
    double flat_shipping_rate3;
    double free_shipping_min;
    //Your first task is to read in these values from the external file and
    // store all the values in variables with an appropriate data type.
    ifstream product;
    product.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/product_public.txt");
    product >> price_per_individual_unit
            >> sales_tax_percentage_rate
            >> shipping_min_1
            >> flat_shipping_rate1
            >> shipping_min_2
            >> flat_shipping_rate2
            >> shipping_min_3
            >> flat_shipping_rate3
            >> free_shipping_min;
    product.close();
    // Once you have read in the product information from the external file,
    // now create the shopping cart system and prompt
    // the user via the standard output & input to
    // enter how many sprockets this wish to order.
    // The price for a single sprocket must be printed to
    // the standard output with two decimal places.
    // The user must be able to enter from
    // the standard input the number of sprockets they wish to order.
    // The number of sprockets ordered must be printed back to the standard output.
    cout << "Welcome to Sprockets-R-Us! \n"
         << "We sell round sprockets, square sprockets, and triangle sprockets. \n"
         << "The cost of a single sprocket is " << price_per_individual_unit << "."
         << "How many sprockets do you wish to order? \n";
    int order = 0;
    cin >> order;
    cout << "Thank you for your order of " << order << " sprockets!  One moment while we prepare your receipt... \n";
    // Once you know how many products are being ordered,
    // you can now calculate the final total.
    // The final total is computed with the following steps in order.
    // First, determine the product total by multiplying the price per unit by quantity ordered.
    double productTotal = order * price_per_individual_unit;
    // Next, determine the shipping fee based on #1.
    double shippingFee = 0;
    if (productTotal <= shipping_min_2) {
        shippingFee = flat_shipping_rate1;

    } else if (productTotal <= shipping_min_3) {
        shippingFee = flat_shipping_rate2;

    } else if (productTotal <= free_shipping_min) {
        shippingFee = flat_shipping_rate3;

    } else {
        shippingFee = 0;
        cout << "Thank you for your large purchase. \n";

    }
    // Next, compute the subtotal of product total (#1) plus shipping fee (#2).
    double subtotalShippingProduct = shippingFee + productTotal;
    // Now determine the sales tax amount by multiplying
    // the subtotal from #3 by the sales tax percentage.
    // When computing the amount, if a fraction of a penny
    // remains then use the half round up rule (round up if >= 5, otherwise round down).
    double salesTax = subtotalShippingProduct * sales_tax_percentage_rate / 100;
    // Compute the subtotal of product total (#1) plus shipping fee (#2) plus sales tax (#4).
    double subtotalShippingProductTax = subtotalShippingProduct + salesTax;
    // If the subtotal from #5 is not an even dollar amount ($X.00),
    // then ask the user if they would like to make a donation and
    // round their total up to the nearest dollar.
    // If they say yes, then compute the donation
    // amount necessary to round the subtotal up to
    // the nearest dollar amount.
    double cents = subtotalShippingProductTax - (int) subtotalShippingProductTax;
    double donationAmount = 0;
    char choose = 0;
    if (cents != 0) {
        cout << "Would you like to make a donation? (y/n) \n";
        // Character to upper case
        cin >> choose;
        choose = (char) toupper(choose);
        if (choose == 'Y') {
            donationAmount = 1 - cents;

        }

    }
    // Finally, compute the grand total by adding
    // the subtotal from #5 with the donation amount from #6.
    // Display this final amount to the user.
    float grandTotal = subtotalShippingProductTax + donationAmount;
    cout << "Thank you for your order. Your total is " << grandTotal << ".";
    // Each step of the calculation will be printed
    // to an external file named receipt.txt.
    // The receipt MUST match the following formatting with example amounts
    // based off of the public_product.txt file.
    //-----------------------------
    //Sprockets-R-Us Order Receipt
    //-----------------------------
    //Price Per Unit:    $     1.99
    //Quantity Ordered:           5
    //Unit Subtotal:     $     9.95
    //-----------------------------
    //Shipping Fee:      $    25.99
    //-----------------------------
    //Sales Tax ( 6.75%):$     2.43
    //-----------------------------
    //Donation?                   Y
    //Donation Amount:   $     0.63
    //=============================
    //Grand Total:       $    39.00
    //=============================
    // When formatting the receipt, make sure the following rules are followed:
    // All dollar amounts are displayed to two decimals.
    // All dollar amounts are right aligned with the decimal point aligned.
    // You can assume all amounts will be less than $100,000.
    // Sales Tax Rate is listed as a percentage.
    // You can assume the rate will be less than 100% and greater than 0%.
    // If the user wants to make a donation, then display the donation amount. Otherwise, do not.
    // A second example is shown below.
    // For extra credit, improve the formatting of the receipt by having the dollar sign next to the amount.
    std::string price_per_individual_unitStr;
    std::string productTotalStr;
    std::string shippingFeeStr;
    std::string salesTaxStr;
    std::string donationAmountStr;
    std::string grandTotalStr;

    std::stringstream price_per_individual_unit_stream;
    price_per_individual_unit_stream.setf(std::ios::fixed);
    price_per_individual_unit_stream.precision(2);
    price_per_individual_unit_stream << price_per_individual_unit;
    price_per_individual_unitStr = price_per_individual_unit_stream.str();

    std::stringstream productTotal_stream;
    productTotal_stream.setf(std::ios::fixed);
    productTotal_stream.precision(2);
    productTotal_stream << productTotal;
    productTotalStr = productTotal_stream.str();

    std::stringstream shippingFee_stream;
    shippingFee_stream.setf(std::ios::fixed);
    shippingFee_stream.precision(2);
    shippingFee_stream << grandTotal;
    shippingFeeStr = shippingFee_stream.str();

    std::stringstream salesTax_stream;
    salesTax_stream.setf(std::ios::fixed);
    salesTax_stream.precision(2);
    salesTax_stream << grandTotal;
    salesTaxStr = salesTax_stream.str();

    std::stringstream donationAmount_stream;
    donationAmount_stream.setf(std::ios::fixed);
    donationAmount_stream.precision(2);
    donationAmount_stream << grandTotal;
    donationAmountStr = donationAmount_stream.str();

    std::stringstream grandTotal_stream;
    grandTotal_stream.setf(std::ios::fixed);
    grandTotal_stream.precision(2);
    grandTotal_stream << grandTotal;
    grandTotalStr = grandTotal_stream.str();
    ofstream receipt;
    receipt.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/receipt.txt");
    // All dollar amounts are displayed to two decimals.
    receipt << fixed << setprecision(2);
    receipt << "-----------------------------\n";
    receipt << "Sprockets-R-Us Order Receipt\n";
    receipt << "-----------------------------\n";
    receipt << "Price Per Unit:    " << setw(10) << string("$") + string(price_per_individual_unitStr) << "\n";
    receipt << "Quantity Ordered:" << setw(12) << order << "\n";
    receipt << "Unit Subtotal:     " << setw(10) << string("$") + string(productTotalStr) << "\n";
    receipt << "-----------------------------\n";
    receipt << "Shipping Fee:      " << setw(10) << string("$") + string(shippingFeeStr) << "\n";
    receipt << "-----------------------------\n";
    receipt << "Sales Tax ( 6.75%):" << setw(10) << string("$") + string(salesTaxStr) << "\n";
    receipt << "-----------------------------\n";
    receipt << "Donation?" << setw(20) << choose << "\n";
    receipt << "Donation Amount:   " << setw(10) << string("$") + string(donationAmountStr) << "\n";
    receipt << "=============================\n";
    receipt << "Grand Total:       " << setw(10) << string("$") + string(grandTotalStr) << "\n";
    receipt << "=============================\n";


}




