int selectuser();
void guanli();
void chaxun();
void zengjia();
void shanchu();
void xiugai();
void bumen();
void chabu();
void chaxun1();
void zhiwei();
void quanju();
void chazhi();
void chazhi1();
void chabu1();
void tiaojian1();
void tiaojian();


int selectuser() {
	MYSQL_RES *result = NULL;
	string id, pw;
	cout << "请输入用户名：" << endl;
	cin >> id;
	cout << "请输入密码：" << endl;
	cin >> pw;
	string sqlstr;
	sqlstr = "SELECT * FROM tb_user WHERE Uname='" + id + "' and password='" + pw + "';";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		//cout << "完成查询" << endl;
		result = mysql_store_result(&mydata);
		if (mysql_num_rows(result))
		{ //mysql_num_rows得到受影响的行数
			mysql_free_result(result); //释放结果集
			//得到用户的角色信息
			sqlstr = "select power  from tb_user where Uname='" + id + "';";
			mysql_query(&mydata, sqlstr.c_str());
			result = mysql_store_result(&mydata);//将查询到的结果集存下来，放到result中去
			MYSQL_ROW row = mysql_fetch_row(result); //row[0]即为用户角色编号
			if (!(strcmp(row[0], "1"))) {
				system("cls");
				cout << "****** " << " 系统管理员欢迎您！" << "**********" << endl;
				guanli(); return 0;
			}
			else if (!(strcmp(row[0], "2"))) {
				system("cls");
				cout << "************ " << " 欢迎使用职工信息查询系统" << "**********" << endl;
				chaxun(); return 0;
			}
		}
		else {
			system("cls");
			cout << "用户或密码错误请重试" << endl;
			return selectuser();
		}

	}
	return 0;
}

