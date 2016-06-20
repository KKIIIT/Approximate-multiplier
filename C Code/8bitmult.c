#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	char s1[8], s2[8],input[65539],ch;
	FILE *fp;
	int ii,jj;
	fp = fopen("in.txt","r"); // read mode
	int final_matrix[9][101];
	for (ii = 1; ii <= 8; ii++)
		for (jj = 0; jj <= 100; jj++)
			final_matrix[ii][jj] = 0;
	if( fp == NULL )
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	int in=0,first=0,second=0,first_1=0,second_1=0;
	while( ( ch = fgetc(fp) ) != EOF )
	{
		input[in]=ch;
		printf("%c",ch);
		in++;
	}
	fclose(fp);
	char stage1[15],stage2[15],stage3[15],stage4[15],stage5[15],stage6[15],stage7[15],stage8[15],i;
	for(first=0;first<256;first++)
	{
		int zz=0,iii=strlen(input);
		printf("I am Here\n");
		printf("len %d \n", iii);
		for(first_1=(first*8);first_1<((first+1)*8);first_1++)
		{
			s1[zz]=input[first_1];
			zz++;
		}
		for(second=0;second<256;second++)
		{
			zz=0;
			for(first_1=(second*8);first_1<((second+1)*8);first_1++)
			{
				s2[zz]=input[first_1];
				zz++;
			}
				printf("s1 = %s s2 = %s\n", s1,s2);
			int k=0;
			k=7;
			for(i=0;i<k;i++)
				stage1[i]='0';
			k=14;
			for(i=7;i>=0;i--)
			{
				//printf("%c %c\n", s2[7],s1[i]);
				if(s2[7]-'0'==1&&s1[i]-'0'==1)
					stage1[k]='1';
				else
					stage1[k]='0';
				k--;
			}

			k=6;
			for(i=0;i<k;i++)
				stage2[i]='0';
			k=13;
			for(i=7;i>=0;i--)
			{
				if(s2[6]-'0'==1&&s1[i]-'0'==1)
					stage2[k]='1';
				else
					stage2[k]='0';
				k--;
			}
			for(i=14;i<15;i++)
				stage2[i]='0';

			k=5;
			for(i=0;i<k;i++)
				stage3[i]='0';
			k=12;
			for(i=7;i>=0;i--)
			{
				if(s2[5]-'0'==1&&s1[i]-'0'==1)
					stage3[k]='1';
				else
					stage3[k]='0';
				k--;
			}
			for(i=13;i<15;i++)
				stage3[i]='0';

			k=4;
			for(i=0;i<k;i++)
				stage4[i]='0';
			k=11;
			for(i=7;i>=0;i--)
			{
				if(s2[4]-'0'==1&&s1[i]-'0'==1)
					stage4[k]='1';
				else
					stage4[k]='0';
				k--;
			}
			for(i=12;i<15;i++)
				stage4[i]='0';

			k=3;
			for(i=0;i<k;i++)
				stage5[i]='0';
			k=10;
			for(i=7;i>=0;i--)
			{
				if(s2[3]-'0'==1&&s1[i]-'0'==1)
					stage5[k]='1';
				else
					stage5[k]='0';
				k--;
			}
			for(i=11;i<15;i++)
				stage5[i]='0';

			k=2;
			for(i=0;i<k;i++)
				stage6[i]='0';
			k=9;
			for(i=7;i>=0;i--)
			{
				if(s2[2]-'0'==1&&s1[i]-'0'==1)
					stage6[k]='1';
				else
					stage6[k]='0';
				k--;
			}
			for(i=10;i<15;i++)
				stage6[i]='0';

			k=1;
			for(i=0;i<k;i++)
				stage7[i]='0';
			k=8;
			for(i=7;i>=0;i--)
			{
				if(s2[1]-'0'==1&&s1[i]-'0'==1)
					stage7[k]='1';
				else
					stage7[k]='0';
				k--;
			}
			for(i=9;i<15;i++)
				stage7[i]='0';

			k=0;
			for(i=0;i<k;i++)
				stage8[i]='0';
			k=7;
			for(i=7;i>=0;i--)
			{
				if(s2[0]-'0'==1&&s1[i]-'0'==1)
					stage8[k]='1';
				else
					stage8[k]='0';
				k--;
			}
			for(i=8;i<15;i++)
				stage8[i]='0';

			char final_stage_copy[16],final_stage1[16], final_stage2[16], final_stage3[16], final_stage4[16], final_stage5[16], final_stage6[16], final_stage7[16], final_stage8[16];

			strcpy(final_stage_copy,stage8);
			int c_in = 0;
			//printf("\n");
			//printf("%d\n",final_stage1[1]-'0' + stage7[1]-'0' + c_in);
			// printf("Final Stage 1 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage1[i]);
			// printf("\n");
			// printf("Final Stage 2 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage2[i]);
			// printf("\n");
			// printf("Final Stage 3 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage3[i]);
			// printf("\n");
			// printf("Final Stage 4 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage4[i]);
			// printf("\n");
			// printf("Final Stage 5 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage5[i]);
			// printf("\n");
			// printf("Final Stage 6 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage6[i]);
			// printf("\n");
			// printf("Final Stage 7 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage7[i]);
			// printf("\n");
			// printf("Final Stage 8 - ");
			// for(i=0;i<15;i++)
			// 	printf("%c",stage8[i]);
			// printf("\n");
			final_stage1[0] = '0';
			for(i=1;i<=15;i++)
			{
				final_stage1[i] = final_stage_copy[i-1];
			}
			for(i=15;i>=1;i--)
			{
				int total = final_stage1[i]-'0' + stage7[i-1]-'0' + c_in;
				if(total >= 2)
				{
					c_in = 1;
				}
				else
					c_in=0;
				int final_total = total%2;
				final_stage2[i] = (char)(final_total+(int)('0'));
			}
			if(c_in==1)
				final_stage2[0]='1';
			else
				final_stage2[0]='0';

			c_in = 0;
			for(i=15;i>=1;i--)
			{
				int total = final_stage2[i]-'0' + stage6[i-1]-'0' + c_in;
				if(total >= 2)
				{
					c_in = 1;
				}
				else
					c_in=0;
				int final_total = total%2;
				final_stage3[i] = (char)(final_total+(int)('0'));
			}
			//	final_stage3[0]=final_stage2[0];
			if(c_in==1)
				final_stage3[0]='1';
			else
				final_stage3[0]=final_stage2[0];

			c_in = 0;
			for(i=15;i>=1;i--)
			{
				int total = final_stage3[i]-'0' + stage5[i-1]-'0' + c_in;
				//printf("%d %c %c %d\n",i,final_stage3[i],stage5[i-1],total);
				if(total >= 2)
				{
					c_in = 1;
				}
				else
					c_in=0;
				int final_total = total%2;
				final_stage4[i] = (char)(final_total+(int)('0'));
			}
			//	final_stage4[0]=final_stage3[0];

			if(c_in==1)
				final_stage4[0]='1';
			else
				final_stage4[0]=final_stage3[0];
			c_in = 0;
			for(i=15;i>=1;i--)
			{
				int total = final_stage4[i]-'0' + stage4[i-1]-'0' + c_in;
				if(total >= 2)
				{
					c_in = 1;
				}
				else
					c_in=0;
				int final_total = total%2;
				final_stage5[i] = (char)(final_total+(int)('0'));
			}
			//	final_stage5[0]=final_stage4[0];
			if(c_in==1)
				final_stage5[0]='1';
			else
				final_stage5[0]=final_stage4[0];

			c_in = 0;
			for(i=15;i>=1;i--)
			{
				int total = final_stage5[i]-'0' + stage3[i-1]-'0' + c_in;
				if(total >= 2)
				{
					c_in = 1;
				}
				else
					c_in=0;
				int final_total = total%2;
				final_stage6[i] = (char)(final_total+(int)('0'));
			}
			//	final_stage6[0]=final_stage5[0];
			if(c_in==1)
				final_stage6[0]='1';
			else
				final_stage6[0]=final_stage5[0];

			c_in = 0;
			for(i=15;i>=1;i--)
			{
				int total = final_stage6[i]-'0' + stage2[i-1]-'0' + c_in;
				if(total >= 2)
				{
					c_in = 1;
				}
				else
					c_in=0;
				int final_total = total%2;
				final_stage7[i] = (char)(final_total+(int)('0'));
			}
			//	final_stage7[0]=final_stage6[0];
			if(c_in==1)
				final_stage7[0]='1';
			else
				final_stage7[0]=final_stage6[0];

			c_in = 0;
			for(i=15;i>=1;i--)
			{
				int total = final_stage7[i]-'0' + stage1[i-1]-'0' + c_in;
				if(total >= 2)
				{
					c_in = 1;
				}
				else
					c_in=0;
				int final_total = total%2;
				final_stage8[i] = (char)(final_total+(int)('0'));
			}
			//		final_stage8[0]=final_stage7[0];
			if(c_in==1)
				final_stage8[0]='1';
			else
				final_stage8[0]=final_stage7[0];


		//	printf("Final Stage 1 - ");
			int s;
			int sum_1=0,sum_2=0,sum_3=0,sum_4=0,sum_5=0,sum_6=0,sum_7=0,sum_8=0;
			for(s = 0; s <16 ; s++)
			{
				//	printf("%c ",final_stage1[s]);
				if(final_stage1[s] == '1')
				{
					sum_1 = sum_1 + pow(2,15-s);
				}
			}
			for(s = 0; s <16 ; s++)
			{
				//	printf("%c ",final_stage1[s]);
				if(final_stage2[s] == '1')
				{
					sum_2 = sum_2 + pow(2,15-s);
				}
			}
			for(s = 0; s <16 ; s++)
			{
				//printf("%c ",final_stage1[s]);
				if(final_stage3[s] == '1')
				{
					sum_3 = sum_3 + pow(2,15-s);
				}
			}
			for(s = 0; s <16 ; s++)
			{
				//		printf("%c ",final_stage4[s]);
				if(final_stage4[s] == '1')
				{
					sum_4 = sum_4 + pow(2,15-s);
				}
			}
			for(s = 0; s <16 ; s++)
			{
				//		printf("%c ",final_stage1[s]);
				if(final_stage5[s] == '1')
				{
					sum_5 = sum_5 + pow(2,15-s);
				}
			}
			for(s = 0; s <16 ; s++)
			{
				//		printf("%c ",final_stage1[s]);
				if(final_stage6[s] == '1')
				{
					sum_6 = sum_6 + pow(2,15-s);
				}
			}
			for(s = 0; s <16 ; s++)
			{
				//	printf("%c ",final_stage1[s]);
				if(final_stage7[s] == '1')
				{
					sum_7 = sum_7 + pow(2,15-s);
				}
			}
			for(s = 0; s <16 ; s++)
			{
				//printf("%c ",final_stage1[s]);
				if(final_stage8[s] == '1')
				{
					sum_8 = sum_8 + pow(2,15-s);
				}
			}
			printf("\n");
			//for(i=0;i<=15;i++)
			//printf("%c",final_stage1[i]);
		//	printf("\n");

			if(sum_8!=0)
			{printf("Accuracy stage1 = %d",((sum_8-sum_1)*100/sum_8));
				int accuracy_1 = (sum_8-sum_1)*100/sum_8;
				final_matrix[1][accuracy_1]++;}
			printf("\n");
			if(sum_8!=0)
			{printf("Accuracy stage2 = %d",((sum_8-sum_2)*100/sum_8));
				int accuracy_2 = (sum_8-sum_2)*100/sum_8;
				final_matrix[2][accuracy_2]++;}
			printf("\n");
			if(sum_8!=0)
			{printf("Accuracy stage3 = %d",((sum_8-sum_3)*100/sum_8));
				int accuracy_3 = (sum_8-sum_3)*100/sum_8;
				final_matrix[3][accuracy_3]++;}
			printf("\n");
			if(sum_8!=0)
			{printf("Accuracy stage4 = %d",((sum_8-sum_4)*100/sum_8));
				int accuracy_4 = (sum_8-sum_4)*100/sum_8;
				final_matrix[4][accuracy_4]++;}
			printf("\n");
			if(sum_8!=0)
			{printf("Accuracy stage5 = %d",((sum_8-sum_5)*100/sum_8));
				int accuracy_5 = (sum_8-sum_5)*100/sum_8;
				final_matrix[5][accuracy_5]++;}
			printf("\n");
			if(sum_8!=0)
			{printf("Accuracy stage6 = %d",((sum_8-sum_6)*100/sum_8));
				int accuracy_6 = (sum_8-sum_6)*100/sum_8;
				final_matrix[6][accuracy_6]++;}
			printf("\n");
			if(sum_8!=0)
			{printf("Accuracy stage7 = %d",((sum_8-sum_7)*100/sum_8));
				int accuracy_7 = (sum_8-sum_7)*100/sum_8;
				final_matrix[7][accuracy_7]++;}
			printf("\n");
			if(sum_8!=0)
			{printf("Accuracy stage8 = %d",((sum_8-sum_8)*100/sum_8));
				int accuracy_8 = (sum_8-sum_8)*100/sum_8;
				final_matrix[8][accuracy_8]++;}
			printf("\n");
			printf("Final Stage 1: ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage1[i]);
			printf("\n");
			printf("Final Stage 2 - ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage2[i]);
			printf("\n");
			printf("Final Stage 3 - ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage3[i]);
			printf("\n");
			printf("Final Stage 4 - ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage4[i]);
			printf("\n");
			printf("Final Stage 5 - ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage5[i]);
			printf("\n");
			printf("Final Stage 6 - ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage6[i]);
			printf("\n");
			printf("Final Stage 7 - ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage7[i]);
			printf("\n");
			printf("Final Stage 8 - ");
			for(i=0;i<=15;i++)
				printf("%c",final_stage8[i]);
			printf("\n");
		}
	}
	int j;
	/*for (i = 1; i <= 7; i++)
	{
		printf("Final Stage %d : ", i);
		for (j = 0; j <= 100; j++)
		{   					 
			printf("%d ",final_matrix[i][j]);
		}
		printf("\n");
	}*/
//        float temp=0;
int temp=0;
        for (i = 1; i <= 8; i++)
	{
		printf("Final Stage %d : ", i);
		for (j = 0; j <= 100; j++)
		{   	
			temp=temp+final_matrix[i][j];
			if(j%10==0&&j!=0){				 
 printf("%d ",temp);			
//printf("%f ",temp*100/65025);
                         temp=0;
                             }
		}
		printf("\n");
	}


}
