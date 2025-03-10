#include<stdio.h>
#include<math.h>

int LaSCP (int n)
{
    int s = (int)sqrt(n);
    if (s * s == n) return 1;
    else return 0;
}

int maximum (int a, int b)
{
    return (a > b) ? a : b;
}


int main ()
{
    int n;
    scanf("%d",&n);
    int a[n+1], dp[n+1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        dp[i] = 1;
    }
    int max = 1;
    /*
    i = 1, j = 2 => |2-6| = 4 => thỏa scp => maximum(1, 1+1) = 2 => dp sau lần duyệt này là = {1, 2, 1, 1, 1, 2, 1}
    => Phát hiện ra 2 cách chọn: chọn thẻ có giá trị 2,6 hoặc chọn thẻ có giá trị 2, 11
    Sau đó, i sẽ chạy liên tục từ đầu đến cuối mảng, j sẽ chạy từ i + 1 đến i+ 10 và thực hiện việc so sánh trên
    */
        
    for (int i = 1; i <= n; i++)    //duyệt từng phần tử làm điểm bắt đầu
        for (int j = i+1; j <= i + 10 && j <= n; j++)   //xét tối đa 10 phần tử sau i
        {
            if (LaSCP(abs(a[i]-a[j])))  //Kiểm tra điều kiện số chính phương
            {
                dp[j] = maximum(dp[j],dp[i] + 1);   //dp[j] là max ở vị trí hiện tại và vị trí sau i
                if (max < dp[j]) max = dp[j];   //cập nhật lại max
            }
        }
    //=> Độ phức tạp của thuật toán này là O(10*n) (vòng i lặp n lần) (vòng j lặp tối đa 10 lần)
    for (int i = 1; i <= n; i++)
        printf("%d ",dp[i]);
    printf("\n");
    printf("%d",max);
}