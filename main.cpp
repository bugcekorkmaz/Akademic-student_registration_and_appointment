#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> //exit
#include <stdio.h>

using namespace std;

class okul{
public:
    string ad;
    string soyad;
    string bolum;
    string eposta;
    string telefon;
    int numara;
};
class ogrenci:public okul{
private:
    string kayitYili;
public:

    void ogrenciEkle(){
    cout<<"Ogrenci Ekleme"<<endl;
    ofstream ogrDosyaYaz;
    ogrDosyaYaz.open("ogrenci.txt",ios::app);
    cout<<"Ogrenci Numarasi :";
     cin>>numara;
    cout<<"\n Ogrenci Adi :";
     cin>>ad;
    cout<<"\n Ogrenci Soyadi :";
     cin>>soyad;
    cout<<"\n Ogrenci Bolumu :";
    cin>>bolum;
    cout<<"\n Ogrenci Telefonu :";
     cin>>telefon;
    cout<<"\n Ogrenci Eposta:";
    cin>>eposta;
    cout<<"\n Ogrenci Kayit Yili:";
    cin>>kayitYili;
    ogrDosyaYaz<<numara<<' '<<ad<<' '<<soyad<<' '<<bolum<<' '<<telefon<<' '<<eposta<<' '<<kayitYili<<endl;
    ogrDosyaYaz.close();
}
};
class akademisyen:public okul{
public:
    void akademisyenEkle(){
    cout<<"Akademisyen Ekleme"<<endl;
    ofstream akdDosyaYaz;
    akdDosyaYaz.open("akademisyen.txt",ios::app);
    cout<<"Akademisyen Numarasi :";
     cin>>numara;
    cout<<"\n Akademisyen Adi :";
     cin>>ad;
    cout<<"\n Akademisyen Soyadi :";
     cin>>soyad;
    cout<<"\n Akademisyen Bolumu :";
     cin>>bolum;
    cout<<"\n Akademisyen Telefonu :";
     cin>>telefon;
    cout<<"\n Akademisyen Eposta:";
     cin>>eposta;
    akdDosyaYaz<<numara<<' '<<ad<<' '<<soyad<<' '<<bolum<<' '<<telefon<<' '<<eposta<<endl;
    akdDosyaYaz.close();
};
};
class randevu:public okul{
private:
    int GirilenNumara;
    int GirilenSaat;
    int GirilenTarih;
    int akaNumara;
    int ogrNumara;
    int tarih;
    int baslangicSaati;
    int bitisSaati;
    char cevap;
public:
    void randevuAl(){
    cout<<"Randevu alma"<<endl;
    cout<<"Akademisyen Numarasi :";
    cin>>GirilenNumara;
    cout<<"tarih :";
    cin>>GirilenTarih;
    cout<<"saat :";
    cin>>GirilenSaat;
    ifstream rndDosyaOku("randevu.txt",ios::app);
    while(!rndDosyaOku.eof())
    {
        rndDosyaOku>>akaNumara>>ogrNumara>>tarih>>baslangicSaati>>bitisSaati;
        if(GirilenNumara==akaNumara && GirilenTarih==tarih && (GirilenSaat==baslangicSaati || GirilenSaat== bitisSaati))
        {
            cout<<"Girilen Tarihte Randevu dolu"<<endl;
            exit(0);
        }
    }
    rndDosyaOku.close();

    ofstream rndDosyaYaz;
    rndDosyaYaz.open("randevu.txt",ios::app);
    akaNumara=GirilenNumara;
    tarih=GirilenTarih;
    baslangicSaati=GirilenSaat;
    cout<<"Randevu Musait"<<endl;
    cout<<"Ogrenci No:";
    cin>>ogrNumara;
    cout<<"Randevu bitis saati:";
    cin>>bitisSaati;
    rndDosyaYaz<<akaNumara<<" "<<ogrNumara<<" "<<tarih<<" "<<baslangicSaati<<" "<<bitisSaati<<"\n";
    rndDosyaYaz.close();
    }
};

int main()
{
    ogrenci o;
    akademisyen a;
    randevu r;
    int menuSecim;
    char islem;
    do{
    cout<<"1- Ogrenci kayit ekleme"<<endl;
    cout<<"2- Akademisyen kayit ekleme"<<endl;
    cout<<"3- Randevu Alma"<<endl;
    cout<<"Yapmak istediginiz islemi seciniz:"<<endl;

    cin>>menuSecim;
    switch(menuSecim)
    {
    case 1:
    {
        o.ogrenciEkle();
        break;
    }
    case 2:
    {
        a.akademisyenEkle();
        break;
    }
    case 3:
    {
        r.randevuAl();
    break;
    }
    }
    cout<<"Baska islem yapmak istiyor musunuz? (e/E) (h/H)";
    cin>>islem;
    }
    while(islem=='e' || islem=='E');
    cout<<endl;

}
