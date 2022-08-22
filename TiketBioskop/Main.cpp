#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <conio.h>

using namespace std;
string hariTayang, waktuTayang;

int filmPilihan, ticketCount, pilihSort;

struct Movies {
	string judulFilm;
	int hargaTiket;
	int theater;
};

struct pilihKursimu {
	string kursiBioskop[25];
	int sisaTiket;
};

const int MAX_VALUE = 5;
Movies mv[MAX_VALUE];
string kursiPilihan[25];
pilihKursimu kursi[MAX_VALUE];

void initialization() {

	string judulFilm[5] = { "THOR: LOVE AND THUNDER", "MINIONS2: THE RISE OF GRU", "NGERI-NGERI SEDAP", "RANAH 3 WARNA", "KELUARGA CEMARA 2" };
	int hargaTiket[5] = { 40000, 35000, 40000, 35000, 40000 };
	int theater[5] = { 1, 2, 3, 4, 5 };

	//assign data ke struct
	for (int i = 0; i < 5; i++)
	{
		mv[i].judulFilm = judulFilm[i];
		mv[i].hargaTiket = hargaTiket[i];
		mv[i].theater = theater[i];
	}

	string kursiBioskop[25] = { "1A", "2A", "3A", "4A", "5A", "1B", "2B", "3B", "4B", "5B","1C", "2C", "3C", "4C", "5C", "1D", "2D", "3D", "4D", "5D", "1E", "2E", "3E", "4E", "5E" };

	//assign data ke struct
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 25; i++) {

			kursi[j].kursiBioskop[i] = kursiBioskop[i];
			kursi[j].sisaTiket = 25;
		}
	}
}

bool sortHargaTiketAsc(Movies h1, Movies h2) {
	if (h1.hargaTiket < h2.hargaTiket) {
		return true;
	}
	return false;
}

bool sortHargaTiketDesc(Movies h1, Movies h2) {
	if (h1.hargaTiket > h2.hargaTiket) {
		return true;
	}
	return false;
}

void menuBioskop() {

	cout << "\t\t\t_____________________________________" << endl;
	cout << "\t\t\t|                                    |" << endl;
	cout << "\t\t\t|            MENU BIOSKOP            |" << endl;
	cout << "\t\t\t|____________________________________|" << endl;
	cout << "\t\t\t|                                    |" << endl;
	cout << "\t\t\t| [1] Tampilkan Daftar Film          |" << endl;
	cout << "\t\t\t| [2] Cari Judul Film                |" << endl;
	cout << "\t\t\t| [3] Cek Ketersediaan Kursi         |" << endl;
	cout << "\t\t\t| [4] Cek Sisa Tiket                 |" << endl;
	cout << "\t\t\t| [5] Sort Film Berdasarkan Harga    |" << endl;
	cout << "\t\t\t| [6] Keluar                         |" << endl;
	cout << "\t\t\t|____________________________________|" << endl;
}

void pilihKursi() {
	cout << "\t\t\tMasukkan jumlah tiket yang ingin dibeli: ";
	cin >> ticketCount;

	kursi[filmPilihan].sisaTiket -= ticketCount;

	for (int loop = 0; loop < ticketCount; loop++) {

		pilihKursiLagi:
		cout << "\t\t\t";
		for (int i = 0; i < 5; i++) {
			cout << kursi[filmPilihan].kursiBioskop[i] << " ";
		}
		cout << endl;

		cout << "\t\t\t";
		for (int i = 5; i < 10; i++) {
			cout << kursi[filmPilihan].kursiBioskop[i] << " ";
		}
		cout << endl;

		cout << "\t\t\t";
		for (int i = 10; i < 15; i++) {
			cout << kursi[filmPilihan].kursiBioskop[i] << " ";
		}
		cout << endl;

		cout << "\t\t\t";
		for (int i = 15; i < 20; i++) {
			cout << kursi[filmPilihan].kursiBioskop[i] << " ";
		}

		cout << endl;
		cout << "\t\t\t";

		for (int i = 20; i < 25; i++) {
			cout << kursi[filmPilihan].kursiBioskop[i] << " ";
		}

		cout << endl;
		cout << endl;
		cout << "\t\t\t";
		cout << "Pilih kursi " << "ke-" << loop + 1 << " kamu: ";
		cin >> kursiPilihan[loop];

		for(int y = 0; y < 25; y++) {
			if (kursiPilihan[loop] == kursi[filmPilihan].kursiBioskop[y]) {
				kursi[filmPilihan].kursiBioskop[y] = "X";
				break;
			}
		}

		cout << endl;
	}

	cout << "\t\t\t";
	for (int i = 0; i < 5; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}
	cout << endl;

	cout << "\t\t\t";
	for (int i = 5; i < 10; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}
	cout << endl;

	cout << "\t\t\t";
	for (int i = 10; i < 15; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}
	cout << endl;

	cout << "\t\t\t";
	for (int i = 15; i < 20; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}

	cout << endl;
	cout << "\t\t\t";

	for (int i = 20; i < 25; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}
	cout << endl;
}

