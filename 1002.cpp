/*
翻译电话号码  7.3 by ChenZhuangyuan
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> Map_Phone;
string key = "ABCDEFGHIJKLMNOPRSTUVWXY";   //编辑映射
string value = "222333444555666777888999";

int main()
{
	int N;   //目录中电话号码的总数
	cin >> N;
	string str_Phone;
	string Map_Num;
	string::size_type str_it;
	map<string, int>::iterator it;

	while (N-- > 0)
	{
		cin >> str_Phone;
		Map_Num = "";
		for (int i = 0; i < str_Phone.length(); ++i)   //依次替代掉
		{
			if (str_Phone[i] == '-' || str_Phone[i] == 'Q' || str_Phone[i] == 'Z')
				continue;
			str_it = key.find(str_Phone[i]);
			if (str_it != string::npos)
				Map_Num += value[str_it];
			else
				Map_Num += str_Phone[i];
		}
		Map_Num.insert(3, 1, '-');   //标准化数据
		it = Map_Phone.find(Map_Num);
		if (it != Map_Phone.end())  //查找到，即已经存在
			it->second += 1;
		else
			Map_Phone.insert(pair<string, int>(Map_Num, 1));   //增加新的元素
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