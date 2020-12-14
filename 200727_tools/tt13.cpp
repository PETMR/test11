#include<stdio.h>
#include<iostream>

using namespace std;

int flt2my(float input, uint16_t& output) {

	input += 512;
	output = input / 0.015625;
	return 0;
}
int my2flt(uint16_t input, float& output) {

	output = input * 0.015625 - 512;
	return 0;
}

int ttt = 1;

int main() {

	//cout << sizeof(short) << endl;
	//cout << sizeof(int) << endl;

	//int aint = 0xABCDDCBA;
	//short bshort;

	//bshort = aint;

	//cout << bshort << endl;
	//cout << aint << endl;

	//printf("%x\n", bshort);
	//printf("%x\n", aint);

	//float TT = 123.875;

	//int big = TT;

	//float small = TT - big;

	//float* tt2 = &small;

	//short my1, my2;

	//my1 = big >> 16 & 0x8000;
	//my2 = big & 0x7FFF<<4;

	//int d1 = small / 0.5;
	//small -= 0.5;
	//int d2 = small / 0.25;
	//small -= 0.25;
	//int d3 = small / 0.125;
	//small -= 0.125;
	//int d4 = small / 0.0675;

	//printf("%f\n", *(float*)(&tt1));
	//my = (short)big + big >> 16 & 0x8000;

	//float tt1 = 123.461;
	//uint16_t out;
	//flt2my(tt1, out);
	//float tt2 = out * 0.015625 - 512;
	//printf("%x\n", out);

	printf("%d\n", ttt);
	ttt = 0;
	printf("%d\n", ttt);

}



