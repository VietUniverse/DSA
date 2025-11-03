#define MAX 1000

void HoanVi(int& a, int& b)
{
    int t = a; a = b; b = t;
}

int File_Array(char* filename, int a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "\nKhong mo duoc tap tin!";
        return 0;
    }
    n = 0;
    while (in >> a[n])
        n++;
    in.close();
    return 1;
}

void XemDuLieu(int a[MAX], int n)
{
    cout << "\nDay so hien hanh:\n";
    for (int i = 0; i < n; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

void Merge(int a[MAX], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L; delete[] R;
}

void MergeSort(int a[MAX], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}

void Shift(int a[MAX], int l, int r)
{
    int i = l;
    int j = 2 * i + 1;
    int x = a[i];
    while (j <= r)
    {
        if (j < r && a[j] < a[j + 1])
            j++;
        if (a[j] <= x)
            return;
        else
        {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
        a[i] = x;
    }
}

void CreateHeap(int a[MAX], int n)
{
    int l = (n - 1) / 2;
    while (l >= 0)
    {
        Shift(a, l, n - 1);
        l--;
    }
}

void HeapSort(int a[MAX], int n)
{
    CreateHeap(a, n);
    int r = n - 1;
    while (r > 0)
    {
        HoanVi(a[0], a[r]);
        r--;
        Shift(a, 0, r);
    }
}

int getMax(int a[MAX], int n)
{
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void CountSort(int a[MAX], int n, int exp)
{
    int output[MAX];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void RadixSort(int a[MAX], int n)
{
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountSort(a, n, exp);
}

int Partition(int a[MAX], int l, int r)
{
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j)
        {
            HoanVi(a[i], a[j]);
            i++; j--;
        }
    }
    return i;
}

void QuickSort(int a[MAX], int l, int r)
{
    if (l < r)
    {
        int pi = Partition(a, l, r);
        if (l < pi - 1)
            QuickSort(a, l, pi - 1);
        if (pi < r)
            QuickSort(a, pi, r);
    }
}