#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Num{
    int num;
    char *s;
};

Num word[999];

int change(char str[999])//��дתСд
{
	int a = 0;
    while (str[a] != '\0')//��str�ַ���δ����ʱ����д��ĸתСд
    {
        if (str[a] >= 'A'&&str[a] <= 'Z')
            str[a] = str[a] + 32;//��Ϊ��д��ĸ��Сд��ĸ��ascll��ֵ���32����дתСдҪ����32
        a++;
    }
	return 0;
}
int Judge(char w[])//�ж��Ƿ��������ĵ���
{
     for (int e = 1; w[e] != '\0';)
    {
		 if(strlen(w)<4)//�жϵ����ֳ��Ƿ񳬹��Լ�����4
	   	return -1;
         if (w[e] >= 'a' && w[e] <= 'z')//�жϵ��ʵ����ַ��Ƿ�����ĸ
	    return -1;
         if (!((w[e] >= 'a' && w[e] <= 'z') || (w[e] >= '0' && w[e] <= '9')))//�жϵ������Ƿ��з���ĸ����
            return -1;
        else
            e++;
	}
	 return 0;
}
int Fre(char f[],int total )   //ͳ�Ƶ��ʳ��ֹ���Ƶ��
{
    if (total>0)
    for (int i = 0; i <total; i++)
    {
        if (!strcmp(f, word[i].s))  
        {
            word[i].num++;      
            return -1;
        }
    }
	return 0;
}

int main()
{   char sentence[999];
    ifstream file("d://test.txt");   //��ȡ
    if (!file){
        cout << "Unable to open ";
        exit(1);   
    }
    while (!file.eof())
    {
        file.getline(sentence,999);
    }
    file.close();
   
    const char *delim = ",����.' '����!?";  //delim����������ָ���������
    char *p= strtok(sentence, delim);//strtok�������ݷָ����ָ��ַ���
	int n=0;
	int c=0;
    while (p)
    {
        if (Judge(p) != -1)
        {
            if (Fre(p, n)!=-1)
            {
                word[n].s = p;
                n++;
            }
        }
        p = strtok(NULL, delim);
    }
    while (word[c].s)        //���ͳ�ƽ��
    {
        cout << word[c].s<< "��" << word[c].num << '\n';
        c++;
    }
    return 0;
}