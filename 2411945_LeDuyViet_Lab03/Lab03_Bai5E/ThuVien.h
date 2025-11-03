#define MAX 100



int File_Array(const char* filename, int a[MAX], int& n)
{
    ifstream in(filename);
    if (!in) {
        cout << "\nKhong mo duoc tap tin " << filename << "!\n";
        return 0;
    }

    n = 0;
    int x;
    while (in >> x) {
        if (n >= MAX) {
            cout << "\nDa dat toi da so phan tu (" << MAX << ").\n";
            break;
        }
        a[n++] = x;
    }

    in.close();

    if (n == 0) {
        cout << "\nFile khong co du lieu.\n";
        return 0;
    }

    return 1;
}




void HoanVi(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}


void SelectionSort(int a[], int n, long& soSanh, long& hoanVi) {
    soSanh = hoanVi = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            soSanh++;
            if (a[j] < a[min])
                min = j;
        }
        if (min != i) {
            HoanVi(a[i], a[min]);
            hoanVi++;
        }
    }
}


void InsertionSort(int a[], int n, long& soSanh, long& hoanVi) {
    soSanh = hoanVi = 0;
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0) {
            soSanh++;
            if (a[j] > x) {
                a[j + 1] = a[j];
                hoanVi++;
                j--;
            }
            else break;
        }
        a[j + 1] = x;
    }
}


void InterchangeSort(int a[], int n, long& soSanh, long& hoanVi) {
    soSanh = hoanVi = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            soSanh++;
            if (a[i] > a[j]) {
                HoanVi(a[i], a[j]);
                hoanVi++;
            }
        }
    }
}


void BubbleSort(int a[], int n, long& soSanh, long& hoanVi) {
    soSanh = hoanVi = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            soSanh++;
            if (a[j] > a[j + 1]) {
                HoanVi(a[j], a[j + 1]);
                hoanVi++;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}


void XuatMang(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}
