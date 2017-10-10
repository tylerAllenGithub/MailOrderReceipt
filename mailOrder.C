/*Tyler Allen
CS111
Assignment 5
3-26-2015
This program will calculate and output a receipt for a mail order*/

#include <iostream>
#include <iomanip>
using namespace std;

void getCustomerInfo(int &accountNumber, int &month, int &day, int &year, char &countyCode);//receive input from customer and pass by reference
void getItemsInfo(double &totalSale, double &totalWeight);//pass by reference totalSale and totalWeight
double calcDiscount(int month);//return the proper discount
double calcSalesTax(char countyCode);//return the sales tax
double calcShipping(double totalWeight);//return proper shipping cost
void outputInvoice(int accountNumber, int month, int day, int year, char countyCode, double totalSale, double discount, double salesTax, double shipping);
//prototypes
int main(){//main function
  int accountNumber;
  int month;
  int day;
  int year;
  char countyCode;//declare variables
  double totalSale=0.0;
  double totalWeight=0.0;
   getCustomerInfo(accountNumber, month, day, year, countyCode);
   getItemsInfo(totalSale, totalWeight);
outputInvoice(accountNumber, month, day, year, countyCode, totalSale, calcDiscount(month), calcSalesTax(countyCode), calcShipping(totalWeight));
  return 0;
}

void getCustomerInfo(int &accountNumber, int &month, int &day, int &year, char &countyCode)
{
  cout<<"Enter your account number: ";
  cin>>accountNumber;
  cout<<"Enter the month of the sale: ";
  cin>>month;
  cout<<"Enter the day of the sale: ";
  cin>>day;
  cout<<"Enter the year of the sale: ";
  cin>>year;
  cout<<"Enter the county code: ";
  cin>>countyCode;
}

void getItemsInfo(double &totalSale, double &totalWeight)
{
  char choice;
  double price;
  double weight;

  cout<<"\n Do you want to order an item? Enter Y or N: ";
  cin>>choice;

  while(choice=='Y'||choice =='y')
    {//continue to ask for input while customer has an item to enter
      cout<<"Please enter the price of the item: ";
      cin>>price;
      totalSale+=price;
      //add new item price to totalSale
      cout<<"Please enter the weight of the item: ";
      cin>>weight;
      totalWeight+=weight;
      //add new item weight to totalWeight
      cout<<"\n Do you want to order another item? Enter Y or N: ";
      cin>>choice;
    }
}

double calcDiscount(int month)
{//returns discount based on month
  if(month>=1&&month<=5)
      return .05;
  else if(month>=6&&month<=8)
    return .10;
  else
    return .15;
}

double calcSalesTax(char countyCode)
{//returns sales tax based on county of residence
  switch(countyCode)
    {
     case 's':
     case 'S':
     case 'o':
     case 'O': return .0775;
     case 'l':
     case 'L': return .0825;
    }
}

double calcShipping(double totalWeight)
{//return shipping cost based on total weight
  double shippingCost=0.0;
  if(totalWeight==0)
    return 0.0;
  else if(totalWeight<=25)
    return 5.0;
  else
    {
      shippingCost+=5.0;
      totalWeight-=25;
      if(totalWeight<=25)
	{
	shippingCost+=totalWeight*.10;
	return shippingCost;
	}
      else
	{
	shippingCost+=2.50;
	totalWeight-=25;
	shippingCost+=totalWeight*.07;
	return shippingCost;
	}
    }
  return shippingCost;
}

void outputInvoice(int accountNumber, int month, int day, int year, char countyCode, double totalSale, double discount, double salesTax, double shipping)
{//print out receipt with all the information
  discount = discount*totalSale;
  salesTax = (totalSale-discount)*salesTax;
  string county;

      switch(countyCode)
	{
	case 's':
	case'S':county="San Diego";
	  break;
	case 'o':
	case 'O':county="Orange";
	  break;
	case 'l':
	case 'L':county="Los Angeles";
	  break;
	default:county="Invalid County";
	}
      cout<<left<<setw(30)<<"ACCOUNT NUMBER"<<"COUNTY"<<endl;
      cout<<left<<setw(30)<<accountNumber<<county<<endl<<endl;
      cout<<"DATE OF SALE "<<month<<"/"<<day<<"/"<<year<<endl<<endl;
      cout<<"TOTAL SALE AMOUNT:"<<right<<setw(2)<<"$"<<setw(8)<<fixed<<setprecision(2)<<totalSale<<endl;
      cout<<"DISCOUNT:"<<setw(11)<<"$"<<setw(8)<<fixed<<setprecision(2)<<discount<<endl;
      cout<<"SALES TAX:"<<setw(10)<<"$"<<setw(8)<<fixed<<setprecision(2)<<salesTax<<endl;
      cout<<"SHIPPING:"<<setw(11)<<"$"<<setw(8)<<fixed<<setprecision(2)<<shipping<<endl;
      cout<<"TOTAL DUE:"<<setw(10)<<"$"<<setw(8)<<fixed<<setprecision(2)<<totalSale-discount+salesTax+shipping<<endl;
}      
