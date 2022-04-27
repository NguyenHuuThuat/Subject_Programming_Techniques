//#include<stdio.h> 
//
//enum week { Mon, Tue, Wed, Thur, Fri, Sat, Sun };
//
//int main() {
//    enum week day;
//    day = Wed;
//    printf("Chi so cua Wed la %d\n", day);
//
//    // duyet tat ca cac chi so phan tu cua enum week
//    int i;
//    for (i = Mon; i <= Sun; i++)
//        printf("%d ", i);
//    return 0;
//}

#include <stdio.h>

enum day {
    sunday = 1, monday, tuesday = 5,
    wednesday, thursday = 10, friday, saturday
};

int main() {
    printf("%d %d %d %d %d %d %d", sunday, monday, tuesday,
        wednesday, thursday, friday, saturday);
    return 0;
}