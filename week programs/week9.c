/*AIM: c-program for congestion control using leaky bucket algorithm
NAME:N.ANAND BABU
ROLL NO:17121A05E1*/
#include<stdio.h>
int main(){
    int incoming, outgoing, buck_size, n, store = 0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n != 0) {
        printf("Enter the incoming packet size : ");
        scanf("%d", &incoming);
        printf("Incoming packet size %d\n", incoming);
        if (incoming <= (buck_size - store)){
            store += incoming;
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
        } else {
            printf("Dropped %d no of packets\n", incoming - (buck_size - store));
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
            store = buck_size;
        }
        store = store - outgoing;
        printf("After outgoing %d packets left out of %d in buffer\n", store, buck_size);
        n--;
    }
}
/* INPUT_OUTPUT:
Enter bucket size, outgoing rate and no of inputs: 20
2
10
Enter the incoming packet size : 2
Incoming packet size 2
Bucket buffer size 2 out of 20
After outgoing 0 packets left out of 20 in buffer
*/