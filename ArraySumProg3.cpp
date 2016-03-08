#include<iostream>
#include<fstream>
using namespace std;

void ArraySum(int n,int m,int p)
{
    int *progthree,sum=0,i=0;
    progthree=new int[n];          //申请动态内存空间
    ifstream open("D:\\prog2.txt");//以读方式打开文件
    if(!open)
    {
        cout<<"文件打开错误！\n";
    }
    while(open>>progthree[i],i<m)  //文件流对象open读入一个字符并判断对象是否出错
    {
        if(i>=p)    {   sum+=progthree[i];  }
        i++;
    }
    cout<<sum<<endl;
    open.close( );                 //关闭所打开的文件
    delete progthree;
}

int main( )
{
    int num=0,max=0,min=0;
    cout<<"请输入所需的数组范围（如：取5~50范围的数组）：";
    cin>>min>>max;
    num=max-min+1;
    cout<<"该"<<num<<"个数组之和为：";
    ArraySum(num,max,--min);
    return 0;
}
