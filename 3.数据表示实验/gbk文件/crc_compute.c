#include <stdio.h>
char g[50];
void print_binary(int);
int compute_crc_remainder(long Nx, int Gx, int R);

int main(){

    // printf("%d\n", 10000^100101);
    // printf("%d\n", 5/2);
    // print_binary(0x1a);printf("\n");

    // for(int i = 0; i < 50; i++){
    //     int r = compute_crc_remainder(1<<i, (1<<5)+(1<<2)+(1<<0), 5);
    //     printf("0x%x, ", r);
    //     if(i%4 == 3){
    //         printf("\n");
    //     }
    //     // if(r == 0x1){
    //     //     printf("\n````循环次数:%d````\n", i);
    //     //     break;
    //     // }
    // }
    // printf("0x%llx\n ", compute_crc_remainder(1<<5, (1<<4)+(1<<3)+(1<<2)+(1<<0), 4));
    for(int i=0; i < 7; i++){
        printf("0x%llx\n ", compute_crc_remainder(1<<i, (1<<4)+(1<<3)+(1<<2)+(1<<0), 4));
    }
    printf("\n");
    for(int i=0; i < 7; i++){
        for(int j=i+1; j < 7; j++){
            printf("0x%llx,, ", compute_crc_remainder((1<<i)+(1<<j), (1<<4)+(1<<3)+(1<<2)+(1<<0), 4));
        }
        printf("\n");
    }
    
    // printf("0x%x\n", ((1<<5)+(1<<2)+1));
    return 0;
}

int compute_crc_remainder(long Nx, int Gx, int R){
    //Nx暂定最多16位
    //, int Gx = 100101 此行作废
    int i = 50;
    int pre6bit = (Nx / (1ULL << 51));
    Nx = Nx % (1ULL << 51);
    while(i >= -1){
        if((pre6bit >> R) == 1){
            pre6bit = pre6bit ^ Gx;
        }
        pre6bit = pre6bit << 1;
        pre6bit |= (Nx / (1ULL << i));
        Nx = Nx % (1ULL << i);
        i--;
    }
    return pre6bit>>1;
}

void print_binary(int x){
    int count = 0;
    int mid;
    while(x){
        g[count] = x % 2;
        x = x/2;
        count++;
    }
    if(count % 2 == 0){
        mid = count/2;
    }else{
        mid = count/2 + 1;
    }
    for(int i = mid; i < count; i++){
        int tmp = g[i];
        g[i] = g[count-1-i];
        g[count-1-i] = tmp;
    }
    for(int i = 0; i < count; i++){
        printf("%d", g[i]);
    }
}