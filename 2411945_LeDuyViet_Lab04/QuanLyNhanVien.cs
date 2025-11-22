using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization;
using System.Threading.Tasks.Sources;

namespace _2411926_HuynhThiAnhThu_Lab04
{
    public class QuanLyNhanVien
    {
        //Cau truc dl chinh
        private LinkedList<NhanVien> ds_nv;
        private const string FILE_PATH = "data.txt";
        public QuanLyNhanVien()
        {
            ds_nv = new LinkedList<NhanVien>();
        }
        public void DocFile()
        {
            ds_nv.Clear();//Xoa cu trc khi doc
            try
            {
                using (StreamReader sr = new StreamReader(FILE_PATH))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 5)
                        {
                            NhanVien nv = new NhanVien
                            {
                                MaNV = parts[0],
                                HoTen = parts[1],
                                PhongBan = parts[2],
                                NgayVaoLam = DateTime.ParseExact(parts[3], "dd/MM/yyyy", CultureInfo.InvariantCulture),
                                LuongCoBan = double.Parse(parts[4])
                            };
                            //Them vao cuoi DSLK (O(1) - rat nhanh)
                            ds_nv.AddLast(nv);
                        }
                    }
                }
                Console.WriteLine($"Da doc thanh cong {ds_nv.Count} nhan vien.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Loi khi doc file: {ex.Message}");
            }
        }
        private void InTieuDeBang()
        {
            Console.WriteLine(new string('=', 86));
            Console.WriteLine($"| {"MaNV",-7} | {"Ho Ten",-25} | {"Phong Ban",-15} | {"Ngay Vao Lam",-12} | {"Luong Co Ban",17} |");
            Console.WriteLine(new string('-', 86));
        }
        public void XuatDanhSach()
        {
            if (ds_nv.Count == 0)
            {
                Console.WriteLine("Danh sach rong");
                return;
            }
            InTieuDeBang();
            //Duyet qua DSLK(dung foreach)
            foreach (NhanVien nv in ds_nv)
            {
                nv.XuatThongTin();
            }
            Console.WriteLine(new string('-', 86));
            Console.WriteLine($"Tong so nhan vien: {ds_nv.Count}");
        }
        //Ham tra ve nut(node)
        public LinkedListNode<NhanVien> TimNode(string maNV)
        {
            LinkedListNode<NhanVien> current = ds_nv.First;
            while (current != null)
            {
                //Lay dl bang .Value
                if (current.Value.MaNV.Equals(maNV, StringComparison.OrdinalIgnoreCase))
                {
                    return current;//Tra ve cai nut
                }
                current = current.Next;//Di tiep
            }
            return null;//Khong tim thay
        }
        public void XoaNhanVien()
        {
            Console.Write("Nhap MaNV can xoa:");
            string maXoa = Console.ReadLine();
            //1.Tim nut(O(n))
            LinkedListNode<NhanVien> nodeCanXoa = TimNode(maXoa);
            if (nodeCanXoa == null)
            {
                Console.WriteLine($"Khong tim thay NV co ma {maXoa}");
                return;
            }
            //2.Xoa nut(O(1) - cuc nhanh)
            ds_nv.Remove(nodeCanXoa);
            Console.WriteLine($"Da xoa thanh cong NV {maXoa}");
        }
        private NhanVien NhapThongTinMoi()
        {
            NhanVien nv = new NhanVien();
            Console.WriteLine("Nhap MaNV (VD:NV100): ");
            nv.MaNV = Console.ReadLine();
            //Ktra trung ma
            if (TimNode(nv.MaNV) != null)
            {
                Console.WriteLine("MaNV nay da ton tai!");
                return null;
            }
            Console.Write("Nhap Ho Ten: ");
            nv.HoTen = Console.ReadLine();
            Console.Write("Nhap Phong Ban: ");
            nv.PhongBan = Console.ReadLine();
            DateTime tempNgay;
            while (true)
            {
                Console.Write("Nhap Ngay Vao Lam (dd/MM/yyyy): ");
                if (DateTime.TryParseExact(Console.ReadLine(), "dd/MM/yyyy", CultureInfo.InvariantCulture, DateTimeStyles.None, out tempNgay))
                {
                    nv.NgayVaoLam = tempNgay;
                    break;
                }
                Console.WriteLine("Dinh dang ngay sai, vui long nhap lai.");
            }
            double tempLuong;
            while (true)
            {
                Console.Write("Nhap Luong Co Ban: ");
                if (double.TryParse(Console.ReadLine(), out tempLuong))
                {
                    nv.LuongCoBan = tempLuong;
                    break;
                }
                Console.WriteLine("Luong phai la so, vui long nhap lai");
            }
            return nv;
        }
        public void ThemNhanVienMoi()
        {
            Console.WriteLine("--- Them Nhan Vien Moi ---");
            NhanVien nvMoi = NhapThongTinMoi();
            if (nvMoi != null)
            {
                ds_nv.AddLast(nvMoi);//Them vao cuoi (O(1))
                Console.WriteLine("Them moi thanh cong!");
            }
        }
        public void TimKiemNhanVien()
        {
            Console.WriteLine("Nhap MaNV can tim: ");
            string maTim = Console.ReadLine();
            LinkedListNode<NhanVien> nodeTim = TimNode(maTim);
            if (nodeTim != null)
            {
                Console.WriteLine("Tim thay nhan vien: ");
                InTieuDeBang();
                nodeTim.Value.XuatThongTin();
                Console.WriteLine(new string('-', 86));
            }
            else
            {
                Console.WriteLine($"Khong tim thay NV co ma {maTim}");
            }
        }
        public void SapXepTheoLuong()
        {
            if (ds_nv.Count == 0)
            {
                Console.WriteLine("DSNV rong");
                return;
            }
            //Chuyen LinkedList sang List
            List<NhanVien> tempList = ds_nv.ToList();
            tempList.Sort((nv1, nv2) => nv1.LuongCoBan.CompareTo(nv2.LuongCoBan));
            //Chuyen lai LinkedList
            ds_nv = new LinkedList<NhanVien>(tempList);
            Console.WriteLine("Da sap xep ");
        }
        public void ThongKeTheoPhong()
        {
            if (ds_nv.Count == 0)
            {
                Console.WriteLine("DSNV trong");
                return;
            }
            Dictionary<string, int> thongKe = new Dictionary<string, int>();
            foreach (NhanVien nv in ds_nv)
            {
                if (thongKe.ContainsKey(nv.PhongBan))
                {
                    thongKe[nv.PhongBan]++;
                }
                else
                {
                    thongKe.Add(nv.PhongBan, 1);
                }
            }
            Console.WriteLine("\n--- Thong Ke Theo Phong Ban ---");
            foreach (var item in thongKe)
            {
                Console.WriteLine($"{item.Key}:{item.Value} nhan vien");
            }
        }
        public void CapNhatNhanVien()
        {
            Console.WriteLine("Nhap MaNV can cap nhat: ");
            string maNV = Console.ReadLine();
            LinkedListNode<NhanVien> node = TimNode(maNV);
            if (node == null)
            {
                Console.WriteLine("Khong tim thay NV voi ma: " + maNV);
                return;
            }
        }
    }
}