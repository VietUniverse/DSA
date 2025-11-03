#define MAX 100

int File_Array(char* filename, int a[MAX], int& n);
void Output(int a[MAX], int n);
void HoanVi(int& x, int& y);

void Selection_R(int a[MAX], int n);
void Selection_R_L(int a[MAX], int n);
void Insertion_R(int a[MAX], int n);
void Interchange_R(int a[MAX], int n);
void Buble_R(int a[MAX], int n);
void Shaker(int a[MAX], int n);

int File_Array(char* filename, int a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
    {
        cout << "\nKhong mo duoc file!";
        return 0;
    }

    n = 0;
    while (in >> a[n])
        n++;

    in.close();
    return 1;
}

void Output(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}


void HoanVi(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

void Selection_R(int a[MAX], int n)
{
    int i, j, cs_max;
    for (i = 0; i < n - 1; i++)
    {
        cs_max = n - 1 - i;
        for (j = n - 2 - i; j >= 0; j--)
            if (a[j] > a[cs_max])
                cs_max = j;
        HoanVi(a[n - 1 - i], a[cs_max]);
    }
}

void Selection_R_L(int a[MAX], int n)
{
    int i, j, cs_min, cs_max;
    for (i = 0; i < n / 2; i++)
    {
        cs_min = i;
        cs_max = n - 1 - i;
        for (j = i; j <= n - 1 - i; j++)
        {
            if (a[j] < a[cs_min])
                cs_min = j;
            if (a[j] > a[cs_max])
                cs_max = j;
        }

        if (cs_min == n - i - 1)
        {
            HoanVi(a[i], a[cs_min]);
            if (cs_max != i)
                HoanVi(a[cs_max], a[n - i - 1]);
        }
        else
        {
            HoanVi(a[cs_max], a[n - i - 1]);
            HoanVi(a[i], a[cs_min]);
        }
    }
}

void Insertion_R(int a[MAX], int n)
{
    int i, x, pos;
    for (i = n - 2; i >= 0; i--)
    {
        x = a[i];
        for (pos = i + 1; (pos < n) && (a[pos] < x); pos++)
            a[pos - 1] = a[pos];
        a[pos - 1] = x;
    }
}

void Interchange_R(int a[MAX], int n)
{
    int i, j;
    for (j = n - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (a[i] > a[j])
                HoanVi(a[i], a[j]);
}

void Buble_R(int a[MAX], int n)
{
    int i, j;
    for (j = n - 1; j > 0; j--)
    {
        for (i = 0; i < j; i++)
            if (a[i] > a[i + 1])
                HoanVi(a[i], a[i + 1]);
        cout << "\nBuoc " << n - j << ": ";
        Output(a, n);
    }
    cout << "\n=> Co " << n - 1 << " buoc thuc hien thuat giai.\n";
}

void Shaker(int a[MAX], int n)
{
    int l = 0, r = n - 1, k = n - 1, j;
    while (l < r)
    {
        j = r;
        while (j > l)
        {
            if (a[j] < a[j - 1])
            {
                HoanVi(a[j], a[j - 1]);
                k = j;
            }
            j--;
        }
        l = k;
        j = l;
        while (j < r)
        {
            if (a[j] > a[j + 1])
            {
                HoanVi(a[j], a[j + 1]);
                k = j;
            }
            j++;
        }
        r = k;
    }
}