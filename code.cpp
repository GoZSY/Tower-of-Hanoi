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
//进阶参考解答
/**********************************************************
时间复杂度O(N),空间复杂度O(N)
***********************************************************/
int process(vector<int> arr, int i, int from, int mid, int to)
{
    if(i == -1)
        return 0;
    if(arr[i] != from && arr[i] != to)
        return 0;
    if(arr[i] == from)
        return process(arr, i-1,from, to, mid);
    if(arr[i] == to)
    {
        int res = process(arr, i-1,mid,from,to);
        if(res == -1)
            return -1;
        return res + (1 << i);
    }
}
int step1(vector<int> arr)
{
    if(arr.size()==0)
        return -1;
    return process(arr, arr.size()-1, 1, 2, 3);
}

/**********************************************************
时间复杂度O(N),空间复杂度O(1)
***********************************************************/

int step2(vector<int> arr)
{
    if(arr.size()==0)
        return -1;
    int from = 1;
    int mid = 2;
    int to = 3;
    int i = arr.size() - 1;
    int res = 0;
    int temp = 0;
    while(i >= 0)
    {
        if(arr[i] != from && arr[i] != to)
            return -1;
        if(arr[i] == from)
        {
            temp = to;
            to = mid;
        }
        if(arr[i] == to)
        {
            res += 1<<i;
            temp = from;
            from = mid;
            
        }
        mid = temp;
        i--;
    }
    return res;
}
