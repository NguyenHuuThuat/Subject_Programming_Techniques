#include<stdio.h>
#include<conio.h>
#include<string.h>

struct date {
	int ngay, thang, nam;
};
typedef struct {
	char ht[25];
	struct date ns;
	float bl; //bac luong
}person;

//khai bao nguyen ham
person* pTim(char* ht, person h[], int n);

main() {



}

//ham
person* pTim(char* ht, person h[], int n) {
	int i;
	person ps;
	ps.ns.ngay = ps.ns.thang = ps.ns.nam = 0;
	ps.bl = 0.0;
	ps.ht[0] = 0;

	for (i = 0; i <= n; i++) {
		if ((strcmp)(ht, h[i].ht) == 0) {
			return &h[i];
		}
	}
	return &ps;

}
