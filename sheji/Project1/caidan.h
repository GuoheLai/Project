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
	cout << "�������û�����" << endl;
	cin >> id;
	cout << "���������룺" << endl;
	cin >> pw;
	string sqlstr;
	sqlstr = "SELECT * FROM tb_user WHERE Uname='" + id + "' and password='" + pw + "';";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		//cout << "��ɲ�ѯ" << endl;
		result = mysql_store_result(&mydata);
		if (mysql_num_rows(result))
		{ //mysql_num_rows�õ���Ӱ�������
			mysql_free_result(result); //�ͷŽ����
			//�õ��û��Ľ�ɫ��Ϣ
			sqlstr = "select power  from tb_user where Uname='" + id + "';";
			mysql_query(&mydata, sqlstr.c_str());
			result = mysql_store_result(&mydata);//����ѯ���Ľ�������������ŵ�result��ȥ
			MYSQL_ROW row = mysql_fetch_row(result); //row[0]��Ϊ�û���ɫ���
			if (!(strcmp(row[0], "1"))) {
				system("cls");
				cout << "****** " << " ϵͳ����Ա��ӭ����" << "**********" << endl;
				guanli(); return 0;
			}
			else if (!(strcmp(row[0], "2"))) {
				system("cls");
				cout << "************ " << " ��ӭʹ��ְ����Ϣ��ѯϵͳ" << "**********" << endl;
				chaxun(); return 0;
			}
		}
		else {
			system("cls");
			cout << "�û����������������" << endl;
			return selectuser();
		}

	}
	return 0;
}

