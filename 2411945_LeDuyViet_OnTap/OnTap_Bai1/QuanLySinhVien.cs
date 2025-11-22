namespace OnTap_Bai1
{
    public class Node
    {
        public SinhVien Data { get; set; }
        public Node Next { get; set; }

        public Node(SinhVien data)
        {
            Data = data;
            Next = null;
        }
    }

    public class QuanLySinhVien
    {
        public Node Head { get; set; }

        public QuanLySinhVien()
        {
            Head = null;
        }

        public bool IsEmpty()
        {
            return Head == null;
        }

        public void AddFirst(SinhVien sinhVien)
        {
            Node newNode = new Node(sinhVien);
            newNode.Next = Head;
            Head = newNode;
        }

        public void AddAfter(string maX, SinhVien sv)
        {
            if (Head == null)
            {
                Console.WriteLine("Danh sach rong");
                return;
            }

            Node current = Head;

            while (current != null && current.Data.MaSinhVien != maX)
            {
                current = current.Next;
            }

            if (current == null)
            {
                Console.WriteLine($"Khong tim thay sinh vien co ma {maX}.");
                return;
            }

            Node newNode = new Node(sv);
            newNode.Next = current.Next;
            current.Next = newNode;

            Console.WriteLine($"Da chen sau ma {maX}");
        }

        public void Remove(string maSV)
        {
            if (Head == null)
            {
                Console.WriteLine("Danh sach rong");
                return;
            }
            if (Head.Data.MaSinhVien == maSV)
            {
                Head = Head.Next;
                Console.WriteLine("Da xoa sinh vien dau danh sach");
                return;
            }

            Node current = Head;
            Node previous = null;

            while (current != null && current.Data.MaSinhVien != maSV)
            {
                previous = current;
                current = current.Next;
            }

            if (current == null)
            {
                Console.WriteLine($"Khong tim thay sinh vien co ma {maSV}.");
                return;
            }

            previous.Next = current.Next;

            Console.WriteLine($"Da xoa sinh vien co ma {maSV}.");
        }


        public void PrintList()
        {
            if (Head == null)
            {
                Console.WriteLine("Danh sách rỗng.");
                return;
            }

            Console.WriteLine("+------------+----------------------+-------+---------+");
            Console.WriteLine("| Ma SV      | Ten SV               | Tuoi  | Diem TB |");
            Console.WriteLine("+------------+----------------------+-------+---------+");

            Node current = Head;
            while (current != null)
            {
                Console.WriteLine(current.Data.ToString());
                current = current.Next;
            }

            Console.WriteLine("+------------+----------------------+-------+---------+");
        }

        public void BubbleSortByMaSinhVien()
        {
            if (Head == null || Head.Next == null) return;

            bool swapped;
            do
            {
                swapped = false;
                Node current = Head;
                while (current != null && current.Next != null)
                {
                    if (string.Compare(current.Data.MaSinhVien, current.Next.Data.MaSinhVien) > 0)
                    {
                        SinhVien temp = current.Data;
                        current.Data = current.Next.Data;
                        current.Next.Data = temp;

                        swapped = true;
                    }
                    current = current.Next;
                }
            } while (swapped);
        }

        public void SelectionSortByTen()
        {
            if (Head == null || Head.Next == null) return;

            Node current = Head;
            while (current != null)
            {
                Node minNode = current;
                Node nextNode = current.Next;

                while (nextNode != null)
                {
                    if (string.Compare(current.Data.TenSinhVien, nextNode.Data.TenSinhVien) > 0 ||
                        (string.Compare(current.Data.TenSinhVien, nextNode.Data.TenSinhVien) == 0 &&
                         string.Compare(current.Data.Ho, nextNode.Data.Ho) > 0))
                    {
                        minNode = nextNode;
                    }
                    nextNode = nextNode.Next;
                }

                if (minNode != current)
                {
                    SinhVien temp = current.Data;
                    current.Data = minNode.Data;
                    minNode.Data = temp;
                }

                current = current.Next;
            }
        }

        public void InsertionSortByDiemTrungBinh()
        {
            if (Head == null || Head.Next == null) return;

            Node sorted = null;

            Node current = Head;
            while (current != null)
            {
                Node next = current.Next;
                if (sorted == null || sorted.Data.DiemTrungBinh <= current.Data.DiemTrungBinh)
                {
                    current.Next = sorted;
                    sorted = current;
                }
                else
                {
                    Node temp = sorted;
                    while (temp.Next != null && temp.Next.Data.DiemTrungBinh > current.Data.DiemTrungBinh)
                    {
                        temp = temp.Next;
                    }
                    current.Next = temp.Next;
                    temp.Next = current;
                }
                current = next;
            }

            Head = sorted;
        }

        public void Clear()
        {
            Head = null;
        }
    }
}
