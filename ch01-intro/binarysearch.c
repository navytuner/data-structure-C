#include <stdio.h>

int binarysearch(int arr[], int len, int st, int en, int target){
    while (st <= en){
        int mid = (st+en)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) st = mid+1;
        else en = mid-1;
    }
    return -1;
}
