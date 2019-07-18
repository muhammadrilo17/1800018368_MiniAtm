 /*
Bismillahirrohmanirrohim

Nama  : Eko Muhammad Rilo Pembudi : 1800018368
	  : Martania Melany 		  : 1800018356
	  : Tanti Solihat 			  : 1800018341
	  
Kelas : H

TUGAS AKHIR DASAR PEMROGRAMAN PROYEK MESIN ATM

Assalamualaikum Wr. Wb.

Alhamdulillah 
Dengan Rahmat Allah Yang Maha Kuasa, dan berkat limpahan karuniaNya
program kami Simulasi Mesin ATM dapat kami selesaikan dalam waktu 3 minggu, yang kami mulai
pada hari rabu tanggl 26 desember 2018 jam 12.41 sampai tanggal 16 januari 2019.

Program ini kami buat semiripan mungkin dengan ATM BRI, yang bisa dikatakan 
program ini adalah simulasi dari mesin ATM BRI yang real.

Harapan kami dengan proyek pertama kami ini, proyek ini bisa menjadikan kami 
menjadi lebih baik lagi dan lebih profesional dalam menyusun script code dalam bahasa c++.

Tentunya ini tidak luput dari Ijin Allah SWT. yang masih memberikan kami kemampuan
untuk membuat program ini.
Dan pelajaran-pelajaran yang telah diajarkan oleh Ibu Dewi Pramudi Ismi M,CompSc.
dan bantuan kawan-kawan Teknik Informatika UAD Saya ucapkan Banyak Terimakasih :)

													       Yogyakarta, 16 Januari 2019
															   Ketua Kelompok
															   		TTD
															   
															   
															Eko Muhammad Rilo Pembudi
															NIM. 1800018368
*/

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <sstream>
#include <MMsystem.h>

using namespace std;

int w=0,i=0,trans=0,y,r,b,line,q;
string kata;
char ch;

ifstream ifile;
ofstream myfile;

