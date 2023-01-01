#include "MLL.h"

void createListSales(list_sales &ls){
    first_sales(ls) = nil;
}
void createListMotor(list_motor &lm){
    first_motor(lm) = nil;
}
adr_sales createElmSales(sales s){
    adr_sales p = new elm_sales;
    info_sales(p) = s;
    next_sales(p) = nil;
    next_jual(p) = nil;
    return p;
}
adr_motor createElmMotor(motor m){
    adr_motor x = new elm_motor;
    info_motor(x) = m;
    next_motor(x) = nil;
    return x;
}
void insertSales(list_sales &ls, adr_sales s){
    if(first_sales(ls) == nil){
        first_sales(ls) = s;
        next_sales(s) = first_sales(ls);
    } else {
        adr_sales p;
        p = first_sales(ls);
        while(next_sales(p) != first_sales(ls)){
            p = next_sales(p);
        }
        next_sales(p) = s;
        next_sales(s) = first_sales(ls);
    }
}
void insertMotor(list_motor &lm, adr_motor m){
    if(first_motor(lm) == nil){
        first_motor(lm) = m;
        next_motor(m) = nil;
    } else {
        adr_motor q;
        q = first_motor(lm);
        while(next_motor(q) != nil){
            q = next_motor(q);
        }
        next_motor(q) = m;
        next_motor(m) = nil;
    }
}
void deleteSalesAndMotor(list_sales &ls, string namaSales, adr_sales &p){
    adr_sales x;
    p = searchSales(ls, namaSales);
    if (p == nil){
        cout << "Data Kosong" << endl;
    } else if (p == first_sales(ls)){
        x = first_sales(ls);
        while(next_sales(x) != first_sales(ls)){
            x = next_sales(x);
        }
        first_sales(ls) = next_sales(first_sales(ls));
        next_sales(x) = first_sales(ls);
        next_sales(p) = nil;
    } else if (next_sales(p) == first_sales(ls)){
        x = first_sales(ls);
        while(next_sales(x) != p){
            x = next_sales(x);
        }
        next_sales(x) = first_sales(ls);
        next_sales(p) = nil;
    } else {
        x = first_sales(ls);
        while(next_sales(x) != p){
            x = next_sales(x);
        }
        next_sales(x) = next_sales(p);
        next_sales(p) = nil;
    }
}
void deleteMotor(list_sales &ls, list_motor &lm, string namaSales, string namaMotor){
    adr_motor x, p;
    adr_sales s = searchSales(ls, namaSales);
    p = searchMotorInSales(ls, lm, namaSales, namaMotor);
    if(p == nil){
        cout << "Data Kosong" << endl;
    }else if (p == first_motor(lm)){
        first_motor(lm) = next_motor(first_motor(lm));
        next_motor(p) = nil;
        next_jual(s) = nil;
    } else if (next_motor(p) == nil){
        x = first_motor(lm);
        while(next_motor(x) != p){
            x = next_motor(x);
        }
        next_motor(p) = nil;
        next_jual(s) = nil;
    } else {
        x = first_motor(lm);
        while(next_motor(x) != p){
            x = next_motor(x);
        }
        next_motor(x) = next_motor(p);
        next_motor(p) = nil;
        next_jual(s) = nil;
    }
}
void showSales(list_sales ls){
    cout << "========Data Sales========"<<endl<<endl;
    if (first_sales(ls) != nil){
        adr_sales p = first_sales(ls);
        cout << "Sales : " << info_sales(p).nama_sales << "(" << info_sales(p).id_sales << ")" << endl;
        p = next_sales(p);
        while(p != first_sales(ls)){
            cout << "Sales : " << info_sales(p).nama_sales << "(" << info_sales(p).id_sales << ")" << endl;
            p = next_sales(p);
        }
        cout << endl;
    } else {
        cout << "List Kosong" << endl;
    }
}
adr_sales searchSales(list_sales &ls, string namaSales){
    adr_sales p = first_sales(ls);
    while(p != nil){
        if(info_sales(p).nama_sales == namaSales){
            return p;
        }
        p = next_sales(p);
    }
    return nil;
}
adr_motor searchMotor(list_motor &lm, string namaMotor){
    adr_motor p = first_motor(lm);
    while(p != nil){
        if(info_motor(p).nama_motor == namaMotor){
            return p;
        }
        p = next_motor(p);
    }
    return nil;
}
adr_motor searchMotorInSales(list_sales &ls, list_motor &lm, string namaSales, string namaMotor){
    adr_sales p = searchSales(ls, namaSales);
    if (p != nil){
       if(info_motor(next_jual(p)).nama_motor == namaMotor){
            return next_jual(p);
        } else {
            return nil;
        }
    } else {
        return nil;
    }
}
int jumMotor(list_sales &ls, string namaSales){
    adr_sales p = searchSales(ls, namaSales);
    if(next_jual(p) != nil){
        return 1;
    } else {
        return 0;
    }
}
void addSalesToMotor(list_sales &ls, list_motor &lm, string namaSales, string namaMotor){
    adr_sales p = searchSales(ls, namaSales);
    adr_motor q = searchMotor(lm, namaMotor);
    if(next_jual(p) == nil){
        next_jual(p) = q;
    }
}
void showAll(list_sales ls){
    cout << "========Data Sales dan Penjualannya========"<<endl<<endl;
    if (first_sales(ls) != nil){
        adr_sales p = first_sales(ls);
        cout << "Sales : " << info_sales(p).nama_sales << "(" << info_sales(p).id_sales << ")" <<endl;
        if(next_jual(p) != nil){
            cout << "Motor : " << info_motor(next_jual(p)).nama_motor << "(" << info_motor(next_jual(p)).cc << ")" << " " << info_motor(next_jual(p)).harga << endl;
        }
        p = next_sales(p);
        cout << endl;
        while(p != first_sales(ls)){
            cout << "Sales : " << info_sales(p).nama_sales << "(" << info_sales(p).id_sales << ")" <<endl;
            if(next_jual(p) != nil){
                cout << "Motor : " << info_motor(next_jual(p)).nama_motor << "(" << info_motor(next_jual(p)).cc << ")" << " " << info_motor(next_jual(p)).harga << endl;
            }
            p = next_sales(p);
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "List Kosong" << endl;
    }
}
int menu(){
    cout << "Menu" << endl;
    cout << "1. Masukkan Data Sales" << endl;
    cout << "2. Masukkan Data Motor" << endl;
    cout << "3. Menghubungkan Sales ke Motor" << endl;
    cout << "4. Hapus Data Sales" << endl;
    cout << "5. Hapus Data Motor" << endl;
    cout << "6. Jumlah Penjualan Motor Sales" << endl;
    cout << "7. Show Sales" << endl;
    cout << "8. Show All" << endl;
    cout << "Masukkan Pilihan : ";

    int i = 0;
    cin >> i;
    return i;
}
