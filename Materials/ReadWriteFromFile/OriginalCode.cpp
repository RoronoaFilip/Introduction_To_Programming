#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<vector<string>> arr = {{"Todor", "Greek"}, {"Alexander", "Bulgarian"}};

    fstream file;
    file.open("text.csv", fstream::out);
    file << "name,nationality" << endl;
    for (auto &person : arr)
    {
        file << person[0] << "," << person[1] << endl;
    }

    file.close();

    file.open("text.csv", fstream::in);
    string buffer;
    getline(file, buffer);
    vector<vector<string>> dest;
    while (getline(file, buffer))
    {
        dest.push_back(vector<string>());
        int i = 0;
        for (; i < buffer.size() && buffer[i] != ','; ++i)
            ;
        dest.back().push_back(buffer.substr(0, i));
        dest.back().push_back(buffer.substr(i, buffer.size() - i));
    }
    cout << dest.size();
    for (auto &person : dest)
    {
        cout << person[0] << "," << person[1] << endl;
    }
    file.close();
    return 0;
}