#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>

using namespace std;

#define first_sales(P) ((P).first_sales)
#define first_motor(P) ((P).first_motor)
#define info_sales(P) (P)->info_sales
#define info_motor(P) (P)->info_motor
#define next_sales(P) (P)->next_sales
#define next_motor(P) (P)->next_motor
#define next_jual(P) (P)->next_jual
#define nil NULL

struct sales {
    string nama_sales;
    int id_sales;
};
struct motor {
    string nama_motor;
    int harga, cc;
};
typedef struct elm_sales *adr_sales;
typedef struct elm_motor *adr_motor;
struct elm_sales {
    sales info_sales;
    adr_sales next_sales;
    adr_motor next_jual;
};
struct elm_motor {
    motor info_motor;
    adr_motor next_motor;
};
struct list_sales {
    adr_sales first_sales;
};
struct list_motor {
    adr_motor first_motor;
};

void createListSales(list_sales &ls);
void createListMotor(list_motor &lm);
adr_sales createElmSales(sales s);
adr_motor createElmMotor(motor m);
void insertSales(list_sales &ls, adr_sales s);
void insertMotor(list_motor &lm, adr_motor m);
void deleteSalesAndMotor(list_sales &ls, string namaSales, adr_sales &p);
void deleteMotor(list_sales &ls, list_motor &lm, string namaSales, string namaMotor);
void showSales(list_sales ls);
adr_sales searchSales(list_sales &ls, string namaSales);
adr_motor searchMotor(list_motor &lm, string namaMotor);
adr_motor searchMotorInSales(list_sales &ls, list_motor &lm, string namaSales, string namaMotor);
int jumMotor(list_sales &ls, string namaSales);
void addSalesToMotor(list_sales &ls, list_motor &lm, string namaSales, string namaMotor);
void showAll(list_sales ls);
int menu();

#endif // MLL_H_INCLUDED
