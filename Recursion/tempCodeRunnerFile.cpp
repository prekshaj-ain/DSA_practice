int mid = e - (e-s)/2;
    if( (mid == n-1 || ele < arr[mid - 1]) && ele == arr[mid]){
        return mid;
    }
    else if(arr[mid] > ele) last(arr,s,mid-1,ele,n);
    else last(arr,mid+1,e,ele,n);