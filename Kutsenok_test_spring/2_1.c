#include <stdio.h>

int main() {
    int max_count_num = 0;
    int max_count = 0;

    int cur_count = 0;
    int cur_count_num;

    int curr;
    int prev;

    scanf("%d", &prev);

    while(scanf("%d", &curr) != EOF) {
        if(curr == prev) {
            cur_count = 2;
            cur_count_num = curr;
            prev = curr;
            while(scanf("%d", &curr) != EOF) {
                if(curr != prev) break;
                else {
                    cur_count++;
                    prev = curr;
                }
            }
        }
        if(cur_count > max_count) {
            max_count = cur_count;
            max_count_num = cur_count_num;
        }
        prev = curr;
    }

    printf("%d (%d)", max_count, max_count_num);
    return 0;
}