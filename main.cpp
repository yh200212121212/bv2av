
#include <iostream>
#include "bv2av.h"

using namespace std;

int main()
{
	bv2av *b_a = new bv2av;
	
    char bh_1;
	for (;;) {
	ask: {
		cout << "��������Ҫִ�еĹ��ܱ��(1:BVתAV��2:AVתBV��q:�˳�):";
		cin >> bh_1;
		}

		switch (bh_1)
		{
		case '1':
			for (;;) {
			     L: {
					cout << "��������Ҫת���̳�AV�ŵ�BV��(��BV�ֶΣ�q�˻�ѡ��˵�):";
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
					cout << "��������Ҫת���̳�BV�ŵ�AV��(q�˻�ѡ��˵�):";
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
			cout << "����������������룡" << endl;
			goto ask;
		}

		delete b_a;
		return 0;
	}
}
