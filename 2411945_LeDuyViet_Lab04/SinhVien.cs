using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2411926_HuynhThiAnhThu_Lab04
{
    public class SinhVien
    {
        public string MaSV { get; set; }
        public string HoTen { get; set; }
        public double DiemTB { get; set; }
        public SinhVien(string ma, string ten, double diem)
        {
            MaSV = ma;
            HoTen = ten;
            DiemTB = diem;
        }
    }
}