void guanli()
{
	int a;
	cout << "1.查询信息" << endl;
	cout << "2.增加新的职工信息" << endl;
	cout << "3.修改职工信息" << endl;
	cout << "4.删除职工信息" << endl;
	cout << "5.退出登录" << endl;
	cout << "6.退出系统" << endl;
	cout << "请选择你要进行的操作:"; cin >> a;
	switch (a)
	{
	case 1:chaxun1(); break;
		case 2:zengjia(); break;
			case 3:xiugai(); break;
				case 4:shanchu(); break;
				case 5:system("cls"); selectuser(); return;
	case 6: exit(0);
	default: cout << "请按提示输入" << endl; guanli(); break;
	}
}
void chaxun1()
{
	int n;
	cout << "1.查询部门信息表" << endl;
	cout << "2.查询职位信息表" << endl;
	cout << "3.查询全体职工信息表" << endl;
	cout << "4.按条件查找职工信息" << endl;
	cout << "5.返回上一级" << endl;
	cout << "请选择你要进行的操作:";
	cin >> n;
	switch (n)
	{
	case 1: bumen(); chabu1(); break;
	case 2:zhiwei(); chazhi1(); break;
	case 3:quanju(); chaxun1(); break;
	case 4:tiaojian1(); break;
	case 5:system("cls"); guanli(); break;
	default: cout << "请按提示输入"<< endl; chaxun1(); break;
	}
}
void chazhi1()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "请问你要查询哪个职位人员信息：" << endl;
	cout << "1.经理，2.员工，3全体职工，4.返回" << endl;
	cin >> bm;
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	if (i == 3)
	{
		quanju();
		chazhi1();
	}
	else if (i == 4) { system("cls"); chaxun1();}
	else if (i == 1) {
		sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE Pname='经理';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//一次性取得数据集  
			result = mysql_store_result(&mydata);
			//取得并打印行数  
			/*int rowcount = mysql_num_rows(result);
			cout << "数据库中共有: " << rowcount << "书目" << endl;*/

			//取得并打印各字段的名称  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//打印各行  
			MYSQL_ROW row = NULL;
			row = mysql_fetch_row(result);
			while (NULL != row) {
				for (int i = 0; i < fieldcount; i++) {
					printf("%8s\t", row[i]);
					//cout << row[i] << "\t  \t";
				}
				cout << endl;
				row = mysql_fetch_row(result);
			}
			cout << endl;
		}
	}
	else if(i==2){
		sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE Pname='员工';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//一次性取得数据集  
			result = mysql_store_result(&mydata);
			//取得并打印行数  
			/*int rowcount = mysql_num_rows(result);
			cout << "数据库中共有: " << rowcount << "书目" << endl;*/

			//取得并打印各字段的名称  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//打印各行  
			MYSQL_ROW row = NULL;
			row = mysql_fetch_row(result);
			while (NULL != row) {
				for (int i = 0; i < fieldcount; i++) {
					printf("%8s\t", row[i]);
					//cout << row[i] << "\t  \t";
				}
				cout << endl;
				row = mysql_fetch_row(result);
			}
			cout << endl;
		}
		
		}
	else {
		cout << "请按要求输入：" << endl;
	}
	chazhi1();
}
void chabu1() {
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "请问你要查询哪个部门人员的信息：" << endl;
	cout << "（1.策划部，2.人事部，3.外联部，4.所有部门，5.返回）";
	cin >> bm;
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	if (i == 4)
	{
		quanju();
		chabu1();
	}
	else if (i == 5) { system("cls"); chaxun1(); }
	else {
		sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE Dno='" + bm + "';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//一次性取得数据集  
			result = mysql_store_result(&mydata);
			//取得并打印行数  
			int rowcount = mysql_num_rows(result);
			if (rowcount == 0) { cout << "无效的部门编号，请重新输入" << endl; chabu1(); }

			//取得并打印各字段的名称  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//打印各行  
			MYSQL_ROW row = NULL;
			row = mysql_fetch_row(result);
			while (NULL != row) {
				for (int i = 0; i < fieldcount; i++) {
					printf("%8s\t", row[i]);
					//cout << row[i] << "\t  \t";
				}
				cout << endl;
				row = mysql_fetch_row(result);
			}
			cout << endl;
		}
		else {
			cout << "该部门不存在" << endl;
		}
	}
	chabu1();
}
void tiaojian1()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm,id,name,sex;
	cout << "1.按职工号查找：" << endl;
	cout << "2.按名字查找："<<endl;
	cout << "3.按性别查找：" << endl;
	cout << "4.返回" << endl;
	cin >> bm;
	system("cls");
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	switch (i) {
	case 1: quanju(); cout << endl<< endl<< "请输入职工号："; cin >> id; sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE id='" + id + "';"; break;
	case 2: quanju(); cout  << endl << endl << "请输入姓名："; cin >> name; sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE name='" + name + "';"; break;
	case 3: quanju(); cout << endl << endl << "请输入性别（男/女）："; cin >> sex; sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE sex='" + sex + "';"; break;
	case 4: chaxun1(); return;
	default: cout << "请按提示输入" << endl; tiaojian1(); break;
	}
	
		
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "完成查询" << endl;
			//一次性取得数据集  
			result = mysql_store_result(&mydata);
			//取得并打印行数  
			int rowcount = mysql_num_rows(result);
			if (rowcount == 0) { cout << "未在数据库中找到"; cout << endl << endl; tiaojian1(); return;};
			cout << "数据库中共发现: " << rowcount << "条查询结果" << endl;

			//取得并打印各字段的名称  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//打印各行  
			MYSQL_ROW row = NULL;
			row = mysql_fetch_row(result);
			while (NULL != row) {
				for (int i = 0; i < fieldcount; i++) {
					printf("%8s\t", row[i]);
					//cout << row[i] << "\t  \t";
				}
				cout << endl;
				row = mysql_fetch_row(result);
			}
			cout << endl;
		}
		else {
			cout << "未在数据库中找到" << endl;
		}
	tiaojian1();
}

