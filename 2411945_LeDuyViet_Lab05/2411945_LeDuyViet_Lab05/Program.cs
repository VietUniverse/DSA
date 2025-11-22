using System;

namespace _2411945_LeDuyViet_Lab05
{
    internal class Program
    {
        public enum Menu
        {
            Nhap = 0,
            XemDuLieu,
            Giao,
            Hop,
            Hieu,
            HieuDoiXung,
            TichDescartes,
            KiemTraThuocTapHop,
            KiemTraQuanHe,
            TinhLucLuong
        }

        static void Main(string[] args)
        {
            TapHop th = new TapHop();

            while (true)
            {
                Console.Clear();
                Console.WriteLine("====== Menu ======");
                Console.WriteLine($"Chon {(int)Menu.Nhap} nhap du lieu tu file");
                Console.WriteLine($"Chon {(int)Menu.XemDuLieu} Xem du lieu tap hop");
                Console.WriteLine($"Chon {(int)Menu.Giao} Giao hai tap hop");
                Console.WriteLine($"Chon {(int)Menu.Hop} Hop hai tap hop");
                Console.WriteLine($"Chon {(int)Menu.Hieu} Hieu hai tap hop");
                Console.WriteLine($"Chon {(int)Menu.HieuDoiXung} Hieu doi xung hai tap hop");
                Console.WriteLine($"Chon {(int)Menu.TichDescartes} Tich Descartes");
                Console.WriteLine($"Chon {(int)Menu.KiemTraThuocTapHop} Kiem tra phan tu thuoc tap hop");
                Console.WriteLine($"Chon {(int)Menu.KiemTraQuanHe} Kiem tra quan he");
                Console.WriteLine($"Chon {(int)Menu.TinhLucLuong} Tinh luc luong tap hop");
                Console.WriteLine("Thoat chuong trinh");
                Console.Write("Nhap mot so de chon menu: ");

                if (!int.TryParse(Console.ReadLine(), out int chon))
                    continue;

                if (chon == -1)
                    break;

                Console.Clear();

                switch ((Menu)chon)
                {
                    case Menu.Nhap:
                        th.NhapDuLieu();
                        break;
                    case Menu.XemDuLieu:
                        th.XemDuLieu();
                        break;
                    case Menu.Giao:
                        th.Giao();
                        break;
                    case Menu.Hop:
                        th.Hop();
                        break;
                    case Menu.Hieu:
                        th.Hieu();
                        break;
                    case Menu.HieuDoiXung:
                        th.HieuDoiXung();
                        break;
                    case Menu.TichDescartes:
                        th.TichDescartes();
                        break;
                    case Menu.KiemTraThuocTapHop:
                        th.KiemTraThuocTapHop();
                        break;
                    case Menu.KiemTraQuanHe:
                        th.KiemTraQuanHe();
                        break;
                    case Menu.TinhLucLuong:
                        th.TinhLucLuong();
                        break;
                    default:
                        return;
                }
            }
            Console.WriteLine("Ket thuc chuong trinh!");
            Console.ReadKey();
        }
    }
}
