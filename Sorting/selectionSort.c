#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
int main()
{
    int nums[14] = {1, 5, 6, 3, 0, 4, 3, 0, 0, 1, 8, 5, 7, 1};
    for(int i=0; i<14; i++){
        int min_ind = i;
        for(int j = i+1; j<14; j++){
            if(nums[j]<nums[min_ind])
                min_ind = j;
        }
        int temp = nums[i];
        nums[i] = nums[min_ind];
        nums[min_ind] =  temp;
    }
    for(int i=0; i<14; i++)
        printf("%d ", nums[i]);
    return 0;
}
