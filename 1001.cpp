/*
������N�η�   7.1   by ChenZhuangyuan 
*/

//#include <iostream>
//#include <string>
//#include <sstream>
//#include <algorithm>
//using namespace std;
////��������
//string filterData(string base)
//{
//	while (base[0] == '0')   //ȥ��ǰ���0
//		base = base.substr(1);
//	if (base.find('.') != string::npos)  //ȥ��С��������0
//		while (base[base.length() - 1] == '0')
//			base = base.substr(0, base.length() - 1);
//	if (base[base.length() - 1] == '.')
//		base = base.substr(0, base.length() - 1);
//
//	return base;
//}
////�������
//string Add_result(string First_Num, string Second_Num)
//{
//	if (First_Num == "")
//		return Second_Num;
//	int start = 0;
//	int one = First_Num.length();
//	int two = Second_Num.length();
//
//	if (one <= two)
//		First_Num.insert(one, two - one, '0');
//	else
//		Second_Num.insert(two, one - two, '0');
//	int Index = 0;  //���ý���λ
//	int result;
//
//	while (start < First_Num.length())
//	{
//		one = First_Num[start] - '0';
//		two = Second_Num[start] - '0';
//		result = one + two + Index;
//		Index = result / 10;
//		First_Num[start] = result % 10 + '0';
//		start++;
//	}
//	if (Index > 0)
//		First_Num += Index + '0';
//
//	return First_Num;
//}
////�������
//string Mul_result(string First_Num, string Second_Num)
//{
//	/*��������*/
//	int len_one, len_two;
//	string new_First_Num = First_Num;
//	string new_Second_Num = Second_Num;
//	string::size_type  it_one = First_Num.find('.');   //����С�����λ��
//	int d_point = 0;   //ͳ�ƽ��С����λ��
//	if (it_one != string::npos)
//	{
//		new_First_Num = First_Num.substr(0, it_one) + First_Num.substr(it_one + 1);
//		d_point = First_Num.length() - it_one - 1;
//	}
//	string::size_type it_two = Second_Num.find('.');
//	if (it_two != string::npos)
//	{
//		new_Second_Num = Second_Num.substr(0, it_two) + Second_Num.substr(it_two + 1);
//		d_point += Second_Num.length() - it_two - 1;
//	}
//	string Result = "";   //�洢���
//	string Result_temp;   //�洢ÿһ���Ľ��
//	string Result_temp_c;   //�洢ÿһ���Ľ�����м���
//	len_one = new_First_Num.length();
//	len_two = new_Second_Num.length();
//
//	for (int i = len_two - 1; i >= 0; --i)
//	{	
//		Result_temp = "";  //����
//		int two = new_Second_Num[i] - '0';
//		int start_one = len_two - 1 - i;   //��һ����ʼλ��
//		for (int j = len_one - 1; j >= 0; --j)
//		{	
//			Result_temp_c = "";
//			int start_two = len_one - 1 - j;  //�ڶ�����ʼλ��
//			Result_temp_c.insert(0, start_one + start_two, '0');   //��0
//			int one = new_First_Num[j] - '0';
//			int result = one * two;
//			if (result >= 10)
//			{
//				Result_temp_c += result % 10 + '0';
//				Result_temp_c += result / 10 + '0';
//			}
//			else
//				Result_temp_c += (result + '0');
//			Result_temp = Add_result(Result_temp, Result_temp_c);
//		}	
//		Result = Add_result(Result, Result_temp);
//	}
//	
//	if (d_point == 0)   //����
//	{
//		reverse(Result.begin(), Result.end());   //��������˳��
//		return Result;
//	}
//	while (Result[0] == '0')   //���С��������0
//		Result = Result.substr(1);
//	reverse(Result.begin(), Result.end());   //��������˳��
//	if (d_point > Result.length())
//	{
//		Result.insert(0, d_point - Result.length(), '0');
//		Result = "." + Result;   //��ȷ��ʾ��ʽ
//	}
//	else
//		Result.insert(Result.length() - d_point, 1, '.');
//
//	return Result;
//}
//
//int main()
//{
//	string str_Num;
//	int index;   //ָ��
//	string base;  //����
//	while (getline(cin, str_Num))
//	{
//		stringstream word_num(str_Num);
//		word_num >> base >> index;
//		base = filterData(base);
//		if (index == 1)
//			cout << base << endl;
//		else
//		{
//			string init_base = base;
//			for (int i = 2; i <= index; ++i)
//			{
//				base = Mul_result(base, init_base);
//				base = filterData(base);
//			}
//			cout << base << endl;
//		}
//	}
//	
//	system("pause");
//	return 0;
//}