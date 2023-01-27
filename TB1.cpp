#include <iostream>
#include <conio.h>
using namespace std;

long total = 0;
void pesan()
{

	int n, tipe[50];
	string nama[50];
	long harga[50];

	cout << "Masukan Jumlah Pembelian Tiket = ";
	cin >> n;
	cout << endl;

	cout << "      MENU PESAN TIKET" << endl;
	cout << "-----------------------------------" << endl;
	cout << "Kode    Kelas          harga" << endl;
	cout << "1.     Reguler        Rp.100000" << endl;
	cout << "2.     VIP Silver     Rp.200000" << endl;
	cout << "3.     VIP Gold       Rp.250000" << endl;
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << endl;

	menu_tiket:
		cout << "Tiket ke-" << i + 1 << endl;
		cout << "Nama Pembeli = ";
		cin >> nama[i];
		cout << "Kode Tiket = ";
		cin >> tipe[i];

		if (tipe[i] == 1)
		{
			harga[i] = 100000;
		}
		else if (tipe[i] == 2)
		{
			harga[i] = 200000;
		}
		else if (tipe[i] == 3)
		{
			harga[i] = 250000;
		}
		else
		{
			cout << "\nKode Tiket Tidak Ada" << endl;
			cout << "Masukkan Ulang\n"
				 << endl;
			goto menu_tiket;
		}
	}

	system("cls");
	cout << endl;
	cout << "       JUMLAH PEMBELIAN TIKET" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "No    Nama           Tipe           Harga         " << endl;
	cout << "-------------------------------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ".    " << nama[i] << "             " << tipe[i] << "          Rp." << harga[i] << endl;
		cout << "-------------------------------------------" << endl;
	}

	for (int a = 0; a < n; a++)
	{
		total = total + harga[a];
	}
	cout << "Total=				   Rp." << int(total) << endl;
	cout << "-------------------------------------------" << endl;
}

bool pembayaran()
{
	long uang_bayar, diskon, kembali;

	if (total > 500000)
	{
		diskon = 0.1 * total;
		cout << "-------------------------------------------" << endl;
		cout << "Mendapatkan Diskon 10%: Rp." << diskon << endl;
		cout << "-------------------------------------------" << endl;
	}
	else
	{
		diskon = 0 * total;
		cout << "-------------------------------------------" << endl;
		cout << "Tidak Mendapatkan Diskon" << endl;
		cout << "Pembelian Di Atas Rp.500000 (Diskon 10%)" << endl;
		cout << "-------------------------------------------" << endl;
	}

	long bayar = total - diskon;
	cout << "\nTotal Bayar Setelah Diskon: Rp." << bayar << endl;

bayar:
	cout << "Uang Bayar: Rp.";
	cin >> uang_bayar;
	kembali = uang_bayar - bayar;

	if (kembali >= 0)
	{
		cout << "Kembalian: Rp." << kembali << endl;
		return true;
	}
	else
	{
		cout << "Uang tidak cukup, masukkan jumlah yang valid" << endl;
		goto bayar;
	}
}

int main()
{
	cout << "=======================================\n";
	cout << "        KONSER JUSTIN BEIBER\n";
	cout << "    Pemesanan Tiket Secara Online\n";
	cout << "   Reguler - VIP Silver - VIP Gold\n";
	cout << "=======================================\n";
	pesan();
	if (pembayaran())
	{
		cout << endl;
		cout << "=======================================\n";
		cout << "          TERIMA KASIH\n";
		cout << "=======================================\n";
		cout << endl;
	}
	// agar tidak lansung keluar dari terminal setelah selesai
	getch();
}