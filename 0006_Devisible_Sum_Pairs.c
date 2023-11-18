/*
6 3             n = 6, k = 3
1 3 2 6 1 2     ar = [1, 3, 2, 6, 1, 2]
return === 5
*/
int divisibleSumPairs(int n, int k, int ar_count, int* ar) {
    int temp;
    int count = 0;
    for(int i = 0; i < n ; i++)
    {
        for(int j = (i+1); j < n; j++)
        {
            if(ar[i] == ar[j])
            {
                continue;
            }
            temp = (ar[i] + ar[j]);
            if(((temp/k) != 0) && ((temp%k) == 0) ){   
                count++;
            }
        }
    }
return count;
}
