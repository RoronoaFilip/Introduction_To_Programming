#pragma once
bool isAllUpper(char word[], int index) {
	for (int i = index; word[i] != '\0'; ++i) {
		if (word[i] == ' ') {
			break;
		}
		if (word[i] < 'A' || word[i]>'Z') {
			return false;
		}
	}
	return true;
}
bool isAllLower(char word[], int index) {

	for (int i = index; word[i] != '\0'; ++i) {
		if (word[i] == ' ') {
			break;
		}
		if (word[i] < 'a' || word[i]>'z') {
			return false;
		}
	}
	return true;
}
int* cntWords(char word[]) {
	int countUpper = 0;
	int countLower = 0;

	for (int i = 0; word[i] != '\0'; ++i) {
		if (word[i] >= 'a' && word[i] <= 'z') {
			if (isAllLower(word, i)) {
				++countLower;
			}
		}
		else if (word[i] >= 'A' && word[i] <= 'Z') {
			if (isAllUpper(word, i)) {
				++countUpper;
			}
		}
		while (word[i] != ' ') {
			++i;
			if (word[i] == '\0') {
				break;
			}
		}
	}

	int* result = new int[2];
	result[0] = countLower;
	result[1] = countUpper;
	return result;
}

long convertNumber(char* num) {
	int index = 0;
	for (int i = 0; num[i] != '\0'; ++i) {
		++index;
	}
	if (index < 3) {
		return -1;
	}

	for (int i = 0; i < index; ++i) {
		for (int j = i + 1; j < index; ++j) {
			if (num[i] <= num[j]) {
				int swap = num[i];
				num[i] = num[j];
				num[j] = swap;
			}
		}
	}

	return num[0] + num[1] + num[2];
}

void convertMax(int* nums, int N) {
	int max = nums[0];
	int neededIndex = 0;

	for (int i = 0; i < N; ++i) {
		if (max < nums[i]) {
			max = nums[i];
			neededIndex = i;
		}
	}

	neededIndex = N - 1 - neededIndex;
	int index = N - 1;

	for (int i = 0; i < N / 2; ++i) {
		int swap = nums[i];
		nums[i] = nums[index];
		nums[index] = swap;
		--index;
	}

	for (int i = 0; i < N; ++i) {
		if (i == neededIndex) {
			continue;
		}
		nums[i] += max;
	}

	return;
}

int CheckStr(char word[]) {
	int count = 0;
	int len = 0;
	for (int i = 0; word[i] != '\0'; ++i) {
		++len;
	}
	if (word == nullptr || len < 2) {
		return -1;
	}

	for (int i = 0; word[i] != '\0'; ++i) {
		bool isTrue = false;
		if (word[i] == ' ') {
			continue;
		}
		for (int j = i + 1; word[j] != '\0'; ++j) {
			if (word[i] == word[j] && word[j] != ' ' && word[i] != ' ') {
				isTrue = true;
				word[i] = ' ';
				word[j] = ' ';
				break;
			}
		}
		if (!isTrue) {
			++count;
		}
	}
	return count <= 1 ? 1 : 0;
}