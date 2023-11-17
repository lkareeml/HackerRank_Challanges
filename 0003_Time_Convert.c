char* timeConversion(char* s) {
///Input : 05:15:33AM OR 05:15:33PM
     char* s_return = (char*)malloc(7 * sizeof(char));

    if((s[8] == 'A') && (s[0] == '1') && (s[1] == '2'))
    {
        s_return[0] = '0';
        s_return[1] = '0';
        for(int i = 2;i<8;i++)
        {
            s_return[i] = s[i];
        }
    }
    else if((s[8] == 'A'))
    {
        for(int i =0;i<8;i++)
        {
            s_return[i] = s[i];
        }
    }
    else if((s[8] == 'P') && (s[0] == '1') && (s[1] == '2'))
    {
        s_return[0] = '1';
        s_return[1] = '2';
        for(int i =2;i<8;i++)
        {
            s_return[i] = s[i];
        }
    }
    else if(s[8] == 'P' && (s[0] == '0') && (s[1] < '8'))
    {
        s_return[0] = '1';
        s_return[1] = s[1] + 2;
        for(int i =2;i<8;i++)
        {
            s_return[i] = s[i];
        }
    }
    else if(s[8] == 'P' && (s[0] == '0') && (s[1] >= '8'))
    {
        s_return[0] = '2';
        s_return[1] = s[1] - 8;
        for(int i =2;i<8;i++)
        {
            s_return[i] = s[i];
        }
    }
    else if(s[8] == 'P' && (s[0] == '1') && ((s[1] == '0')| (s[1] == '1')))
    {
        s_return[0] = '2';
        s_return[1] = s[1] + 2;
        for(int i =2;i<8;i++)
        {
            s_return[i] = s[i];
        }
    }
return s_return;
}
