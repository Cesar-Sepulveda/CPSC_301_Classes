#include "person.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void readData(string fileName, Person arr[], size_t size){
  fstream myFile;
  myFile.open(fileName);
  string fName_;
  string lName_;
  float pay_;
  float hours_;
  string space;

  for(int i = 0; i < size; ++i){
    myFile >> fName_ >> lName_;
    arr[i].setFirstName(fName_);
    arr[i].setLastName(lName_);
    myFile >> pay_ >> hours_;
    arr[i].setPayRate(pay_);
    arr[i].setHoursWorked(hours_);
    getline(myFile, space);
    if( i > 1 && arr[i].getFirstName() == arr[i-1].getFirstName()){
      i = size;
    }
  }
myFile.close();
}

void writeData(string fileName, Person arr[], size_t size){
  fstream myFile;
  myFile.open(fileName);
  for(int i = 0; i < size; ++i){
    if(arr[i].fullName() == "No employee" && arr[i].totalPay() == 0){
      i = size;
    }else{
      cout << fixed << showpoint << setprecision(2);
      myFile << arr[i].fullName() << " " << arr[i].totalPay() << endl;
    }
  }

  myFile.close();
}

int main(){
  cout << "-----Employee Salary Calculator-----" << endl;
  const size_t size = 20;
  Person employees[size];
  string input_;
  string output_;
  cout << "Enter the name of the input file: ";
  cin >> input_;
  cout << endl;
  readData(input_, employees, size);
  cout << "Enter the name of the output file: ";
  cin >> output_;
  cout << endl;
  writeData(output_, employees, size);
  cout << "Done..." << endl;

  for(int i = 0; i < size; ++i){
    cout << employees[i].fullName() << " " << employees[i].totalPay() << endl;
  }

  return 0;
}
