#include<iostream>
#include<fstream>
using namespace std;

void ArraySum(int n)
{
    int *progtwo,sum=0,i=0;
    progtwo=new int[n];          //申请动态内存空间
    ifstream open("D:\\prog2.txt");//以读方式打开文件
    if(!open)
    {
        cout<<"文件打开错误！\n";
    }
    while(open>>progtwo[i],i<n)  //文件流对象open读入一个字符并判断对象是否出错
    {
        sum+=progtwo[i];
        i++;
    }
    cout<<sum<<endl;
    open.close( );                 //关闭所打开的文件
    delete progtwo;
}

int main( )
{
    int num;
    cout<<"请输入所需的数组长度：";
    cin>>num;
    cout<<"该"<<num<<"个数组之和为：";
    ArraySum(num);
    return 0;
}
