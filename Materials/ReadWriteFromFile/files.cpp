#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string nameNationality;
	fstream file;
	getline(cin, nameNationality);

	if (nameNationality == "clear")
	{
		file.open("text.csv", fstream::out | fstream::trunc);
		file << "name,nationality" << endl;
		file.close();
		return main();
	}

	if (nameNationality == "add")
	{
		file.open("text.csv", fstream::app);
		while (getline(cin, nameNationality))
		{
			if (nameNationality == "stop")
			{
				break;
			}
			file << nameNationality << endl;
		}
		file.close();

		return main();
	}

	if (nameNationality == "exit")
	{
		return 0;
	}

	if (nameNationality == "print")
	{
		cout << endl;
		file.open("text.csv", fstream::in);

		string buffer;
		getline(file, buffer);

		vector<vector<string>> dest;
		while (getline(file, buffer))
		{
			dest.push_back(vector<string>());

			int i = 0;
			for (; i < buffer.size() && buffer[i] != ','; ++i);

			dest.back().push_back(buffer.substr(0, i));
			dest.back().push_back(buffer.substr(i + 1, buffer.size() - i));
		}

		for (auto &person : dest)
		{
			cout << person[0] << "," << person[1] << endl;
		}

		file.close();
		return main();
	}
}