#include "calendarmodel.h"

CalendarModel::CalendarModel(QObject *parent)
  : QObject(parent)
{
    QDate date = QDate::currentDate();
    int i, j, k;

    for(i=0; i<12; i++) {
        for(j=0; j<32; j++) {
            group[0][i][j] = false;
            group[1][i][j] = false;
            group[2][i][j] = false;
            group[3][i][j] = false;
            group[4][i][j] = false;
        }
    }

    for(k=0, i=1; i<=31; i++) { // 1
        k = (k+1)%3;
        group[k][0][i] = true;
        switch(i) {
        case 3: case 10: case 17: case 24: case 31:
        case 6: case 13: case 20: case 27:
            group[3][0][i] = true;
            group[4][0][i] = true;
            break;
        case 8: case 22:
            group[3][0][i] = true;
            break;
        case 15: case 29:
            group[4][0][i] = true;
            break;
        }
    }
    for(i=1; i<=29; i++) { // 2
        k = (k+1)%3;
        group[k][1][i] = true;
        switch(i) {
        case 3: case 10: case 17: case 24: //case 31:
        case 7: case 14: case 21: case 28:
//        case 6: case 13: case 20: case 27:
            group[3][1][i] = true;
            group[4][1][i] = true;
            break;
//        case 4: case 18:
        case 5: case 19:
//        case 8: case 15:
            group[3][1][i] = true;
            break;
        case 12: case 26:
//        case 11: case 25:
//        case 22: case 29:
            group[4][1][i] = true;
            break;
        }
    }
    for(i=1; i<=31; i++) { // 3
        k = (k+1)%3;
        group[k][2][i] = true;
        switch(i) {
        case 2: case 9: case 16: case 23: case 30:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 7: case 14: case 21: case 28:
        case 6: case 13: case 20: case 27:
            group[3][2][i] = true;
            group[4][2][i] = true;
            break;
        case 4: case 18:
//        case 5: case 19:
//        case 8: case 15:
            group[3][2][i] = true;
            break;
        case 11: case 25:
//        case 12: case 26:
//        case 22: case 29:
            group[4][2][i] = true;
            break;
        }
    }
    for(i=1; i<=30; i++) { // 4
        k = (k+1)%3;
        group[k][3][i] = true;
        switch(i) {
//        case 2: case 9: case 16: case 23: case 30:
        case 3: case 10: case 17: case 24: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 7: case 14: case 21: case 28:
        case 6: case 13: case 20: case 27:
            group[3][3][i] = true;
            group[4][3][i] = true;
            break;
//        case 4: case 18:
//        case 5: case 19:
        case 8: case 22:
            group[3][3][i] = true;
            break;
//        case 11: case 25:
//        case 12: case 26:
        case 15: case 29:
            group[4][3][i] = true;
            break;
        }
    }
    for(i=1; i<=31; i++) { // 5
        k = (k+1)%3;
        group[k][4][i] = true;
        switch(i) {
        case 1: case 8: case 15: case 22: case 29:
//        case 2: case 9: case 16: case 23: case 30:
//        case 3: case 10: case 17: case 24: //case 31:
        case 4: case 11: case 18: case 25: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 7: case 14: case 21: case 28:
//        case 6: case 13: case 20: case 27:
            group[3][4][i] = true;
            group[4][4][i] = true;
            break;
//        case 4: case 18:
//        case 5: case 19:
        case 6: case 20:
//        case 8: case 22:
            group[3][4][i] = true;
            break;
//        case 11: case 25:
//        case 12: case 26:
        case 13: case 27:
//        case 15: case 29:
            group[4][4][i] = true;
            break;
        }
    }
    for(i=1; i<=30; i++) { // 6
        k = (k+1)%3;
        group[k][5][i] = true;
        switch(i) {
        case 1: case 8: case 15: case 22: case 29:
//        case 2: case 9: case 16: case 23: case 30:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 4: case 11: case 18: case 25: //case 31:
        case 5: case 12: case 19: case 26: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 7: case 14: case 21: case 28:
//        case 6: case 13: case 20: case 27:
            group[3][5][i] = true;
            group[4][5][i] = true;
            break;
        case 3: case 17:
//        case 4: case 18:
//        case 5: case 19:
//        case 6: case 20:
//        case 8: case 22:
            group[3][5][i] = true;
            break;
        case 10: case 24:
//        case 11: case 25:
//        case 12: case 26:
//        case 13: case 27:
//        case 15: case 29:
            group[4][5][i] = true;
            break;
        }
    }
    for(i=1; i<=31; i++) { // 7
        k = (k+1)%3;
        group[k][6][i] = true;
        switch(i) {
//        case 1: case 8: case 15: case 22: case 29:
//        case 2: case 9: case 16: case 23: case 30:
        case 3: case 10: case 17: case 24: case 31:
//        case 4: case 11: case 18: case 25: //case 31:
//        case 5: case 12: case 19: case 26: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 7: case 14: case 21: case 28:
        case 6: case 13: case 20: case 27:
            group[3][6][i] = true;
            group[4][6][i] = true;
            break;
//        case 3: case 17:
//        case 4: case 18:
//        case 5: case 19:
//        case 6: case 20:
        case 8: case 22:
            group[3][6][i] = true;
            break;
//        case 10: case 24:
//        case 11: case 25:
//        case 12: case 26:
//        case 13: case 27:
        case 15: case 29:
            group[4][6][i] = true;
            break;
        }
    }
    for(i=1; i<=31; i++) { // 8
        k = (k+1)%3;
        group[k][7][i] = true;
        switch(i) {
//        case 1: case 8: case 15: case 22: case 29:
//        case 2: case 9: case 16: case 23: case 30:
        case 3: case 10: case 17: case 24: case 31:
//        case 4: case 11: case 18: case 25: //case 31:
//        case 5: case 12: case 19: case 26: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
        case 7: case 14: case 21: case 28:
//        case 6: case 13: case 20: case 27:
            group[3][7][i] = true;
            group[4][7][i] = true;
            break;
//        case 3: case 17:
//        case 4: case 18:
        case 5: case 19:
//        case 6: case 20:
//        case 8: case 22:
            group[3][7][i] = true;
            break;
//        case 10: case 24:
//        case 11: case 25:
        case 12: case 26:
//        case 13: case 27:
//        case 15: case 29:
            group[4][7][i] = true;
            break;
        }
    }
    for(i=1; i<=30; i++) { // 9
        k = (k+1)%3;
        group[k][8][i] = true;
        switch(i) {
//        case 1: case 8: case 15: case 22: case 29:
//        case 2: case 9: case 16: case 23: case 30:
//        case 3: case 10: case 17: case 24: case 31:
        case 4: case 11: case 18: case 25: //case 31:
//        case 5: case 12: case 19: case 26: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
        case 7: case 14: case 21: case 28:
//        case 6: case 13: case 20: case 27:
            group[3][8][i] = true;
            group[4][8][i] = true;
            break;
        case 2: case 16:
//        case 3: case 17:
//        case 4: case 18:
//        case 5: case 19:
//        case 6: case 20:
//        case 8: case 22:
            group[3][8][i] = true;
            break;
        case 9: case 23:
//        case 10: case 24:
//        case 11: case 25:
//        case 12: case 26:
//        case 13: case 27:
//        case 15: case 29:
            group[4][8][i] = true;
            break;
        }
    }
    for(i=1; i<=31; i++) { // 10
        k = (k+1)%3;
        group[k][9][i] = true;
        switch(i) {
//        case 1: case 8: case 15: case 22: case 29:
        case 2: case 9: case 16: case 23: case 30:
//        case 3: case 10: case 17: case 24: case 31:
//        case 4: case 11: case 18: case 25: //case 31:
        case 5: case 12: case 19: case 26: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 7: case 14: case 21: case 28:
//        case 6: case 13: case 20: case 27:
            group[3][9][i] = true;
            group[4][9][i] = true;
            break;
//        case 2: case 16:
//        case 3: case 17:
//        case 4: case 18:
//        case 5: case 19:
//        case 6: case 20:
        case 7: case 21:
//        case 8: case 22:
            group[3][9][i] = true;
            break;
//        case 9: case 23:
//        case 10: case 24:
//        case 11: case 25:
//        case 12: case 26:
        case 14: case 28:
//        case 15: case 29:
            group[4][9][i] = true;
            break;
        }
    }
    for(i=1; i<=30; i++) { // 11
        k = (k+1)%3;
        group[k][10][i] = true;
        switch(i) {
//        case 1: case 8: case 15: case 22: case 29:
        case 2: case 9: case 16: case 23: case 30:
//        case 3: case 10: case 17: case 24: case 31:
//        case 4: case 11: case 18: case 25: //case 31:
//        case 5: case 12: case 19: case 26: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
//        case 7: case 14: case 21: case 28:
        case 6: case 13: case 20: case 27:
            group[3][10][i] = true;
            group[4][10][i] = true;
            break;
//        case 2: case 16:
//        case 3: case 17:
        case 4: case 18:
//        case 5: case 19:
//        case 6: case 20:
//        case 7: case 21:
//        case 8: case 22:
            group[3][10][i] = true;
            break;
//        case 9: case 23:
//        case 10: case 24:
        case 11: case 25:
//        case 12: case 26:
//        case 14: case 28:
//        case 15: case 29:
            group[4][10][i] = true;
            break;
        }
    }
    for(i=1; i<=31; i++) { // 12
        k = (k+1)%3;
        group[k][11][i] = true;
        switch(i) {
//        case 1: case 8: case 15: case 22: case 29:
//        case 2: case 9: case 16: case 23: case 30:
//        case 3: case 10: case 17: case 24: case 31:
        case 4: case 11: case 18: case 25: //case 31:
//        case 5: case 12: case 19: case 26: //case 31:
//        case 3: case 10: case 17: case 24: //case 31:
        case 7: case 14: case 21: case 28:
//        case 6: case 13: case 20: case 27:
            group[3][11][i] = true;
            group[4][11][i] = true;
            break;
        case 2: case 16:
//        case 3: case 17:
//        case 4: case 18:
//        case 5: case 19:
//        case 6: case 20:
//        case 7: case 21:
//        case 8: case 22:
            group[3][11][i] = true;
            break;
        case 9: case 23:
//        case 10: case 24:
//        case 11: case 25:
//        case 12: case 26:
//        case 14: case 28:
//        case 15: case 29:
            group[4][11][i] = true;
            break;
        }
    }
}

bool CalendarModel::getEventForDate(int index, const QDate &date)
{
//    qDebug()<<date.day()<<", "<<date.month()<<", "<<date.year();
//    qDebug()<<date.dayOfWeek(); 7 is sunday

    return group[index][date.month()-1][date.day()];
//    return true;
}
bool CalendarModel::getHoliday(const QDate &date)
{
//    qDebug()<<date.dayOfWeek();
    if(date.dayOfWeek() == 7) {
        return true;
    }
    return false;
}
