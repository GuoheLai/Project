#include"mysql_link.h"
#include<Windows.h>
#include<iostream>
#include"caidan.h"
#include <stdlib.h>
using namespace std;
int main() {
	mysqlinit();
	cout << "                   *****************************" << endl;
	cout << "                       ��ӭʹ��ְ������ϵͳ" << endl;
	cout << "                   *****************************" << endl;
	selectuser();
	system("pause");
	return 0;
	}