void printKursi() {
	
	char konfirm;

	cout << "\t\t\t";
	for (int i = 0; i < 5; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}
	cout << endl;

	cout << "\t\t\t";
	for (int i = 5; i < 10; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}
	cout << endl;

	cout << "\t\t\t";
	for (int i = 10; i < 15; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}
	cout << endl;

	cout << "\t\t\t";
	for (int i = 15; i < 20; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}

	cout << endl;
	cout << "\t\t\t";

	for (int i = 20; i < 25; i++) {
		cout << kursi[filmPilihan].kursiBioskop[i] << " ";
	}

	cout << endl << endl;
}

void pilihHari() {

	int hariSelector;

	string hariHari[7] = { "Mon, 31-May" , "Tue, 31-May", "Wed, 01-Jun", "Thu, 02-Jun", "Fri, 03-Jun", "Sat, 04-Jun", "Sun, 05-Jun" };

	cout << "\t\t\t_____________________________________" << endl;
	cout << "\t\t\t|                                    |" << endl;
	cout << "\t\t\t|           Hari tayang film         |" << endl;
	cout << "\t\t\t|____________________________________|" << endl;
	cout << "\t\t\t[1] Senin, 30 Mei \n";
	cout << "\t\t\t[2] Selasa, 31 Mei \n";
	cout << "\t\t\t[3] Rabu, 1 Juni \n";
	cout << "\t\t\t[4] Kamis, 2 Juni \n";
	cout << "\t\t\t[5] Jumat, 3 Juni \n";
	cout << "\t\t\t[6] Sabtu, 4 Juni \n";
	cout << "\t\t\t[7] Minggu, 5 Juni \n" << endl;
	cout << "\t\t\tPilih hari yang anda inginkan: ";
	cin >> hariSelector;

	hariSelector--;
	hariTayang = hariHari[hariSelector];
}

void pilihWaktu() {
	int waktuSelector;

	string waktuWaktu[5] = { "10:30", "12:00", "16:00", "19:15 [Dolby Atmos]", "21:00" };

	cout << "\t\t\t_____________________________________" << endl;
	cout << "\t\t\t|                                   | " << endl;
	cout << "\t\t\t|         Waktu tayang film         | " << endl;
	cout << "\t\t\t|___________________________________|" << endl;
	cout << "\t\t\t[1] 10:30 \n";
	cout << "\t\t\t[2] 12:00 \n";
	cout << "\t\t\t[3] 16:00 \n";
	cout << "\t\t\t[4] 19:15 [Dolby Atmos] \n";
	cout << "\t\t\t[5] 21:00 \n" << endl;
	cout << "\t\t\tPilih waktu yang anda inginkan: ";
	cin >> waktuSelector;

	waktuSelector--;

	waktuTayang = waktuWaktu[waktuSelector];
	
	cout << endl;
}

void pilihFilm() {

	cout << "\t\t\t_____________________________________" << endl;
	cout << "\t\t\t|                                    |" << endl;
	cout << "\t\t\t|             DAFTAR FILM            |" << endl;
	cout << "\t\t\t|____________________________________|" << endl;

	for (int f = 0; f < 5; f++) {
		cout << "\t\t\t_____________________________________" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t|     FILM #" << left << setw(24) << f + 1 << "|" << endl;
		cout << "\t\t\t|___________________________________|" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t|     " << left << setw(30) << mv[f].judulFilm << "|" << endl;
		cout << "\t\t\t|     IDR " << left << setw(26) << mv[f].hargaTiket << "|" << endl;
		cout << "\t\t\t|     THEATRE : " << left << setw(20) << mv[f].theater << "|" << endl;
		cout << "\t\t\t|___________________________________|" << endl;
		cout << endl;
	}

	cout << "\t\t\tMasukkan nomor film pilihan kamu: ";
	cin >> filmPilihan;
	filmPilihan--;

}

