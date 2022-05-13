// Filip Filchev 0MI0600041
#include <iostream>
using namespace std;
int main()
{
	const int size = 50;
	char word[size];
	cin.getline(word, 50);
	int k;
	cin >> k;
	if (k == 0)
	{
		return 0;
	}
	if (k < 0)
	{
		cout << -1;
		return 0;
	}
	int spaceCount = 0;
	for (int i = 0; i < size; ++i) //	for (int i = 0; word[i] != '\0'; ++i)
	{
		char letter = word[i];
		if (letter == 32)
		{
			spaceCount++;
		}
	}
	if (spaceCount < k - 1)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < size; ++i) // for(int i=0; word[i] != '\0'; ++i)
	{
		char letter = word[i];
		cout << letter;
		if (letter == 32)
		{
			--k;
		}
		if (k == 0)
		{
			return 0;
		}
	}
	return 0;
}