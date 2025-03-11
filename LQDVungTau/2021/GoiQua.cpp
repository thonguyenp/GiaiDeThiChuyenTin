#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Biến toàn cục để lưu kết quả tốt nhất
int minDiff = -1, bestSum1 = -1, bestSum2 = -1;

//Kỹ thuật cần xem lại: Quay Lui
// Hàm đệ quy để sinh các tập con
void backtrack(int index, int sum1, int totalSum, int arr[], int n) {
    if (index == n) //thành phần dừng: duyệt hết mảng
    {   
        //các câu lệnh thực hiện khi gặp thành phần dừng
        int sum2 = totalSum - sum1; //sum2 sẽ bằng tổng mảng trừ cho sum1 đã tính được
        if (isPrime(sum1) && isPrime(sum2)) 
        {
            //Nếu tổng 1 và 2 đều là snt
            int diff = abs(sum1 - sum2);    //lấy ra diff
            if (minDiff == -1 || diff < minDiff) {
                minDiff = diff;
                bestSum1 = sum1;
                bestSum2 = sum2;
            }
        }
        return;
    }

    // Nhánh 1: Thêm phần tử hiện tại vào tập con 1
    backtrack(index + 1, sum1 + arr[index], totalSum, arr, n);

    // Nhánh 2: Không thêm phần tử hiện tại vào tập con 1
    backtrack(index + 1, sum1, totalSum, arr, n);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    int totalSum = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        totalSum += arr[i];  // Tính tổng toàn bộ mảng
    }

    // Gọi đệ quy tìm tập con tốt nhất
    backtrack(0, 0, totalSum, arr, n);

    // Xuất kết quả
    if (minDiff == -1) {
        printf("-1\n");
    } else {
        printf("%d %d %d\n", bestSum1, bestSum2, minDiff);
    }

    return 0;
}
