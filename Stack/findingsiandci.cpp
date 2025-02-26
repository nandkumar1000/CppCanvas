#include <iostream>
#include <cmath>

using namespace std;

// Base Class A - Calculates Simple Interest
class A
{
protected:
  double principal, rate, time, SI;

public:
  void getData()
  {
    cout << "Enter Principal, Rate of Interest (in %), and Time (in years): ";
    cin >> principal >> rate >> time;
  }

  void findSimpleInterest()
  {
    SI = (principal * rate * time) / 100.0;
  }
};

// Derived Class B - Inherits A and Calculates Compound Interest
class B : public A
{
protected:
  double CI;

public:
  void findCompoundInterest()
  {
    CI = principal * pow((1 + rate / 100.0), time) - principal;
  }
};

// Derived Class C - Inherits B and Displays Results
class C : public B
{
public:
  void displayResults()
  {
    cout << "\nPrincipal: " << principal;
    cout << "\nRate of Interest: " << rate << "%";
    cout << "\nTime: " << time << " years";
    cout << "\nSimple Interest: " << SI;
    cout << "\nCompound Interest: " << CI << endl;
  }
};

// Main Function
int main()
{
  C obj;
  obj.getData();
  obj.findSimpleInterest();
  obj.findCompoundInterest();
  obj.displayResults();
  return 0;
}
