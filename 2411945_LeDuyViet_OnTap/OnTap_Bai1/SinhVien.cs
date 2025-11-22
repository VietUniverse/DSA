using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OnTap_Bai1
{
    public class SinhVien
    {
        public string MaSinhVien { get; set; }
        public string TenSinhVien { get; set; }
        public int Tuoi { get; set; }
        public double DiemTrungBinh { get; set; }
        public string Ho { get; set; }

        public SinhVien(string maSinhVien, string tenSinhVien, int tuoi)
        {
            MaSinhVien = maSinhVien;
            TenSinhVien = tenSinhVien;
            Tuoi = tuoi;
            DiemTrungBinh = 0;

            Ho = tenSinhVien.Split(' ')[0];
        }
        public SinhVien(string maSinhVien, string tenSinhVien, int tuoi, double diemTrungBinh)
        {
            MaSinhVien = maSinhVien;
            TenSinhVien = tenSinhVien;
            Tuoi = tuoi;
            DiemTrungBinh = diemTrungBinh;

            Ho = tenSinhVien.Split(' ')[0];
        }

        public override string ToString()
        {
            return string.Format("| {0,-10} | {1,-20} | {2,5} | {3,7:F2} |", MaSinhVien, TenSinhVien, Tuoi, DiemTrungBinh);
        }
    }
}

