#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

#if 0
//strtok,�ַ������ң�
int main(){
	char str[] = "you are,a.student";
	char str1[] = "i am.a,student";
	char sep[] = ",. ";
	char *tok = NULL;
	char maxlen[20] = "";//�洢��ַ����ʣ�
	for (tok = strtok(str, sep); tok != NULL; tok = strtok(NULL, sep)){
		//puts(tok);
		if (strlen(maxlen) < strlen(tok)){
			strcpy(maxlen, tok);
		}
	}
	puts(maxlen);
	system("pause");
	return 0;
}
#endif

#if 0
//�����������ַ���������
int main(){
	char str1[] = "abcdef";
	char str2[] = "abcahiohios";
	int n = strncmp(str1+1, str2+1, 3);//�Ƚ�ǰn���ַ���
	printf("%d\n", n);
	system("pause");
	return 0;
}
#endif

#if 0
//�����ַ���ǰn���ַ���
int main(){
	char str1[] = "abcdef";
	char str2[] = "1234";
	strncpy(str1, str2, 6);
	puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//strncat:ƴ��ǰn���ַ���
int main(){
	char str1[20] = "abcdef";
	char str2[] = "1234";
	strncat(str1, str2, 6);//��str2ǰn���ַ�ƴ�ӵ�str1���棻
	puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//strstr:����ҵ����Ӧ���ַ����ͷ����ҵ����׵�ַ�����û���ҵ����ͷ���NULL��
int main(){
	char str1[] = "abcbcdef";
	char str2[] = "bcdefk";
	char *p = NULL;
	if (p=strstr(str1, str2))//��str1�в���str2�ַ���
		puts(p);
	else
		printf("û���Ҽ�\n");
	system("pause");
	return 0;
}
#endif

#if 0
//���strstr��
char *my_strstr(const char*str1, const char*str2){
	char*p = (char*)str1;
	char*s1 = (char*)str1;
	char*s2 = (char*)str2;
	assert(str1 != NULL);
	while (*p){
		s1 = p;
		s2 = (char*)str2;
		while (*s1 && *s2 && *s1 == *s2){
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return p;
		p++;
	}
	return NULL;
}
int main(){
	char str1[] = "abcbcdefggg";
	char str2[] = "bcdef";
	char *p = NULL;
	if (p = my_strstr(str1, str2))
		puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//memcpy:�����ַ�������\0�󲻻�ֹͣ����;
//ģ��ʵ��memcpy;
void *my_memcpy(void *dest, const void *src, size_t count){
	void *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (count){
		*(char*)dest = *(char*)src;
		src = (char*)src + 1;
		dest = (char*)dest + 1;
		count--;
	}
	return ret;
}

int main(){
	char str1[] = "abcdef";
	char str2[] = "12345678";
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[10] = { 9, 8, 0 };
	my_memcpy(arr1, arr1+2, 5 * sizeof(int));
	//memcpy(str1, str2, 2);//��str2ǰn���ַ�������str1��Ӧλ�ã�
	puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//memmove:�ַ�������
int main(){
	char a[20] = "1234567890";
	char b[20] = "qwertyui";
	memmove(a, b + 2, 5);
	puts(a);
	system("pause");
	return 0;
}
#endif

#if 0
//�ṹ�壻
//struct{
//	int num;
//	char name[20];
//	int age;
//}aa;
//
//struct{
//	int num;
//	char name[20];
//	int age;
//}*p;
struct student{
	int num;       //4
	char name[20]; //20
	int age;       //4
};
//�ṹ��С��->�ڴ��ֽڶ������⣬���ͺ�������ռ�ֽڴ�Ķ��룻
struct data{
	int num;    //4
	char a;     //1
	char b;     //1
	double d;   //8   
//ǰ��С����һ�ߣ�int��char��char����С���ڴ�֮�ͺʹ�Ķ��루����Ϊ��ı�������
//���С�������ߣ������߷ֱ���룻
};
int main(){
	struct student a;
	printf("%d\n", sizeof(struct student));//28
	system("pause");
	return 0;
}
#endif

#if 0
//�ṹ��
typedef struct student{
	int num;
	char name[20];
}STU;
//typedef    ��ʾ��STU��ʾstruct student��
//��STU a = struct student a��
struct node{
	int n;
	//struct node next;�ṹ���в��ܰ���ֵ���ͣ�
	struct node *next;//���ǿ��԰����Լ���ָ�����ͣ�
};
int main(){
	system("pause");
	return 0;
}
#endif

#if 0
//�ṹ��
struct s1{
	char c1;
	int c2;
	char c3;
};
//1����һ����Ա��Զ�����ڽṹ����ʼλ�õ�0ƫ��������
//2���ӵڶ�����Ա��ʼ��ÿ����Ա������ĳ������������������ƫ�ƴ���
//ĳ������������Ա�����������Ĭ�϶������Ľ�Сֵ��
//3���ṹ���ܴ�С�������г�Ա�������е����ֵ����������
int main(){
	printf("%d\n",offsetof(struct s1,c1));
	printf("%d\n", offsetof(struct s1, c2));
	printf("%d\n", offsetof(struct s1, c3));
	printf("%d\n", sizeof(struct s1));
	system("pause");
	return 0;
}
#endif

#if 0
//�ṹ��;
struct s2{
	char c1;//1
	char c2;//1
	int c3;//4
};
struct s3{
	struct s2 a;//8   Ƕ�׵Ľṹ����������������->4
	int b;//4
	//double c;//8
	char c[15];//15
};
int main(){
	printf("%d\n", sizeof(struct s3));
	system("pause");
	return 0;
}
#endif

#if 0
//�ṹ��
typedef struct student{
	int num;
	char name[20];
	char sex;
}STU;
int main(){
	STU a = { 1, "zhangsan", 'f' };//��ʼ���Լ���ֵ
	STU b;//��ʼ��
	b.num = 2;//��ֵ
	strcpy(b.name, "lisi");//��ֵ
	b.sex = 'm';//��ֵ
	STU c;
	STU *p = &a;//��ֵ
	c = { 3, "wangwu", 'm' };
	printf("%d,%s,%c\n",a.num,a.name,a.sex);
	printf("%d,%s,%c\n", b.num, b.name, b.sex);
	printf("%d,%s,%c\n", c.num, c.name, c.sex);
	printf("%d,%s,%c\n", (*p).num, p->name, p->sex);
	system("pause");
	return 0;
}
#endif

#if 0
//�ṹ��
#pragma pack(1)//Ĭ�϶�����Ϊ1
struct data{
	int a;
	char c;
};
int main(){
	printf("%d\n", sizeof(struct data));
	system("pause");
	return 0;
}
#endif

#if 0
//λ��
//struct A{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
struct A{
//λ���ϵĿռ��ǰ���Ҫ�󿪱�һ�������ĸ��ֽڣ�
	char e;//1�ֽ�
	int a : 2;//00000010 00000000 00000000 00000000//ռ�ֽ��е�nλ�����Ҳ��ܿ��ֽ�ռλ�������������¿����¿ռ䣻
	int b : 5;//01000010 00000000 00000000 00000000
	int c : 10;//01000010 00000000 00000010 00000000
	int d : 30;//���¿����¿ռ䣻
};
int main(){
	printf("%d\n", sizeof(struct A));
	system("pause");
	return 0;
}
#endif

#if 0
//ö��--һһ�о�
enum week{Mon = 1, Tues, Wed, Thu, Fri��Sat��Sun};//��û�и�ֵ������£�Ĭ�ϴ�0��ʼ��
enum data{a=5,b,c,d,e=1,f};//�����ֵΪö�ٳ�����
int main(){
	enum week w;//����ö�ٱ���w��
	enum data t;
	w = Thu;
	t = d;
	printf("%d\n", w);
	printf("%d\n", t);
	system("pause");
	return 0;
}
#endif

#if 0
//�����壻
union data{
	int a;
	char b;
	double c;
	int i;
	char e;
};
int main(){
	union data aa;
	union data d;
	d.i = 0x11223344;
	d.e = 0x55;
	printf("%x\n", d.i);
	printf("%d\n", sizeof(aa));
	printf("%p\n", &aa.a);
	printf("%p\n", &aa.b);
	printf("%p\n", &aa.c);
	system("pause");
	return 0;
}
#endif

#if 1
int sys_check(){
	int a = 1;
	return *((char*)&a);
}
int main(){
	int n = sys_check();
	if (n == 1)
		printf("С��\n");
	else
		printf("���\n");
	system("pause");
	return 0;
}
#endif