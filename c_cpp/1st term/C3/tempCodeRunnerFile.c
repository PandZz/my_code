for (LL i = 0; i <= 97; ++i) 
    {
        if (ans[i] * 2 == ans[i + 1]) ans[i] = ans[i + 1] = 0;
        ans[i + 1] += ans[i] / 2, ans[i + 2] += ans[i] / 2;
        ans[i] %= 2;
    }