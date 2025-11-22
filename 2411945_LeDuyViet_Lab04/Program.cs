using _2411926_HuynhThiAnhThu_Lab04;
using System;
class Program
{
    static void Main(string[] args)
    {
        // --- Phan 1 (da chay, co the xoa) ---
        // --- Phan 2 & 3: MENU CHINH ---
        QuanLyNhanVien qlnv = new QuanLyNhanVien();
        int luaChon;
        do
        {
            Console.Clear();
            Console.WriteLine("===== Chuong Trinh Quan Ly Nhan Vien (LinkedList<T>) =====");
            Console.WriteLine("1. Doc danh sach nhan vien tu file(data.txt)");
            Console.WriteLine("2. Xuat DSNV(dang bang)");
            Console.WriteLine("3. Them NV moi(vao cuoi)");
            Console.WriteLine("4. Xoa NV(theo maNV)");
            Console.WriteLine("5. Tim kiem NV(theo maNV)");
            Console.WriteLine("6. Sap xep NV(theo Luong tang dan)-[BT]");
            Console.WriteLine("7. Thong ke theo Phong Ban - [BT]");
            Console.WriteLine("8. Cap nhat thong tin NV(theo maNV)-[BT]");
            Console.WriteLine("9. Ghi DS ra file moi(output.txt)-[BT]");
            Console.WriteLine("0. Thoat chuong trinh");
            Console.WriteLine("===========================================================");
            if (!int.TryParse(Console.ReadLine(), out luaChon))
            {
                luaChon = -1;//Dat gtri khong hop le
            }
            switch (luaChon)
            {
                case 1:
                    qlnv.DocFile();
                    break;
                case 2:
                    qlnv.XuatDanhSach();
                    break;
                case 3:
                    qlnv.ThemNhanVienMoi();
                    break;
                case 4:
                    qlnv.XoaNhanVien();
                    break;
                case 5:
                    qlnv.TimKiemNhanVien();
                    break;
                case 6:
                    qlnv.SapXepTheoLuong();
                    break;
                case 7:
                    qlnv.ThongKeTheoPhong();
                    break;
                case 8:
                case 9:
                case 0:
                    Console.WriteLine("Cam on da sd chuong trinh!");
                    break;
                default:
                    Console.WriteLine("Lua chon khong hop le.Vui long nhap lai");
                    break;
            }
            if (luaChon != 0)
            {
                Console.WriteLine("\nNhan phim bat ky de tiep tuc...");
                Console.ReadKey();
            }
        } while (luaChon != 0);
    }
}