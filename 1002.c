#include <stdio.h>
#include <string.h>
int num;
struct student{
	char name[200];
	int final;
	int commit;
	char cadre;
	char west;
	int paper;
};

int yuanshi(struct student st)
{
  if ((st.final>80) && (st.paper>0))
  	{return 8000;}
  else
  	{return 0;}
}

int wusi(struct student st)
{
  if ((st.final>85) && (st.commit>80))
  	{return 4000;}
  else
  	{return 0;}
}

int good(struct student st)
{
  if (st.final>90)
  	{return 2000;}
  else
  	{return 0;}
}

int west(struct student st)
{
  if ((st.final>85) && (st.west=='Y'))
  	{return 1000;}
  else
  	{return 0;}
}

int cadre(struct student st)
{
  if ((st.commit>80) && (st.cadre == 'Y'))
  	{return 850;}
  else
  	{return 0;}
}


int sum(struct student st)
{
	int sum=0;
	// struct student st;
	// scanf("%d",&num);
	sum = yuanshi(st) + wusi(st) + good(st) + west(st) + cadre(st);
	// printf("%d\n",sum);
	// printf("%s\n",st.name);
	// printf("%d\n",st.final);
	// printf("%d\n",st.commit);
	// printf("%s\n",st.cadre);
	// printf("%s\n",st.west);
	// printf("%d\n",st.paper);
	return sum;
}

int main()
{
	int bestscore = 0;
	int score= 0;
	int sumscore = 0;
	char bestname[200];
	scanf("%d",&num);
	for(;num>0;--num)
	{
	    struct student st;
	    scanf("%s %d %d %c %c %d", st.name, &st.final, &st.commit, &st.cadre, &st.west, &st.paper);
	    score = sum(st);
	    sumscore = sumscore + score;
	    if (score>=bestscore)
	    	{
	    		bestscore = score;
	    		strcpy(bestname,st.name);
	    	}


	}
		    printf("%s\n",bestname);
		    printf("%d\n",bestscore);
		    printf("%d\n",sumscore);
		    return 0;
}