void guanli()
{
	int a;
	cout << "1.��ѯ��Ϣ" << endl;
	cout << "2.�����µ�ְ����Ϣ" << endl;
	cout << "3.�޸�ְ����Ϣ" << endl;
	cout << "4.ɾ��ְ����Ϣ" << endl;
	cout << "5.�˳���¼" << endl;
	cout << "6.�˳�ϵͳ" << endl;
	cout << "��ѡ����Ҫ���еĲ���:"; cin >> a;
	switch (a)
	{
	case 1:chaxun1(); break;
		case 2:zengjia(); break;
			case 3:xiugai(); break;
				case 4:shanchu(); break;
				case 5:system("cls"); selectuser(); return;
	case 6: exit(0);
	default: cout << "�밴��ʾ����" << endl; guanli(); break;
	}
}
void chaxun1()
{
	int n;
	cout << "1.��ѯ������Ϣ��" << endl;
	cout << "2.��ѯְλ��Ϣ��" << endl;
	cout << "3.��ѯȫ��ְ����Ϣ��" << endl;
	cout << "4.����������ְ����Ϣ" << endl;
	cout << "5.������һ��" << endl;
	cout << "��ѡ����Ҫ���еĲ���:";
	cin >> n;
	switch (n)
	{
	case 1: bumen(); chabu1(); break;
	case 2:zhiwei(); chazhi1(); break;
	case 3:quanju(); chaxun1(); break;
	case 4:tiaojian1(); break;
	case 5:system("cls"); guanli(); break;
	default: cout << "�밴��ʾ����"<< endl; chaxun1(); break;
	}
}
void chazhi1()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "������Ҫ��ѯ�ĸ�ְλ��Ա��Ϣ��" << endl;
	cout << "1.����2.Ա����3ȫ��ְ����4.����" << endl;
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
		sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE Pname='����';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//һ����ȡ�����ݼ�  
			result = mysql_store_result(&mydata);
			//ȡ�ò���ӡ����  
			/*int rowcount = mysql_num_rows(result);
			cout << "���ݿ��й���: " << rowcount << "��Ŀ" << endl;*/

			//ȡ�ò���ӡ���ֶε�����  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//��ӡ����  
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
		sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE Pname='Ա��';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//һ����ȡ�����ݼ�  
			result = mysql_store_result(&mydata);
			//ȡ�ò���ӡ����  
			/*int rowcount = mysql_num_rows(result);
			cout << "���ݿ��й���: " << rowcount << "��Ŀ" << endl;*/

			//ȡ�ò���ӡ���ֶε�����  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//��ӡ����  
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
		cout << "�밴Ҫ�����룺" << endl;
	}
	chazhi1();
}
void chabu1() {
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "������Ҫ��ѯ�ĸ�������Ա����Ϣ��" << endl;
	cout << "��1.�߻�����2.���²���3.��������4.���в��ţ�5.���أ�";
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
		sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE Dno='" + bm + "';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//һ����ȡ�����ݼ�  
			result = mysql_store_result(&mydata);
			//ȡ�ò���ӡ����  
			int rowcount = mysql_num_rows(result);
			if (rowcount == 0) { cout << "��Ч�Ĳ��ű�ţ�����������" << endl; chabu1(); }

			//ȡ�ò���ӡ���ֶε�����  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//��ӡ����  
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
			cout << "�ò��Ų�����" << endl;
		}
	}
	chabu1();
}
void tiaojian1()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm,id,name,sex;
	cout << "1.��ְ���Ų��ң�" << endl;
	cout << "2.�����ֲ��ң�"<<endl;
	cout << "3.���Ա���ң�" << endl;
	cout << "4.����" << endl;
	cin >> bm;
	system("cls");
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	switch (i) {
	case 1: quanju(); cout << endl<< endl<< "������ְ���ţ�"; cin >> id; sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE id='" + id + "';"; break;
	case 2: quanju(); cout  << endl << endl << "������������"; cin >> name; sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE name='" + name + "';"; break;
	case 3: quanju(); cout << endl << endl << "�������Ա���/Ů����"; cin >> sex; sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE sex='" + sex + "';"; break;
	case 4: chaxun1(); return;
	default: cout << "�밴��ʾ����" << endl; tiaojian1(); break;
	}
	
		
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "��ɲ�ѯ" << endl;
			//һ����ȡ�����ݼ�  
			result = mysql_store_result(&mydata);
			//ȡ�ò���ӡ����  
			int rowcount = mysql_num_rows(result);
			if (rowcount == 0) { cout << "δ�����ݿ����ҵ�"; cout << endl << endl; tiaojian1(); return;};
			cout << "���ݿ��й�����: " << rowcount << "����ѯ���" << endl;

			//ȡ�ò���ӡ���ֶε�����  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//��ӡ����  
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
			cout << "δ�����ݿ����ҵ�" << endl;
		}
	tiaojian1();
}

