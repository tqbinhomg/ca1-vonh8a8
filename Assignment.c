#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void yeuCau1();
int UCLN(int a, int b);
int BCNN(int a, int b);
void yeuCau2();
void yeuCau3();
void yeuCau4();
struct giaDien
{
    int mucTieuThu;
    int gia;
};
struct phanSo
{
    int tu;
    int mau;
};
void yeuCau5();
void yeuCau6();
void yeuCau7();
void yeuCau8();
const char *xepLoai(float diem);
void yeuCau9();
void yeuCau10();
struct phanSo nhapPhanSo();
struct phanSo rutGonPS(struct phanSo ps);

int main()
{
    int chon;
    do
    {
        printf("+---------------------------------------------------+\n");
        printf("|                    MENU CHUONG TRINH              |\n");
        printf("+---------------------------------------------------+\n");
        printf("|  0. Thoat chuong trinh                            |\n");
        printf("|  1. Kiem tra so nguyen                            |\n");
        printf("|  2. Tim uoc so chung va boi so chung cua 2 so     |\n");
        printf("|  3. Chuong trinh tinh tien cho quan Karaoke       |\n");
        printf("|  4. Tinh tien dien                                |\n");
        printf("|  5. Doi tien                                      |\n");
        printf("|  6. Tinh lai suat vay ngan hang vay tra gop       |\n");
        printf("|  7. Vay tien mua xe                               |\n");
        printf("|  8. Sap xep thong tin nhan vien                   |\n");
        printf("|  9. Game FPOLY - LOTT (2/15)                      |\n");
        printf("|  10. Tinh toan phan so                            |\n");
        printf("+---------------------------------------------------+\n");
        printf("=> Chon chuc nang cua ban (0-10): ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 0:
            printf("Ban chon chuc nang 0: Thoat chuong trinh\n");
            break;
        case 1:
            yeuCau1();
            break;
        case 2:
            yeuCau2();
            break;
        case 3:
            yeuCau3();
            break;
        case 4:
            yeuCau4();
            break;
        case 5:
            yeuCau5();
            break;
        case 6:
            yeuCau6();
            break;
        case 7:
            yeuCau7();
            break;
        case 8:
            yeuCau8();
            break;
        case 9:
            yeuCau9();
            break;
        case 10:
            yeuCau10();
            break;
        default:
            printf("Ban phai chon chuc nang 0 - 10!\n");
            break;
        }
    } while (chon != 0);
    return 0;
}
void yeuCau1()
{
    float n;
    printf("Ban chon chuc nang 1: Kiem tra so nguyen\n");
    printf("Nhap mot so nguyen: ");
    scanf("%f", &n);
    if (n == (int)n)
    {
        printf("So %f la so nguyen\n", n);
    }
    else
    {
        printf("So %.0f khong phai la so nguyen\n", n);
        printf("So %.0f khong la so nguyen to\n", n);
        printf("So %.0f khong la so chinh phuong\n", n);
        goto ketThuc2;
    }
    if (n <= 1)
    {
        printf("So %.0f khong phai la so nguyen to\n", n);
    }
    else
    {
        for (int i = 2; i <= (int)n / 2; i++)
        {
            if ((int)n % i == 0)
            {
                printf("So %.0f khong phai la so nguyen to\n", n);
                goto ketThuc;
            }
        }
        printf("So %.0f la so nguyen to\n", n);
    }
ketThuc:
    if (n < 0)
    {
        printf("So %.0f khong phai la so chinh phuong\n", n);
    }
    else
    {
        for (int i = 0; i * i <= (int)n; i++)
        {
            if (i * i == (int)n)
            {
                printf("So %.0f la so chinh phuong\n", n);
                goto ketThuc2;
            }
        }
        printf("So %.0f khong phai la so chinh phuong\n", n);
    }
ketThuc2:
}

int UCLN(int a, int b)
{
    int ucln;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    ucln = a;
    return ucln;
}

int BCNN(int a, int b)
{
    int bcnn = (a * b) / UCLN(a, b);
    return bcnn;
}

