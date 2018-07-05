/*
����绰����  7.3 by ChenZhuangyuan
*/

#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

map<string, int> Map_Phone;
stack<string> input_Phone;
string key = "ABCDEFGHIJKLMNOPRSTUVWXY";   //�༭ӳ��
string value = "222333444555666777888999";

inline string map_num(string str_Phone)
{	
	string Map_Num = "";
	string::size_type it;
	
	for (int i = 0; i < str_Phone.length(); ++i)   //���������
	{
		if (str_Phone[i] == '-' || str_Phone[i] == 'Q' || str_Phone[i] == 'Z')
			continue;
		it = key.find(str_Phone[i]);
		if (it != string::npos)
			Map_Num += value[it];
		else
			Map_Num += str_Phone[i];
	}
	Map_Num.insert(3, 1, '-');   //��׼������
	return Map_Num;
}

int main()
{
	int N;   //Ŀ¼�е绰���������
	cin >> N;
	string str_Phone;
	while (N-- > 0)
	{
		cin >> str_Phone;
		input_Phone.push(str_Phone);
	}
	map<string, int>::iterator it;
	while (!input_Phone.empty())
	{
		it = Map_Phone.find(input_Phone.top());
		if (it != Map_Phone.end())  //���ҵ������Ѿ�����
			it->second += 1;
		else
		{
			str_Phone = map_num(input_Phone.top());   //��ȡת�����׼�ĺ���	
			it = Map_Phone.find(str_Phone);
			if (it != Map_Phone.end())  //���ҵ������Ѿ�����
				it->second += 1;
			else
				Map_Phone.insert(pair<string, int>(str_Phone, 1));   //�����µ�Ԫ��
		}
		input_Phone.pop();
	}
 	bool flag = false;
	for (it = Map_Phone.begin(); it != Map_Phone.end(); ++it)
		if (it->second > 1)
		{
			cout << it->first << " " << it->second << endl;
			flag = true;
		}
	if (flag == false)
		cout << "No duplicates" << endl;

	system("pause");
	return 0;
}