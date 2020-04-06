#include "bv2av.h"



string bv2av::dec(string x1)
{
	bv2av::LL r = 0;
	for (bv2av::I a = 0; a < 6; a++) {
		r += tr[x1[s[a]]] * (bv2av::LL)pow(58, a);
	}
	return to_string(((bv2av::LL)r - (bv2av::LL)add1) ^ xor1);
}

string bv2av::enc(bv2av::LL x1)
{
	x1 = (x1 ^ xor1) + add1;
	char r[] = "BV1  4 1 7  ";
	for (bv2av::I i = 0; i < 6; i++)
	{
		r[s[i]] = table[(bv2av::I)(x1 / (bv2av::LL)pow(58, i) % 58)];
	}
	string rstring = "";
	bv2av::I r1 = sizeof(r);
	for (bv2av::I j = 0; j <r1; j++)
	{
		rstring += r[j];
	}
	return rstring;
}

bv2av::bv2av()
{
	for (bv2av::I i = 0; i < 58; i++) {
		tr[table[i]] = i;
	}
	Log.open(Filename, ios::app, _SH_DENYRW);
}

string & bv2av::Copy(string & in)
{
	bv2av::C array[100] = { 0 };
	size_t len = in.length();
	bv2av::S_P arrayPtr = array;
	bv2av::S_S nArray;
	nArray = in.copy(arrayPtr, len);
	Copyed = string(array);
	// TODO: 在此处插入 return 语句
	return Copyed;
}



bv2av::~bv2av()
{
	Log.close();
}

string & bv2av::ParseBV(string & in)
{
	auto Temp = in.substr(0, 2);
	if ((Temp != "BV") && (Temp != "bv"))
	{
		return E_S;
	}
	Dec = dec(in);
	string message = (string("原BV号:") + in + string("\nAV号:") + Dec + string("\n"));
	const char *  c_message = message.c_str();size_t s_len = message.length();
	Log.write(c_message, s_len);
	Log.flush();
	cout << "\n==============生成AV号====================\n转换结果:" << Dec << "\n==========================================\n\n";
	return Dec;
}

string & bv2av::ParseAV(string & in)
{
	auto Temp = in.substr(0, 2);
	if ((Temp == "AV") || (Temp == "av"))
	{
		Copy(in);
		bv2av::S_I Begin = in.begin(),End = Begin + 2;
		in.erase(Begin, End);
	}
	else
	{
		return E_S;
	}
	Enc = enc(stoll(in));
	string message = (string("原AV号:") + Copyed + string("\nBV号:") + Enc + string("\n"));
	const char *  c_message = message.c_str();size_t s_len = message.length();
	Log.write(c_message, s_len);
	Log.flush();
	// TODO: 在此处插入 return 语句
	cout << "\n==============生成BV号====================\n转换结果:" << Enc << "\n==========================================\n\n";
	return Enc;
}
