
#include <iostream>
#include "bv2av.h"

using namespace std;

int main()
{
	bv2av *b_a = new bv2av;
	
    char bh_1;
	for (;;) {
	ask: {
		cout << "请输入你要执行的功能编号(1:BV转AV，2:AV转BV，q:退出):";
		cin >> bh_1;
		}

		switch (bh_1)
		{
		case '1':
			for (;;) {
			     L: {
					cout << "请输入您要转换程成AV号的BV号(带BV字段，q退回选择菜单):";
					string a;
					cin >> a;
					if (a == "q") {
						cout << "\n";
						goto ask;
					}
					else {
						auto ret = b_a->ParseBV(a);
						if (ret == string("-1"))
						{
							goto L;
						}
					}
				}
			  }
				break;
		case '2':
			for (;;) {
				M:{
					cout << "请输入您要转换程成BV号的AV号(q退回选择菜单):";
					string a;
					cin >> a;
					if (a == "q") {
						cout << "\n";
						goto ask;
					}
					else {
						auto ret = b_a->ParseAV(a);
						if (ret == string("-1"))
						{
							goto M;
						}
					}
				}
			}
		case 'q':
			exit(0);
			return 0;
		default:
			cout << "输入错误！请重新输入！" << endl;
			goto ask;
		}

		delete b_a;
		return 0;
	}
}