void chaxun()
{
	int n;
	cout << "1.查询部门信息表" << endl;
	cout << "2.查询职位信息表" << endl;
	cout << "3.查询全体职工信息表" << endl;
	cout << "4.按条件查找职工信息" << endl;
	cout << "5.退出登录" << endl;
	cout << "6.退出系统" << endl;
	cout << "请选择你要进行的操作:";
	cin >> n;
	switch (n)
	{
	case 1:bumen(); chabu(); break;
	case 2:zhiwei(); chazhi(); break;
	case 3:quanju(); chaxun(); break;
	case 4:tiaojian(); break;
	case 5:system("cls"); selectuser();return;
	case 6:exit(0);
	default: cout << "请按提示输入" << endl; chaxun(); break;
	}
	/*int n;
	cout << "*****1.查询部门信息*****" << endl;
	cout << "*****2.查询现有职位信息*****" << endl;
	cout << "*****3.查询全体职工信息*****" << endl;
	cout << "*****4.退出系统*****" << endl;
	cout << "请选择你要进行的操作:";
	cin >> n;
	switch (n)
	{
	case 1: bumen(); break;
	case 2:zhiwei(); break;
	case 3:quanju(); break;
	case 4:cout << "您已成功退出系统" << endl << endl; break;
	default: break;
	}*/
}
void zhiwei()
{
	int a;
	MYSQL_RES *result = NULL;
	string sqlstr;
	sqlstr = "SELECT  pno 职位等级,pname 职位名 FROM tb_post";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "完成查询" << endl;

		//一次性取得数据集  
		result = mysql_store_result(&mydata);
		//取得并打印行数  
		int rowcount = mysql_num_rows(result);
		cout << "数据库中共有: " << rowcount << "个职位" << endl;

		//取得并打印各字段的名称  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%10s\t\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//打印各行  
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		while (NULL != row) {
			for (int i = 0; i < fieldcount; i++) {
				printf("%10s\t \t", row[i]);
				//cout << row[i] << "\t  \t";
			}
			cout << endl;
			row = mysql_fetch_row(result);
		}

	}
	else {
		cout << "查询失败" << endl;
		mysql_close(&mydata);

	}
}
void chazhi()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "请问你要查询哪个职位人员信息：" << endl;
	cout << "1.经理，2.员工，3全体职工，4.返回" << endl;
	cin >> bm;
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	if (i == 3)
	{
		quanju();
		chazhi();
	}
	else if (i == 4) { system("cls"); chaxun(); return; }
	else if (i == 1) {
		sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE pname='经理';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "完成查询" << endl;
			//一次性取得数据集  
			result = mysql_store_result(&mydata);
			//取得并打印行数  
			/*int rowcount = mysql_num_rows(result);
			cout << "数据库中共有: " << rowcount << "书目" << endl;*/

			//取得并打印各字段的名称  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//打印各行  
			MYSQL_ROW row = NULL;
			row = mysql_fetch_row(result);
			while (NULL != row) {
				for (int i = 0; i < fieldcount; i++) {
					printf("%8s\t", row[i]);
					//cout << row[i] << "\t  \t";
				}
				cout << endl;
				row = mysql_fetch_row(result);
			}
			cout << endl;
		}
		
	}
	else if(i==2){
		sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE pname='员工';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "完成查询" << endl;
			//一次性取得数据集  
			result = mysql_store_result(&mydata);
			//取得并打印行数  
			/*int rowcount = mysql_num_rows(result);
			cout << "数据库中共有: " << rowcount << "书目" << endl;*/

			//取得并打印各字段的名称  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//打印各行  
			MYSQL_ROW row = NULL;
			row = mysql_fetch_row(result);
			while (NULL != row) {
				for (int i = 0; i < fieldcount; i++) {
					printf("%8s\t", row[i]);
					//cout << row[i] << "\t  \t";
				}
				cout << endl;
				row = mysql_fetch_row(result);
			}
			cout << endl;
		}
	}
	else {
		cout << "请按要求输入：" << endl;
	}
	chazhi();
}
void quanju() {
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "完成查询" << endl;
		//一次性取得数据集  
		result = mysql_store_result(&mydata);
		//取得并打印行数  
		int rowcount = mysql_num_rows(result);
		if (rowcount == 0) { cout << "无效的部门编号，请重新输入"<< endl; chabu(); }

		//取得并打印各字段的名称  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%8s\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//打印各行  
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		while (NULL != row) {
			for (int i = 0; i < fieldcount; i++) {
				printf("%8s \t", row[i]);
				//cout << row[i] << "\t  \t";
			}
			cout << endl;
			row = mysql_fetch_row(result);
		}
		cout << endl;
	}
	else {
		cout << "不存在" << endl;
	}
}
void bumen()
{
	int a;
	MYSQL_RES *result = NULL;
	string sqlstr;
	sqlstr = "SELECT  Dno 部门编号,Dname 部门名称 FROM tb_department";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "完成查询" << endl;

		//一次性取得数据集  
		result = mysql_store_result(&mydata);
		//取得并打印行数  
		int rowcount = mysql_num_rows(result);
		cout << "数据库中共有: " << rowcount << "个部门" << endl;

		//取得并打印各字段的名称  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%10s\t\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//打印各行  
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		while (NULL != row) {
			for (int i = 0; i < fieldcount; i++) {
				printf("%10s\t \t", row[i]);
				//cout << row[i] << "\t  \t";
			}
			cout << endl;
			row = mysql_fetch_row(result);
		}

	}
	else {
		cout << "查询失败" << endl;
		mysql_close(&mydata);

	}
}
void chabu() {
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "请问你要查询哪个部门人员的信息：" << endl;
	cout << "（1.策划部，2.人事部，3.外联部，4.所有部门，5.返回）";
	cin >> bm;
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	if (i == 4)
	{
		quanju();
		chabu();
	}
	else if (i == 5) { system("cls"); chaxun(); }
	else {
		sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE Dno='" + bm + "';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//一次性取得数据集  
			result = mysql_store_result(&mydata);
			//取得并打印行数  
			int rowcount = mysql_num_rows(result);
			if (rowcount == 0) { cout << "无效的部门编号，请重新输入" << endl; chabu(); }

			//取得并打印各字段的名称  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//打印各行  
			MYSQL_ROW row = NULL;
			row = mysql_fetch_row(result);
			while (NULL != row) {
				for (int i = 0; i < fieldcount; i++) {
					printf("%8s\t", row[i]);
					//cout << row[i] << "\t  \t";
				}
				cout << endl;
				row = mysql_fetch_row(result);
			}
			cout << endl;
		}
		else {
			cout << "该部门不存在" << endl;
		}
	}
	chabu();
}
void tiaojian()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm, id, name, sex;
	cout << "1.按职工号查找：" << endl;
	cout << "2.按名字查找：" << endl;
	cout << "3.按性别查找：" << endl;
	cout << "4.返回" << endl;
	cin >> bm;
	system("cls");
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	switch (i) {
	case 1: quanju(); cout << endl << endl << "请输入职工号："; cin >> id; sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE id='" + id + "';"; break;
	case 2: quanju(); cout << endl << endl << "请输入姓名："; cin >> name; sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE name='" + name + "';"; break;
	case 3: quanju(); cout << endl << endl << "请输入性别（男/女）："; cin >> sex; sqlstr = "SELECT id 职工号,name 姓名,sex 性别,Dno 部门编号,Dname 部门,Pname 职位,salary 工资,phone 电话 FROM tb_information WHERE sex='" + sex + "';"; break;
	case 4: chaxun(); return;
	default: cout << "请按提示输入" << endl; tiaojian(); break;
	}


	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		//一次性取得数据集  
		result = mysql_store_result(&mydata);
		//取得并打印行数  
		int rowcount = mysql_num_rows(result);
		if (rowcount == 0) { cout << "未在数据库中找到" << endl << endl; tiaojian(); return; };
		cout << "数据库中共发现: " << rowcount << "条查询结果" << endl;

		//取得并打印各字段的名称  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%8s\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//打印各行  
		MYSQL_ROW row = NULL;
		row = mysql_fetch_row(result);
		while (NULL != row) {
			for (int i = 0; i < fieldcount; i++) {
				printf("%8s\t", row[i]);
				//cout << row[i] << "\t  \t";
			}
			cout << endl;
			row = mysql_fetch_row(result);
		}
		cout << endl;
	}
	else {
		cout << "未在数据库中找到" << endl;
	}
	tiaojian();
}

