#include "person.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void readData(string fileName,vector<Person> &vec){
  fstream myFile;
  myFile.open(fileName);
  string fName_;
  string lName_;
  float pay_;
  float hours_;
  string space;
  int i = 0;

  while(myFile){
      Person emp(" ", " ", 0.0, 0.0);
      vec.emplace_back(emp);
      myFile >> fName_ >> lName_;
      if(i >= 1 && vec.at(i-1).getFirstName() == fName_ && vec.at(i-1).getLastName() == lName_){
        i = vec.size();
      }else{
        vec.at(i).setFirstName(fName_);
        vec.at(i).setLastName(lName_);
        myFile >> pay_ >> hours_;
        vec.at(i).setPayRate(pay_);
        vec.at(i).setHoursWorked(hours_);
        getline(myFile, space);
        ++i;
    }
  }
myFile.close();
}

void writeData(string fileName,vector<Person> &vec){
  fstream myFile;
  myFile.open(fileName);
  for(int i = 0; i < vec.size()-1; ++i){
      myFile << fixed << showpoint << setprecision(2);
      myFile << vec[i].fullName() << " " << vec[i].totalPay() << endl;
    }

  myFile.close();
}

int main(){
  cout << "-----Employee Salary Calculator-----" << endl;
  vector<Person> employees;
  string input_;
  string output_;
  cout << "Enter the name of the input file: ";
  cin >> input_;
  cout << endl;
  readData(input_, employees);
  cout << "Enter the name of the output file: ";
  cin >> output_;
  cout << endl;
  writeData(output_, employees);
  cout << "Done..." << endl;

  return 0;
}
