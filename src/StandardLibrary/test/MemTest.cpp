//
// Created by 80216435 on 2018/8/27.
//

#include <gtest/gtest.h>
#include <iostream>

namespace {
	using namespace std;
	struct st1 {
		char a;
		int b;
		short c;
	};

	struct st2 {
		short c;
		char a;
		int b;
	};
	/**
	 * 平台原因(移植原因)：不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址处取某些特定类型的数据，否则抛出硬件异常。
	 * 性能原因：经过内存对齐后，CPU的内存访问速度大大提升。具体原因稍后解释。
	 *
	 *
	 */

	TEST(test1,test1)
	{
		cout<<"sizeof(char)="<< sizeof(char)<<endl;
		cout<<"sizeof(int)="<< sizeof(int)<<endl;
		cout<<"sizeof(short)="<< sizeof(short)<<endl;

		cout<<"sizeof(st1) is "<<sizeof(st1)<<endl;
		cout<<"sizeof(st2) is "<<sizeof(st2)<<endl;
	}
	/**
	 * 数据成员各自对齐：对于结构的各个成员，第一个成员位于偏移为0的位置，
	 * 				   以后每个数据成员的偏移量必须是min(#pragma pack()指定的数，
	 * 				   这个数据成员的自身长度) 的倍数。
	 * 结构(或联合)本身也要进行对齐：在数据成员完成各自对齐之后，结构(或联合)本身也要进行对齐，
	 * 			 对齐将按照#pragma pack指定的数值和结构(或联合)最大数据成员长度中，
	 * 			 比较小的那个进行。
	 *
	 * min(#pragma pack()指定的数，这个数据成员的自身长度) = 4
	 */

}
