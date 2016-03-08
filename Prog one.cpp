#include<iostream>
#include<fstream>
using namespace std;

int main( )
{
    int sum=0,progone[100],i=0;
    ifstream open("D:\\prog1.txt");//以读方式打开磁盘文件
    if(!open)
    {
        cout<<"文件打开错误！/n";
    }
    while(open>>progone[i],i<100)  //文件流对象open读入一个字符并判断对象是否出错
    {
        sum+=progone[i];
        i++;
    }
    cout<<"该100个元素之和为："<<sum<<endl;
    open.close( );                 //关闭所打开的文件
    return 0;
}
