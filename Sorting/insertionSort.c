#include <stdio.h>
#include <stdbool.h>
int main()
{
    // int nums[] = {}
    int nums[14] = {1, 5, 6, 3, 0, 4, 3, 0, 0, 1, 8, 5, 7, 1};
    for (int i = 1; i < 14; i++)
    {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > temp)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
    for (int i = 0; i < 14; i++)
        printf("%d ", nums[i]);
    return 0;
}