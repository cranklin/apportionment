#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMSTATES   50
#define MAXSEATS    435

void highestAverage(int state, int *representatives, double *divisors){
    double divisor;
    divisor = sqrt(representatives[state] * (representatives[state]+1));
    divisors[state] = divisor;
}

int getLargest(int *populations, double *divisors){
    int max,i;
    max = 0;
    for(i=1;i<NUMSTATES;i++){
        if(populations[i]/divisors[i] > populations[max]/divisors[max]){
            max = i;
        }
    }
    return max;
}

void printArray(char *stateNames[],int *representatives){
    int i,counter;
    counter = 0;
    for(i=0;i<NUMSTATES;i++){
        printf("%s - %d \n",stateNames[i],representatives[i]);
        counter = counter+representatives[i];
    }
    printf("total %d \n",counter);
}

int main(void){
    int populationArray[NUMSTATES] = {4661900,686293,6500180,2855390,36756666,4939456,3501252,873092,18328340,9685744,1288198,1523816,12901563,6376792,3002555,2802134,4269245,4410796,1316456,5633597,6497967,10003422,5220393,2938618,5911605,967440,1783432,2600167,1315809,8682661,1984356,19490297,9222414,641481,11485910,3642361,3790060,12448279,1050788,4479800,804194,6214888,24326974,2736424,621270,7769089,6549224,1814468,5627967,532668};
    int representativesArray[NUMSTATES];
    double divisorsArray[NUMSTATES];
    char *stateNamesArray[NUMSTATES] = {"Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa",
"Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota",
"Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico",
"New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island",
"South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington",
"West Virginia", "Wisconsin", "Wyoming" };
    
    int largest;
    int i,j;
    for(i=0;i<NUMSTATES;i++){
        representativesArray[i] = 1;
        highestAverage(i,representativesArray,divisorsArray);
    }
    for(j=NUMSTATES;j<MAXSEATS;j++){
        largest = getLargest(populationArray,divisorsArray);
        representativesArray[largest]++;
        highestAverage(largest,representativesArray,divisorsArray);
    }
    printArray(stateNamesArray,representativesArray);
    return 0;
}
