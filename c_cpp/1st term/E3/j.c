#include <stdio.h>

void myPrint(int ans)
{
    if (!ans) { puts("Empty set"); return ; }
    putchar('{');
    int flag = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (ans & 1)
        {
            if (!flag) { flag = 1; putchar('a' + i); }
            else printf(",%c", 'a' + i);
        }
        ans >>= 1;
    }
    putchar('}'), putchar('\n');
    return ;
}

int main()
{
    // freopen("test.txt", "w", stdout);
    char elem_a[30], elem_b[30];
    int op, na, nb, set_op, ans, a, b, cnt = 0;
    const int full_set = (1 << 26) - 1;
    while (~scanf("%d", &op) && (~op))
    {
        ++cnt;
        printf("Case %d:\n", cnt);
        if (!op)
        {
            scanf("%d", &ans);
            myPrint(ans);
        }
        else
        {
            scanf("%d%d%d\n", &na, &nb, &set_op);
            a = 0, b = 0;
            scanf("%s%s", elem_a, elem_b);
            for (int i = 0; i < na; ++i) a |= 1 << (elem_a[i] - 'a');
            // 因为Windows生成数据换行符是\n\r需要两个getchar()
            for (int i = 0; i < nb; ++i) b |= 1 << (elem_b[i] - 'a');
            // printf("a=%d b=%d\n", a, b);
            if (a == b) { puts("Set A is equal to set B!"); continue; }
            if ((a | b) == b) puts("Set A is the subset of set B!");
            else if ((a | b) == a) puts("Set B is the subset of set A!");
            else puts("No subset relationship!");
            switch (set_op)
            {
                case 0: { ans = a & b; printf("The intersection of set A and set B is:"), myPrint(ans); break; }
                case 1: { ans = a | b; printf("The union of set A and set B is:"), myPrint(ans); break; }
                case 2: { ans = full_set ^ a; printf("The complement of set A is:"), myPrint(ans); break; }
                case 3: { ans = a - (b & a); printf("The difference of set A and set B is:"), myPrint(ans); break; }
                case 4: { ans = full_set ^ (a & b); printf("The complement of the intersection of set A and set B is:"), myPrint(ans); break; }
                case 5: { ans = full_set ^ (a | b); printf("The complement of the union of set A and set B is:"), myPrint(ans); break; }
            }
        }
    }
    return 0;
}