void yeuCau2()
{
    float a, b;
    printf("Ban chon chuc nang 2: Tim uoc so chung va boi so chung cua 2 so\n");
    printf("Nhap hai so nguyen a va b: ");
    scanf("%f%f", &a, &b);
    while (a != (int)a || b != (int)b)
    {
        printf("Vui long nhap hai so nguyen!\n");
        printf("Nhap hai so nguyen a va b: ");
        scanf("%f%f", &a, &b);
    }
    printf("Uoc so chung lon nhat cua %d va %d la: %d\n", (int)b, (int)a, UCLN((int)a, (int)b));
    printf("Boi so chung nho nhat cua %d va %d la: %d\n", (int)a, (int)b, BCNN((int)a, (int)b));
}

void yeuCau3()
{
    int s, e, tien;
    printf("\nBan chon chuc nang 3: tinh tien dien cho quan karaoke\n");
    printf("\nNhap gio vao: ");
    scanf("%d", &s);
    printf("\nNhap gio ra: ");
    scanf("%d", &e);
    while (s < 12 || e > 23 || s >= e)
    {
        printf("Vui long nhap lai gio vao va gio ra (12-23)!\n");
        printf("\nNhap gio vao: ");
        scanf("%d", &s);
        printf("\nNhap gio ra: ");
        scanf("%d", &e);
    }
    int gio = e - s;
    if (gio <= 3)
    {
        tien = gio * 150000;
    }
    else
    {
        tien = 150000 * 3 + (gio - 3) * 150000 * 0.7;
    }
    // sau khi tinh tien roi moi xet dieu kien giam 10% neu gio vao trong khoang 14-17
    if (s >= 14 && s <= 17)
    {
        tien = tien * 0.9;
    }
    printf("\nSo tien phai tra la: %d vnd\n", tien);
}

void yeuCau4()
{
    int soKW, tongTien = 0;
    struct giaDien bangGiaDien[6] = {
        {50, 1678},
        {100, 1734},
        {200, 2014},
        {300, 2536},
        {400, 2834},
        {401, 2927}};
    printf("\nBan chon chuc nang 4: tinh tien dien\n");
    printf("\nNhap so kWh tieu thu: ");
    scanf("%d", &soKW);
    while (soKW < 0)
    {
        printf("Vui long nhap lai so kWh tieu thu (>=0)!\n");
        printf("\nNhap so kWh tieu thu: ");
        scanf("%d", &soKW);
    }
    if (soKW <= bangGiaDien[0].mucTieuThu)
    {
        tongTien = soKW * bangGiaDien[0].gia;
    }
    else if (soKW <= bangGiaDien[1].mucTieuThu)
    {
        tongTien = 50 * bangGiaDien[0].gia + (soKW - 50) * bangGiaDien[1].gia;
    }
    else if (soKW <= bangGiaDien[2].mucTieuThu)
    {
        tongTien = 50 * bangGiaDien[0].gia + 50 * bangGiaDien[1].gia + (soKW - 100) * bangGiaDien[2].gia;
    }
    else if (soKW <= bangGiaDien[3].mucTieuThu)
    {
        tongTien = 50 * bangGiaDien[0].gia + 50 * bangGiaDien[1].gia + 100 * bangGiaDien[2].gia + (soKW - 200) * bangGiaDien[3].gia;
    }
    else if (soKW <= bangGiaDien[4].mucTieuThu)
    {
        tongTien = 50 * bangGiaDien[0].gia + 50 * bangGiaDien[1].gia + 100 * bangGiaDien[2].gia + 100 * bangGiaDien[3].gia + (soKW - 300) * bangGiaDien[4].gia;
    }
    else
    {
        tongTien = 50 * bangGiaDien[0].gia + 50 * bangGiaDien[1].gia + 100 * bangGiaDien[2].gia + 100 * bangGiaDien[3].gia + 100 * bangGiaDien[4].gia + (soKW - 400) * bangGiaDien[5].gia;
    }
    printf("\nSo tien phai tra cho %d kwh la: %d vnd\n", soKW, tongTien);
}

