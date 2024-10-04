#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){               
	char opcode[10],operand[10],mnemonic[10],label[10],code[10];        	
	FILE *f1,*f2,*f3,*f4;
	int locctr,start,length;
	
	f1=fopen("input.txt","r");
	f2=fopen("optab.txt","r");
	f3=fopen("symtab.txt","w");
	f4=fopen("intertab.txt","w");

	fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	
	if(strcmp(opcode,"START")==0){
		start=atoi(operand);
		locctr=start;
		fprintf(f4,"\t%s\t%s\t%s\n",label,opcode,operand);
		fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	}
	else{
		locctr=0;
	}
	while(strcmp(opcode,"END")!=0){
		fprintf(f4,"%d\t",locctr);
		if(strcmp(label,"**")!=0){
			fprintf(f3,"%s\t%d\n",label,locctr);
		}
		
		fscanf(f2,"%s\t%s",code,mnemonic);
		
		while(strcmp(code,"END")!=0){
			if(strcmp(opcode,code)==0){
				locctr+=3;
				break;
			}
			fscanf(f2,"%s\t%s",code,mnemonic);
		}
		if(strcmp(opcode,"WORD")==0){
			locctr+=3;
		}
		else if(strcmp(opcode,"BYTE")==0){
			++locctr;
		}
		else if(strcmp(opcode,"RESB")==0){
			locctr+=atoi(operand);
		}
		else if(strcmp(opcode,"RESW")==0){
			locctr+=3*(atoi(operand));
		}
		else{
			printf("Invalid\n");
		}
		
		fprintf(f4,"%s\t%s\t%s\n",label,opcode,operand);
		fscanf(f1,"%s\t%s\t%s",label,opcode,operand);		
	}
	length=locctr-start;
	printf("Length:%d",length);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	return 0;
}					
