
/*
https://stackoverflow.com/questions/22450423/how-to-use-crt-secure-no-warnings


*/
#include<stdio.h>
#include<string.h>
#include <locale.h>
#define CR 13
#define ESC 27


char* yy_gets(int len)
{
	char* str = malloc(len + 1); memset(str, '\0', len + 1);



	for (int j = 0; j < len; j++)
	{
		char ch;
		ch = getch();
		//	printf("%d ", ch);
		if (ch == -89)  ch = 'ğ';
		if (ch == -127) ch = 'ü';
		if (ch == -97)  ch = 'ş';
		if (ch == 105)  ch = 'i';
		if (ch == -108) ch = 'ö';
		if (ch == -121) ch = 'ç';
		if (ch == -115) ch = 'ı';
		if (ch == -104) ch = 'İ';
		if (ch == CR)break;
		if (ch == ESC)break;
		putch(ch);
		*(str + j) = ch;
	

	}
	return str;
}


void ilkharf(char* ad)
{
	char harf=*(ad+0);
	int x = 0;

	if (harf >= 'a' && harf <= 'z' && harf != 'i')
		*(ad + 0) = harf-32;
	else
	{
		if (harf == 'ğ') *(ad + 0) = 'Ğ';
		if (harf == 'ü') *(ad + 0) = 'Ü';
		if (harf == 'ş') *(ad + 0) = 'Ş';
		if (harf == 'i') *(ad + 0) = 'İ';
		if (harf == 'ö') *(ad + 0) = 'Ö';
		if (harf == 'ç') *(ad + 0) = 'Ç';
		if (harf == 'ı') *(ad + 0) = 'I';
		
	}
}

void caps(char* soyad) {
	for (int i = 0; *(soyad + i) != '\0'; i++) 
	{
		if (*(soyad + i) >= 'a' && *(soyad + i) <= 'z') 
		{
			*(soyad + i) = *(soyad + i) - 32;
		} 
		else {
			if (*(soyad + i) == 'ğ') *(soyad + i) = 'Ğ';
			if (*(soyad + i) == 'ü') *(soyad + i) = 'Ü';
			if (*(soyad + i) == 'ş') *(soyad + i) = 'Ş';
			if (*(soyad + i) == 'i') *(soyad + i) = 'İ';
			if (*(soyad + i) == 'ö') *(soyad + i) = 'Ö';
			if (*(soyad + i) == 'ç') *(soyad + i) = 'Ç';
			if (*(soyad + i) == 'ı') *(soyad + i) = 'I';
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Turkish");
	char* ad, * soyad, * adsoyad, * basharf;

	adsoyad = malloc(50);
	memset(adsoyad, '\0', 50);
	ad = malloc(50);
	memset(ad, '\0', 50);
	soyad = malloc(50);
	memset(soyad, '\0', 50);

	printf("Ad-soyad: \n");
	adsoyad = yy_gets(50);

	int length = strlen(adsoyad);

	for (int i = length; i > 0; i--) {
		if (*(adsoyad + i) == ' ') {
			strncpy(soyad, (adsoyad + i + 1), (length - i));
			strncpy(ad, adsoyad, i);
		}
	}
	printf("\nSurname after cut: ");
	printf("%s\n", soyad);
	printf("Name after cut: ");
	printf("%s\n", ad);
	getch();


	ilkharf(ad);

	printf("The name which is starts with caps letter:");
	printf("\n%s", ad);
	getch();

	caps(soyad);
	printf("\nThe surname which is all caps letters");
	printf("\n%s", soyad);
	getch();

	return 0;
}



/*
int main() {

	setlocale(LC_ALL, "Turkish");
//	setlocale(LC_ALL, NULL);



	char* adisoyadi = malloc(50); memset(adisoyadi, '\0', 50);

	printf("gir:"); adisoyadi=yy_gets(50);

	char a = *(adisoyadi + 0);

	if (a == 'ğ')
		printf("\ndoğru");
	else
		printf("\nyanlıs");
	getch();
	return 0;
}
*/