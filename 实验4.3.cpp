#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    // 读取数组
    int* A = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d,", &A[i]);
    }
    
    int k;
    scanf("%d", &k);
    
    int left = 0;
    int right = N - 1;
    int found = -1;  // 记录找到的位置，-1表示未找到
    
    // 用于记录查找过程的数组
    int* process = (int*)malloc(N * sizeof(int));
    int process_count = 0;
    
    // 折半查找
    while (left <= right) {
        int mid = (left + right) / 2;
        
        // 记录中间位置的值
        process[process_count++] = A[mid];
        
        if (A[mid] == k) {
            found = mid;
            break;
        } else if (A[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // 输出结果
    if (found != -1) {
        printf("%d\n", found);
    } else {
        printf("no\n");
    }
    
    // 输出查找过程
    for (int i = 0; i < process_count; i++) {
        printf("%d", process[i]);
        if (i < process_count - 1) {
            printf(",");
        }
    }
    printf("\n");
    
    free(A);
    free(process);
    
    return 0;
}
