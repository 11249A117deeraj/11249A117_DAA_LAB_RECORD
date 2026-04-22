#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
int t = *a;
*a = *b;
*b = t;
}
int partition_left(int arr[], int low, int high) {
int pivot = arr[high];
int i = low;
for (int j = low; j &lt; high; j++) {
if (arr[j] &lt;= pivot) {
swap(&amp;arr[i], &amp;arr[j]);
i++;
}
}
swap(&amp;arr[i], &amp;arr[high]);
return i;
}
int partition_right(int arr[], int low, int high) {
srand(time(NULL));
int r = low + rand() % (high - low);
swap(&amp;arr[r], &amp;arr[high]);
return partition_left(arr, low, high);
}
void quicksort(int arr[], int low, int high) {
if (low &lt; high) {
int p = partition_right(arr, low, high);
quicksort(arr, low, p - 1);
quicksort(arr, p + 1, high);
}
}
void printArray(int arr[], int size) {
for (int i = 0; i &lt; size; i++)
printf(&quot;%d &quot;, arr[i]);
printf(&quot;\n&quot;);
}
int main() {
int arr[] = { 6, 4, 12, 8, 15, 16};
int n = sizeof(arr) / sizeof(arr[0]);
printf(&quot;Original array: &quot;);
printArray(arr, n);
quicksort(arr, 0, n - 1);
printf(&quot;Sorted array: &quot;);
printArray(arr, n);
return 0;

}