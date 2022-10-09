#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
  FILE *f1,*f2,*f3,*f4,*f5;
  f1 = fopen("input.txt","r");
  f2= fopen("optab.txt","r");
  f3 = fopen("symtab","w+");
  f4 = fopen("object_program.txt","w");
  f5 = fopen("temp.txt","w");
  char label[15],opcode[15],operand[20],symbol[20],op[10],val[10],add[30],sym[10][10];
  int sa,ea,locctr,i=0,siz=0,k=0;
  int address[10],loc[10];
  fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
  if(strcmp(opcode,"START")==0)
    {
      fprintf(f4,"H^%s^00%s^",label,operand);
      sa = atoi(operand);
      locctr = sa;
    }
  fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
  while(strcmp(opcode,"END")!=0)
    {
      if(strcmp(label,"-")==0)
	{
	  
	  while(fscanf(f2,"%s\t%s",op,val)!=EOF)
	    {
	      if(strcmp(op,opcode)==0)
		break;
	    }
	  fprintf(f5,"^%s0000",val);
       	  strcpy(sym[i],operand);
	  address[i] = locctr+1;
	  siz+=6;
	  locctr+=3;
	  i++;
	}
	else
	  {
	    int p = 0;
	    loc[k]=locctr;
	    k++;
	    
	    while(p<=i)
	      {
	
		if(strcmp(sym[p],label)==0)
		  {
		  
		    fprintf(f3,"\n%s\t%d",sym[p],locctr);
		    break;
		  }
		p++;
	      }
	    
	     
	    if(strcmp(opcode,"RESW")==0)
	      locctr+=(3*atoi(operand));
	    else if(strcmp(opcode,"WORD")==0)
	      locctr+=3;
	    else if(strcmp(opcode,"RESB")==0)
	      locctr+=atoi(operand);
	    else if(strcmp(opcode,"BYTE")==0)
	      locctr++;
	  }
	fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	
    }
  fclose(f5);
  f5 = fopen("temp.txt","r");
  ea = locctr-sa;
  fprintf(f4,"00%X\nT^00%d^0%X",ea,sa,siz);
      
  while(fscanf(f5,"%s",add)!=EOF)
    {
      fprintf(f4,"%s",add);
    }
  int x = siz/6;
  for(i=0;i<x;++i)
    {
      fprintf(f4,"\nT^00%d^02^%d",address[i],loc[i]);
    }
  fprintf(f4,"\nE^00%d",sa);
}
