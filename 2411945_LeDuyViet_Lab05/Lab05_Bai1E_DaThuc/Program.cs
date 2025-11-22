using _2411945_LeDuyViet_Lab05;

internal class Program
{
    public enum Menu
    {
        Nhap = 0,
        Xem,
        Tong,
        Hieu,
        Tich,
        DaoHam,
        TichPhan,
        GiaTri
    }

    static void Main(string[] args)
    {
        DaThuc A = new DaThuc();
        DaThuc B = new DaThuc();

        while (true)
        {
            Console.Clear();
            Console.WriteLine("====== MENU PHEP TOAN DA THUC ======");
            Console.WriteLine("0. Nhap du lieu tu file");
            Console.WriteLine("1. Xem du lieu da thuc");
            Console.WriteLine("2. Tong 2 da thuc");
            Console.WriteLine("3. Hieu 2 da thuc (A - B)");
            Console.WriteLine("4. Tich 2 da thuc");
            Console.WriteLine("5. Dao ham da thuc");
            Console.WriteLine("6. Tich phan da thuc");
            Console.WriteLine("7. Tinh gia tri da thuc tai x");
            Console.WriteLine("-1. Thoat");
            Console.Write("Nhap lua chon: ");
            if (!int.TryParse(Console.ReadLine(), out int chon)) continue;
            if (chon == -1) break;

            Console.Clear();
            switch ((Menu)chon)
            {
                case Menu.Nhap:
                    A.DocTuFile("A.txt");
                    B.DocTuFile("B.txt");
                    Console.WriteLine("Da nhap xong du lieu tu file A.txt va B.txt!");
                    break;
                case Menu.Xem:
                    A.Xuat("A");
                    B.Xuat("B");
                    break;
                case Menu.Tong:
                    A.Cong(B).Xuat("A + B");
                    break;
                case Menu.Hieu:
                    A.Tru(B).Xuat("A - B");
                    break;
                case Menu.Tich:
                    A.Nhan(B).Xuat("A * B");
                    break;
                case Menu.DaoHam:
                    Console.WriteLine("Dao ham cua A:");
                    A.DaoHam().Xuat("A'");
                    Console.WriteLine("Dao ham cua B:");
                    B.DaoHam().Xuat("B'");
                    break;
                case Menu.TichPhan:
                    Console.WriteLine("Tich phan cua A:");
                    A.TichPhan().Xuat("∫A");
                    Console.WriteLine("Tich phan cua B:");
                    B.TichPhan().Xuat("∫B");
                    break;
                case Menu.GiaTri:
                    Console.Write("Nhap x = ");
                    double x = double.Parse(Console.ReadLine());
                    Console.WriteLine($"A({x}) = {A.GiaTri(x)}");
                    Console.WriteLine($"B({x}) = {B.GiaTri(x)}");
                    break;
            }
            Console.WriteLine("\nNhan phim bat ky de tiep tuc...");
            Console.ReadKey();
        }

        Console.WriteLine("Ket thuc chuong trinh!");
    }
}