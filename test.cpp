/* CSCI 261 - A3 - Sprockets-R-Us Shopping Cart
 * Author: Jon Serrano
 *
 */
#include <iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;

/* The format of the text file goes accordingly:
 * price_per_individual_unit
sales_tax_percentage_rate
shipping_min_1 flat_shipping_rate1
shipping_min_2 flat_shipping_rate2
shipping_min_3 flat_shipping_rate3
free_shipping_min
 *
 *
 */

float price_per_individual_unit;
float sales_tax_percentage_rate;
float shipping_min_1;
float shipping_min_2;
float shipping_min_3;
float flat_shipping_rate1;
float flat_shipping_rate2;
float flat_shipping_rate3;
float free_shipping_min;
int numOrder;
float basePrice;
float shippingPrice;
float subtotal;
float total;
float cents;
char donation;
float donationAmount;
float salesTax;

void initVariables(){
    ifstream numbers;
    numbers.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/product_public.txt");
    if(!numbers){
        cerr << "Couldn't open the file";
        //Make sure you're work directory is the one before!!! cd ..
    }
    numbers >> price_per_individual_unit >> sales_tax_percentage_rate >> shipping_min_1 >> flat_shipping_rate1 >> shipping_min_2 >> flat_shipping_rate2 >> shipping_min_3 >> flat_shipping_rate3 >> free_shipping_min;
    //cout << price_per_individual_unit << sales_tax_percentage_rate << shipping_min_1 << flat_shipping_rate1 << shipping_min_2 << flat_shipping_rate2 << shipping_min_3 << flat_shipping_rate3 << free_shipping_min;
    numbers.close();
}
void calcShipping(){
    if(basePrice > shipping_min_2){
        if(basePrice > shipping_min_3){
            if(basePrice > free_shipping_min){
                cout << "\nThank you for your large purchase! You have free shipping for this purchase.";
                shippingPrice = 0.00;
            }else{
                shippingPrice = flat_shipping_rate3;
            }
        }else{
            shippingPrice = flat_shipping_rate2;
        }
    }else{
        shippingPrice = flat_shipping_rate1;
    }
}
void printReceipt(){
    ofstream file;
    file.open("/Users/YanzhiWang/CLionProjects/CPPProgrammingConcepts/receipt.txt");
    if(!file){
        cerr << "couldn't write to receipt?";
    }
    //For the next lines outputting stuff to the file, it should mirror what is seen on each line for the receipt.
    file << setw(29) << setfill('-') << "\n";
    file << "Sprockets-R-Us Order Receipt\n" << setw(29) << setfill('-') << "\n";
    file << "Price Per Unit:" << right << setw(9) << setfill(' ')<< "$" << price_per_individual_unit << endl;
    file << "Quantity ordered:" << right << setw(11)<< setfill(' ')<< numOrder << endl;
    file << "Unit Subtotal:" << right << setw(9)<< setfill(' ')<<  "$" << basePrice <<endl;
    file <<setw(29) <<setfill('-') << "\n";
    file << "Shipping Fee:" << right << setw(10)<< setfill(' ')<< fixed << setprecision(2) << "$"<<shippingPrice <<endl;
    file <<setw(29) <<setfill('-') << "\n";
    file << "Sales Tax (6.75%):" << right << setw(5)<< setfill(' ')<<  fixed << setprecision(2)  << "$" << salesTax <<endl;
    file <<setw(29) <<setfill('-') << "\n";
    file << "Donation?" << right << setw(19)<< setfill(' ')<< donation <<endl;
    if(donation == 'Y'){
        file << "Donation Amount:" << right << setw(8)<< setfill(' ')<< fixed << setprecision(2) <<  "$"<<donationAmount <<endl;
    }
    file <<setw(29) <<setfill('=') << "\n";
    file << "Grand Total:" << right << setw(10)<< setfill(' ')<< "$" << total <<endl;
    file <<setw(29) <<setfill('=') << "\n";
}
int main() {
    initVariables();
    cout << "Welcome to Sprockets-R-Us!\nWe sell round sprockets, square sprockets, and triangle sprockets.\nThe cost of a single sprocket is $" << fixed << setprecision(2) <<price_per_individual_unit;
    cout << ".\nHow many Sprockets do you wish to order?\n>";
    cin >> numOrder;
    cout <<"Thank you for your order of " << numOrder << " Sprockets! One moment while we prepare your receipt...";
    basePrice = numOrder * price_per_individual_unit;
    calcShipping();
    subtotal = shippingPrice + basePrice;
    //cout << "\nBaseprice is :" <<basePrice << "\nshipping price is: "<< shippingPrice <<  "\nsubtotal is:" << subtotal  <<endl;
    salesTax = subtotal * sales_tax_percentage_rate / 100;
    total = subtotal * (1 + (sales_tax_percentage_rate/100));
    //cout << "Total is:" << total;
    //cout << "Total - (int) total = " << total - (int)total;
    cents = (total-(int)total);
    if (!(cents == 0 )){
        cout << "\nWould you like to round up your total (" << 1.00 - cents << ") and donate to the Children\'s Hospital? (Y\\N)\n>";
        cin >> donation;
        donation = (char) toupper(donation);
        if (donation == 'Y'){
            donationAmount = 1.00 - cents;
            total += donationAmount;
        }
    }
    //cout << total;
    printReceipt();
    return 0;
}