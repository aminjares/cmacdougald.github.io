// chp3example4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string strFileName = "address.vcf";
	string strLine1 = "";
	string strLine2 = "";
	string strLine3 = "";
	string strLine4 = "";
	string strLine5 = "";
	string strLast = "";
	ifstream fileAddress;
	fileAddress.open(strFileName);
	fileAddress >> strLine1;
	fileAddress >> strLine2;
	fileAddress >> strLine3;
	fileAddress >> strLine4 >> strLast;
	fileAddress >> strLine5;
	fileAddress.close();

	cout << strLine1 << endl
		<< strLine2 << endl 
		<< strLine3 << endl 
		<< strLine4 << strLast << endl 
		<< strLine5 << endl;

    return 0;
}

