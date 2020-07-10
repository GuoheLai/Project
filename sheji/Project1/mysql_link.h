#include <winsock.h>
#include <iostream>  
#include <string>  
#include <mysql.h>  
#include <process.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")  
#pragma comment(lib, "libmysql.lib")  
void mysqlinit();
void initdata();
void linkdatabase();
void linkdatabase();
void insert();
void selectnow();
//�ر���һ�����ݽṹ  
MYSQL mydata;
void mysqlinit() {
	initdata();
	linkdatabase();

	//��ʼ�����ݿ�  
	if (0 == mysql_library_init(0, NULL, NULL)) {
		cout << "��ʼ�����ݿ�ɹ�" << endl;
	}
	else {
		cout << "��ʼ�����ݿ�ʧ��" << endl;
		return ;
	}
}
void initdata() {
	//��ʼ�����ݽṹ  
	if (NULL != mysql_init(&mydata)) {
		cout << "��ʼ�����ݽṹ�ɹ�" << endl;
	}
	else {
		cout << "��ʼ�����ݽṹʧ��" << endl;
		return ;
	}

	//���������ݿ�֮ǰ�����ö��������ѡ��  
	//�������õ�ѡ��ܶ࣬���������ַ����������޷���������  
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
		cout << "mysql_options() succeed" << endl;
	}
	else {
		cout << "mysql_options() failed" << endl;
		return ;
	}
}

void linkdatabase() {

	//�������ݿ�  
	if (NULL
		!= mysql_real_connect(&mydata, "localhost", "root", "root", "work", 3306, NULL, 0))
		//����ĵ�ַ���û��������룬�˿ڿ��Ը����Լ����ص��������  
	{
		cout << "�������ݿ�ɹ�" << endl;
	}
	else {
		cout << "�������ݿ�ʧ��" << endl;
		return ;
	}
}

void insert() {
	//����в������� 
	string sqlstr;
	sqlstr =
		"INSERT INTO user_info(user_name) VALUES('��˾����'),('һ������'),('��������'),('����С��'),('����');";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() insert data succeed" << endl;
	}
	else {
		cout << "mysql_query() insert data failed" << endl;
		mysql_close(&mydata);
		return ;
	}
}

void selectnow() {

	string sqlstr;
	//��ʾ�ղŲ��������  
	sqlstr = "SELECT user_id,user_name,user_second_sum FROM user_info";
	MYSQL_RES *result = NULL;
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() select data succeed" << endl;

		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&mydata);
		//ȡ�ò���ӡ����  
		int rowcount = mysql_num_rows(result);
		cout << "row count: " << rowcount << endl;

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			cout << field->name << "\t\t";
		}
		cout << endl;

		//��ӡ����  
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		while (NULL != row) {
			for (int i = 0; i < fieldcount; i++) {
				cout << row[i] << "\t\t";
			}
			cout << endl;
			row = mysql_fetch_row(result);
		}

	}
	else {
		cout << "mysql_query() select data failed" << endl;
		mysql_close(&mydata);
		return ;
	}
}

/*
	//ɾ���ղŽ��ı�  
	sqlstr = "DROP TABLE user_info";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() drop table succeed" << endl;
	}
	else {
		cout << "mysql_query() drop table failed" << endl;
		mysql_close(&mydata);
		return -1;
	}
	mysql_free_result(result);
	mysql_close(&mydata);
	mysql_server_end();

	system("pause");
	return 0;
}*/