#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
   
   long long prc = 0;
   long long N,B,C; //교실숫자,주감,부감 + 응시자 수가 실수형일 리는 없으니 C도 long long에다가 넣어두죠

   scanf("%lld", &N);
   
   long long * A = malloc(sizeof(long long) * N); // 우선 동적할당은 일반 정수형으로 할게 아니라 longlong으로 해야 long long 형을 저장 가능하겠죠?

   for (long long i = 0; i < N; i++){
      scanf("%lld", &A[i]);
      //prc += 1; // 주감독관 1명/ 1교실
   }
    prc = N; // 아예 이렇게 해서 시간복잡도를 줄여보죠.
    
   scanf("%lld %lld", &B,&C);
    
   long long CC;
    
   for (long long i = 0; i < N; i++)
   {
       A[i] -= B;
       if( A[i] <= 0 ) // 총감독관이 관리 가능한 범위보다 적은 인원이라면 위 코드에서 마이너스가 나오고 그러면 연산이 꼬이니까 혼자 해결할 수 있는 경우는 추가하지 않고 그냥 둡시다.
       {
           continue;
       }
       if(A[i]<C) // 우선 세가지 정도의 케이스가 나옵니다 1. 부감독관의 관리수용 인원보다 인간이 적은경우 -> 한명을 더해주는걸로 모두 커버가 가능하죠
       {
           prc++;
       }
       else if(A[i]%C == 0) // 2. 부감독관의 관리수용 인원보다 많고 딱 나누어 떨어지는 경우 평범하게 나누기로 해결 가능합니다.
       {
           CC = A[i]/C;
           prc += CC;
       }
       else // 3. 처음 생각하면 생각이 잘 안날 수도 있는 케이스인데 부감독관의 관리 수용인원보다는 많은데 딱 떨어지지 않는 경우 마지막에 한명 추가해주는 걸로 끝내면 됩니다.
       {
           CC = ceil(A[i]/C);
           prc += CC;
           prc++;
       }
   }
   printf("%lld", prc);
}
