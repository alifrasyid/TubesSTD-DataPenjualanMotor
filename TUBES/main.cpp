#include "MLL.h"

int main()
{
    list_sales ls;
    list_motor lm;
    createListSales(ls);
    createListMotor(lm);
    adr_sales p;
    adr_motor q;
    sales s;
    motor m;
    string namaSales, namaMotor;
    char y;
    int pilihan = 0, n, i;
    pilihan = menu();
    while(pilihan != 0){
        system("cls");
        switch(pilihan){
        case 1:
            i = 0;
            cout << "Jumlah Sales yang akan ditambahkan: ";
            cin >> n;
            cout << endl;
            while(i < n){
                cout << "Masukkan Nama Sales : ";
                cin >> s.nama_sales;
                cout << "Masukkan ID Sales : ";
                cin >> s.id_sales;
                p = createElmSales(s);
                insertSales(ls, p);
                i++;
            }
            cout << endl;
            break;

        case 2:
            i = 0;
            cout << "Jumlah Motor yang akan ditambahkan: ";
            cin >> n;
            cout << endl;
            while(i < n){
                cout << "Masukkan Nama Motor : ";
                cin >> m.nama_motor;
                cout << "Masukkan CC Motor : ";
                cin >> m.cc;
                cout << "Masukkan Harga Motor : ";
                cin >> m.harga;
                q = createElmMotor(m);
                insertMotor(lm, q);
                i++;
            }
            cout << endl;
            break;

        case 3:
            cout << "Masukkan Nama Sales : ";
            cin >> namaSales;
            cout << "Masukkan Nama Motor : ";
            cin >> namaMotor;
            addSalesToMotor(ls, lm, namaSales, namaMotor);
            cout << endl;
            break;

        case 4:
            cout << "Masukkan Sales Yang Ingin Dihapus: ";
            cin >> namaSales;
            deleteSalesAndMotor(ls, namaSales, p);
            cout << endl;
            break;

        case 5:
            cout << "Masukkan Sales Motor: ";
            cin >> namaSales;
            p = searchSales(ls, namaSales);
            if (next_jual(p) != nil){
                cout << "Masukkan Motor Yang Ingin Dihapus: ";
                cin >> namaMotor;
                deleteMotor(ls, lm, namaSales, namaMotor);
                cout << endl;
            } else {
                cout << "Data kosong" << endl << endl;
            }
            break;

        case 6:
            cout << "Nama Sales: ";
            cin >> namaSales;
            cout << "Jumlah Motor Terjual: " << jumMotor(ls, namaSales) << endl << endl;
            break;

        case 7:
            showSales(ls);
            break;

        case 8:
            showAll(ls);
            break;
        }
        cout << "Kembali ke munu utama? (Y/N): ";
        cin >> y;
        if (y == 'Y'){
            cout << endl;
            system("cls");
            pilihan = menu();
            cout << endl;
        } else if (y == 'N') {
            system("cls");
            pilihan = 0;
            cout << endl;
        }

    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;

    return 0;
}
