#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
int main()
{
    int nums[14] = {1, 5, 6, 3, 0, 4, 3, 0, 0, 1, 8, 5, 7, 1};
    // bool ans = false;
    for(int i=0; i<14; i++){
        bool ans = false;
        for(int j =0; j<14-i+1; j++){
            if(nums[j]>nums[j+1]){
                int t = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = t;
                ans = true;
            }
        }
        if(ans == false)
            break;

    }
    for (int i = 0; i < 14; i++)
    {
        printf("%d  ", nums[i]);
    }
    return 0;
}