void yeuCau5()
{
    struct dsMenhGia
    {
        int soLuongTo;
        int menhGia;
    };
    struct dsMenhGia dsTien[] =
        {
            {0, 1000},
            {0, 2000},
            {0, 5000},
            {0, 10000},
            {0, 20000},
            {0, 50000},
            {0, 100000},
            {0, 200000},
            {0, 500000},
        };
    int tien;
    int soTo = 9;
    printf("\nBan chon chuc nang 5: doi tien\n");
    printf("\nNhap so tien can doi: \n");
    scanf("%d", &tien);
    while (tien <= 0)
    {
        printf("\nVui long nhap lai so tien can doi (>0)!\n");
        printf("\nNhap so tien can doi: \n");
        scanf("%d", &tien);
    }
    for (int i = soTo - 1; i >= 0; i--)
    {
        dsTien[i].soLuongTo = tien / dsTien[i].menhGia;
        tien = tien % dsTien[i].menhGia;
        if (dsTien[i].soLuongTo > 0)
        {
            printf("Menh gia %d co so to: %d\n", dsTien[i].menhGia, dsTien[i].soLuongTo);
        }
    }
    if (tien > 0)
    {
        printf(">> So tien con lai khong doi duoc la: %d vnd\n", tien);
    }
}

void yeuCau6()
{
    int tienVay, tienGoc, kyHan;
    float laiSuat, tienLai;
    printf("\nBan chon chuc nang 6: tinh lai suat vay ngan hang vay tra gop\n");
    printf("\nNhap so tien vay: ");
    scanf("%d", &tienVay);
    while (tienVay <= 0)
    {
        printf("\nVui long nhap lai so tien can vay (>0)!\n");
        printf("\nNhap so tien vay: ");
        scanf("%d", &tienVay);
    }
    printf("\nNhap so thang vay: ");
    scanf("%d", &kyHan);
    while (kyHan <= 0)
    {
        printf("\nVui long nhap lai so thang (>0)!\n");
        printf("\nNhap so thang vay: ");
        scanf("%d", &kyHan);
    }
    printf("\nNhap lai xuat vay: ");
    scanf("%f", &laiSuat);
    while (laiSuat <= 0)
    {
        printf("\nVui long nhap lai lai xuat vay (>0)!\n");
        printf("\nNhap lai xuat vay: ");
        scanf("%f", &laiSuat);
    }
    printf("%36s\n", "BANG TINH TIEN GOP MOI THANG:");
    printf("\n");
    printf("%6s%18s%18s%18s%18s\n", "Ky han", "Lai phai tra", "Goc phai tra", "Tien tra", "So tien con lai");
    tienGoc = tienVay / kyHan;
    for (int i = 1; i <= kyHan; i++)
    {
        tienLai = tienVay * laiSuat;
        tienVay = tienVay - tienGoc;
        printf("%6d%18d%18d%18d%18d\n", i, (int)tienLai, tienGoc, (int)tienGoc + (int)tienLai, tienVay);
    }
}

void yeuCau7()
{
    int tienVay = 500000000;
    int kyHan = 24 * 12;
    float laiThang = 7.2 / 12;
    int tienGoc = tienVay / kyHan;
    float phanTramVay;
    printf("\nBan chon chuc nang 7: vay tien mua xe\n");
    printf("\nNhap so phan tram vay toi da (0-100): ");
    scanf("%d", &phanTramVay);
    while (phanTramVay < 0 || phanTramVay > 100)
    {
        printf("Vui long nhap lai so phan tram vay toi da (0-100)!\n");
        printf("\nNhap so phan tram vay toi da (0-100): ");
        scanf("%d", &phanTramVay);
    }
    for (int i = 1; i <= kyHan; i++)
    {
        int tienLai = tienVay * laiThang;
        tienVay = tienVay - tienGoc;
        int tienPhaitra = tienLai + tienGoc;
        if (i == kyHan)
        {
            tienPhaitra = tienPhaitra + tienVay;
            tienVay = 0;
        }
        printf("%6d%18d%18d%18d%18d\n", i, (int)tienLai, tienGoc, (int)tienGoc + (int)tienLai, tienVay);
    }
}

