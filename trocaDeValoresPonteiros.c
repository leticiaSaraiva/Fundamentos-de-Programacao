
#include <stdio.h>

void troca(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(){
   int x, y;
   scanf("%d %d", &x, &y);
   troca(&x, &y);
   printf("%d %d", x, y);
   return 0;
}
