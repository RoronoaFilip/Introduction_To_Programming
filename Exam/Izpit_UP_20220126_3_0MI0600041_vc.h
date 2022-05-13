#pragma once
// Filip Filchev - 0MI0600041

//task 1
int numLen(long num) {
	int len = 0;
	while (num != 0) {
		++len;
		num /= 10;
	}
	return len;
}
long newNum(long num) {

	int lenght = numLen(num);
	const int SIZE = 50;
	int nums[SIZE] = {};
	int index = lenght - 1;

	int i = lenght - 1;
	while (num != 0) {
		int temp = num % 10;
		if (temp % 2 == 0) {
			nums[i] = temp;
			--i;
		}
		num /= 10;
	}

	long finalNum = 0;
	int j = 0;
	for (int i = 0; i < lenght; ++i) {
		finalNum = finalNum * 10 + nums[j];
		++j;
	}
	return finalNum;
}

//task 2
int* mergeArr(int* arr1, int* arr2, int len) {
	int* result = new int[len];
	if (arr1 == nullptr || arr2 == nullptr || len <= 0) {
		result[0] = -1;
		return result;
	}
	for (int i = 0; i < len; ++i) {
		result[i] = 0;
	}
	int index = 0;

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (arr2[j] > arr1[i] && j < len) {
				result[index] = j;
				++index;
				break;
			}
			else if (j + 1 == len) {
				result[index] = -1;
				++index;
				break;
			}
		}
	}

	return result;
}

//task 3
char* getWord(char* str, int k) {
	int len = 0;
	char* result = new char[50];
	int index = 0;
	if (str == nullptr) {
		return result;
	}
	for (int i = 0; str[i] != '\0'; ++i) {
		++len;
	}


	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ' ' && (str[i - 1] == ' ' || str[i - 1] == '\t')) {
			continue;
		}if (str[i] == '\t' && (str[i - 1] == '\t' || str[i - 1] == ' ')) {
			continue;
		}
		result[index] = str[i];
		++index;
	}

	result[index] = '\0';


	int countWords = 0;
	int neededIndex = 0;

	for (int i = 0; result[i] != '\0'; ++i) {
		if (result[i] == ' ') {
			++countWords;
		}
		else if (result[i] == '\t') {
			++countWords;
		}
	}
	++countWords;

	char* word = new char[50];
	char word1[14] = "Wrong Number!";
	if (countWords < k) {
		for (int i = 0; word1[i] != '\0'; ++i) {
			word[i] = word1[i];
		}
		word[13] = '\0';
		return word;
	}

	int wordNum = 1;
	for (int i = 0; result[i] != '\0'; ++i) {
		if (result[i] == ' ') {
			++wordNum;
		}
		else if (result[i] == '\t') {
			++wordNum;
		}
		if (wordNum == k) {
			neededIndex = ++i;
			break;
		}
	}


	int lenght = 0;
	int index2 = 0;

	for (int i = neededIndex; result[i] != '\0'; ++i) {
		if (result[i] == ' ') {
			break;
		}if (result[i] == '\t') {
			break;
		}
		word[index2] = result[i];
		++lenght;
		++index2;
	}

	int diff = 'a' - 'A';
	for (int i = 0; i < lenght; ++i) {
		if (word[i] >= 'a' && word[i] <= 'z') {
			word[i] -= diff;
			continue;
		}
		else if (word[i] >= 'A' && word[i] <= 'Z') {
			word[i] += diff;
			continue;
		}
	}
	word[lenght] = '\0';
	return word;
}