void menuFilm() {

	cout << "\t\t\t_____________________________________" << endl;
	cout << "\t\t\t|                                    |" << endl;
	cout << "\t\t\t|             DAFTAR FILM            |" << endl;
	cout << "\t\t\t|____________________________________|" << endl;

	for (int f = 0; f < 5; f++) {
		cout << "\t\t\t_____________________________________" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t|     FILM #" << left << setw(24) << f + 1 << "|" << endl;
		cout << "\t\t\t|___________________________________|" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t|     " << left << setw(30) << mv[f].judulFilm << "|" << endl;
		cout << "\t\t\t|     IDR " << left << setw(26) << mv[f].hargaTiket << "|" << endl;
		cout << "\t\t\t|     THEATRE : " << left << setw(20) << mv[f].theater << "|" << endl;
		cout << "\t\t\t|___________________________________|" << endl;
		cout << endl;
	}
}

void pilihFilmKursi() {

	cout << "\t\t\t_____________________________________" << endl;
	cout << "\t\t\t|                                    |" << endl;
	cout << "\t\t\t|             DAFTAR FILM            |" << endl;
	cout << "\t\t\t|____________________________________|" << endl;

	for (int f = 0; f < 5; f++) {
		cout << "\t\t\t_____________________________________" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t|     FILM #" << left << setw(24) << f + 1 << "|" << endl;
		cout << "\t\t\t|___________________________________|" << endl;
		cout << "\t\t\t|                                   |" << endl;
		cout << "\t\t\t|     " << left << setw(30) << mv[f].judulFilm << "|" << endl;
		cout << "\t\t\t|     IDR " << left << setw(26) << mv[f].hargaTiket << "|" << endl;
		cout << "\t\t\t|     THEATRE : " << left << setw(20) << mv[f].theater << "|" << endl;
		cout << "\t\t\t|___________________________________|" << endl;
		cout << endl;
	}

	cout << "\t\t\tMasukkan nomor film pilihan kamu: ";
	cin >> filmPilihan;
	filmPilihan--;
}

void cekSisaTiket() {

	char konfirm;

	cout << "\t\t\t________________________________________________" << endl;
	cout << "\t\t\t|                                              |" << endl;
	cout << "\t\t\t| Sisa tiket " << left << setw(26) << mv[filmPilihan].judulFilm << " = " << left << setw(5) << kursi[filmPilihan].sisaTiket << "|" << endl;
	cout << "\t\t\t|______________________________________________|" << endl;
}

void pembayaran() {

	int totalHarga, uangAnda, kembalian;
	totalHarga = mv[filmPilihan].hargaTiket * ticketCount;
	cout << "\t\t\tTotal harga tiket: Rp." << totalHarga << endl;
	
	bayar:
	cout << "\t\t\tUang kamu: Rp.";
	cin >> uangAnda;


	if (uangAnda > totalHarga) {
		kembalian = uangAnda - totalHarga;
		cout << "\t\t\tKembalian kamu: Rp." << kembalian << endl;
	}
	else if (uangAnda < totalHarga) {
		cout << "\t\t\tUang kamu kurang! Masukkan jumlah yang benar\n";
		goto bayar;
	}
	else if (uangAnda == totalHarga) {
		cout << "\t\t\tUang kamu pas!\n" << endl;

	}
	cout << endl << endl;
}

void searchMovies() {

	string search;
	char konfirm;

	cout << "\t\t\tMasukkan judul film yang ingin dicari: ";
	cin >> search;

	for (int q = 0; q < MAX_VALUE; q++) {
		if (mv[q].judulFilm.find(search) != string::npos) {
			cout << "\t\t\tFilm ditemukan dengan kode #" << q + 1 << endl;
			cout << "\t\t\t>>" << mv[q].judulFilm << endl << endl;
		}
		else {
			cout << "\t\t\tFilm tidak ditemukan" << " pada kode #" << q + 1 << endl << endl;
		}
	}
}

void pilihSortFilm(){

	cout << "\t\t\t[1]Tampilkan Film Berdasarkan Harga Ascending" << endl;
	cout << "\t\t\t[2]Tampilkan Film Berdasarkan Harga Descending" << endl;
	cout << "\t\t\tPilih pengurutan yang kamu inginkan: ";
	cin >> pilihSort;
}

