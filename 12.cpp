void solve(vector<int> &a,int n){
    int count_zero = 0;
    int product = 1;

    for(int i = 0 ; i<n ; i++){
        if(a[i] != 0){
            product *= a[i];
        }else{
            count_zero++;
        }
    }
//O(n)
    if(count_zero > 1){
        return vector<int> ans(n,0);
    }
    vector<int> ans(n,0);
    for(int i = 0 ; i<n ; i++){
        if(count_zero != 0){
            if(a[i] == 0){
                ans.push_back(product);
            }
        }else{
            ans.push_back(product/a[i]);
        }
    }
    return ans;
}