struct variable{
	string textpin[100],textnama[100],textnorek[100],textcard[100],cekkode,kodegopay,blokir,titik;
	string noreklain,namabank[100],kodebank,referensi,textnoreklain[100],textnamalain[100],pil,card,bank,pin,norek,datapin,idpelanggan,pin1,nohp;
	int datasaldo,textsaldo[100],bpin,tarik,textsaldolain[100],uangtransfer,read,sisasaldo,biayaadmin,gopay;
	char xx;
}a;
void music(){
	PlaySound(TEXT("briatm.wav"),NULL,SND_SYNC);
}
void gotoxy(int x, int y){
	COORD coord;
	coord.X =x;
	coord.Y =y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void animasi(){
	int z2,z3,z,z1;
	z3=27;
	z2=77;
	for(int m=0;m<51;m++){
		Sleep(80);
		gotoxy(z3,7);cout<<"-";gotoxy(z2,17);cout<<"-";gotoxy(2,1);cout<<z3/10<<"%";gotoxy(1,1);
		z3++;
		z2--;
	}
	z3=8;
	z2=16;
	for(int m=0;m<9;m++){
		Sleep(150);
		gotoxy(77,z3);cout<<"|";gotoxy(27,z2);cout<<"|";gotoxy(2,1);cout<<"15%";gotoxy(1,1);
		z3++;
		z2--;
	}
	z3=29;
	for(int m=0;m<19;m++){
		Sleep(80);
		gotoxy(z3,9);cout<<"CREATED BY:";
		if(m<23){
			gotoxy(z3-1,9);cout<<" ";gotoxy(2,1);cout<<"24%";gotoxy(1,1);
			z3++;
		}
	}
	z3=50;
	z2=54;
	z=6;z1=18;
	for(int m=0;m<26;m++){
		Sleep(150);
		if(z3>=25){
			gotoxy(z3,5);cout<<"=";gotoxy(z3,19);cout<<"=";gotoxy(2,1);cout<<24+m<<"%";gotoxy(1,1);
			z3--;
		}
		gotoxy(51,19);cout<<"===";
		if(z2<80){
			gotoxy(z2,5);cout<<"=";gotoxy(z2,19);cout<<"=";gotoxy(1,1);
			z2++;
		}
	}
	for(int m=0;m<=7;m++){
		Sleep(150);
		gotoxy(25,z);cout<<"|";gotoxy(79,z);cout<<"|";gotoxy(1,1);
		z++;
		gotoxy(79,z1);cout<<"|";gotoxy(25,z1);cout<<"|";gotoxy(2,1);cout<<46+m<<"%";gotoxy(1,1);
		z1--;
	}	
	gotoxy(51,6);cout<<"| |";gotoxy(2,1);cout<<"60%";gotoxy(1,1);
	Sleep(240);
	gotoxy(34,11);cout<<"EKO MUHAMMAD RILO PEMBUDI : 1800018368";
	gotoxy(34,13);cout<<"MARTANIA MELANY           : 1800018356";
	gotoxy(34,15);cout<<"TANTI SOLIHAT             : 1800018341";	
	for(int ll=0;ll<5;ll++){
		z2=6;z3=52;z=52;
		gotoxy(2,1);cout<<60+((ll)*8)<<"%";gotoxy(1,1);
		for(int m=0;m<5;m++){
			gotoxy(z3,z2);cout<<"*";gotoxy(z,z2);cout<<"*";gotoxy(1,1);
			if(m>=1){
				for(int v=0;v<m;v++){
					gotoxy(52,6-m);cout<<"*";gotoxy(1,1);
					gotoxy(50+m,6-m);cout<<"*";gotoxy(1,1);
					gotoxy(54-m,6-m);cout<<"*";gotoxy(1,1);
				}
			}
			Sleep(300);			
			if(m>=1){
				for(int v=0;v<m;v++){
					gotoxy(52,6-m);cout<<" ";gotoxy(1,1);
					gotoxy(50+m,6-m);cout<<" ";gotoxy(1,1);
					gotoxy(54-m,6-m);cout<<" ";gotoxy(1,1);
				}
			}
			gotoxy(z3,z2);cout<<" ";gotoxy(z,z2);cout<<" ";gotoxy(1,1);
			z2--;z3--;z++;
		}	
		Sleep(700);
	}
	cout<<"100%";
	gotoxy(39,21);cout<<"SELAMAT DATANG DI ATM BRI";music();
}
void ps(){
	gotoxy(43,27);system("pause");
}	
void cls(){
	system("cls");
}
void header(){
	cls();
	gotoxy(47,1);cout<<"PT BANK RAKYAT INDONESIA";
	gotoxy(21,3);cout<<"--------------------------------------------------------------------------";	
}
void downheader(){
	int number;
	char num[8]={'A','S','D','F','G','H','J','K'};
	gotoxy(22,26);cout<<"-------------------------------------------------------------------------";
	for(i=0;i<=28;i++){
		gotoxy(21,i);cout<<"|\n";
		gotoxy(95,i);cout<<"|\n";
	}
	for(i=0;i<=28;i++){
		gotoxy(9,i);cout<<"|";
	}
	for(i=0;i<=28;i++){
		gotoxy(107,i);cout<<"|";
	}
	number=0;
	for(i=9;i<=21;i+=4){
		gotoxy(13,i);cout<<": "<<num[number]<<" :";
		number++;
	}
	for(i=9;i<=21;i+=4){
		gotoxy(99,i);cout<<": "<<num[number]<<" :";
		number++;
	}
	gotoxy(82,27);cout<<"X = CANCEL";gotoxy(25,27);
}
void pilihanid(){
	string id;
	b=0;
	while(b<10 && ch!='X'){
		ch=getch();
		ch=toupper(ch);
		if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='0'){	
			id.push_back(ch);
			cout<<ch;
			b++;
			q--;								
		}
	}
	a.card=id;
}
void pilihannorek(){
	string norek;
	b=0;
	while(b<1){
		ch=getch();
		ch=toupper(ch);
		if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='0'){
			norek.push_back(ch);
			cout<<ch;
		}	
		else if(ch=='H' || ch=='J' || ch=='K' || ch=='X'){
			b++;
		}
	}
	a.norek=norek;
	
}
void pilihanpin(){
	string input;
	b=0; q=89;
	while(b<6 && ch!='X'){
		if(b!=6){
		gotoxy(q,13);ch = getch();
		}
		ch=toupper(ch);
		if(ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='0'){	
			input.push_back(ch);
			gotoxy(q,13);cout<<'X';
			b++;
			q--;								
		}
		gotoxy(q,13);
	}
	a.pin=input;
	Sleep(400);
}
void pilihanGH(){
	gotoxy(82,27);cout<<"X = CANCEL";gotoxy(25,27);
	b=0;
	while(b<1){
		gotoxy(25,27);ch=getch();
		ch=toupper(ch);
		if(ch=='G'||ch=='H'||ch=='X'){	
			b++;								
		}
	}
}
void pilihanASG(){
	b=0;
	while(b<1){
		gotoxy(25,27);ch=getch();
		ch=toupper(ch);
		if(ch=='A'||ch=='S'||ch=='G'||ch=='X'){	
			b++;								
		}
	}
}
void pilihanJK(){
	b=0;
	while(b<1){
		gotoxy(25,27);ch=getch();
		ch=toupper(ch);
		if(ch=='J'||ch=='K'||ch=='X'){	
			b++;								
		}
	}
	if(ch=='K'||ch=='X'){
		b++;
		a.pil="7";
	}
}
void pilihanGHJK(){
	b=0;
	while(b<1){
		gotoxy(25,27);ch=getch();
		ch=toupper(ch);
		if(ch=='G'||ch=='H'||ch=='J'||ch=='K'||ch=='X'){	
			b++;								
		}
	}
}
void pilihanx(){
	b=0;
	while(b<1){
		gotoxy(25,27);ch=getch();
		ch=toupper(ch);
		if(ch=='A'||ch=='S'||ch=='D'||ch=='F'||ch=='G'||ch=='H'||ch=='J'||ch=='K'||ch=='X'){	
			b++;								
		}
	}
}
void pilihanHJ(){
	b=0;
	while(b<1){
		gotoxy(25,27);ch=getch();
		ch=toupper(ch);
		if(ch=='H'||ch=='J'||ch=='X'){	
			b++;								
		}
	}
}
void mutasi(){
	
}
void savedata(){
	myfile.open("bankbri.txt");
	for(i=0;i<r;i++){
		myfile<<a.textcard[i]<<endl;
		myfile<<a.textnama[i]<<endl;	
		myfile<<a.textnorek[i]<<endl;	
		myfile<<a.textsaldo[i]<<endl;
		myfile<<a.textpin[i]<<endl;
		myfile<<"-------------------"<<endl;
	}
	myfile.close();
}
void DataBaseKodeBank(){
	ifile.open("kodebank.txt");
	do{
		getline(ifile,kata);
		a.cekkode=kata;
		getline(ifile,kata);
		a.bank=kata;
	}while(a.bank!=a.namabank[trans] && !ifile.eof());
	ifile.close();
}
void ATMLAIN(){
	i=0;
	a.read=0;
	ifile.open("semuabank.txt");
	while(!ifile.eof()){
		getline(ifile,kata);
		a.textnamalain[i]=kata;
		getline(ifile,kata);
		a.textnoreklain[i]=kata;
		getline(ifile,kata);
		y = atoi(kata.c_str());
		a.textsaldolain[i]=y;
		getline(ifile,kata);
		a.namabank[i]=kata;
		getline(ifile,kata);
		i++;
		a.read++;
	}
	a.read-=1;
	ifile.close();
}
void belumtersedia(){
	header();
	downheader();
	gotoxy(41,9);cout<<"MOHON MAAF TRANSAKSI BELUM TERSEDIA";
	gotoxy(41,10);cout<<"-----------------------------------";
	gotoxy(53,13);cout<<"TRANSAKSI LAGI?";
	gotoxy(87,13);cout<<"YA =>";
	gotoxy(84,17);cout<<"TIDAK =>";
	pilihanHJ();a.pil="1";
	if(ch=='J'||ch=='X'){
		a.pil="7";
	}
}
class English{
	public :
		void infoENG(){
			header();
			downheader();
			gotoxy(25,4);cout<<"DEAR COSTUMER,";
			gotoxy(25,6);cout<<"TIPS SECURE TRANSACTATION ON ATM:";
			gotoxy(25,8);cout<<"- KEEP YOUR PIN CONFIDENTIAL";
			gotoxy(25,10);cout<<"- CHANGE YOUR PIN REGULARY";
			gotoxy(25,11);cout<<"  WITH PIN NUMBER THAT";
			gotoxy(25,12);cout<<"  HAVE NOT BEEN USED";
			gotoxy(25,14);cout<<"- COVER WITH HAND WHILE";
			gotoxy(25,15);cout<<"  PRESSING PIN NUMBER";
			gotoxy(25,17);cout<<"BRI CONTACT CENTER:";
			gotoxy(25,18);cout<<"  14017, 508017, (021) 57987400";
			gotoxy(25,19);cout<<"PLEASE NOT TO CONTACT ANOTHER";
			gotoxy(25,20);cout<<"CONTACT NUMBER OTHER THAN ABOVE";
			gotoxy(83,21);cout<<"PROCEED =>";	
			ps();
		}

};
class Indonesia{
	public:
		void pic(){
			string teks;
			ifile.open("pic.txt");
			while(!ifile.eof()){
				getline(ifile,teks);
				cout<<teks<<endl;
			}
			ifile.close();
		}
		void daftarbank(){
			header();
			downheader();
			gotoxy(47,6);cout<<"KODE BANK TUJUAN TRANSFER";
			string teks2;
			line=8;
			ifile.open("daftarkodebank1.txt");
			while(!ifile.eof()){
				getline(ifile,teks2);
				gotoxy(25,line);cout<<teks2<<endl;
				line++;
			}
			ifile.close();
			ps();
		}
		void beranda(){			
			header();
			downheader();
			gotoxy(60,24);cout<<"ENTER YOUR CARD";
			gotoxy(60,25);cout<<"MASUKKAN KARTU ANDA : ";pilihanid();
			for(i=0;i<r;i++){
				if(a.card==a.textcard[i]){
					w=i;
				}
			}
			a.datasaldo=a.textsaldo[w];
		}
		void infoIND(){
			header();
			downheader();
			gotoxy(25,4);cout<<"NASABAH YTH,";
			gotoxy(25,6);cout<<"TIPS AMAN BERTRANSAKSI DI ATM:";
			gotoxy(25,8);cout<<"- JAGA KERAHASIAAN PIN";
			gotoxy(25,10);cout<<"- GANTI PIN ANDA SECARA BERKALA";
			gotoxy(25,11);cout<<"  DENGAN PIN YANG BELUM PERNAH";
			gotoxy(25,12);cout<<"  DIPERGUNAKAN";
			gotoxy(25,14);cout<<"- TUTUP DENGAN TANGAN SAAT";
			gotoxy(25,15);cout<<"  MENEKAN NOMOR PIN";
			gotoxy(25,17);cout<<"CALL CENTER BRI:";
			gotoxy(25,18);cout<<"  14017, 508017, (021) 57987400";
			gotoxy(25,19);cout<<"DIMOHON TIDAK MENGHUBUNGI NOMOR";
			gotoxy(25,20);cout<<"LAIN SELAIN NOMOR DIATAS";
			gotoxy(81,21);cout<<"LANJUTKAN =>";	
			ps();
		}
		void pinIND(){
			do{		
				header();
				gotoxy(30,4);pic();
				downheader();
				gotoxy(78,9);cout<<" MASUKKAN PIN "<<endl<<endl;
				gotoxy(78,15);cout<<"TEKAN 'ENTER'"<<endl;
				gotoxy(78,16);cout<<" JIKA SELESAI"<<endl;
				gotoxy(78,17);cout<<" MASUKKAN PIN"<<endl<<endl;
				pilihanpin();
				if(ch=='X'){
					a.pil="7";
				}
				else if(a.bpin<3 && a.pin==a.textpin[w]){
					cls();
					a.bpin=0;
					menu1();				
				}
				else if(a.bpin<2){
					header();
					downheader();
					gotoxy(54,14);cout<<"PIN SALAH"<<endl<<endl;
					a.bpin++;
					gotoxy(78,17);cout<<"GANTI KARTU =>"<<endl;
					gotoxy(69,21);cout<<"MASUKKAN PIN KEMBALI =>"<<endl;pilihanJK();
					if(ch=='K'){
						a.pil="8";
					}
					else{
						a.pil="7";
					}
				}
				else{
					header();
					downheader();
					gotoxy(36,8);cout<<"PIN ANDA TELAH DI BLOKIR, SILAHKAN MENGHUBUNGI CS"<<endl;
					gotoxy(69,21);cout<<"MASUKKAN PIN KEMBALI =>"<<endl;
					gotoxy(78,17);cout<<"GANTI KARTU =>"<<endl;pilihanJK();
					if(ch=='K'){
						a.pil="8";
					}			
					else{
						a.pil="7";
					}	
					a.bpin++;
				}	
			}while(a.pil!="7");
		}
		void gagal(){
			header();
			downheader();
			gotoxy(49,8);cout<<"SALDO ANDA TIDAK CUKUP";
			gotoxy(53,13);cout<<"TRANSAKSI LAGI?";
			gotoxy(87,13);cout<<"YA =>";
			gotoxy(84,17);cout<<"TIDAK =>";
			pilihanHJ();
			if(ch=='J' || ch=='X'){
				a.pil="7";
			}	
		}
		void gagaltransfer(){
			header();
			downheader();
			gotoxy(53,8);cout<<"TRANSFER GAGAL";
			gotoxy(53,13);cout<<"TRANSAKSI LAGI?";
			gotoxy(87,13);cout<<"YA =>";
			gotoxy(84,17);cout<<"TIDAK =>";
			pilihanHJ();a.pil="1";
			if(ch=='J'){
				a.pil="7";
			}		
		}
		void prosestunggu(){
			header();
			downheader();
			gotoxy(52,5);cout<<"SILAHKAN TUNGGU";
			gotoxy(46,6);cout<<"TRANSAKSI SEDANG DIPROSES";
			gotoxy(52,8);cout<<"---------------";
			gotoxy(51,23);cout<<"INFO CONTACT BRI";
			gotoxy(53,24);cout<<"14017/1500017";
			Sleep(1800);
		}
		void terimakasih(){
			header();
			downheader();
			gotoxy(53,6);cout<<"TERIMA KASIH";
			gotoxy(44,8);cout<<"ANDA TELAH MENGGUNAKAN ATM BRI";
			gotoxy(46,10);cout<<"SILAHKAN AMBIL KARTU ANDA";
			ps();
		}
		void sisa(){
			gotoxy(46,9);cout<<"SISA SALDO ANDA RP. "<<a.textsaldo[w];
			Sleep(1000);
		}
		void berhasiltarik(){
			header();
			downheader();
			gotoxy(46,6);cout<<"SILAHKAN AMBIL UANG ANDA";
			a.pil="7";
			ps();sisa();
		}
		void succes(){
			header();
			downheader();
			gotoxy(52,6);cout<<"TRANSAKSI ANDA";
			gotoxy(49,8);cout<<"BERHASIL DILAKSANAKAN";
			gotoxy(53,10);cout<<"TERIMA KASIH";
			gotoxy(52,13);cout<<"TRANSAKSI LAGI?";
			gotoxy(87,13);cout<<"YA =>";
			gotoxy(84,17);cout<<"TIDAK =>";
			pilihanHJ();
			if(ch=='H'){
				a.pil="8";
			}
			else if(ch=='J'){
				a.pil="7";
			}
		}
		void transaksigopay(){
			gpy:
			header();
			downheader();
			gotoxy(52,6);cout<<"TOP UP GO-PAY";
			gotoxy(48,7);cout<<"MASUKKAN JUMLAH TOP UP";
			gotoxy(84,13);cout<<"BENAR =>";
			gotoxy(84,17);cout<<"SALAH =>";
			gotoxy(48,25);cout<<"TEKAN CANCEL UNTUK BATAL"; 
			gotoxy(47,9);cout<<"RP";
			string penampung;i=68;
			a.titik="";
			b=0;
			while(b<1){
				gotoxy(i,9);ch=getch();
				ch=toupper(ch);
				if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
					if(a.titik.length()<=10){
						penampung.push_back(ch);
						a.titik=penampung;
						if(a.titik.length()>3){
							a.titik.insert(a.titik.end()-3,'.');
						}
						if(a.titik.length()>7){
							a.titik.insert(a.titik.end()-7,'.');
						}	
						if(a.titik.length()==3||a.titik.length()==7){
							i--;
						}
						cout<<a.titik;
						i--;
					}
				}
				else if(ch=='H'||ch=='J'||ch=='X'){
					b++;
				}
			}
			a.gopay = atoi(penampung.c_str());
			a.sisasaldo=a.textsaldo[w];
			a.sisasaldo-=a.gopay;
			if (ch=='X'){
				a.pil="7";
			}
			else if(ch=='J'){
				goto gpy;
			}
			else if (a.sisasaldo>=50000){
				header();
				downheader();
				gotoxy(54,6);cout<<"TOP UP GO-PAY";
				gotoxy(43,9);cout<<"NO.HP\t\t: "<<a.nohp;
				gotoxy(43,10);cout<<"NAMA\t\t\t: "<<a.textnama[w];
				gotoxy(43,11);cout<<"JENIS\t\t: "<<a.kodegopay;
				gotoxy(43,12);cout<<"JMLH TOPUP\t\t: RP. "<<a.gopay;
				gotoxy(43,13);cout<<"ADMIN BANK\t\t: RP. "<<a.biayaadmin;
				gotoxy(43,14);cout<<"TOTAL\t\t: RP. "<<a.titik;
				gotoxy(51,17);cout<<"PROSES TRANSAKSI?";
				gotoxy(87,17);cout<<"YA =>";
				gotoxy(84,21);cout<<"TIDAK =>";
				pilihanJK();
				if(ch=='J'){
					a.textsaldo[w]-=a.gopay;
					savedata();
					prosestunggu();
					myfile.open("strukgopay.txt");
						myfile<<"            TOP UP GO-PAY"<<endl;
						myfile<<"-----------------------------------------"<<endl;
						myfile<<"NO.         : "<<a.nohp<<endl;
						myfile<<"NAMA        : "<<a.textnama[w]<<endl;
						myfile<<"JENIS       : "<<a.kodegopay<<endl;
						myfile<<"JMLH TOPUP  : RP. "<<a.titik<<endl;
						myfile<<"ADMIN BANK  : RP. "<<a.biayaadmin<<endl;
						myfile<<"TOTAL       : RP. "<<a.titik<<endl;
						myfile<<"-----------------------------------------"<<endl;
					myfile.close();
					system("strukgopay.txt");
					succes();
				}
			}
			else {
				gagal();
			}	
		}
		void gopay(){
			gpy:
			header();
			downheader();
			gotoxy(52,6);cout<<"TOP UP GO-PAY";
			gotoxy(44,8);cout<<"MASUKKAN KODE DAN NO.HANDPHONE";
			gotoxy(48,10);cout<<"++++++---------------";
			gotoxy(84,13);cout<<"BENAR =>";
			gotoxy(84,17);cout<<"SALAH =>";
			gotoxy(25,22);cout<<"DAFTAR KODE:";
			gotoxy(25,23);cout<<"301341:CUSTOMER";
			gotoxy(25,24);cout<<"301342:DRIVER";
			gotoxy(25,25);cout<<"301343:MERCHANT";
			string input;
			char abc[6];
			b=0;q=48;
			while(b<1){
				gotoxy(q,10);ch=getch();
				ch=toupper(ch);
				if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
					input.push_back(ch);
					cout<<ch;
					q++;
				}
				else if(ch=='H'||ch=='J'||ch=='X'){
					b++;
				}
			}
			strncpy(abc,input.c_str(),6);
			string kodegopay(abc);
			a.kodegopay=kodegopay;
			input.erase(0,6);
			a.nohp=input;
			if(ch=='X'){
				a.pil="7";
			}
			else if(ch=='J'){
				goto gpy;
			}
			else if(kodegopay=="301341"||kodegopay=="301342"||kodegopay=="301343"){
				if(kodegopay=="301341"){
					header();
					downheader();
					a.kodegopay="COSTUMER";
					transaksigopay();
				}
				else if(kodegopay=="301342"){
					a.kodegopay="DRIVER";
					transaksigopay();
				}
				else if(kodegopay=="301343"){
					a.kodegopay="MERCHANT";
					transaksigopay();
				}
				else{
					header();
					downheader();
					gotoxy(44,9);cout<<"KODE YANG ANDA MASUKKAN SALAH";
					gotoxy(53,13);cout<<"TRANSAKSI LAGI?";
					gotoxy(87,13);cout<<"YA =>";
					gotoxy(84,17);cout<<"TIDAK =>";
					pilihanHJ();a.pil="1";
					if(ch=='H'){
						a.pil="6";
					}		
					else{
						a.pil="7";
					}
				}
			}
		}
		void transferlain(){
			char kbank[3];
			strncpy(kbank,a.noreklain.c_str(),3);
			string abc(kbank);
			a.kodebank=abc;
			a.norek.erase(0,3);
			ATMLAIN();
			i=0;
			do{
				if(a.norek==a.textnoreklain[i]){
					trans=i;
				}
				i++;
			}while(i<a.read);
			atas:
			header();
			downheader();
			DataBaseKodeBank();
			gotoxy(47,6);cout<<"MASUKKAN JUMLAH TRANSFER";
			gotoxy(84,17);cout<<"BENAR =>";
			gotoxy(84,21);cout<<"SALAH =>";
			gotoxy(48,25);cout<<"TEKAN CANCEL UNTUK BATAL"; 
			gotoxy(47,9);cout<<"RP";
			string penampung;i=70;
			a.titik="";
			b=0;
			while(b<1){
				gotoxy(i,9);ch=getch();
				ch=toupper(ch);
				if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
					if(a.titik.length()<=10){
						penampung.push_back(ch);
						a.titik=penampung;
						if(a.titik.length()>3){
							a.titik.insert(a.titik.end()-3,'.');
						}
						if(a.titik.length()>7){
							a.titik.insert(a.titik.end()-7,'.');
						}	
						if(a.titik.length()==3||a.titik.length()==7){
							i--;
						}
						cout<<a.titik;
						i--;
					}
				}
				else if(ch=='J'||ch=='K'||ch=='X'){
					b++;
				}
			}
			a.uangtransfer = atoi(penampung.c_str());
			if(ch=='J'){
				a.sisasaldo=a.textsaldo[w];
				a.sisasaldo-=a.uangtransfer;
				if(a.uangtransfer>a.textsaldo[w] || a.sisasaldo<50000){
					gagal();
				}
				else if(a.namabank[trans]!=a.bank || a.textnoreklain[trans]!=a.norek){
					gagaltransfer();
				}
				else if(a.textnoreklain[trans]==a.norek){
					atas1:
					header();
					downheader();
					gotoxy(47,5);cout<<"MASUKKAN NOMOR REFERENSI";
					gotoxy(46,6);cout<<"(KOSONGKAN BILA TIDAK ADA)";
					gotoxy(49,7);cout<<"--------------------";
					gotoxy(84,13);cout<<"BENAR =>";	
					gotoxy(84,17);cout<<"SALAH =>";
					gotoxy(45,25);cout<<"KETIK CANCEL UNTUK BATAL";	
					gotoxy(49,7);
					string penampung;
					b=0;
					while(b<1){
						gotoxy(49,7);ch=getch();
						ch=toupper(ch);
						if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9' && penampung.length()<9){
							penampung.push_back(ch);
							gotoxy(49,7);cout<<penampung;
							i--;
						}
						else if(ch=='H'||ch=='J'||ch=='X'){
							b++;
						}
					}
					a.referensi=penampung;
					if(ch=='H'){
						prosestunggu();
						header();
						downheader();
						gotoxy(50,6);cout<<"INFORMASI TRANSFER";
						gotoxy(37,9);cout<<"B A N K             \t: "<<a.namabank[trans];
						gotoxy(37,10);cout<<"NOMOR REKENING     \t: "<<a.norek;
						gotoxy(37,11);cout<<"N A M A            \t: "<<a.textnamalain[trans];
						gotoxy(37,12);cout<<"NOMOR REF          \t: "<<a.referensi;
						gotoxy(37,13);cout<<"JUMLAH             \t: RP "<<a.titik;
						gotoxy(51,17);cout<<"PROSES TRANSAKSI?";
						gotoxy(87,17);cout<<"YA =>";
						gotoxy(84,21);cout<<"TIDAK =>";
						pilihanJK();
						if(ch=='J'){
							a.textsaldo[w]-=a.uangtransfer;
							a.textsaldolain[trans]+=a.uangtransfer;
							savedata();
							myfile.open("semuabank.txt");
							i=0;
							while(i<a.read){
								myfile<<a.textnamalain[i]<<endl;
								myfile<<a.textnoreklain[i]<<endl;
								myfile<<a.textsaldolain[i]<<endl;
								myfile<<a.namabank[i]<<endl;
								myfile<<"-------------------"<<endl;
								i++;
							}
							myfile.close();
							myfile.open("struk.txt");
							i=0;
							while(i<1){
								myfile<<"INFORMASI TRANSFER\nATM BRI"<<endl;
								myfile<<"---------------------------------------"<<endl<<endl;
								myfile<<"B A N K            : "<<a.namabank[trans]<<endl;
								myfile<<"NOMOR REKENING     : "<<a.norek<<endl;
								myfile<<"N A M A            : "<<a.textnamalain[trans]<<endl;
								myfile<<"NOMOR REF          : "<<a.referensi<<endl;
								myfile<<"JUMLAH             : RP "<<a.titik<<endl;
								myfile<<"SISA SALDO ANDA    : RP "<<a.textsaldo[w]<<endl<<endl;
								myfile<<"---------------------------------------"<<endl<<endl;
								i++;
							}
							myfile.close();
							prosestunggu();
							system("struk.txt");
							succes();	
						}
						else if(ch=='K'){
							gagaltransfer();
						}
					}
					else if(ch=='J'){
						goto atas1;
					}	
					else if (ch=='X'){
						a.pil="7";
					}	
				}
			}	
			else if(ch=='K'){
				goto atas;
			}
		}
		void cektransfer(){
			atas:
			for(i=0;i<=r;i++){
				if(a.norek==a.textnorek[i]){
					trans=i;
				}
			}
			header();
			downheader();
			gotoxy(47,6);cout<<"MASUKKAN JUMLAH TRANSFER";
			gotoxy(84,17);cout<<"BENAR =>";
			gotoxy(84,21);cout<<"SALAH =>";
			gotoxy(48,25);cout<<"TEKAN CANCEL UNTUK BATAL"; 
			gotoxy(47,9);cout<<"RP";
			string penampung;i=70;
			a.titik="";
			b=0;
			while(b<1){
				gotoxy(i,9);ch=getch();
				ch=toupper(ch);
				if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
					if(a.titik.length()<=10){
						penampung.push_back(ch);
						a.titik=penampung;
						if(a.titik.length()>3){
							a.titik.insert(a.titik.end()-3,'.');
						}
						if(a.titik.length()>7){
							a.titik.insert(a.titik.end()-7,'.');
						}	
						if(a.titik.length()==3||a.titik.length()==7){
							i--;
						}
						cout<<a.titik;
						i--;
					}
				}
				else if(ch=='J'||ch=='K'||ch=='X'){
					b++;
				}
			}
			a.uangtransfer = atoi(penampung.c_str());
			if(ch=='J'){
				a.sisasaldo=a.textsaldo[w];
				a.sisasaldo-=a.uangtransfer;
				prosestunggu();
				if(a.uangtransfer>a.textsaldo[w]){
					gagal();
				}
				else if(a.textnorek[w]==a.norek || a.textnorek[trans]!=a.norek){
					gagaltransfer();
				}
				else if(a.textnorek[trans]==a.norek){
					header();
					downheader();
					gotoxy(51,6);cout<<"INFORMASI TRANSFER";
					gotoxy(37,9);cout<<"DARI NOREK          \t: "<<a.textnorek[w];
					gotoxy(37,10);cout<<"KE NOMOR           \t: "<<a.textnorek[trans];
					gotoxy(37,11);cout<<"N A M A            \t: "<<a.textnama[trans];
					gotoxy(37,12);cout<<"JUMLAH             \t: RP "<<a.titik;
					gotoxy(51,17);cout<<"PROSES TRANSAKSI?";
					gotoxy(87,17);cout<<"YA =>";
					gotoxy(84,21);cout<<"TIDAK =>";
					pilihanJK();
					if(ch=='J'){
						a.pil="6";
						a.textsaldo[w]-=a.uangtransfer;
						a.textsaldo[trans]+=a.uangtransfer;
						savedata();
						myfile.close();
						myfile.open("struk.txt");
						i=0;
						while(i<1){
							myfile<<"INFORMASI TRANSFER\nATM BRI"<<endl;
							myfile<<"---------------------------------------"<<endl<<endl;
							myfile<<"DARI NOREK         : "<<a.textnorek[w]<<endl;
							myfile<<"NOMOR REKENING     : "<<a.textnorek[trans]<<endl;
							myfile<<"N A M A            : "<<a.textnama[trans]<<endl;
							myfile<<"JUMLAH             : RP "<<a.titik<<endl;
							myfile<<"SISA SALDO ANDA    : RP "<<a.textsaldo[w]<<endl<<endl;
							myfile<<"---------------------------------------"<<endl<<endl;
							i++;
						}
						myfile.close();
						prosestunggu();
						system("struk.txt");
						succes();	
					}
					else if(ch=='K'){
						gagaltransfer();
					}
				}
			}				
			else if(ch=='K'){
				goto atas;
			}
			else if(ch=='X'){
				a.pil="7";
			}
		}
		void transfer(){
			header();
			downheader();
			gotoxy(47,5);cout<<"PILIH BANK TUJUAN TRANSFER";
			gotoxy(84,9);cout<<"B R I =>";
			gotoxy(80,13);cout<<"BANK LAIN =>";
			gotoxy(45,25);cout<<"KETIK CANCEL UNTUK BATAL";	
			pilihanGH();
			if(ch=='G'){
				ats:
				header();
				downheader();
				gotoxy(48,5);cout<<"MASUKKAN NOMOR REKENING";
				gotoxy(49,6);cout<<"TUJUAN TRANSFER ANDA";
				gotoxy(49,7);cout<<"--------------------";
				gotoxy(84,13);cout<<"BENAR =>";
				gotoxy(84,17);cout<<"SALAH =>";
				gotoxy(45,25);cout<<"KETIK CANCEL UNTUK BATAL";	
				gotoxy(49,7);pilihannorek();
				if(ch=='H'){	
					cektransfer();
				}
				else if(ch=='J'){
					goto ats;
				}
				else if(ch=='K'){
					goto ats;
				}
				else if(ch=='X'){
					a.pil="7";
				}
			}
			else if(ch=='H'){
				atas:
				header();
				downheader();
				gotoxy(48,5);cout<<"MASUKKAN KODE BANK DAN";
				gotoxy(48,6);cout<<"NOMOR REKENING TUJUAN";
				gotoxy(49,7);cout<<"--------------------";
				gotoxy(84,13);cout<<"BENAR =>";
				gotoxy(84,17);cout<<"SALAH =>";
				gotoxy(73,21);cout<<"DAFTAR KODE BANK =>";
				gotoxy(45,25);cout<<"KETIK CANCEL UNTUK BATAL";	
				gotoxy(49,7);pilihannorek();
				if(ch=='H'){
					transferlain();
				}
				else if(ch=='J'){
					goto atas;
				}
				else if(ch=='K'){
					daftarbank();
					goto atas;
				}
				else if(ch=='X'){
					a.pil="7";
				}
			}
			else if(ch=='X'){
				a.pil="7";
			}
		}
		void sisasaldo(){
			header();
			downheader();
			stringstream sald;
			sald<<a.textsaldo[w];
			a.titik = sald.str();
			if(a.titik.length()>3){
				a.titik.insert(a.titik.end()-3,'.');
			}
			if(a.titik.length()>7){
				a.titik.insert(a.titik.end()-7,'.');
			}
			if(a.titik.length()>11){
				a.titik.insert(a.titik.end()-11,'.');
			}
			gotoxy(43,6);cout<<"TRANSAKSI BERHASIL";
			gotoxy(46,8);cout<<"SISA SALDO ANDA RP. "<<a.titik;
			gotoxy(51,13);cout<<"TRANSAKSI LAGI?";	
			gotoxy(87,13);cout<<"YA =>";
			gotoxy(84,17);cout<<"TIDAK";
			pilihanHJ();
			if(ch=='K' || ch=='X'){
				a.pil="7";
			}
		}
		void gantipin(){
			do{
				header();
				downheader();
				gotoxy(80,8);cout<<"PERUBAHAN PIN"<<endl;
				gotoxy(80,9);cout<<"MASUKKAN"<<endl;
				gotoxy(80,10);cout<<"6 DIGIT PIN"<<endl;
				gotoxy(80,11);cout<<"BARU ANDA";
				pilihanpin();a.pin1=a.pin;
				cls();
				header();
				downheader();
				gotoxy(80,8);cout<<"PERUBAHAN PIN"<<endl;
				gotoxy(80,9);cout<<"MASUKKAN LAGI"<<endl;	
				gotoxy(80,10);cout<<"6 DIGIT PIN"<<endl;
				gotoxy(80,11);cout<<"BARU ANDA";
				pilihanpin();
				a.datapin=a.pin;
				if(a.datapin==a.pin1){
					a.textpin[w]=a.datapin;		
					savedata();
					header();
					downheader();
					gotoxy(51,10);cout<<"UBAH PIN BERHASIL"<<endl;
					a.pil="8";
					ps();
				}
				else {
					header();
					downheader();
					gotoxy(54,9);cout<<"PIN BERBEDA"<<endl;
					gotoxy(56,13);cout<<"ULANGI?";
					gotoxy(87,13);cout<<"YA =>";
					gotoxy(84,17);cout<<"TIDAK =>";
					pilihanHJ();
					if(ch=='J'){
						a.pil="7";
					}
					else {
						a.pil="6";
					}
				}
			}while(a.pil=="6");
		}
		void pembelianpulsa(){
			if (ch=='A'){
				a.sisasaldo-=10000;
				if(a.sisasaldo>=50000){
					a.textsaldo[w]-=10000;
					savedata();
					succes();							
				}
			}
			else if (ch=='S'){
				a.sisasaldo-=20000;
				if(a.sisasaldo>=50000){
					a.textsaldo[w]-=20000;
					savedata();
					succes();							
				}
			}
			else if (ch=='D'){
				a.sisasaldo-=25000;
				if(a.sisasaldo>=50000){
					a.textsaldo[w]-=25000;
					savedata();
					succes();							
				}
			}
			else if (ch=='F'){
				a.sisasaldo-=50000;
				if(a.sisasaldo>=50000){
					a.textsaldo[w]-=50000;
					savedata();
					succes();							
				}
			}
			else if (ch=='G'){
				a.sisasaldo-=100000;
				if(a.sisasaldo>=50000){
					a.textsaldo[w]-=100000;
					savedata();
					succes();							
				}
			}
			else if (ch=='H'){
				a.sisasaldo-=150000;
				if(a.sisasaldo>=50000){
					a.textsaldo[w]-=150000;
					savedata();
					succes();							
				}
			}
			else if (ch=='J'){
				a.sisasaldo-=200000;
				if(a.sisasaldo>=50000){
					a.textsaldo[w]-=200000;
					savedata();
					succes();							
				}
			}					
		}
		void pembelian(){
			back:
			header();
			downheader();
			gotoxy(47,6);cout<<"PILIH TRANSAKSI PEMBELIAN";
			gotoxy(74,9);cout<<"PULSA ISI ULANG =>";
			gotoxy(74,13);cout<<"DEPOSIT E-MONEY =>";
			gotoxy(86,17);cout<<"PLN =>";
			gotoxy(76,21);cout<<"TOP UP GO_PAY =>";
			pilihanGHJK();
			if(ch=='G'){
				ats:
				header();
				downheader();
				gotoxy(47,6);cout<<"PEMBELIAN PULSA ISI ULANG";
				gotoxy(25,9);cout<<"<= IM3";                      gotoxy(79,9);cout<<"SIMPATI/AS =>";
				gotoxy(25,13);cout<<"<= XL/AXIS";	              gotoxy(82,13);cout<<"MENTARI =>";
				gotoxy(25,17);cout<<"<= STAR-ONE";                gotoxy(84,17);cout<<"FLEXI =>";
				gotoxy(25,21);cout<<"<= FREN/MOBI/HEPI";        gotoxy(82,21);cout<<"KEMBALI =>";
				pilihanx();
				if(ch=='K'){
					goto back;
				}
				if (ch=='A'||ch=='S'||ch=='D'||ch=='F'||ch=='G'||ch=='H'||ch=='J'){
					header();
					downheader();
					gotoxy(47,6);cout<<"PEMBELIAN PULSA ISI ULANG ";
					gotoxy(25,9);cout<<"<= 10.000";                      gotoxy(82,9);cout<<"100.000 =>";
					gotoxy(25,13);cout<<"<= 20.000";	              gotoxy(82,13);cout<<"150.000 =>";
					gotoxy(25,17);cout<<"<= 25.000";                gotoxy(82,17);cout<<"200.000 =>";
					gotoxy(25,21);cout<<"<= 50.000";        gotoxy(82,21);cout<<"KEMBALI =>";
					pilihanx();	
					header();
					downheader();
					a.sisasaldo=a.textsaldo[w];
					pembelianpulsa();
					if(ch=='K'){
						goto ats;
					}
					if(ch=='X'){
						a.pil="7";
					}
				}
				else{
					a.pil="7";
				}
			}
			else if(ch=='J'){
				header();
				downheader();
				gotoxy(53,7);cout<<"PLN PRA BAYAR";
				gotoxy(80,9);cout<<"PRA BAYAR =>";gotoxy(78,13);cout<<"CETAK TOKEN =>";gotoxy(48,25);cout<<"TEKAN CANCEL UNTUK BATAL";gotoxy(25,27);pilihanGH();
				if(ch=='G'){
					belumtersedia();	
				}
				else if(ch=='H'){
					belumtersedia();
				}		
			}
			else if(ch=='H'){
				belumtersedia();
			}
			else if(ch=='K'){
				gopay();
			}
			else if(ch=='X'){
				a.pil="7";
			}
		}
		void penarikan(){
			ats:
			header();
			downheader();
			gotoxy(47,6);cout<<"MASUKKAN PENARIKAN TUNAI";
			gotoxy(45,7);cout<<"(DALAM KELIPATAN RP.100.000)";
			gotoxy(87,13);cout<<"YA =>";
			gotoxy(84,17);cout<<"SALAH =>";
			gotoxy(50,9);cout<<"RP.";
			b=0;
			string penampung;i=68;
			a.titik="";
			while(b<1){
				gotoxy(i,9);ch=getch();
				ch = toupper(ch);
				if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
					if(a.titik.length()<=10){
						penampung.push_back(ch);
						a.titik=penampung;
						if(a.titik.length()>3){
							a.titik.insert(a.titik.end()-3,'.');
						}
						if(a.titik.length()>7){
							a.titik.insert(a.titik.end()-7,'.');
						}	
						if(a.titik.length()==3||a.titik.length()==7){
							i--;
						}
						cout<<a.titik;
						i--;
					}
				}
				else if(ch=='H'||ch=='J'||ch=='X'){
					
					b++;
				}
			}
			a.tarik = atoi(penampung.c_str());	
			a.sisasaldo=a.textsaldo[w];
			a.sisasaldo-=a.tarik;
			if(ch=='J'){
				goto ats;
			}
			if(ch=='X'){
				a.pil="7";
			}
			else if(a.tarik%100000==0&&a.sisasaldo<=50000){
				gagal();
			}
			else if(a.tarik%100000==0&&a.tarik<=a.textsaldo[w]&&a.tarik != 0){
				a.textsaldo[w]=a.textsaldo[w]-a.tarik;		
				savedata();
				prosestunggu();
				succes();
			}
			else{
				header();
				downheader();
				gotoxy(41,8);cout<<"UANG HANYA DALAM PECAHAN RP.100.000";			
				gotoxy(52,13);cout<<"TRANSAKSI LAGI?";
				gotoxy(87,13);cout<<"YA =>";
				gotoxy(84,17);cout<<"TIDAK =>";
				pilihanHJ();
				if(ch=='K' || ch=='X'){
					a.pil="7";
				}
			}	
		}
		void bahasa(){
			header();
			downheader();		
			gotoxy(47,5);cout<<"SILAKAN PILIH BAHASA ANDA";		
			gotoxy(46,6);cout<<"---------------------------";
			gotoxy(46,7);cout<<"PLEASE SELECT YOUR LANGUAGE";
			gotoxy(81,13);cout<<"INDONESIA =>";
			gotoxy(81,17);cout<<"  ENGLISH =>";
			gotoxy(46,23);cout<<"TO OBTAIN CARD PRESS CANCEL";
			gotoxy(44,24);cout<<"--------------------------------";
			gotoxy(44,25);cout<<"TEKAN 'CANCEL' UNTUK MEMBATALKAN";
			gotoxy(25,27);
			b=0;
			while(b<1){
				a.xx = getch();
				a.xx = toupper(a.xx);
				if(a.xx=='H'||a.xx=='J'){	
					b++;								
				}
				if(a.xx=='X'){
					a.pil="7";
					b++;
				}
			}
		}
		void ceksaldo(){
			header();	
			downheader();
			stringstream sald;
			sald<<a.textsaldo[w];
			a.titik = sald.str();
			if(a.titik.length()>3){
				a.titik.insert(a.titik.end()-3,'.');
			}
			if(a.titik.length()>7){
				a.titik.insert(a.titik.end()-7,'.');
			}
			if(a.titik.length()>11){
				a.titik.insert(a.titik.end()-11,'.');
			}
			gotoxy(51,5);cout<<"INFORMASI SALDO";
			gotoxy(36,8);cout<<"SALDO : RP\t\t      "<<a.titik;
			gotoxy(51,13);cout<<"TRANSAKSI LAGI?";
			gotoxy(87,13);cout<<"YA =>";
			gotoxy(84,17);cout<<"TIDAK =>";
			pilihanHJ();
			if(ch=='J' || ch=='X'){
				a.pil="7";
			}
		}
		void TL(){
			header();
			downheader();
			gotoxy(49,5);cout<<"PILIH JENIS TRANSAKSI";
			gotoxy(25,9);cout<<"<= PENARIKAN";      gotoxy(76,9);cout<<"INFO REKENING =>";
			gotoxy(25,13);cout<<"<= TRANSFER";    	  gotoxy(79,13);cout<<"PEMBAYARAN =>";
			gotoxy(25,17);cout<<"<= PEMBELIAN";         gotoxy(81,17);cout<<"UBAH PIN =>";
			gotoxy(25,21);cout<<"<= LAINNYA";             gotoxy(83,21);cout<<"KELUAR =>";
			pilihanx();
			if(ch=='A'){
				penarikan();
			}
			else if(ch=='S'){
				transfer();
			}
			else if(ch=='D'){
				pembelian();
			}
			else if(ch=='F'){
				belumtersedia();
			}
			else if(ch=='G'){
				ats:
				header();
				downheader();
				gotoxy(48,5);cout<<"PILIH JENIS TRANSAKSI";
				gotoxy(25,9);cout<<"<= MUTASI REKENING";
				gotoxy(25,13);cout<<"<= INFO POINT";
				gotoxy(79,9);cout<<"INFO SALDO =>";
				pilihanASG();
				if(ch=='G'){
					ceksaldo();	
				}
				else if(ch=='S'){
					prosestunggu();
					header();
					downheader();
					gotoxy(54,8);cout<<"INFO POINT";
					gotoxy(47,12);cout<<"ANDA TIDAK MEMILIKI POINT";
					gotoxy(52,17);cout<<"TRANSAKSI LAGI?";
					gotoxy(87,17);cout<<"YA =>";
					gotoxy(84,21);cout<<"TIDAK =>";
					pilihanJK();
				}
				else if(ch=='A'){
					prosestunggu();
					header();
					downheader();
					gotoxy(45,9);cout<<"SILAKAN AMBIL RECEIPT ANDA";
					Sleep(2000);
					succes();
				}
				else if (ch=='X'){
					a.pil=="7";
				}
			}
			else if(ch=='H'){
				belumtersedia();
			}
			else if(ch=='J'){
				gantipin();
			}
			else if(ch=='K' || ch=='X'){
				a.pil="7";
			}
		}
		void menu1(){
			menu1:
			header();
			downheader();
			gotoxy(47,5);cout<<"PILIH JUMLAH PAKET TUNAI";
			gotoxy(25,9);cout<<"<= 100.000"; gotoxy(80,9);cout<<"1.000.000 =>";
			gotoxy(25,13);cout<<"<= 200.000";	gotoxy(80,13);cout<<"1.500.000 =>";		
			gotoxy(25,17);cout<<"<= 300.000"; gotoxy(80,17);cout<<"2.000.000 =>";
			gotoxy(25,21);cout<<"<= 500.000"; gotoxy(72,21);cout<<"TRANSAKSI LAINNYA =>";
			pilihanx();
			a.sisasaldo=a.textsaldo[w];
			if(ch=='A'){
				a.sisasaldo-=100000;
				if(a.sisasaldo>=50000){
				a.textsaldo[w]=a.textsaldo[w]-100000;
				prosestunggu();berhasiltarik();savedata();a.pil="7";
				}
			}
			else if(ch=='S'){
				a.sisasaldo-=200000;
				if(a.sisasaldo>=50000){
				a.textsaldo[w]=a.textsaldo[w]-200000;
				prosestunggu();berhasiltarik();savedata();a.pil="7";
				}
			}
			else if(ch=='D'){
				a.sisasaldo-=300000;
				if(a.sisasaldo>=50000){
				a.textsaldo[w]=a.textsaldo[w]-300000;
				prosestunggu();berhasiltarik();savedata();a.pil="7";
				}
			}
			else if(ch=='F'){
				a.sisasaldo-=500000;
				if(a.sisasaldo>=50000){
				a.textsaldo[w]=a.textsaldo[w]-500000;
				prosestunggu();berhasiltarik();savedata();a.pil="7";
				}
			}
			else if(ch=='G'){
				a.sisasaldo-=1000000;
				if(a.sisasaldo>=50000){
				a.textsaldo[w]=a.textsaldo[w]-1000000;
				prosestunggu();berhasiltarik();savedata();a.pil="7";
				}
			}
			else if(ch=='H'){
				a.sisasaldo-=1500000;
				if(a.sisasaldo>=50000){
				a.textsaldo[w]=a.textsaldo[w]-1500000;
				prosestunggu();berhasiltarik();savedata();a.pil="7";
				}
			}
			else if(ch=='J'){
				a.sisasaldo-=2000000;
				if(a.sisasaldo>=50000){
				a.textsaldo[w]=a.textsaldo[w]-2000000;
				prosestunggu();berhasiltarik();savedata();a.pil="7";
				}
			}
			else if(ch=='K'){
				TL();
			}
			else if(ch=='X'){
				a.pil="7";
			}
			else {
				gagal();
			}
		}		
		
};
class DATABASE{
	public:
		void DataBase(){
			ifile.open("bankbri.txt");
			r=0;
			i=0;
			while(!ifile.eof()){
				getline(ifile,kata);
				a.textcard[i]=kata;
				getline(ifile,kata);
				a.textnama[i]=kata;
				getline(ifile,kata);
				a.textnorek[i]=kata;
				getline(ifile,kata);
				y=atoi(kata.c_str());
				a.textsaldo[i]=y;
				getline(ifile,kata);
				a.textpin[i]=kata;
				getline(ifile,kata);
				i++;
				r++;
			}
			r-=1;
			ifile.close();
		}
};

int main(){
	system ("COLOR 17");
	DATABASE DB;
	English en;
	Indonesia ind;
	DB.DataBase();
	animasi();
	do{
		hea:
		a.pil="1";
		ch='Z';
		ind.beranda();
		if(ch=='X'){
			goto hea;
		}
		else if(a.card!=a.textcard[w]){
			header();
			downheader();
			gotoxy(41,14);cout<<"NOMOR KARTU ATM ANDA TIDAK TERDAFTAR!";
			gotoxy(38,15);cout<<"-----------------------------------------";
			gotoxy(38,16);cout<<"YOUR NUMBER CARD OF ATM IS NOT REGISTERED!";
			ps();
		}
		else{
			if(a.card!=a.blokir){
				a.bpin=0;	
			}
			bhs:
			ind.bahasa();
			if(a.xx=='H'){
				ind.infoIND();
			}
			else if(a.xx=='J'){
				en.infoENG();
			}
			do{
				if(a.xx=='H'||a.xx=='J'){
				ind.pinIND();
				}
			}while(a.pil!="7");
			ind.terimakasih();
			a.blokir=a.card;
		}
	}while(1);		
}
