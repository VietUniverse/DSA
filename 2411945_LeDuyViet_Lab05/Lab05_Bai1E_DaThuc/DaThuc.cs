using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace _2411945_LeDuyViet_Lab05
{
    internal class DaThuc
    {
        private Dictionary<int, double> dsHeSo = new Dictionary<int, double>();

        public void DocTuFile(string filePath)
        {
            dsHeSo.Clear();
            if (!File.Exists(filePath))
            {
                Console.WriteLine($"Không tìm thấy file: {filePath}");
                return;
            }

            string[] lines = File.ReadAllLines(filePath);
            foreach (var line in lines)
            {
                if (string.IsNullOrWhiteSpace(line)) continue;
                var parts = line.Split((char[])null!, StringSplitOptions.RemoveEmptyEntries);

                if (parts.Length == 2)
                {
                    double heSo = double.Parse(parts[0]);
                    int soMu = int.Parse(parts[1]);
                    if (dsHeSo.ContainsKey(soMu))
                        dsHeSo[soMu] += heSo;
                    else
                        dsHeSo[soMu] = heSo;
                }
            }
        }


        public void Xuat(string ten = "P")
        {
            Console.Write($"{ten}(x) = ");
            var sapXep = dsHeSo.OrderBy(p => p.Key);
            bool dau = false;
            foreach (var item in sapXep)
            {
                double hs = item.Value;
                int sm = item.Key;
                if (Math.Abs(hs) < 1e-12) continue;

                if (dau && hs > 0) Console.Write(" + ");
                else if (hs < 0) Console.Write(" - ");

                double hsAbs = Math.Abs(hs);
                if (sm == 0) Console.Write($"{hsAbs}");
                else if (sm == 1) Console.Write($"{hsAbs}x");
                else Console.Write($"{hsAbs}x^{sm}");

                dau = true;
            }
            Console.WriteLine();
        }

        public DaThuc Cong(DaThuc b)
        {
            DaThuc kq = new DaThuc();
            foreach (var p in dsHeSo)
                kq.dsHeSo[p.Key] = p.Value;
            foreach (var p in b.dsHeSo)
            {
                if (kq.dsHeSo.ContainsKey(p.Key))
                    kq.dsHeSo[p.Key] += p.Value;
                else
                    kq.dsHeSo[p.Key] = p.Value;
            }
            return kq;
        }

        public DaThuc Tru(DaThuc b)
        {
            DaThuc kq = new DaThuc();
            foreach (var p in dsHeSo)
                kq.dsHeSo[p.Key] = p.Value;
            foreach (var p in b.dsHeSo)
            {
                if (kq.dsHeSo.ContainsKey(p.Key))
                    kq.dsHeSo[p.Key] -= p.Value;
                else
                    kq.dsHeSo[p.Key] = -p.Value;
            }
            return kq;
        }

        public DaThuc Nhan(DaThuc b)
        {
            DaThuc kq = new DaThuc();
            foreach (var a in dsHeSo)
                foreach (var bb in b.dsHeSo)
                {
                    int sm = a.Key + bb.Key;
                    double hs = a.Value * bb.Value;
                    if (kq.dsHeSo.ContainsKey(sm))
                        kq.dsHeSo[sm] += hs;
                    else
                        kq.dsHeSo[sm] = hs;
                }
            return kq;
        }

        public DaThuc DaoHam()
        {
            DaThuc kq = new DaThuc();
            foreach (var p in dsHeSo)
            {
                if (p.Key > 0)
                    kq.dsHeSo[p.Key - 1] = p.Key * p.Value;
            }
            return kq;
        }

        public DaThuc TichPhan()
        {
            DaThuc kq = new DaThuc();
            foreach (var p in dsHeSo)
            {
                kq.dsHeSo[p.Key + 1] = p.Value / (p.Key + 1);
            }
            return kq;
        }

        public double GiaTri(double x)
        {
            double sum = 0;
            foreach (var p in dsHeSo)
            {
                sum += p.Value * Math.Pow(x, p.Key);
            }
            return sum;
        }
    }
}
