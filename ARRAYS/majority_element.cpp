//  majority element is the element in array which is present more than n/2 times in a array
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
/* int main(){
    int n;
    int max_c = INT_MIN;
    int count = 0,index = -1;
    cin >> n;
    int *arr = new int[n];
    for(int  i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        count = 0;
        for(int j = 0;j<n;j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
       if(count > max_c){
           max_c = count;
           index = i;
       }

    }
    if(max_c>n/2){
        cout <<arr[index] << endl;
    }



    return 0;
} */
// this is brute force approach. with time complexity O(n^2).space complexity O(1).

// now we will try to optimixe the solution. order in the question does not matter.so we can sort the array
//  for ex: [1 3 4 2 1 1 1] = [1 1 1 1 2 3 4]
//  now we can just count the till element is same and if count is greater than n/2 output that element.
//   time complexity will be o(nlogn +n) equals to o(nlogn)

int main()
{
    int n;
    int max_c = INT_MAX;
    int count = 1, index = -1;
    cin >> n;
    int *arr = new int[n];
    int temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n); // sort in nlogn time complexity
    for (int i = 1; i < n; i++)
    {
        if (temp == arr[i])
        {
            count++;
        }
        else
        {
            temp = arr[i];
            count = 1;
        }
        if (count > max_c)
        {
            max_c = count;
            index = i;
        }
    }
    if (max_c > n / 2)
        cout << arr[index] << endl;

    return 0;
}
