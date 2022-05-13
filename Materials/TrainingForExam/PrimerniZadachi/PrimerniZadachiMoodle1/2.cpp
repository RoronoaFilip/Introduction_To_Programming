#include <iostream>
using namespace std;

//Да се напише функция на C++, която приема като параметри две отсечки в декартовата координатна система.
// За представянето на отсечка, използвайте създадена от вас структура (struct, запис). Функцията да върне
// дължината на общата им част, ако отсечките лежат на права, успоредна на една от координатните оси или
// -1 в противен случай.
struct Line {
    int x1;
    int x2;
    int y1;
    int y2;
};
int returnLenght(Line line1, Line line2) {
    if (line1.y1 != line1.y2 && line1.x1 != line1.x2) {
        return -1;
    }
    if (line2.y1 != line2.y2 && line2.x1 != line2.x2) {
        return -1;
    }
    // --------
    //   ---------
    if (line1.x1 < line2.x1 && line1.x2 < line2.x2) {
        return line1.x2 - line2.x1;
    }
    //    ----------
    //  ----------
    if (line2.x1 < line1.x1 && line2.x2 < line1.x2) {
        return line2.x2 - line1.x1;
    }
    //     ----------
    //  ---------------------
    if (line2.x1 < line1.x1 && line2.x2 > line1.x2) {
        return line1.x2 - line1.x1;
    }
    //  ----------------
    //    ---------
    if (line1.x1 < line2.x1 && line1.x2 > line2.x2) {
        return line2.x2 - line2.x1;
    }

    //====================================================================

    // --------
    //   --------
    if (line1.y1 < line2.y1 && line1.y2 < line2.y2) {
        return line1.y2 - line2.y1;
    }
    //    ----------
    //  ----------
    if (line2.y1 < line1.y1 && line2.y2 < line1.y2) {
        return line2.y2 - line1.y1;
    }
    //     ----------
    //  ---------------------
    if (line2.y1 < line1.y1 && line2.y2 > line1.y2) {
        return line1.y2 - line1.y1;
    }
    //  ----------------
    //    ---------
    if (line1.y1 < line2.y1 && line1.y2 > line2.y2) {
        return line2.y2 - line2.y1;
    }
    return -3;
}
int main() {
    Line line1;
    Line line2;
    line1.x1 = 0;
    line1.x2 = 0;
    line2.x1 = 0;
    line2.x2 = 0;
    line1.y1 = -6;
    line1.y2 = 80;
    line2.y1 = -5;
    line2.y2 = 9;
    cout << returnLenght(line1, line2);
    return 0;
}