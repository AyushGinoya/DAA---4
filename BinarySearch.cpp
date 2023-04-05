#include<bits/stdc++.h>
using namespace std;

int find_val(int arr[], int x, int s, int e) {
    if (e >= s) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
            return mid;
        if (x < arr[mid])
            return find_val(arr, x, s, mid - 1);
        else
            return find_val(arr, x, mid + 1, e);
    }
    return -1;
}

int main() {
    int n = 8;
    int arr[] = {1, 12, 32, 42, 59, 222, 455, 4322};
    int x = 42;

    int result = find_val(arr, x, 0, n-1);
    if(result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;

    return 0;
}
