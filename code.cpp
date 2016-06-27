/***************************************************
1、圆盘1~n-1从from移动到mid
2、剩下的一个直接从from移动到to
3、为把圆盘1~n-1从1~n-1从mid移动到to。如果圆盘只有一个，
直接把这个圆盘从from移动到to即可。
****************************************************/
void hanoi(int n)
{
    if(n > 0)]
    {
        func(n,"left","mid","right");
    }
}

void func(int n, string from, string mid, string to)
{
    if(n == 1)
        cout << "move from " << from << " to " << to;
    else
    {
        func(n-1, from, to, mid);
        func(1, from, mid, to);
        func(n-1, mid, from, to);
    }
}
