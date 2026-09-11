while(l <= r) {
    int mid = l + ((r - l) >> 1);
    cout << "? " << mid << endl;
    int resp;
    cin >> resp;
    if(resp == 0) {
        cout << "! " << mid << endl;
        return 0;
    }   
    else if(resp == -1) r = mid - 1;
    else    l = mid + 1;
}
cout << "! " << l << endl;