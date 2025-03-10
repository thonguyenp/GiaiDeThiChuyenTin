#include<stdio.h>

int main ()
{
    int n; 
    scanf("%d",&n);
    /*
    Bài toán: Đếm ước 1 số
    Độ phức tạp: O(sqrt(n))
    Thay vì duyệt tới n thì chỉ duyệt tới sqrt(n) để tính ước nhỏ, sau đó lấy n / i != i thì tính thêm ước lớn
    */
    int c = 0;
    for (int i = 1; i *i <= n; i++) 
    {
        if (n % i == 0) c++;
        if (n / i != i) c++;
    }
    printf("%d",c);
}