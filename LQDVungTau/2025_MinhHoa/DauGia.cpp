#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);

    int a[n], max_sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        max_sum += a[i];  // Tính tổng lớn nhất có thể có
    }
    int dp[max_sum];
    memset(dp, 0, sizeof(dp));  // Đánh dấu tất cả tổng là chưa đạt được
    dp[0] = 1;  // Tổng 0 luôn có thể đạt được (tập rỗng)

    /*
    Bài toán: tìm các tổng có thể đưa ra tương ứng với giá trị của 1 (nhiều) viên ngọc
    Hướng: 
    1.Ta có max_sum là tổng của các viên ngọc -> tạo mảng dp với kích thước như thế này
    2. Đặt dp[0] = 1 -> tổng 0 luôn là 1 tổng có thể đạt được (số tiền vừa đủ mua 1 viên ngọc)
    Vì max_sum là tổng của các viên ngọc => nếu duyệt từ max_sum về a[i], thì sẽ có lúc j giảm về số là tổng của 2 
    hoặc nhiều viên ngọc trong mảng 
    
    => lúc đó lấy j - a[i] sẽ ra được vị trí của phần tử dp được gán sẵn là 1
    Tại lần duyệt đầu tiên, tại dp[j-a[i]] chỉ bằng 1 chính là dp[0] đã gán ban đầu (số tiền chỉ mua được viên ngọc đầu tiên)
    => Tại đó dp[j] sẽ gán bằng 1 để đánh dấu tại vị trí đó có tồn tại 1 tổng
     

    */
    // Duyệt từng viên ngọc
    for (int i = 0; i < n; i++) {
        // Duyệt từ cuối về đầu để tránh ghi đè dữ liệu
        for (int j = max_sum; j >= a[i]; j--) {
            if (dp[j - a[i]]) {
                dp[j] = 1;
            }
        }
    }

    // Đếm số tổng có thể tạo được (trừ tổng 0)
    int count = 0;
    for (int i = 1; i <= max_sum; i++)  //tính từ 1 vì dp[0] = 1=> tổng 0 ko thỏa mọi input
    {
        if (dp[i]) count++; //nếu dp[i] != 0 => tồn tại 1 tổng => tăng biến count
    }
    for (int i = 0; i <= max_sum; i++)
        printf("%d ",dp[i]);
    printf("\n%d\n", count);
    return 0;
}
