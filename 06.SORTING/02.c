#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;}
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }}
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }}}
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");}
int main() {
    printf("CH.SC.U4CSE25248\n");
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 0;
        }}
    selectionSort(arr, n);
    printArray(arr, n);
    free(arr);
    return 0;
}