void chaxun()
{
	int n;
	cout << "1.��ѯ������Ϣ��" << endl;
	cout << "2.��ѯְλ��Ϣ��" << endl;
	cout << "3.��ѯȫ��ְ����Ϣ��" << endl;
	cout << "4.����������ְ����Ϣ" << endl;
	cout << "5.�˳���¼" << endl;
	cout << "6.�˳�ϵͳ" << endl;
	cout << "��ѡ����Ҫ���еĲ���:";
	cin >> n;
	switch (n)
	{
	case 1:bumen(); chabu(); break;
	case 2:zhiwei(); chazhi(); break;
	case 3:quanju(); chaxun(); break;
	case 4:tiaojian(); break;
	case 5:system("cls"); selectuser();return;
	case 6:exit(0);
	default: cout << "�밴��ʾ����" << endl; chaxun(); break;
	}
	/*int n;
	cout << "*****1.��ѯ������Ϣ*****" << endl;
	cout << "*****2.��ѯ����ְλ��Ϣ*****" << endl;
	cout << "*****3.��ѯȫ��ְ����Ϣ*****" << endl;
	cout << "*****4.�˳�ϵͳ*****" << endl;
	cout << "��ѡ����Ҫ���еĲ���:";
	cin >> n;
	switch (n)
	{
	case 1: bumen(); break;
	case 2:zhiwei(); break;
	case 3:quanju(); break;
	case 4:cout << "���ѳɹ��˳�ϵͳ" << endl << endl; break;
	default: break;
	}*/
}
void zhiwei()
{
	int a;
	MYSQL_RES *result = NULL;
	string sqlstr;
	sqlstr = "SELECT  pno ְλ�ȼ�,pname ְλ�� FROM tb_post";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "��ɲ�ѯ" << endl;

		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&mydata);
		//ȡ�ò���ӡ����  
		int rowcount = mysql_num_rows(result);
		cout << "���ݿ��й���: " << rowcount << "��ְλ" << endl;

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%10s\t\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//��ӡ����  
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
		cout << "��ѯʧ��" << endl;
		mysql_close(&mydata);

	}
}
void chazhi()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "������Ҫ��ѯ�ĸ�ְλ��Ա��Ϣ��" << endl;
	cout << "1.����2.Ա����3ȫ��ְ����4.����" << endl;
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
		sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE pname='����';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "��ɲ�ѯ" << endl;
			//һ����ȡ�����ݼ�  
			result = mysql_store_result(&mydata);
			//ȡ�ò���ӡ����  
			/*int rowcount = mysql_num_rows(result);
			cout << "���ݿ��й���: " << rowcount << "��Ŀ" << endl;*/

			//ȡ�ò���ӡ���ֶε�����  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//��ӡ����  
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
		sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE pname='Ա��';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "��ɲ�ѯ" << endl;
			//һ����ȡ�����ݼ�  
			result = mysql_store_result(&mydata);
			//ȡ�ò���ӡ����  
			/*int rowcount = mysql_num_rows(result);
			cout << "���ݿ��й���: " << rowcount << "��Ŀ" << endl;*/

			//ȡ�ò���ӡ���ֶε�����  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//��ӡ����  
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
		cout << "�밴Ҫ�����룺" << endl;
	}
	chazhi();
}
void quanju() {
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "��ɲ�ѯ" << endl;
		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&mydata);
		//ȡ�ò���ӡ����  
		int rowcount = mysql_num_rows(result);
		if (rowcount == 0) { cout << "��Ч�Ĳ��ű�ţ�����������"<< endl; chabu(); }

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%8s\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//��ӡ����  
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
		cout << "������" << endl;
	}
}
void bumen()
{
	int a;
	MYSQL_RES *result = NULL;
	string sqlstr;
	sqlstr = "SELECT  Dno ���ű��,Dname �������� FROM tb_department";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "��ɲ�ѯ" << endl;

		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&mydata);
		//ȡ�ò���ӡ����  
		int rowcount = mysql_num_rows(result);
		cout << "���ݿ��й���: " << rowcount << "������" << endl;

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%10s\t\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//��ӡ����  
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
		cout << "��ѯʧ��" << endl;
		mysql_close(&mydata);

	}
}
void chabu() {
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm;
	cout << "������Ҫ��ѯ�ĸ�������Ա����Ϣ��" << endl;
	cout << "��1.�߻�����2.���²���3.��������4.���в��ţ�5.���أ�";
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
		sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE Dno='" + bm + "';";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			//һ����ȡ�����ݼ�  
			result = mysql_store_result(&mydata);
			//ȡ�ò���ӡ����  
			int rowcount = mysql_num_rows(result);
			if (rowcount == 0) { cout << "��Ч�Ĳ��ű�ţ�����������" << endl; chabu(); }

			//ȡ�ò���ӡ���ֶε�����  
			unsigned int fieldcount = mysql_num_fields(result);
			MYSQL_FIELD *field = NULL;
			for (unsigned int i = 0; i < fieldcount; i++) {
				field = mysql_fetch_field_direct(result, i);
				printf("%8s\t", field->name);
				//cout << field->name << "\t\t\t\t";
			}
			cout << endl;
			//��ӡ����  
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
			cout << "�ò��Ų�����" << endl;
		}
	}
	chabu();
}
void tiaojian()
{
	MYSQL_RES *result = NULL;
	string sqlstr;
	string bm, id, name, sex;
	cout << "1.��ְ���Ų��ң�" << endl;
	cout << "2.�����ֲ��ң�" << endl;
	cout << "3.���Ա���ң�" << endl;
	cout << "4.����" << endl;
	cin >> bm;
	system("cls");
	char* end;
	int i = static_cast<int>(strtol(bm.c_str(), &end, 16));
	i = static_cast<int>(strtol(bm.c_str(), &end, 10));
	switch (i) {
	case 1: quanju(); cout << endl << endl << "������ְ���ţ�"; cin >> id; sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE id='" + id + "';"; break;
	case 2: quanju(); cout << endl << endl << "������������"; cin >> name; sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE name='" + name + "';"; break;
	case 3: quanju(); cout << endl << endl << "�������Ա���/Ů����"; cin >> sex; sqlstr = "SELECT id ְ����,name ����,sex �Ա�,Dno ���ű��,Dname ����,Pname ְλ,salary ����,phone �绰 FROM tb_information WHERE sex='" + sex + "';"; break;
	case 4: chaxun(); return;
	default: cout << "�밴��ʾ����" << endl; tiaojian(); break;
	}


	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		//һ����ȡ�����ݼ�  
		result = mysql_store_result(&mydata);
		//ȡ�ò���ӡ����  
		int rowcount = mysql_num_rows(result);
		if (rowcount == 0) { cout << "δ�����ݿ����ҵ�" << endl << endl; tiaojian(); return; };
		cout << "���ݿ��й�����: " << rowcount << "����ѯ���" << endl;

		//ȡ�ò���ӡ���ֶε�����  
		unsigned int fieldcount = mysql_num_fields(result);
		MYSQL_FIELD *field = NULL;
		for (unsigned int i = 0; i < fieldcount; i++) {
			field = mysql_fetch_field_direct(result, i);
			printf("%8s\t", field->name);
			//cout << field->name << "\t\t\t\t";
		}
		cout << endl;
		//��ӡ����  
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
		cout << "δ�����ݿ����ҵ�" << endl;
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
	cout << "***************�����µ�ְ����Ϣ*****************" << endl;
	cout << "������������ְ����ְ���ţ����֣��Ա𣬲��ű�ţ�ְλ�����ʣ��ֻ��ţ�" << endl;
	cin >> id >> name >> sex >> dno >> pname >> salary >> phone;
	i = static_cast<int>(strtol(dno.c_str(), &end, 16));
	i = static_cast<int>(strtol(dno.c_str(), &end, 10));
	
	switch (i)
	{
	case 1:dname = "�߻���"; break;
	case 2:dname = "���²�"; break;
	case 3:dname = "������"; break;
	default:cout << "����Ĳ��ű�Ų����ڣ����������룺"<<endl << endl; zengjia(); break;
	}
	if(pname!="����"&&pname!= "Ա��")
	{
		cout << "�����ְλ�����ڣ����������룺" << endl;zengjia();
	}
	else {
		sqlstr = "insert into tb_information(id, name,sex,dno,dname,pname,salary,phone) VALUES('" + id + "','" + name + "','" + sex + "','" + dno + "','" + dname + "','" + pname + "','" + salary + "','" + phone + "');";
		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "����ְ����Ϣ�ɹ���" << endl;
		}
		else {
			cout << "ְ����Ϣ����ʧ�ܣ�" << endl;
			cout << mysql_error(&mydata) << endl;
			mysql_close(&mydata);
		}
		quanju();
		cout << endl;
		cout << "1.�������ְ����Ϣ" << endl;
		cout << "2.�������˵�" << endl;
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
	cout << "��������Ҫ�޸ĵ�ְ����ְ���ţ�"; cin >> id; 
	cout << "1.ְ���ţ�2.���֣�3.�Ա�4.���ţ�5.ְλ��6.���ʣ�7.�ֻ���" << endl;
	cout << "��ѡ����Ҫ�޸ĸ�ְ��������Ϣ:"<<endl;
	cin >> a;
	switch (a)
	{
	case 1:cout << "��������ְ����: "; cin >> id1; sqlstr = "UPDATE tb_information SET id='" + id1 + "' WHERE id='" + id + "';"; break;
	case 2:cout << "������������: "; cin >> name; sqlstr = "UPDATE tb_information SET name='" + name + "' WHERE id='" + id + "';"; break;
	case 3:cout << "���������Ա�: "; cin >> sex; if (sex!= "��" && sex!= "Ů")
	{cout << "�Ա����������޸�ʧ�ܣ�" << endl; xiugai();}
		  else { sqlstr = "UPDATE tb_information SET sex='" + sex + "' WHERE id='" + id + "';"; } break;
	case 4:cout << "�������²��ŵı�� "; cin >> dno; i = static_cast<int>(strtol(dno.c_str(), &end, 16));i = static_cast<int>(strtol(dno.c_str(), &end, 10)); 
	switch (i){case 1:dname = "�߻���"; break;case 2:dname = "���²�"; break;case 3:dname = "������"; break;
	default:cout << "����Ĳ��ű�Ų����ڣ��޸�ʧ�ܣ�" << endl << endl; xiugai(); break;
	}sqlstr = "UPDATE tb_information SET dno='" + dno + "',dname='" + dname + "' WHERE id='" + id + "';"; break;

	case 5:cout << "��������ְλ: "; cin >> pname;  if (pname != "����"&&pname != "Ա��")
	{
		cout << "�����ְλ�����ڣ��޸�ʧ�ܣ�" << endl; xiugai();
	}
		   else { sqlstr = "UPDATE tb_information SET pname='" + pname + "' WHERE id='" + id + "';"; } break;
	case 6:cout << "�������¹���: "; cin >> salary; sqlstr = "UPDATE tb_information SET salary='" + salary + "' WHERE id='" + id + "';"; break;
	case 7:cout << "���������ֻ���: "; cin >> phone; sqlstr = "UPDATE tb_information SET phone='" + phone + "' WHERE id='" + id + "';"; break;
	}
	if (0 == mysql_query(&mydata, sqlstr.c_str()))
	{
		mysql_query(&mydata, sqlstr.c_str());

		//sqlstr = "update ckbook set ckbook.stock = ckbook.stock - (select num from outputckbook where isbn = '" + isbn + "') where isbn = '" + isbn + "';";
		//mysql_query(&mydata, sqlstr.c_str());
		//sqlstr = "SELECT bookname ����,isbn ISBN,price ����,num ����,allprice �ܼ� FROM outputckbook WHERE isbn='" + isbn + "';";

		if (0 == mysql_query(&mydata, sqlstr.c_str())) {
			cout << "�޸���Ϣ�ɹ�" << endl;
		}
		else {
			cout << "�޸���Ϣʧ��" << endl;
			mysql_close(&mydata);
			return;
		}
		quanju();
		cout << "1.�����޸�ְ����Ϣ" << endl;
		cout << "2.�������˵�" << endl;
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
	cout << "������Ҫɾ����ְ����ְ���ţ�";
	cin >> id;
	sqlstr = "DELETE FROM tb_information WHERE id='" + id + "  ';";
	if (0 == mysql_query(&mydata, sqlstr.c_str())) {
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ�" << endl;
		cout << mysql_error(&mydata) << endl;
		mysql_close(&mydata);
	}
	cout << endl;
	quanju();
	cout << "1.����ɾ��ְ����Ϣ" << endl;
	cout << "2.�������˵�" << endl;
	cin >> a;
	switch (a)
	{
	case 1:shanchu(); break;
	case 2:system("cls"); guanli(); break;
	}

}