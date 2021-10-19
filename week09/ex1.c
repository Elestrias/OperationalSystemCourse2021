#include <stdio.h>
#include <stdlib.h>


struct Frame{
    int age;
    int page;
};

void moveAll(struct Frame* f, int n)
{
    for(int i = 0 ; i < n; ++i)
    {
        f[i].age >>= 1;
    }
}

int main() {
    printf("Enter frames number:");
    int frame_num;
    scanf("%d", &frame_num);
    struct Frame * frames = (struct Frame *)malloc(sizeof(struct Frame)*frame_num);

    for(int i = 0; i<frame_num; i++){
        frames[i].age = 0;
        frames[i].page = -1;
    }

    freopen("input.txt", "r", stdin);
    unsigned long long hit = 0, miss = 0;
    int min = 0;
    long long tact = 0, page = 0, prev_tact = 0;

    end:
    while(scanf("%ld", &page) == 1) {
        for (int j = 0; j < frame_num; ++j)
        {
            if (frames[j].page == page)
            {
                frames[j].age |= (1 << 7);
                ++hit;
                moveAll(frames, frame_num);
                goto end;
            }
        }

        int i = 0;
        int flag = 0;
        min = 0;
        for(int j  = 0; j < frame_num; j++){
                if(frames[j].page == -1){
                    flag = 1;
                    min = j;
                    break;
                }

                if(frames[j].age < frames[min].age){
                    min = j;
                }

        }
        miss++;
        frames[min].age =  1 << 7;
        frames[min].page = page;
        moveAll(frames, frame_num);
    }
    printf("Hit: %llu\nMiss: %llu\nHit/Miss ratio: %f\n", hit, miss, (float)hit / miss);
    return 0;
}
