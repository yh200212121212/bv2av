#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map> 

using namespace std;

class bv2av
{
private:
	typedef int I;
	typedef long L;
	typedef long long LL;
	typedef char C;
	typedef typename string::pointer S_P;
	typedef typename string::size_type S_S;
	typedef typename string::iterator  S_I;
public:
	string dec(string x1);
	string enc(bv2av::LL x1);	
	bv2av();
	~bv2av();
private:
	string table = "fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
	map <bv2av::L, bv2av::L> tr;
	bv2av::L s[6] = { 11,10,3,8,4,6 };
	bv2av::LL xor1 = 177451812;
	bv2av::LL add1 = 8728348608;
	const string Filename = "Log.txt";
	string Copyed;
	ofstream Log;
	string Dec, Enc;
public:
	string & ParseAV(string &in);
	string & ParseBV(string &in);
private:
	string &Copy(string &in);
private:
	string E_S = string("-1");
};