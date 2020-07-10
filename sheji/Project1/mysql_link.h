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
//必备的一个数据结构  
MYSQL mydata;
void mysqlinit() {
	initdata();
	linkdatabase();

	//初始化数据库  
	if (0 == mysql_library_init(0, NULL, NULL)) {
		cout << "初始化数据库成功" << endl;
	}
	else {
		cout << "初始化数据库失败" << endl;
		return ;
	}
}
void initdata() {
	//初始化数据结构  
	if (NULL != mysql_init(&mydata)) {
		cout << "初始化数据结构成功" << endl;
	}
	else {
		cout << "初始化数据结构失败" << endl;
		return ;
	}

	//在连接数据库之前，设置额外的连接选项  
	//可以设置的选项很多，这里设置字符集，否则无法处理中文  
	if (0 == mysql_options(&mydata, MYSQL_SET_CHARSET_NAME, "gbk")) {
		cout << "mysql_options() succeed" << endl;
	}
	else {
		cout << "mysql_options() failed" << endl;
		return ;
	}
}

void linkdatabase() {

	//连接数据库  
	if (NULL
		!= mysql_real_connect(&mydata, "localhost", "root", "root", "work", 3306, NULL, 0))
		//这里的地址，用户名，密码，端口可以根据自己本地的情况更改  
	{
		cout << "连接数据库成功" << endl;
	}
	else {
		cout << "连接数据库失败" << endl;
		return ;
	}
}

void insert() {
	//向表中插入数据 
	string sqlstr;
	sqlstr =
		"INSERT INTO user_info(user_name) VALUES('公司名称'),('一级部门'),('二级部门'),('开发小组'),('姓名');";
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
	//显示刚才插入的数据  
	sqlstr = "SELECT user_id,user_name,user_second_sum FROM user_info";
	MYSQL_RES *result = NULL;
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "mysql_query() select data succeed" << endl;

		//一次性取得数据集  
		result = mysql_store_result(&mydata);
		//取得并打印行数  
		int rowcount = mysql_num_rows(result);
		cout << "row count: " << rowcount << endl;

		//取得并打印各字段的名称  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			cout << field->name << "\t\t";
		}
		cout << endl;

		//打印各行  
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
	//删除刚才建的表  
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