void yeuCau8()
{
    struct sinhVien
    {
        char mssv[9];
        char tenSV[50];
        float diemSV;
    };
    struct sinhVien dsSinhVien[40] =
        {
            {"ps1234", "Nguyen Van A", 7.5},
            {"ps1223", "Tran Thi B", 5.3},
            {"ps1222", "Chau Thi Truc Quyen", 9.9}};
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        printf("%5d%10s%30s%6.2f%10s", i + 1, dsSinhVien[i].mssv, dsSinhVien[i].tenSV, dsSinhVien[i].diemSV), xepLoai(dsSinhVien[i].diemSV);
    }
}

const char *xepLoai(float diem)
{
    if (diem > 8.0)
        return "Gioi";
    else if (diem > 6.5)
        return "Kha";
    else if (diem > 5.0)
        return "Turng Binh";
    else
        return "Yeu";
}
void yeuCau9()
{
    srand(time(NULL));
    int r1 = rand() % 15 + 1, r2;
    int a, b;
    do
    {
        r2 = rand() % 15 + 1;
    } while (r1 != r2);
    printf("\nNhap a va b: \n");
    scanf("%d%d", &a, &b);
    int dem = 0;
    if ((a == r1) || (a == r2))
    {
        dem++;
    }
    if ((b == r1) || (b == r2))
    {
        dem++;
    }
    switch (dem)
    {
    case 0:
        printf("Chuc ban may man lan sau\n");
        break;
    case 1:
        printf("Chuc mung ban da trung giai nhi!\n");
        break;
    case 2:
        printf("Chuc mung ban da trung giai nhat!\n");
        break;
    }
}

void yeuCau10()
{
    struct phanSo ps1, ps2, psTong, psHieu, psTich, psThuong;
    printf("\nNhap phan so 1: \n");
    // scanf("%d%d",&ps1.tu,&ps1.mau);
    ps1 = nhapPhanSo();
    printf("\nNhap phan so 2: \n");
    // scanf("%d%d",&ps2.tu,&ps2.mau);
    ps2 = nhapPhanSo();
    psTong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    psTong.mau = ps1.mau * ps2.mau;
    psHieu.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    psHieu.mau = ps1.mau * ps2.mau;
    psTich.tu = ps1.tu * ps2.tu;
    psTich.mau = ps1.mau * ps2.mau;
    psThuong.tu = ps1.tu * ps2.mau;
    psThuong.mau = ps1.mau * ps2.tu;
    printf("\nTong: %d/%d + %d/%d = %d/%d -> %d/%d", ps1.tu, ps1.mau, ps2.tu, ps2.mau, psTong.tu, psTong.mau, rutGonPS(psTong).tu, rutGonPS(psTong).mau);
    printf("\nHieu: %d/%d - %d/%d = %d/%d -> %d/%d", ps1.tu, ps1.mau, ps2.tu, ps2.mau, psHieu.tu, psHieu.mau, rutGonPS(psHieu).tu, rutGonPS(psHieu).mau);
    printf("\nTich: %d/%d : %d/%d = %d/%d -> %d/%d", ps1.tu, ps1.mau, ps2.tu, ps2.mau, psTich.tu, psTich.mau, rutGonPS(psTich).tu, rutGonPS(psTich).mau);
    printf("\nThuong: %d/%d * %d/%d = %d/%d -> %d/%d", ps1.tu, ps1.mau, ps2.tu, ps2.mau, psThuong.tu, psThuong.mau, rutGonPS(psThuong).tu, rutGonPS(psThuong).mau);
}

struct phanSo nhapPhanSo()
{
    struct phanSo ps;
    printf("\nNhap (tu - mau): \n");
    scanf("%d%d", &ps.tu, &ps.mau);
    return ps;
};
struct phanSo rutGonPS(struct phanSo ps)
{
    struct phanSo tempPS;
    tempPS.tu = ps.tu / UCLN(ps.tu, ps.mau);
    tempPS.mau = ps.mau / UCLN(ps.tu, ps.mau);
    return tempPS;
}