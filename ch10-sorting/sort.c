#include <stdio.h>
#include <stdlib.h>
#define HLEN 100
#define MAX_LEN 1000
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. bubble sort
void bubble_sort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++){
            if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
    }
}

// 2. selection sort
void selection_sort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        int minidx = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[minidx]) minidx = j;
        }
        swap(&arr[i], &arr[minidx]);
    }
}

// 3. insertion sort
void insertion_sort(int arr[], int n){
    int i, j;
    for (i = 1; i < n; i++){
        int val = arr[i];
        for (j = i-1; j >= 0; j--){
            if (arr[j] > val) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = val;
    }
}


int heap[HLEN];
int sz = 0;

void heap_push(int x){
    int idx = ++sz;
    heap[idx] = x;
    while (idx > 1){
        int pidx = (idx >> 1);
        if (heap[idx] >= heap[pidx]) break;
        swap(&heap[idx], &heap[pidx]);
        idx = pidx;
    }
}
int heap_pop(void){
    int res = heap[1];
    int idx = 1;
    heap[1] = heap[sz--];
    while (2*idx <= sz){
        int lc = (idx << 1);
        int rc = (idx << 1) + 1;
        int minc = lc;
        if (rc <= sz && heap[rc] < heap[lc]) minc = rc;
        if (heap[idx] <= heap[minc]) break;
        swap(&heap[idx], &heap[minc]);
        idx = minc;
    }
    return res;
}

// 4. heap sort
void heap_sort(int arr[], int n){
    for (int i = 0; i < n; i++){
        heap_push(arr[i]);
    }
    for (int i = 0; i < n; i++){
        arr[i] = heap_pop();
    }
}

void merge(int arr[], int st, int en){
    int mid = (st+en) / 2;
    int lidx = st;
    int ridx = mid;
    int tmp[MAX_LEN];
    for (int i = st; i < en; i++){
        if (lidx == mid) tmp[i] = arr[ridx++];
        else if (ridx == en) tmp[i] = arr[lidx++];
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for (int i = st; i < en; i++) arr[i] = tmp[i];
}

// 5. merge sort
void merge_sort(int arr[], int st, int en){
    if (st+1 == en) return;
    int mid = (st+en)/2;
    merge_sort(arr, st, mid);
    merge_sort(arr, mid, en);
    merge(arr, st, en);
}

// 6. quick sort
void quick_sort(int arr[], int st, int en){
    if (st+1 >= en) return;
    int pivot = arr[st];
    int l = st+1;
    int r = en-1;
    while (1){
        while (l <= r && arr[l] <= pivot) l++;
        while (l <= r && arr[r] >= pivot) r--;
        if (l > r) break;
        swap(&arr[l], &arr[r]);
    } 
    swap(&arr[st], &arr[r]);
    quick_sort(arr, st, r);
    quick_sort(arr, r+1, en);
}

int main(){
    int arr[4] = {3, 2, 4, 1};
    int n = 4;

    // bubble_sort(arr, n);
    // selection_sort(arr, n);
    // insertion_sort(arr, n);
    // heap_sort(arr, n);
    merge_sort(arr, 0, n);
    display(arr, n);
    return 0;
}

