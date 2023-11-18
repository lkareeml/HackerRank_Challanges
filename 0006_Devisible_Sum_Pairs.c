/*
6 3             n = 6, k = 3
1 3 2 6 1 2     ar = [1, 3, 2, 6, 1, 2]
return === 5
*/
int divisibleSumPairs(int n, int k, int ar_count, int* ar) {
    int x,y;
    int count = 0;
    for(int i = 0; i < n ; i++)
    {
        for(int j = (i+1); j < n; j++)
        {
            if(ar[i] == ar[j])
            {
                //continue; In case you want i>j but didnt work with cases
            }
            x = (ar[i] + ar[j]) / k;
            y = (ar[i] + ar[j]) % k;

            if((x != 0) && (y == 0)){   
                count++;
            }
        }
    }
return count;
}
