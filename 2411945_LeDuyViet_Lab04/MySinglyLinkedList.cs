using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _2411926_HuynhThiAnhThu_Lab04;

namespace _2411926_HuynhThiAnhThu_Lab04
{
    public class MySinglyLinkedList
    {
        private Node head; //con tro qtrong nhat, ql dau ds
        public MySinglyLinkedList()
        {
            head = null; //khoi tao ds rong
        }
        public void ThemCuoi(SinhVien sv)
        {
            Node newNode = new Node(sv);
            if (head == null)
            {
                head = newNode;//neu ds rong
            }
            else
            {
                Node current = head;
                while (current.Next != null)//duyet den node cuoi
                {
                    current = current.Next;
                }
                current.Next = newNode;//moc node moi vao cuoi
            }
        }
        public void XuatDanhSach()
        {
            Node current = head;
            while (current != null)
            {
                Console.WriteLine($"{current.Data.MaSV}-{current.Data.HoTen}-{current.Data.DiemTB}");
                current = current.Next;
            }
        }
        public bool Xoa(string maSV)
        {
            if (head == null) return false;//ds rong
            //TH1: Xoa ngay dau (head)
            if (head.Data.MaSV.Equals(maSV))
            {
                head = head.Next;
                return true;
            }
            //TH2: Xoa o giua hoac cuoi
            Node previous = null;
            Node current = head;
            //Tim node can xoa,'previous' lun theo sau 'current'
            while (current != null && !current.Data.MaSV.Equals(maSV))
            {
                previous = current;
                current = current.Next;
            }
            //Neu khong tim thay (duyet ht ds)
            if (current == null) return false;
            //Neu tim thay('current' la node can xoa)
            //Noi 'previous' voi 'current.Next'(bo qua 'current')
            previous.Next = current.Next;
            return true;
        }
    }
}