void cetakTiket() {
	
	char konfirm;

	for (int cetak = 0; cetak < ticketCount; cetak++) {

		cout << "\t\t\t____________________________________\n";
		cout << "\t\t\t|                                   |\n";
		cout << "\t\t\t|            EMPIRE XXI             |\n";
		cout << "\t\t\t|___________________________________|\n";
		cout << "\t\t\t|                                   |\n";
		cout << "\t\t\t| " <<left << setw(34) << mv[filmPilihan].judulFilm << "|" << endl;
		cout << "\t\t\t|                                   |\n";
		cout << "\t\t\t| PRICE   : " << left << setw(24) << mv[filmPilihan].hargaTiket << "|" << endl;
		cout << "\t\t\t|                                   |\n";
		cout << "\t\t\t| ROW     : " << left << setw(7) << kursiPilihan[cetak][1] << "SEAT : " << left << setw(10) << kursiPilihan[cetak][0] << "|" << endl;
		cout << "\t\t\t|                                   |\n";
		cout << "\t\t\t| DATE    : "  << left << setw(24) << hariTayang << "|" << endl;
		cout << "\t\t\t|                                   |\n";
		cout << "\t\t\t| TIME    : " << left << setw(24) << waktuTayang << "|" << endl;
		cout << "\t\t\t|                                   |\n";
		cout << "\t\t\t| THEATRE : " << left << setw(24) << mv[filmPilihan].theater << "|" << endl;
		cout << "\t\t\t|___________________________________|\n";
		cout << endl << endl;
	}
	cout << endl << endl;
}

int main() {
	
	int menuDipilih;
	char konfirm;
	int konfirmasi;
	initialization();

	balikMenu:
	menuBioskop();

	cout << "\t\t\tPilih Menu: ";
	cin >> menuDipilih;

	while (menuDipilih < 1 || menuDipilih > 6) {
		cout << "\t\t\tMasukkan pilihan yang benar!" << endl;
		goto balikMenu;
	}

	switch (menuDipilih) {
	case 1:
		system("CLS");
		menuFilm();
		cout << "\t\t\t____________________________________" << endl;
		cout << "\t\t\t| [1] Beli tiket                    |" << endl;
		cout << "\t\t\t| [2] Kembali ke menu               |" << endl;
		cout << "\t\t\t|___________________________________|" << endl;
		cout << "\t\t\tMasukkan pilihan kamu: ";
		cin >> konfirmasi;

		switch (konfirmasi) {
		case 1:
			pilihFilm();
			pilihKursi();
			pilihHari();
			pilihWaktu();
			pembayaran();
			cetakTiket();
			cout << "\t\t\tApakah anda ingin kembali ke menu? y/n: ";
			cin >> konfirm;

			if (konfirm != 'y' && konfirm != 'Y') {
				exit(0);
			}
			else {
				goto balikMenu;
			}
			break;
		case 2:
			goto balikMenu;
			break;
		}
		break;
	case 2:
		cariLagi:
		searchMovies();
		cout << "\t\t\tApa kamu ingin cari film lagi? y/n: ";
		cin >> konfirm;
		if (konfirm == 'y' || konfirm == 'Y') {
			goto cariLagi;
		}
		else {
			goto balikMenu;
		}
		break;
	case 3:
		pilihFilmKursi();
		printKursi();
		cout << "\t\t\tApakah anda ingin kembali ke menu? y/n: ";
		cin >> konfirm;
		if (konfirm != 'y' && konfirm != 'Y') {
			exit(0);
		} else {
			goto balikMenu;
		}
	case 4:
		pilihFilmKursi();
		cekSisaTiket();
		cout << "\t\t\tApakah anda ingin kembali ke menu? y/n: ";
		cin >> konfirm;
		if (konfirm != 'y' && konfirm != 'Y') {
			exit(0);
		}
		else {
			goto balikMenu;
		}
		break;
	case 5:
		pilihSortFilm();
		switch (pilihSort) {
		case 1:
			sort(mv, mv + 5, sortHargaTiketAsc);
			cout << "\t\t\tData berhasil disorting!" << endl;
			break;
		case 2:
			sort(mv, mv + 5, sortHargaTiketDesc);
			cout << "\t\t\tData berhasil disorting!" << endl;
			break;
		}
		goto balikMenu;
		break;
	case 6:
		exit(0);
		break;
	}

	return 0;
}

/**
Ku tak bisa coding yang indah
Dan bervalidasi
Yang kuingin langsung saja
Yang penting jadi
**/

/**
Sudah saya coba bikin validasi
Tapi malah mengulang tak ada henti
Saya tak sanggup lagi
**/
