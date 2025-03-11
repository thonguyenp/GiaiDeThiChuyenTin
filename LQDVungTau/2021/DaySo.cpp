#include<stdio.h>
#include<math.h>

int LaSNT (int n)
{
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    // Kiểm tra các số dạng 6k ± 1 từ 5 đến √n
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;

}

int LaSCP (int n)
{
    if (n < 1) return 0;
    int sq = sqrt(n);
    if (sq*sq == n) return 1;
    else return 0;
}

void CauC (int a[], int n)
{
    int left = 0, right = n - 1;
    while (!LaSCP(a[left]) && left < n) left++;
    while (!LaSCP(a[right]) && right >= 0) right--;
    if (left < right) printf("%d",right - left - 1);
        else printf("%d",-1);
}

int cmp (const void *a, const void *b)
{
    return (*(int*)b) - (*(int*)a);
}

void CauD (int a[], int n)
{
    int k; 
    scanf("%d",&k);
    qsort(a,n,sizeof(int),cmp); //qsort giảm dần
    int b[k], c[n-k];
    for (int i = 0; i < k; i++)
    {
        b[i] = a[i];
        printf("%d ",b[i]);
    }
    printf("\n");
    for (int i = k; i < n; i++)
    {
        c[i] = a[i];
        printf("%d ",c[i]);
    }

}

void maxDifferenceWithLargestK(int arr[], int n) {
    int k; 
    scanf("%d",&k);
    int totalSum = 0, maxSum = 0;
    int maxValues[n], chosen[n] = {0}; // Mảng lưu K phần tử lớn nhất
    int i, j;

    //Review: Cần xem lại kỹ thuật heap (priority queue trong bài này)
    // Tính tổng toàn bộ mảng
    for (i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Bước 1: Chọn K số lớn nhất
    for (i = 0; i < k; i++) {
        maxValues[i] = arr[i]; // Chọn K phần tử đầu tiên
    }

    // Bước 2: Duyệt mảng còn lại để tìm K số lớn nhất
    for (i = k; i < n; i++) {
        int minIndex = 0;
        for (j = 1; j < k; j++) {
            if (maxValues[j] < maxValues[minIndex]) {
                minIndex = j;
            }
        }
        if (arr[i] > maxValues[minIndex]) {
            maxValues[minIndex] = arr[i];
        }
    }

    // Bước 3: Đánh dấu các phần tử thuộc nhóm K số lớn nhất
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            if (arr[j] == maxValues[i] && !chosen[j]) { 
                chosen[j] = 1; 
                break; 
            }
        }
    }

    // In ra mảng thứ nhất (K số lớn nhất)
    printf("Phần thứ nhất: ");
    for (i = 0; i < n; i++) {
        if (chosen[i]) {
            printf("%d ", arr[i]);
            maxSum += arr[i];
        }
    }
    printf("(Tổng là: %d)\n", maxSum);

    // In ra mảng thứ hai (phần còn lại)
    printf("Phần thứ hai: ");
    for (i = 0; i < n; i++) {
        if (!chosen[i]) {
            printf("%d ", arr[i]);
        }
    }
    printf("(Tổng là: %d)\n", totalSum - maxSum);

    // Tính và in ra giá trị chênh lệch lớn nhất
    printf("Giá trị chênh lệch lớn nhất giữa hai phần là: %d\n", abs(2 * maxSum - totalSum));
}

int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     if ((a[i] - 2) / 5 == (float)(a[i] - 2) / 5) printf("%d ",a[i]);   //câu a
    // }
    printf("\n");
    // for (int i = 0; i < n; i++)
    //     if (LaSNT(a[i])) printf("%d ",a[i]);//câu b
    // CauC(a,n);   //cau c
    // CauD(a,n);  //cau d  
    maxDifferenceWithLargestK(a,n);
    
}