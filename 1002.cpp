/*
����绰����  7.3 by ChenZhuangyuan
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> Map_Phone;
string key = "ABCDEFGHIJKLMNOPRSTUVWXY";   //�༭ӳ��
string value = "222333444555666777888999";

int main()
{
	int N;   //Ŀ¼�е绰���������
	cin >> N;
	string str_Phone;
	string Map_Num;
	string::size_type str_it;
	map<string, int>::iterator it;

	while (N-- > 0)
	{
		cin >> str_Phone;
		Map_Num = "";
		for (int i = 0; i < str_Phone.length(); ++i)   //���������
		{
			if (str_Phone[i] == '-' || str_Phone[i] == 'Q' || str_Phone[i] == 'Z')
				continue;
			str_it = key.find(str_Phone[i]);
			if (str_it != string::npos)
				Map_Num += value[str_it];
			else
				Map_Num += str_Phone[i];
		}
		Map_Num.insert(3, 1, '-');   //��׼������
		it = Map_Phone.find(Map_Num);
		if (it != Map_Phone.end())  //���ҵ������Ѿ�����
			it->second += 1;
		else
			Map_Phone.insert(pair<string, int>(Map_Num, 1));   //�����µ�Ԫ��
	}
	
 	bool flag = false;
	for (it = Map_Phone.begin(); it != Map_Phone.end(); ++it)
		if (it->second > 1)
		{
			cout << it->first << " " << it->second << endl;
			flag = true;
		}
	if (flag == false)
		cout << "No duplicates." << endl;

	system("pause");
	return 0;
}