using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace _2411945_LeDuyViet_Lab05
{
    internal class TapHop
    {
        private HashSet<int> A = new HashSet<int>();
        private HashSet<int> B = new HashSet<int>();

        public void NhapDuLieu()
        {
            A = DocFile("A.txt");
            B = DocFile("B.txt");
            Console.WriteLine("Done!");
            Console.ReadKey();
        }

        private HashSet<int> DocFile(string filename)
        {
            var tap = new HashSet<int>();
            if (File.Exists(filename))
            {
                foreach (var line in File.ReadAllLines(filename))
                {
                    var parts = line.Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var part in parts)
                    {
                        if (int.TryParse(part, out int n))
                            tap.Add(n);
                    }
                }
            }
            else
            {
                Console.WriteLine($"Không tìm thấy file {filename}");
            }
            return tap;
        }

        public void XemDuLieu()
        {
            HienThiTapHop(A, "A");
            HienThiTapHop(B, "B");
            Console.ReadKey();
        }

        private void HienThiTapHop(HashSet<int> tap, string name)
        {
            Console.WriteLine($"{name} = {{ {string.Join(", ", tap)} }}");
        }

        public void Giao()
        {
            var giao = new HashSet<int>(A);
            giao.IntersectWith(B);
            HienThiTapHop(giao, "A ∩ B");
            Console.ReadKey();
        }

        public void Hop()
        {
            var hop = new HashSet<int>(A);
            hop.UnionWith(B);
            HienThiTapHop(hop, "A ∪ B");
            Console.ReadKey();
        }

        public void Hieu()
        {
            var hieu = new HashSet<int>(A);
            hieu.ExceptWith(B);
            HienThiTapHop(hieu, "A - B");
            Console.ReadKey();
        }

        public void HieuDoiXung()
        {
            var hieuDX = new HashSet<int>(A);
            hieuDX.SymmetricExceptWith(B);
            HienThiTapHop(hieuDX, "A Δ B");
            Console.ReadKey();
        }

        public void TichDescartes()
        {
            Console.WriteLine("Tích Descartes A × B:");
            foreach (var a in A)
                foreach (var b in B)
                    Console.Write($"({a},{b}) ");
            Console.WriteLine();
            Console.ReadKey();
        }

        public void KiemTraThuocTapHop()
        {
            Console.Write("Nhập phần tử cần kiểm tra: ");
            if (int.TryParse(Console.ReadLine(), out int x))
            {
                Console.WriteLine($"Phần tử {x} {(A.Contains(x) ? "thuộc" : "không thuộc")} tập A");
                Console.WriteLine($"Phần tử {x} {(B.Contains(x) ? "thuộc" : "không thuộc")} tập B");
            }
            else
            {
                Console.WriteLine("Giá trị nhập không hợp lệ!");
            }
            Console.ReadKey();
        }

        public void KiemTraQuanHe()
        {
            Console.WriteLine($"A ⊆ B: {A.IsSubsetOf(B)}");
            Console.WriteLine($"B ⊆ A: {B.IsSubsetOf(A)}");
            Console.ReadKey();
        }

        public void TinhLucLuong()
        {
            Console.WriteLine($"|A| = {A.Count}");
            Console.WriteLine($"|B| = {B.Count}");
            Console.ReadKey();
        }
    }
}
