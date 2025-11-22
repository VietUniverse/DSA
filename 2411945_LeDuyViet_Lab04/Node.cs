using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _2411926_HuynhThiAnhThu_Lab04;

namespace _2411926_HuynhThiAnhThu_Lab04
{
    public class Node
    {
        public SinhVien Data { get; set; } //du lieu
        public Node Next { get; set; } //con tro
        public Node(SinhVien sv)
        {
            Data = sv;
            Next = null;
        }
    }
}
