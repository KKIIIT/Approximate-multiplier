#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int per[16][101];
char pro[]="00000000000000000000000000000000";
char reset[]="00000000000000000000000000000000";
int stage=1;
int flag=0;
unsigned long long int r_stage[16]={0};
unsigned long long int final;
int check=0;
void add(char[],int);
int findfirst(char a[])
{
	int i=0;
	while(a[i]!='\0')
	{
		if(a[i]=='1')
			break;
		i++;
	}
	return i;
}
int main()
{
	char gen[65536][17];
        int i,j;
        for(i=0;i<65536;i++)
        {
                for(j=0;j<16;j++)
                {
                        gen[i][j]=(char)((i/(int)(pow(2,16-(j+1))))%2+(int)('0'));
                }
                gen[i][16]='\0';
                //printf("%s\n",gen[i]);
        }
	char s1[17],s2[17],zeros[17];
	int x,y;
	for(x=0;x<15;x++)
		zeros[x]='0';
	zeros[16]='\0';
	for(x=0;x<101;x++)
		for(y=0;y<=16;y++)
			per[y][x]=0;
	for(x=0;x<65536;x++)
	{
		strcpy(s1,gen[x]);
		int p1=findfirst(s1);
		//printf("%s %s %d",s1,gen[x],p1);
		for(y=0;y<65536;y++)
		{
			//printf("%s %s %d\n",s1,gen[x],p1);
			stage=1;
			flag=0;
			strcpy(pro,reset);
			//printf("initial = %s\n",pro);
			int u=0;
			for(u=0;u<16;u++)
				r_stage[u]=0;			
			strcpy(s2,gen[y]);
			char temp[17];
			int p2=findfirst(s2);
			if(p1>p2)
			{
				strcpy(temp,s1);
				strcpy(s1,s2);
				strcpy(s2,temp);
			}
//			printf("multiplicant = %s\nmultiplier = %s\n",s1,s2);
			int a,b,c,i,j,k;
			for(i=0;i<=15;i++)
			{
				if(s2[i]=='1')
				{
					flag=1;
                                        //printf("Send to add %s \n",s1);
					add(s1,i);
					//printf("Send to add %s \n",s1);
				}
				if(s2[i]=='0')
					add(zeros,i);
				if(flag==1)
					stage++;	
			}
			//printf("%d\n",stage);
			for(i=0;i<stage-1&&final!=0;i++)
			{
				unsigned long long int p=0,p1,sub;
				sub=final-r_stage[i];
				p1=sub*100;
				p=p1/final;
				per[i][(int)(p)]++;
			}
			if(final==0)
				per[0][0]++;
		}
	}
	unsigned long long int per1[16][10];
	unsigned long long int total=0,t=0,l=0;
	for(x=0;x<16;x++)
	{
		total=0;
		for(y=0;y<101;y++)
		{
			t+=per[x][y];
			if(y%10==9)
			{
				per1[x][l++]=t;
				total+=t;
				t=0;
			}	
			//printf("%d ",per[x][y]);
		}
		//printf("\n");
		for(y=0;y<10;y++)
		{
			printf("%llu ",per1[x][y]);
		}
		l=0;
		printf(" [ %llu ]  ",total);
		int tot=0;
		for(y=0;y<10;y++)
		{
			tot+=per1[x][y];
			if(total!=0)
				printf("%.3f ",((float)(tot*100)/(float)(total)));
			else
				printf("0.000 ");
		}	
		printf("\n");
	}
	return 0;
}
void add(char num[],int k)
{
	//printf("%s %d\n",num,k);
	int i;
	int c=0;
	char res[]="0000000000000000000000000000000";
	//printf("%d",(int)(strlen(res)));
	for(i=0;num[i]!='\0';i++)
	{
		res[i+k]=num[i];
	}
	res[31]='\0';
        //printf("%d",(int)(strlen(res)));
	//printf("%s\n",res);
	for(i=30;i>=0;i--)
	{
		//printf("%c - ",pro[i+1]);
		pro[i+1]=(char)((int)(res[i])+(int)(pro[i+1])-(int)('0')+c);
		if(pro[i+1]>='2')
			c=1;
		else
			c=0;
		if(pro[i+1]=='2'||pro[i+1]=='0')
			pro[i+1]='0';
		else
			pro[i+1]='1';
		//printf("%c - %c - %d\n",res[i],pro[i+1],c);
	}
	//printf("%s\n",pro);
	//int j=k-1;
	if(c>0)
	{
		/*pro[j]=(char)((int)(pro[j])+c);
		  if(pro[j]>='2')
		  c=1;
		  else
		  c=0;
		  if(pro[j]=='2'||pro[j]=='0')
		  pro[j]='0';
		  else
		  pro[j]='1';
		  j--;*/
		pro[0]='1';
	}
	if(flag==1)
	{
		unsigned long long int temp=0;
		for(i=0;i<32;i++)
		{
			int num=pro[i]-(int)('0');
			temp*=2;
			temp+=(unsigned long long int)(num);
		}
		//printf("%s\n",pro);
		r_stage[stage-1]=temp;	
//		printf("Stage %d : %llu\n",stage,r_stage[stage-1]);
		final=temp;
	}
}	
