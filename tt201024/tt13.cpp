#include <stdio.h>
#include<iostream>

using namespace std;

int func(int* input, int len) {
	//int treelen = 1;
	for (int i = 1; i < len; i=i*2) {
		for (int j = 0; j < i && i+j<len; j++) {
			if (input[i + j - 1] != NULL) {
				cout << input[i + j - 1] << ",";
			}			
		}
		cout << endl;
	}
	return 0;
}

class mytest
{
public:
	mytest();
	~mytest();

private:

};

mytest::mytest()
{
}

mytest::~mytest()
{
}

dfsdf::dfsdf()
{
}

dfsdf::~dfsdf()
{
}



MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
	int input[] = { 3,9,20,NULL,NULL,15,7 };
	func(input, 7);
	return 0;
}