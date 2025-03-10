#include<stdio.h>
#include<stdlib.h>
	int buffsize;
	int mutex=1,full = 0,empty;
	int x=0,in=0,out=0;

	int wait(int s){
	return --s;
	}

	int signal(int s){
	return ++s;
	}

	void producer(int buff[]){
	empty = wait(empty);
	mutex=wait(mutex);

buff[in]=++x;
printf("Producer produces item %d\n",x);
in=(in+1)%buffsize;

mutex=signal(mutex);
full = signal(full);
}

void consumer(int buff[]){
full = wait(full);
mutex=wait(mutex);

printf("Consumer consumes item %d\n",buff[out]);
out=(out+1)%buffsize;

mutex=signal(mutex);
empty = signal(empty);
}

void main(){
printf("Enter Buffer Size:");
scanf("%d",&buffsize);
empty = buffsize;
int buff[buffsize],op;
printf("\tMenu\n1.Produce\n2.Consume\n3.Exit\n");
while(1){
printf("Enter option:");
scanf("%d",&op);

switch(op){
case 1:
if(mutex==1 && empty !=0)
producer(buff);
else
printf("Buffer is full!!!\n");
break;
case 2:
if(mutex==1 && full!=0)
consumer(buff);
else
printf("Buffer is empty!!!\n");
break;
case 3:
printf("Exiting...");
exit(0);
break;
default:
printf("Invalid Option");
}
}
}
