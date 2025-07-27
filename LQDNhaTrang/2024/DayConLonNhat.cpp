#include <stdio.h>

/*
    Kiến thức quan trọng:
    - Nếu chỉ số bắt đầu từ 1 => tạo mảng có n + 1 phần tử, sau đó duyệt từ 1
    - Kỹ thuật cửa sổ trượt:
        + Tính toán các giá trị cho cửa sổ đầu tiên, lấy các giá trị này là max
        + Duyệt từ cửa sổ thứ 2 -> cửa sổ cuối: n - k + 1 (chỉ số đầu tiên của cửa sổ cuối)
        + Tính thông số của các cửa sổ tiếp theo
        + Viết lệnh if theo yêu cầu đề bài
        + Cập nhật lại các giá trị max
        + In ra kết quả

*/

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    int start_idx = 1;
    int end_idx = k;
    
    // Tính tổng và số chẵn cho cửa sổ đầu tiên
    long long sum = 0;
    int even_count = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i];
        if (a[i] % 2 == 0) even_count++;
    }
    
    long long max_sum = sum;
    long long max_even = even_count;
    
    // Cửa sổ trượt
    //Đi từ cửa sổ thứ 2 -> cửa số cuối cùng
    for (int i = 2; i <= n - k + 1; i++) {
        sum = sum - a[i - 1] + a[i + k - 1];
        int new_even_count = even_count;
        if (a[i - 1] % 2 == 0) new_even_count--;
        if (a[i + k - 1] % 2 == 0) new_even_count++;
        
        // Cập nhật kết quả nếu:
        // 1. Tổng lớn hơn
        // 2. Tổng bằng nhưng số chẵn nhiều hơn
        // 3. Tổng bằng, số chẵn bằng, chỉ số nhỏ hơn
        // new_even_count chính là cửa sổ hiện tại
        if (sum > max_sum || 
            (sum == max_sum && new_even_count > max_even) ||
            (sum == max_sum && new_even_count == max_even && i < start_idx)) {
            max_sum = sum;
            max_even = new_even_count;
            start_idx = i;
            end_idx = i + k - 1;
        }
        even_count = new_even_count;
    }
    
    printf("%d %d\n", start_idx, end_idx);
}