void zengjia()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string id, name,dno,sex,dname,pname,salary,phone;
	int a,i;
	char* end;
	cout << "***************增加新的职工信息*****************" << endl;
	cout << "请依次输入新职工的职工号，名字，性别，部门编号，职位，工资，手机号：" << endl;
	cin >> id >> name >> sex >> dno >> pname >> salary >> phone;
	i = static_cast<int>(strtol(dno.c_str(), &end, 16));
	i = static_cast<int>(strtol(dno.c_str(), &end, 10));
	
	switch (i)
	{
	case 1:dname = "策划部"; break;
	case 2:dname = "人事部"; break;
	case 3:dname = "外联部"; break;
	default:cout << "输入的部门编号不存在，请重新输入："<<endl << endl; zengjia(); break;
	}
	if(pname!="经理"&&pname!= "员工")
	{
		cout << "输入的职位不存在，请重新输入：" << endl;zengjia();
	}
	else {
		sqlstr = "insert into tb_information(id, name,sex,dno,dname,pname,salary,phone) VALUES('" + id + "','" + name + "','" + sex + "','" + dno + "','" + dname + "','" + pname + "','" + salary + "','" + phone + "');";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "增加职工信息成功！" << endl;
		}
		else {
			cout << "职工信息加入失败！" << endl;
			cout << mysql_error(&mydata) << endl;
			mysql_close(&mydata);
		}
		quanju();
		cout << endl;
		cout << "1.继续添加职工信息" << endl;
		cout << "2.返回主菜单" << endl;
		cin >> a;
		switch (a)
		{
		case 1:zengjia(); break;
		case 2:system("cls"); guanli(); break;
		}
	}
}
void xiugai() {
	MYSQL_RES *result = NULL;
	string sqlstr, id,id1, name, sex, dno,  dname, pname, salary, phone;
	int a,b,i;
	char* end;
	quanju();
	cout << "请输入你要修改的职工的职工号："; cin >> id; 
	cout << "1.职工号，2.名字，3.性别，4.部门，5.职位，6.工资，7.手机号" << endl;
	cout << "请选择你要修改该职工哪项信息:"<<endl;
	cin >> a;
	switch (a)
	{
	case 1:cout << "请输入新职工号: "; cin >> id1; sqlstr = "UPDATE tb_information SET id='" + id1 + "' WHERE id='" + id + "';"; break;
	case 2:cout << "请输入新名字: "; cin >> name; sqlstr = "UPDATE tb_information SET name='" + name + "' WHERE id='" + id + "';"; break;
	case 3:cout << "请输入新性别: "; cin >> sex; if (sex!= "男" && sex!= "女")
	{cout << "性别输入有误，修改失败：" << endl; xiugai();}
		  else { sqlstr = "UPDATE tb_information SET sex='" + sex + "' WHERE id='" + id + "';"; } break;
	case 4:cout << "请输入新部门的编号 "; cin >> dno; i = static_cast<int>(strtol(dno.c_str(), &end, 16));i = static_cast<int>(strtol(dno.c_str(), &end, 10)); 
	switch (i){case 1:dname = "策划部"; break;case 2:dname = "人事部"; break;case 3:dname = "外联部"; break;
	default:cout << "输入的部门编号不存在，修改失败：" << endl << endl; xiugai(); break;
	}sqlstr = "UPDATE tb_information SET dno='" + dno + "',dname='" + dname + "' WHERE id='" + id + "';"; break;

	case 5:cout << "请输入新职位: "; cin >> pname;  if (pname != "经理"&&pname != "员工")
	{
		cout << "输入的职位不存在，修改失败：" << endl; xiugai();
	}
		   else { sqlstr = "UPDATE tb_information SET pname='" + pname + "' WHERE id='" + id + "';"; } break;
	case 6:cout << "请输入新工资: "; cin >> salary; sqlstr = "UPDATE tb_information SET salary='" + salary + "' WHERE id='" + id + "';"; break;
	case 7:cout << "请输入新手机号: "; cin >> phone; sqlstr = "UPDATE tb_information SET phone='" + phone + "' WHERE id='" + id + "';"; break;
	}
	if (0 == mysql_query(&mydata, sqlstr.c_str()))
	{
		mysql_query(&mydata, sqlstr.c_str());

		//sqlstr = "update ckbook set ckbook.stock = ckbook.stock - (select num from outputckbook where isbn = '" + isbn + "') where isbn = '" + isbn + "';";
		//mysql_query(&mydata, sqlstr.c_str());
		//sqlstr = "SELECT bookname 书名,isbn ISBN,price 单价,num 数量,allprice 总价 FROM outputckbook WHERE isbn='" + isbn + "';";

		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "修改信息成功" << endl;
		}
		else {
			cout << "修改信息失败" << endl;
			mysql_close(&mydata);
			return;
		}
		quanju();
		cout << "1.继续修改职工信息" << endl;
		cout << "2.返回主菜单" << endl;
		cin >> b;
		switch (b)
		{
		case 1:xiugai(); break;
		case 2:system("cls"); guanli(); break;
		}

	}
}
void shanchu() 
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string id;
	int a;
	quanju();
	cout << "请输入要删除的职工的职工号：";
	cin >> id;
	sqlstr = "DELETE FROM tb_information WHERE id='" + id + "  ';";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败！" << endl;
		cout << mysql_error(&mydata) << endl;
		mysql_close(&mydata);
	}
	cout << endl;
	quanju();
	cout << "1.继续删除职工信息" << endl;
	cout << "2.返回主菜单" << endl;
	cin >> a;
	switch (a)
	{
	case 1:shanchu(); break;
	case 2:system("cls"); guanli(); break;
	}

}