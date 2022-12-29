#include <stdio.h>
#include <conio.h>


FILE *dosya;
int toplam = 0;
char giris;
char a=0;
char karakter;
char satir[120];
char sayac=0;

void yazdir(FILE *dosya){ //Sonuclari yazdirmak icin kullandigimiz fonksiyon
    karakter=fgetc(dosya);
while(karakter!=EOF){
    printf("%c",karakter);
    karakter=fgetc(dosya);

}
fclose(dosya);
}



void deger(){ //cevaplarin katsayilarinin toplandigi fonksiyon

while(a!=1){

printf("\nCevabinizi Giriniz:\n");
scanf("%s",&giris);

switch(giris){

 case 'A':
 case 'a': toplam+=0;
           a=1;
           break;

 case 'B':
 case 'b': toplam+=4;
           a=1;
           break;

 case 'C':
 case 'c': toplam+=8; 
           a=1; 
           break;

 case 'D':
 case 'd': toplam+=10;
           a=1;
           break;


 default:
          printf("\n!!!!A, B, C, D harflerinden birini giriniz!!!!\n");
          break;

}

}

a=0;
}

void soruvecevaplar(){ //sorulari yazdirdigimiz fonksiyon
    

    while((fgets(satir, sizeof(satir), dosya))){
        printf(satir);

        if(sayac%6==5){
            deger();
        }

        sayac++;
    }
   fclose(dosya);
   deger();
}

int main(){

int basla=0;

while(basla!=111) { //teste baslamak icin dongu
    printf("Baslamak icin 111 yaziniz.\n");
    scanf("%d",&basla);

}

printf("\n\nOncelikle Friends bilgini test edelim\n");

dosya = fopen("test.txt","r");
soruvecevaplar();

if(toplam==12){  
    
    sayac=0;
    toplam=0;
    printf("\nteste katilmaya hak kazandiniz.\n");

   dosya = fopen("friends.txt", "r"); 
   soruvecevaplar();


  if(toplam<=24){ //katsayilarin toplaminin araligina gore sonuclarin belirlenmesi
    dosya=fopen("joey.txt","r");
    yazdir(dosya);
  }

  else if(toplam>24 && toplam<=48){
    dosya=fopen("rachel.txt","r");
    yazdir(dosya);
  }

  else if(toplam>48 && toplam<=80){
    dosya=fopen("chandler.txt","r");
    yazdir(dosya);
  }

  else if(toplam>80){
    dosya=fopen("phoebe.txt","r");
    yazdir(dosya);
  }
}

else{
    printf("\nteste katilmaya hak kazanamadiniz\n");
}

char cikis;
printf("\ncikmak icin herhangi bir tusa basiniz");
cikis=getch();

return 0;
}