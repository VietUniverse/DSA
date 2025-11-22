using System;
using System.Collections.Generic;

namespace OnTap_Bai1
{
    internal class Program
    {
        public enum Menu
        {
            TaoDuLieu = 1,
            TaoDanhSachLienKetRong,
            XuatDanhSach,
            ChenSinhVienVaoDau,
            ChenSinhVienSauMa,
            XoaSinhVienTheoMa,
            SapXepNoiBotTangDanTheoMaSV,
            SapXepChonTrucTiepTangDanTheoTen,
            SapXepChenTrucTiepGiamDanTheoDTB,
        }

        static void Main(string[] args)
        {
            QuanLySinhVien list = new QuanLySinhVien();
            while (true)
            {
                Console.Clear();
                Console.WriteLine($"Nhap {(int)Menu.TaoDuLieu} de khoi tao du lieu");
                Console.WriteLine($"Nhap {(int)Menu.TaoDanhSachLienKetRong} de tao danh sach lien ket rong");
                Console.WriteLine($"Nhap {(int)Menu.XuatDanhSach} de xuat danh sach");
                Console.WriteLine($"Nhap {(int)Menu.ChenSinhVienVaoDau} de chen sinh vien vào đau danh sach");
                Console.WriteLine($"Nhap {(int)Menu.ChenSinhVienSauMa} de chen sinh vien sau ma sinh vien");
                Console.WriteLine($"Nhap {(int)Menu.XoaSinhVienTheoMa} de xoa sinh vien theo ma");
                Console.WriteLine($"Nhap {(int)Menu.SapXepNoiBotTangDanTheoMaSV} de sap xep noi bot tang dan theo ma sinh vien");
                Console.WriteLine($"Nhap {(int)Menu.SapXepChonTrucTiepTangDanTheoTen} de sap xep chon truc tiep tang dan theo ten");
                Console.WriteLine($"Nhap {(int)Menu.SapXepChenTrucTiepGiamDanTheoDTB} de sap xep chen truc tiep giam dan theo dtb");
                Console.WriteLine();

                Menu chon = (Menu)int.Parse(Console.ReadLine());

                switch (chon)
                {
                    case Menu.TaoDuLieu:
                        Console.WriteLine("Tao du lieu ban dau");
                        list.AddFirst(new SinhVien("SV01", "Nguyen An", 20, 10));
                        list.AddFirst(new SinhVien("SV02", "Tran Binh", 21, 9.5));
                        list.AddFirst(new SinhVien("SV03", "Le Cuong", 19, 1.5));
                        Console.WriteLine("Da tao 3 sinh vien ban dau");
                        break;

                    case Menu.TaoDanhSachLienKetRong:
                        list.Clear();
                        Console.WriteLine("Da tao danh sach lien ket rong");
                        break;

                    case Menu.XuatDanhSach:
                        Console.WriteLine("Danh sach sinh vien: ");
                        list.PrintList();
                        break;

                    case Menu.ChenSinhVienVaoDau:
                        Console.Write("Nhap ma sinh vien: ");
                        string maSV = Console.ReadLine();

                        Console.Write("Nhap ten sinh vien: ");
                        string tenSV = Console.ReadLine();

                        Console.Write("Nhap tuoi sinh vien: ");
                        int tuoi = int.Parse(Console.ReadLine());

                        list.AddFirst(new SinhVien(maSV, tenSV, tuoi));
                        Console.WriteLine("Da chen sinh vien vao dau danh sach");
                        break;

                    case Menu.ChenSinhVienSauMa:
                        Console.Write("Nhap ma sinh vien X can chen sau: ");
                        string maX = Console.ReadLine();

                        Console.Write("Nhap ma sinh vien: ");
                        string maAfter = Console.ReadLine();

                        Console.Write("Nhap ten sinh vien: ");
                        string tenAfter = Console.ReadLine();

                        Console.Write("Nhap tuoi sinh vien: ");
                        int tuoiAfter = int.Parse(Console.ReadLine());

                        list.AddAfter(maX, new SinhVien(maAfter, tenAfter, tuoiAfter));
                        break;

                    case Menu.XoaSinhVienTheoMa:
                        Console.Write("Nhap ma sinh vien can xoa: ");
                        string maRemove = Console.ReadLine();

                        list.Remove(maRemove);
                        break;
                    case Menu.SapXepNoiBotTangDanTheoMaSV:
                        list.BubbleSortByMaSinhVien();
                        break;
                    case Menu.SapXepChonTrucTiepTangDanTheoTen:
                        list.SelectionSortByTen();
                        break;
                    case Menu.SapXepChenTrucTiepGiamDanTheoDTB:
                        list.BubbleSortByMaSinhVien();
                        break;

                    default:
                        return;
                }

                Console.WriteLine("Nhan mot phim bat ky de tiep tuc");
                Console.ReadKey();
            }
        }
    }
}
