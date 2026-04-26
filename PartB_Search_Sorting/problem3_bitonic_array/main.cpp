#include"BitonicArray.h"
#include<iostream>
using namespace std;
int main()
{
	cout << "\n======= TestCaseOne ============\n";
	vector<int> v1 = { 7, 2, 9, 4, 6, 1, 8, 3, 12 };
	BitonicArray<int> a1(v1);
	cout << a1.search(12) << endl; // bitonic point
	a1.printData();
	cout << "\n======= TestCaseTwo ============\n";

	vector<int> v2 = { 5, 1, 8, 3, 7, 2, 6, 4, 10 };
	BitonicArray<int> a2(v2);
	cout << a2.search(5) << endl; // left half
	a2.printData();
	cout << "\n======= TestCaseThree ============\n";

	vector<int> v3= { 2, 4, 6, 9, 8, 5, 3, 1, 7 };
	BitonicArray<int> a3(v3);
	cout << a3.search(3) << endl; // right half
	a3.printData();
	cout << "\n======= TestCaseFour ============\n";

	vector<int> v4 = { 1, 3, 5, 7, 9, 6, 4, 2, 8 };
	BitonicArray<int> a4(v4);
	cout << a4.search(100) << endl; // not found 
	a4.printData();
	cout << "\n======= TestCaseFive ============\n";

	vector<int> v5 = { 1, 3, 5, 5, 9, 8, 5, 2, 1 };
	BitonicArray<int> a5(v5);
	cout << a5.search(5) << endl; // duplicate
	a5.printData(); 
}