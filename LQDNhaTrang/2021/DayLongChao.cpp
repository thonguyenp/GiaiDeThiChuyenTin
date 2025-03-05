#include <stdio.h>

#define MAX_N 1000

void findLongestValley(int arr[], int n) {
    int maxLength = 0, startIdx = -1;
    
    for (int i = 1; i < n; i++) {
        int left = i - 1;
        
        // Xác định đoạn giảm dần
        while (left >= 0 && arr[left] > arr[left + 1]) {
            left--;
        }
        left++; // Lùi lại 1 bước để có điểm đầu
        
        int right = i;
        
        // Xác định đoạn tăng dần
        while (right < n - 1 && arr[right] < arr[right + 1]) {
            right++;
        }
        
        // Kiểm tra xem có tạo thành lòng chảo hay không
        if (left < i && right > i) { // Có cả phần giảm và phần tăng
            int length = right - left + 1;
            if (length > maxLength) {
                maxLength = length;
                startIdx = left;
            }
        }
        
        // Tiếp tục duyệt từ right để tránh kiểm tra lại
        i = right;
    }

    // Xuất kết quả
    if (maxLength > 0) {
        for (int i = startIdx; i < startIdx + maxLength; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("-1");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findLongestValley(arr, n);
    
    return 0;
}
