#include <iostream>
using namespace std;


int subArraySum(int arr[], int n, int sum)
{
    int currentSum = arr[0], start = 0;

    for (int i = 1; i <=n; i++) {
        while (currentSum > sum && start<i-1) {
            currentSum = currentSum - arr[start];
            start++;
        }

        if (currentSum == sum) {
            cout << "Sum found between indexes " << start
                 << " and " << i - 1;
            return 1;
        }
        if(i<n)
        {
            currentSum = currentSum + arr[i];
        }
    }
    cout << "No subarray found";
    return 0;
}


int main()
{
    int arr[] = { 1,5,7,2,9,5,8,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 20;
    subArraySum(arr, n, sum);
    return 0;
}
// https://www.geeksforgeeks.org/find-subarray-with-given-sum/