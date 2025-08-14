#pragma GCC optimize("O3", "unroll-loops")
char* largestGoodInteger(char* num) {
    int count=1;
    char prev=num[0], maxd=' ';
    for (register int i=1; num[i]!='\0'; i++){
        char c=num[i];
        if (c==prev) count++;
        else count=1;
        if (count==3 && c>maxd)
            maxd=c;
        prev=c;
    }
    if (maxd==' ') return "";
    char* ans=malloc(4);
    memset(ans, maxd, 3);
    ans[3]='\0';
    return ans;
}